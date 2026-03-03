# 🐚 MINISHELL1

## 🧭 DESCRIPTION DU PROJET

- L'objectif de ce projet est de réaliser un interpréteur de commandes UNIX (Shell) basé sur le fonctionnement de ```TCSH```.
- C'est la première étape cruciale avant d'aborder des projets plus complexes comme le 42sh.

- Le programme doit afficher un prompt, attendre une commande, l'exécuter, puis afficher à nouveau le prompt.

## 🗓️ DATES

📅 **Du 07/02/2026 à 08h42 au 23/01/2026 à 19h42**

## 🛠️ Fonctionnalités attendues

- Exécution de commandes : Trouvées via la variable PATH ou par chemin direct (ex: /bin/ls).

- Gestion de l'environnement : Copie et restauration de l'environnement initial.

- Builtins obligatoires :

        - cd : Changer de répertoire.

        - setenv : Ajouter/modifier une variable d'environnement.

        - unsetenv : Supprimer une variable d'environnement.

        - env : Afficher l'environnement actuel.

        - exit : Quitter le shell.

> [!NOTE]
> ⚠️ Pour cette première version, aucune gestion de pipes (|), de redirections (>) ou de fonctionnalités avancées n'est demandée.

## 🚀 UTILISATION

### - Lancement :

```bash
make (make && make clean = supprimer les .o obsolètes)
./mysh
```

### ⚙️ - Interactions :

#### 💻​ - Mode interactif :

```bash
$> ./mysh
[~/Flasheski_Minishell1] $> pwd
/home/Flasheski_Minishell1
[~/Flasheski_Minishell1] $> cd ..
[~] $> pwd
/home
```

#### 🖥️ - Mode non-interactif :

Le shell doit également fonctionner en recevant des commandes via un pipe.

```bash
echo "ls -l" | ./mysh
```

> [!IMPORTANT]
> Le code de retour (exit status) de votre minishell doit être identique à celui de la dernière commande exécutée. En cas d'erreur interne, le programme doit quitter avec le code 84.

## 📜 RÈGLES ET CONTRAINTES :

* Le projet suit des règles strictes de développement :

    - Langage : C.

    - Groupe : 1 personne.

    - Gestion d'erreurs : Les messages d'erreur doivent être écrits sur la sortie d'erreur (stderr). Inspirez-vous des messages d'erreur de TCSH.

    - Bonus : Tous les fichiers bonus doivent être dans un dossier nommé bonus.

* Fonctions autorisées :

malloc, free, exit, opendir, readdir, closedir, getcwd, chdir, fork, stat, lstat, fstat, open, close, getline, strtok, strtok_r, read, write, execve, access, isatty, wait, waitpid, wait3, wait4, signal, kill, getpid, strerror, perror, strsignal.

📁 FICHIERS && STRUCTURE DU PROJET :

Une organisation modulaire est recommandée pour gérer le cycle de vie du Shell et une meilleure compréhension.

```bash
├── bonus
│   └── display_bonus.c
├── crash_abort
├── crash_div
├── crash_seg
├── div_zero.c
├── env.txt
├── include
│   ├── my.h
│   └── shell.h
├── lib
│   ├── libmy.a
│   └── my/
├── Makefile
├── mysh
├── segfault.c
├── src
│   ├── commands
│   │   ├── cd_command.c
│   │   ├── find_command.c
│   │   ├── handle_command.c
│   │   ├── parse_command.c
│   │   └── print_cd_path.c
│   ├── envs
│   │   ├── free_env.c
│   │   ├── my_setenv.c
│   │   ├── my_unsetenv.c
│   │   └── put_env.c
│   ├── exec.c
│   ├── main.c
│   ├── paths
│   │   ├── check_paths.c
│   │   └── get_path.c
│   └── signals.c
├── tester
│   ├── mysh
│   ├── README
│   ├── tester.sh
│   └── tests
└── tester_add
    ├── mysh
    ├── tester.sh
    ├── tests
    └── tests.txt
