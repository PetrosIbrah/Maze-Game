# What is MazeGame?
It is a C++ terminal game project using old libraries, like ncurses. The idea of this game includes a player and a Bot Enemy. The player is trapped in a maze and the only exit is to capture the stone. The enemy however will find the smartest paths to capture the stone first and trap the player. 

Furthermore, the following characters indicate their roles:
- <pre>L => Player</pre>
- <pre>M => Enemy</pre>
- <pre>@ => Stone</pre>

## Requirements
Before compliling or running the project you will need the following
1. Make sure you have g++ compiler installed:
    <pre>sudo apt install g++</pre>
2. Install the ncurses library:
    <pre>sudo apt-get install libncurses5-dev libncursesw5-dev</pre>
3. Finally, install the make utility in order to be able to use the make file
    <pre>sudo apt install make</pre>

## How to run
For ease of Compiling & Running, a Makefile is included in the project
- To Compile & Run type the following in a terminal in the same directory as the project
  <pre>make compile</pre>
- To Run the project with out Compiling:
  <pre>make</pre>
- To clear the executable type the following
  <pre>make clean</pre>
