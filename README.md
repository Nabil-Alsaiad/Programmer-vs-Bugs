# Programmer vs Bugs

A game inspired by the game "Alien path", made as a command line text game with some modifications to the idea of the original game

The player character (programmer) was working on an application but suddenyl many bugs has came out of no where, he has brought his coffee and opened google search and AI tabs in the browser as preperation for a long night, will he be able to fix these bugs? or will the bugs overwhelm our programmer?.

<details>
  <summary>   Screenshots</summary>
  
![Screenchot1](https://user-images.githubusercontent.com/73927632/219968768-78a2fca9-97a9-455f-837c-b3243ec0843f.png)
![Screenchot2](https://user-images.githubusercontent.com/73927632/219968772-df5e86bb-2480-4e81-b44f-be9cfdf15843.png)
![Screenchot3](https://user-images.githubusercontent.com/73927632/219968777-39250e7b-55e2-418c-b8fe-28bef20eba82.png)

</details>


A YouTube playlits of the game part 1 and part 2 videos link: [Click here to watch](https://youtube.com/playlist?list=PLVhmJfFMWiivr1c07V-rWZlTWjDnynAfK).

## Compilation Instructions

Compile only the main file using this command
```
g++ "src/main.cpp" -o "programmer vs bugs"
```

Then run the game by simply typing the full path or/and name of the file you just compiled. 
```
"programmer vs bugs"
```

## User Manual

### Setting menu

After launching the game, you'll face a settings menu where you can change the game settings before playing, type 'y' if you want to change them, or 'n' if you want to use these settings, note that anything other than 'y' or 'n' will bot be accepted.

If you chose to change the default settings then the game will list the settings for you and you have to give a value to each one of them, you use a different value of the default one.

If you chose not to change anything then it'll take you straight to the main game menu.

### Game menu

The game menu consists of 3 major parts

1. Game map: consist of many slots numbered by the x and y coordinates, each slot can hold an unit, object or be empty
2. Units board: Shows all the units in game with their location and attributes, it also shows an arrow before a unit to indicate that it's this unit's round
3. Commands: commands are used in programmer round only, use h/help to list all commands 

<hr width="75%" size="3">

Units

<table>
  <tr>
    <th>Name</th>
    <th>Symbol</th>
    <th>Description</th>
  </tr>
  <tr>
    <td>Programmer</td>
    <td>P</td>
    <td>The player character</td>
  </tr>
  <tr>
    <td>Bug</td>
    <td>B</td>
    <td>The enemies character</td>
  </tr>
</table>

Objects

<table>
  <tr>
    <th>Name</th>
    <th>Symbol</th>
    <th>Description</th>
  </tr>
  <tr>
    <td>Feature</td>
    <td>f</td>
    <td>Double programmers's current damage amount, spawn one feature for every fixed bug</td>
  </tr>
  <tr>
    <td>Artificial intelligence (AI)</td>
    <td>a</td>
    <td>Attacks the closes bug to it with a fixed damage of 10</td>
  </tr>
  <tr>
    <td>Coffee</td>
    <td>c</td>
    <td>Heals programmer by 20</td>
  </tr>
  <tr>
    <td>Search</td>
    <td>s</td>
    <td>Reveal what's hidden beneath it and stops movement</td>
  </tr>
  <tr>
    <td>Arrow</td>
    <td>^/v/>/<</td>
    <td>Changes programmer direction and increases his damage by 20</td>
  </tr>
  <tr>
    <td>Trial</td>
    <td>.</td>
    <td>Placed upon movement of a unit, replaced later with random object</td>
  </tr>
</table>

Commands

<table>
  <tr>
    <th>Name</th>
    <th>Description</th>
  </tr>
  <tr>
    <td>h/help</td>
    <td>List down all game commands</td>
  </tr>
  <tr>
    <td>m/move</td>
    <td>Move programmer in a desired direction that will be asked to insert afterwards</td>
  </tr>
  <tr>
    <td>a/arrow</td>
    <td>Chage an arrow direction, the x and y coordinates of the arrow and the new direction will be asked afterwards</td>
  </tr>
  <tr>
    <td>q/quit</td>
    <td>Shutdown the game</td>
  </tr>
</table>

## Progress Log

-   [Part 1](PART1.md)
-   [Part 2](PART2.md)

## Contributors

Please replace the following with your group members' names.

-   Nabil Alsaiad
-   Asem Mroof
-   Hilmi Zaki
