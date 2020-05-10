# ohmysch
trying to make scheduler notification for zsh-terminal. 
Print out To-do list when opening each terminal window.

<div>
<img width="800" src="https://user-images.githubusercontent.com/52643858/81502262-e8f32080-9317-11ea-9981-82965129c8c8.png">
</div>

<style>.embed-container { position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden; max-width: 100%; } .embed-container iframe, .embed-container object, .embed-container embed { position: absolute; top: 0; left: 0; width: 100%; height: 100%; }</style><div class='embed-container'><iframe src='https://www.youtube.com/embed//wlqta98CvGw' frameborder='0' allowfullscreen></iframe></div>

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

