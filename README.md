# Pac-Man game
## About source code
Environment: Ubuntu
Compile: Using Qt qmake
Execution: Pressing Qt "Run" button
    or 
    ./pd2-pacman
## Game instruction
### Introduction
You are the yellow circle, and your mission is to "eat" all the points on the screen. Press button "B" to start the game.
### Move
Press "Arrow Up", "Arrow Down", "Arrow Left", "Arrow Right" to move.
No need to press "Arrow button" immediately at the cross road. You can "pre-press" the "Arrow button", and the yellow will turn to the direction you pressed as it can turn.
### Ghost
There are four ghosts in the map. Each has its moving algorism. Do not touch them, or you will reborn at the start point.
### Power pellet
Bigger point in the map. As you "eat" it, the ghosts turn to frighten mode, and can not hurt you. Moreover, you can eat them, and let them reborn.
## About the program
### Program UML
|GameObj                        |
|:------------------------------|
|#locate:int[0..1]<br>#looklike:int<br>#movespeed:int<br>#speedTimer:int<br>#direction:int<br>#step:int<br>|
|<\<constructor>>+GameObj()<br>+move()<br>+die(in:int)<br>+setLook(in:int)<br>+getLocate(in:int):int{query}<br>+getLook():int{query}<br>+getDirection():int{query}<br>+getStep():int{query}<br>|

&nbsp; &nbsp; &nbsp; &#8593;<br>

|Ghost                          |
|:------------------------------|
|#map:int[0..923]<br>#destination:int[0..1]<br>#timer:int<br>#isfright:int<br>#frightTimer:int<br>#frightTime:int<br>|
|<\<constructor>>+Ghost()<br>#move()<br>#die(in:int)<br>#scatter()<br>#fright()<br>#chase()<br>#findDir()<br>|

&nbsp; &nbsp; &nbsp; &#8593;<br>

|Blinky                         |
|:------------------------------|
||
|<\<constructor>>+Blinky(tar:GameObj,look:int)<br>+die(in:int)<br>|

|Ghost|
|:---:|

&nbsp; &nbsp; &#8593;<br>

|Pinky                          |
|:------------------------------|
||
|<\<constructor>>+Pinky(tar:GameObj,look:int)<br>+chase()<br>+die(in:int)<br>|

|Ghost|
|:---:|

&nbsp; &nbsp; &#8593;<br>

|Inky                           |
|:------------------------------|
|#blinky:GameObj                |
|<\<constructor>>+Inky(tar:GameObj,blink:GameObj,in:int)<br>+chase()<br>+die(in:int)<br>|

|Ghost|
|:---:|

&nbsp; &nbsp; &#8593;<br>

|Clyde                          |
|:------------------------------|
||
|<\<constructor>>+Clyde(tar:GameObj,in:int)<br>+chase()<br>+die(in:int)<br>|

|GameObj|
|:-----:|

&nbsp; &nbsp; &#8593;<br>

|Pacman|
|:-----|
|+map:int[0..923]<br>+eatPos:int<br>#preDir:int<br>#eaten:int<br>#timer:int<br>#powerTime<br>|
|<\<constructor>>+Pacman()<br>+move()<br>+changeDir(in:int)<br>+getEaten():int<br>+getPower():int<br>+die(in:int)<br>|

### Code description
I compute every pixel to let the "Game object" move. Using "speedTime" and a timer to determine whether they can move or not. Every game object has it own timer.
In the mainwindow.cpp file, I use the polymorphism technique to call all game object's move()function.
