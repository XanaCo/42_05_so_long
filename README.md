
<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/so_longm.png alt=Xanaco's 42Project Badge/>
<h2>Final score</h2>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/125Grade.png alt=Xanaco's 42Project Score/>
<h4>Completed + Bonus</h4>
<h5>Outstanding Project 3/3</h5>
</div>

## Installation

### Prerequisites
Make sure all dependencies are installed on your system, may vary depending on your distribution.

### Build
```
git clone git@github.com:XanaCo/42_05_so_long.git SoLong
cd SoLong
make
```

### Run
For the mandatory part:
```
./so_long  maps/mandatory/valid/choose-one-file-here
```
For the bonus part:
```
./so_long maps/bonus/valid/choose-one-file-here
```
# So_long (mini) Bible

<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/So_long.png alt=SOLONG Title Screenshot/>
</div>

This is my **first game** entirely coded in C, created as a school project at **42**.

The so_long project presents students with the challenge of creating a simple 2D game. Leveraging graphical programming, it revolves around a character (here, a small cute yellow dog) who needs to collect items in a map (bones) and then reach the exit, all while avoiding enemies (skeletons).  

This project offers an introduction to **game development and graphical libraries**, providing hands-on experience in creating interactive visual applications.  

The game mechanics are straightforward, but they allow for creativity in designing the map, characters, and items. The goal was to make a fun, cute, and challenging little game where exploration and planning matter.

## Table of Contents
- [Installation](#installation)
- [Game Concept](#game-concept)
- [Gameplay](#gameplay)
- [Controls](#controls)
- [Enemies](#enemies)
- [Objectives](#objectives)

## Game Concept

You take control of **Inca**, a playful little dog exploring a spooky graveyard. Your goal is to **collect all bones** while avoiding skeletons, then safely reach the exit.  

- **Genre:** 2D Top-down Puzzle / Arcade  
- **Target Platform:** Linux (prototype) 
- **Audience:** Players who enjoy cute characters, light puzzles, and arcade-style challenges

## Gameplay

1. Explore the graveyard and navigate through tombs.  
2. Collect all bones scattered throughout the level.  
3. Avoid skeletons, which remain idle but will cause a fail if touched.  
4. Once all bones are collected, reach the exit to finish the level.  

## Controls

- **Movement:** Arrow Keys / WASD  
- **Action:** None (simple collection by touching bones)  
- **Pause / Quit:** ESC or Q, or close window  

## Enemies

### Skeletons
- Idle in place, guarding bones or tombs.  
- **Touching a skeleton ends the game.**

## Objectives

- **Collect all bones** in the graveyard.  
- **Avoid skeletons** at all costs.  
- **Reach the exit** only after collecting all bones.  

