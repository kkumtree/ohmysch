# ohmysch
trying to make scheduler notification for zsh-terminal. 
Print out To-do list when opening each terminal window.

<div>
<img width="800" src="https://user-images.githubusercontent.com/52643858/81502262-e8f32080-9317-11ea-9981-82965129c8c8.png">
</div>

<iframe width="560" height="315" src="https://www.youtube.com/embed/wlqta98CvGw" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

## dependency
- SQlite3 required
	```
	sudo apt-get update 
	sudo apt-get install sqlite3 libsqlite3-dev
	```
- Github: Kaundur/cmdo required ( https://github.com/Kaundur/cmdo )
	- (python 2 required)
	```
	pip install cmdo-app 
	```

## installation

```
cd ~
git clone git@github.com:kkumtree/ohmysch.git
echo "~/ohmysch/ohmysch" >> ~/.zshrc
```

## etc
- If additional function added to .c file, add flag like below when compiling.
	- gcc -o ohmysch o.c -L. -l ft -lsqlite3

