#!/bin/bash

# Default values
MYSHELL="$PWD/mysh"
TESTS_FILE="tests"
REFER="/bin/tcsh -f"
TRAPSIG=0

GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

# Binary paths
CAT=`which cat`
GREP=`which grep`
SED=`which sed`
RM=`which rm`
TR=`which tr`
HEAD=`which head`
TAIL=`which tail`
WC=`which wc`
CHMOD=`which chmod`
EXPR=`which expr`
MKDIR=`which mkdir`
CP=`which cp`

# Parse optional arguments
# Usage: ./tester.sh [-e executable] [-t tests_file] [-d] [test_id]
DEBUG=0
TEST_ID=""

while [[ $# -gt 0 ]]; do
  case $1 in
    -e)
      MYSHELL="$2"
      shift 2
      ;;
    -t)
      TESTS_FILE="$2"
      shift 2
      ;;
    -d)
      DEBUG=2
      shift
      ;;
    *)
      TEST_ID="$1"
      shift
      ;;
  esac
done

# Clean environment
for i in `env | grep BASH_FUNC_ | cut -d= -f1`; do
    f=`echo $i | sed s/BASH_FUNC_//g | sed s/%%//g`
    unset -f $f
done

disp_test()
{
  id=$1
  $CAT "$TESTS_FILE" | $GREP -A1000 "\[$id\]" | $GREP -B1000 "^\[$id-END\]" | $GREP -v "^\[.*\]"
}

run_script()
{
  SC="$1"
  echo "$SC" > /tmp/.tmp.$$
  . /tmp/.tmp.$$
  $RM -f /tmp/.tmp.$$
}

prepare_test()
{
  local testfn="/tmp/.tester.$$"
  local runnerfn="/tmp/.runner.$$"
  local refoutfn="/tmp/.refer.$$"
  local shoutfn="/tmp/.shell.$$"
  WRAPPER="$runnerfn"
  echo "#!/bin/bash" > $runnerfn
  echo "$SETUP" >> $runnerfn
  echo "/bin/bash -c '"$testfn" | "$MYSHELL" ; echo Shell exit with code \$?' > "$shoutfn" 2>&1" >> $runnerfn
  echo "$CLEAN" >> $runnerfn
  echo "$SETUP" >> $runnerfn
  echo "$TCSHUPDATE" >> $runnerfn
  echo "/bin/bash -c '"$testfn" | "$REFER" ; echo Shell exit with code \$?' > "$refoutfn" 2>&1" >> $runnerfn
  echo "$CLEAN" >> $runnerfn
  echo "#!/bin/bash" > $testfn
  echo "$TESTS" | $TR "²" "\n" >> $testfn
  chmod 755 $testfn
  chmod 755 $runnerfn
}

load_test()
{
  id=$1
  debug=$2
  # Fetch details from specific tests file
  SETUP=`disp_test "$id" | $GREP "SETUP=" | $SED s/'SETUP='// | $SED s/'"'//g`
  CLEAN=`disp_test "$id" | $GREP "CLEAN=" | $SED s/'CLEAN='// | $SED s/'"'//g`
  NAME=`disp_test "$id" | $GREP "NAME=" | $SED s/'NAME='// | $SED s/'"'//g`
  TCSHUPDATE=`disp_test "$id" | $GREP "TCSHUPDATE=" | $SED s/'TCSHUPDATE='// | $SED s/'"'//g`
  TESTS=`disp_test "$id" | $GREP -v "SETUP=" | $GREP -v "CLEAN=" | $GREP -v "NAME=" | $GREP -v "TCSHUPDATE=" | $GREP -v "TESTS=" | $TR "\n" "²" | $SED s/"²$"//`
  
  prepare_test
  $WRAPPER

  nb=`$CAT /tmp/.refer.$$ | $GREP -v '^_=' | $GREP -v '^\[1\]' | $WC -l`
  i=1
  ok=1
  while [ $i -le $nb ]
  do
    l=`$CAT /tmp/.refer.$$ | $GREP -v '^_=' | $GREP -v '^\[1\]' | $HEAD -$i | $TAIL -1`
    a=`$CAT /tmp/.shell.$$ | $GREP -v '^_=' | $GREP -v '^\[1\]' | $GREP -- "$l$" | $WC -l`
    if [ $a -eq 0 ]; then ok=0; fi
    i=`$EXPR $i + 1`
  done

  if [ $ok -eq 1 ]; then
    if [ $debug -ge 1 ]; then
      echo -e "${GREEN}Test $id ($NAME) : OK${RESET}"
      if [ $debug -eq 2 ]; then
        echo "Output $MYSHELL :"
        $CAT -e /tmp/.shell.$$
        echo -e "\nOutput $REFER :"
        $CAT -e /tmp/.refer.$$
        echo ""
      fi
    else
      echo -e "${GREEN}OK${RESET}"
    fi
  else
    if [ $debug -ge 1 ]; then
      echo -e "${RED}Test $id ($NAME) : KO - Check output in /tmp/test.$$/$id/${RESET}"
      $MKDIR -p /tmp/test.$$/$id 2>/dev/null
      $CP /tmp/.shell.$$ /tmp/test.$$/$id/mysh.out
      $CP /tmp/.refer.$$ /tmp/test.$$/$id/tcsh.out
    else
      echo -e "${RED}KO${RESET}"
    fi
  fi
}

# Signal Trapping
if [ $TRAPSIG -eq 1 ]; then
  for sig in `trap -l`; do
    echo "$sig" | grep "^SIG" >/dev/null 2>&1
    if [ $? -eq 0 ]; then trap "echo Received signal $sig !" $sig; fi
  done
fi

# Validation
if [ ! -f "$TESTS_FILE" ]; then
  echo "Error: Tests file '$TESTS_FILE' not found." >&2
  exit 1
fi

if [ ! -f "$MYSHELL" ]; then
  echo "Error: Executable '$MYSHELL' not found." >&2
  exit 1
fi

# Execution Logic
if [ -z "$TEST_ID" ]; then
  # Run all tests
  for lst in `$CAT "$TESTS_FILE" | grep "^\[.*\]$" | grep -vi end | sed s/'\['// | sed s/'\]'//`
  do
    path_backup=$PATH
    load_test $lst 1
    export PATH=$path_backup
  done
else
  # Run specific test
  load_test "$TEST_ID" "$DEBUG"
fi
