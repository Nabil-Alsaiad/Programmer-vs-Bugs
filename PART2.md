# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/DQ_OQxRIVtA).

## Minimum Requirements

### Completed

List all the features completed.

1. Settings menu which allows for changing game board dimentions and number of enemies
2. Correct display of game board with numbers of columns and rows
3. Correct display of units board which contain the following information for each unit (name, number, location, health, damage, range)
4. Displaying an arrow indicating a specific unit's turn before the unit's name
5. Help command with listing down all commands avialable
6. Move command with choosing one of the 4 directions
7. Arrow command with choosing an arrow at a location and change it's direction to one of the 4 directions
8. Quit command for shutting down the game
9. Continous movement for programmer and 1 step movement for bugs
11. Dealing damage on contact for programmer and if within range for bugs
12. Dying upon reaching 0 health
13. Arrows functionality: increasing damage by 20 upon collecting
14. AI functionality: inflicting an instant 10 damage to the closest bug
15. Coffe functionality: healing programmer by 20
16. Search functionality: stoping units movement and hiding another object
17. Feature functionality: spawn for each bug fixed and double current programmer damage
18. Trial functionality: placed behind units movement
19. Fixed bugs rounds are skipped but their attributes remain
20. Game winning and losing
21. Restarting game

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Log messages (logging what happened in the game)
2. Save and load

## Additional Features

1. Bugs leave trails upon movement too
2. Trial clearing hapens at the start of a rounds set
3. Changing the game theme from "Alien VS Zmobies" to "Programmer VS Bugs" along side other game objects
4. New game object "Feature/f" from the bug-feature meme that spawns in the map upon fixing bugs and doubles current programmer damage upon collecting
5. Grouping programmer movement commands in one command
6. Making arrow command information given in 1 line
7. End game messages for winning and losing that complete the story of the game

## Contributions

### Nabil Alsaiad

1. Game structure
2. Units board Displayment
3. Units movement
4. User commands
5. Objects and units spawning and despawning
6. Bugs logic
7. Game rounds
8. Game winning and losing
9. ...

### Asem Maroof

1. Settings menu setup
2. AI and Coffee logic
3. Features object spawn logic
4. ...

### Hilmi Zaki

1. Basic commands setup
2. ...

## Problems Encountered & Solutions

A problem we faced was the communication between classes and object and how to connect everything together, at first everything was working on the same level which made monitoring logic and information flow a headeche specially when we ededn up having reference loops between classes, so we decided to make them work on different levels, like a tree-structure where you have the main root "main.cpp" which will rule everything and send the necessary information needed by other classes by injection, and other classes be a higher level than other where class A can use class B but not vice versa to avoid reference loops.
