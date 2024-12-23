# Undead Assault: A Classic Shooter

## Overview

**Undead Assault** is a dynamic 2D side-scroller game developed using Unreal Engine 4. In this thrilling zombie apocalypse, you control Cyborg, the last hope to combat relentless waves of zombies and defeat monstrous enemies like the Ogre Boss. The game incorporates a variety of weapons, AI-driven enemies, smooth level design, and efficient game mechanics powered by essential data structures and algorithms.

This README will walk you through the core features of the game, system requirements, setup instructions, and development insights.

---

## Table of Contents

- [Gameplay Overview](#gameplay-overview)
- [Main Features](#main-features)
  - [Main Menu](#main-menu)
  - [Main Character](#main-character)
  - [Weapons](#weapons)
  - [Enemies](#enemies)
  - [Level Design](#level-design)
  - [AI Controllers](#ai-controllers)
  - [Sounds](#sounds)
  - [Health and Damage Systems](#health-and-damage-systems)
- [Technical Details](#technical-details)
  - [Data Structures & Algorithms](#data-structures--algorithms)
  - [Optimization Techniques](#optimization-techniques)
- [Challenges Faced](#challenges-faced)
- [Potential Improvements](#potential-improvements)
- [Conclusion](#conclusion)
- [Sources](#sources)

---

## Gameplay Overview

Undead Assault is set in a post-apocalyptic world overrun by zombies. As Cyborg, the protagonist, you navigate through multiple levels, facing increasingly difficult enemies. With powerful weapons and strategic gameplay, your objective is to eliminate all enemies and defeat a final boss to save humanity. Each level offers different challenges, ranging from maze-like platforms to intense boss battles.

---

## Main Features

### Main Menu

The main menu of **Undead Assault** is simple and intuitive, featuring:
- A **Play** button to start the game.
- A **Settings** button to adjust game volume.
- A background image enhancing the eerie atmosphere of the game.

### Main Character

**Cyborg** is the player-controlled character, a resilient survivor in a world ravaged by the undead. Armed with a variety of weapons, Cyborg is ready to face hordes of zombies and other terrifying enemies.

### Weapons

The game features a range of weapons dropped in crates across levels:
1. **GunOne**: A reliable sidearm with moderate damage.
2. **GunTwo**: A low-damage, close-range weapon perfect for early game.
3. **GunThree**: A long-range, high-damage weapon with slow reload times.
4. **GunFour**: A versatile, high-fire-rate gun ideal for mid-range combat.

These weapons offer varied combat styles, allowing players to adapt to different challenges.

### Enemies

The game introduces several enemy types:
- **Zombies**: Standard mob enemies that increase in number as you progress.
- **Ogres**: Larger, more powerful foes, culminating in the **Final Boss** in Level 3.

Enemy waves get progressively harder, with strategic positioning and weapon choice crucial to survival.

### Level Design

The game consists of three unique levels:
1. **Level 1**: A maze of platforms, featuring a hidden crate.
2. **Level 2**: A cave-like environment with two pathways.
3. **Level 3**: The final level with an epic Ogre boss fight.

Each level has a unique theme and challenges, requiring the player to adapt to new environments.

### AI Controllers

Two primary AI controllers drive enemy behavior:
- **Zombie AI**: Moves towards Cyborg using a Lerp algorithm for smooth movement.
- **Ogre AI**: More complex, requiring strategic thinking to defeat.

### Sounds

The game features a variety of atmospheric soundtracks and effects:
- **Main Menu**: Blood Swamps (DOOM Eternal).
- **Level 1**: End Times (Outer Wilds).
- **Level 2**: The Angler (Inscryption).
- **Boss Level**: The Ash Twin Project (Outer Wilds).

Weapon sounds and other in-game effects enhance the immersive experience.

### Health and Damage Systems

The health and damage systems allow for dynamic player-enemy interactions. When Cyborg collides with enemies, damage is applied using the built-in collision detection. Enemies also have their own health systems, and game events such as picking up health potions affect player stats.

---

## Technical Details

### Data Structures & Algorithms

We implemented essential data structures and algorithms to optimize gameplay and ensure smooth performance:
- **Heap**: Used for priority queue management of items in crates, ensuring that the most valuable items (e.g., health potions, weapons) are prioritized.
- **Doubly Linked List**: For efficient gun inventory management, allowing players to switch weapons quickly.
- **Hashmaps**: Used for saving and loading weapon stats (e.g., ammo count) across levels.
- **Queue**: Manages enemy spawning in waves, ensuring pacing and challenge.
- **Lerp Algorithm**: Smooth movement of enemies towards the player.

### Optimization Techniques

We focused on optimizing performance through:
- **Efficient Code Optimization**: Streamlined processes to reduce lag and stuttering gameplay.
- **Memory Management**: Prevented memory leaks, ensuring smoother gameplay and better performance across different systems.

---

## Challenges Faced

- **Git LFS Issues**: Due to asset size limitations, we resorted to Google Drive for file sharing, causing some version control challenges.
- **Visual Studio Compatibility**: Some team members faced issues with Visual Studio on non-Windows platforms, requiring workarounds such as using Unreal Engine 4 instead of the latest version.
- **Communication Issues**: Early communication lapses led to inefficiencies in level design, resolved through more open discussions and feedback.

---

## Potential Improvements

1. **Version Control with GitHub**: This would improve collaboration and simplify tracking changes.
2. **360-Degree Aiming with Mouse**: Enhancing the aiming mechanics for more precise targeting.
3. **Multiplayer Mode**: A co-op multiplayer mode would add excitement and replayability.
4. **Cross-Platform Support**: Expanding to macOS, Linux, Android, and iOS to broaden the player base.
5. **Variety in Enemies**: Introducing new enemy types and interactive hazards.
6. **Structured Storyline**: A branching narrative with multiple endings based on player choices.
7. **Scoreboard**: Implementing a global scoreboard to encourage competition.

---

## Conclusion

**Undead Assault** was a rewarding project that enhanced our skills in Unreal Engine, game mechanics, and data structures. The collaborative effort allowed us to overcome numerous challenges, culminating in an engaging 2D shooter game. Our journey through this project not only improved our technical abilities but also strengthened our teamwork, problem-solving, and creative skills.

---

## Members

Meet the team behind **Undead Assault**! Check out their GitHub profiles for more of their work and contributions.

- **Muhammad Wasif Shakeel**  
  GitHub: [Muhammad Wasif Shakeel](https://github.com/mwasifshkeel)
  
- **Qasim Ahmed**  
  GitHub: [Qasim Ahmed](https://github.com/qasimahmed06)
  
- **Adyaan Ahmed**  
  GitHub: [Adyaan Ahmed](https://github.com/adyaanismyname)
  
- **Attiqa Bano**  
  
- **Fizza Kashif**  
  
- **Mehreen Raheel**  

---

## Sources

- **Sprites**:  
  - [Free Graveyard Platformer Tileset - Game Art 2D](https://www.gameart2d.com)  
  - [Free Halloween 2D Game Backgrounds - CraftPix.net](https://craftpix.net)  
  - [Free Green Zone Tileset - CraftPix.net](https://craftpix.net)  
  - Terryble Knight Assets by ansimuz  
  - Zombie by IronnButterfly  

- **Learning Resources**:  
  - [2D Scroller UE4 Lesson 1: Setting the Scene](https://www.youtube.com)
  
- **Error Debugging**:  
  - Unreal Engine Forum  
  - Unreal Engine 5.5 Documentation  
  - [ChatGPT](https://chat.openai.com)  
  - Stack Overflow

---

## Getting Started

Clone this repository to your local machine:

```bash
git clone https://github.com/mwasifshkeel/undead-assault.git
