# Programmer vs Bugs

A game inspired by the game "Alien path", made as a command line text game with some modifications to the idea of the original game

You as a programmer must get rid of all bugs in order to have happier customers.

![image](https://user-images.githubusercontent.com/73927632/216097719-ec48dfb5-459b-4999-b174-8560ab962854.png)

A YouTube videos of the game playlist link, [Click here to watch](https://youtube.com/playlist?list=PLVhmJfFMWiivr1c07V-rWZlTWjDnynAfK).

## Compilation Instructions

```
g++ "src/main.cpp" -o "programmer vs bugs"
```

## User Manual

### Setting menu

On game start, you'll face a settings menu where it'll ask you if you want to change the default game settings or not, type ONLY 'y' if you want to change them, or ONLY 'n' if you want to confirm them, note that anything other than 'y' or 'n' will bot be accepted.

If chose to change the default settings then the game will list the settings for you and you have to give a value to each one of them, you use a different value of the default one.

If chose not to change anything then it'll take you straight to the main game menu.

### Game menu

The game menu consists of 3 major parts

1. Game map
2. Units board
3. commands and logs (logs are not done yet)

The map it's columns and rows numbered on the left and below the map, the map consists of slots, each slot can hold an unit, object or be empty.

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
    <td>The enemies in the game</td>
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
    <td>Artificial intelligence (AI)</td>
    <td>a</td>
    <td>Attacks the closes bug to it with a fixed damage of 10</td>
  </tr>
  <tr>
    <td>Documentation</td>
    <td>d</td>
    <td>Heals the player by 20</td>
  </tr>
  <tr>
    <td>Search</td>
    <td>s</td>
    <td>Hides something beneath it, or maybe nothing</td>
  </tr>
  <tr>
    <td>Arrow</td>
    <td>^/v/>/<</td>
    <td>Changes the player direction and increases it's damage by 20</td>
  </tr>
  <tr>
    <td>Trial</td>
    <td>.</td>
    <td>Indicates that a unit has passed from here</td>
  </tr>
</table>

<hr width="75%" size="3">

## Progress Log

-   [Part 1](PART1.md)
-   [Part 2](PART2.md)

## Contributors

Please replace the following with your group members' names.

-   Nabil Alsaiad
-   Asem Mroof
-   Hilmi Zaki
