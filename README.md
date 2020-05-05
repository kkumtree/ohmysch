# ohmysch
trying to make scheduler for zsh-terminal. (ramdomly) print out such as To-do list.

## dependency
- SQlite3 required
	- sudo apt-get update 
	- sudo apt-get install sqlite3 libsqlite3-dev
- Github: Kaundur/cmdo required ( https://github.com/Kaundur/cmdo )
	- (python 2 required)
	- pip install cmdo-app 

## installation
- cd ~
- git clone git@github.com:kkumtree/ohmysch.git
- echo "~/ohmysch/ohmysch" >> ~/.zshrc

## etc
- If additional function added to .c file, add flag like below when compiling.
	- gcc -o ohmysch o.c -L. -l ft -lsqlite3

