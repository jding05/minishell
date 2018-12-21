# minishell

## Description
In this project, you need to make a **mini-shell [a simple version of bash]** that reads and evaluates simple commands from the user. The reading will involve a trivial *lexical* and syntactical analysis of the command, and the evaluation will involve finding the **corresponding binary** on the machine and executing it, or to execute the code concerned in the case of a **"built-in"** command to the shell.

## Objective
* Basic lexical and syntactic analysis ("lexing" and "parsing") 
* Execution of a command in a new process 
* Management of the environment 
* Management of the PATH 

## Built-in
There are **6 built-in** functions:
1. echo
2. cd
3. setenv
4. unsetenv
5. env
6. exit

## Additonal (bonus)
* Management of **signals** to handle signal interrupt (Ctrl C)
* Management of execution rights in the **PATH**
* Auto completion
* The separation of commands with **";"**

## Download the project ?
```
# open your terminal & copy following lines
git clone https://github.com/jding05/minishell

cd minishell

make && ./minishell
```
