# 🎓 1st Semester C++ Projects

This repository contains first-semester C++ projects designed to demonstrate fundamental programming concepts including loops, functions, arrays, and console-based interaction.

---

##  Project 1: ⚔️ Skull Fighter – 2D Action Game

A console-based 2D action game where the player controls a character to fight enemies, navigate mazes, and progress through levels. The game uses ASCII characters for visual representation and includes file handling for high scores.

### ⭐ Project Overview

Skull Fighter is a procedural C++ program that implements player movement, projectile attacks, enemy AI behavior, and persistent score tracking in a command-line interface. Gameplay logic is divided into modular functions for better structure and scalability.

### 🚀 Key Features

- **Player Controls:** Smooth character movement and bullet firing.

- **Multi-Level System:** Includes Level 1 (skulls) and Level 2 (Spiders/bossSpider and skulls) with increasing difficulty.

- **Enemy Interaction:** Diverse enemies (Skulls, Mechs, Spiders) with horizontal/vertical movement and collision detection.

- **Leaderboard:** Persistent storage using file handling to save and display top player scores.

- **Game Loop:** Continuously updates game state, processes real-time input, and renders graphics using ASCII.

### ⚙️ Technical Details

Component | Implementation
---|---
 Player Data | Variables passed by reference for coordinates, health, and score
 Enemy Logic | Arrays and loops for managing movement, erasing, and collision
 Game Loop | While-loop with state management for level transitions and input
 UI/UX | Console-based ASCII visuals using `<windows.h>` for cursor positioning
 Persistence | `<fstream>` integration for saving player names and high scores to a file

### 💡 Future Improvements

- Introduce a shop system to upgrade player health and damage.

- Implement more complex enemy chasing algorithms.

- Add specialized power-ups and more diverse level environments.

### ▶️ How to Run

1. Ensure you are on a **Windows system** (requires `<windows.h>` and `<conio.h>`).  

2. Compile using a C++ compiler (e.g., MinGW/g++):  

   ```bash

   g++ skullFighter.cpp -o SkullFighter.exe
---


 Project 2: Digital Logic Simulator & Boolean Verifier

A high-performance C++ console application designed to simulate digital logic environments. This tool bridges the gap between theoretical Boolean algebra and practical circuit implementation, featuring real-time logic processing, automated truth table generation, and interactive circuit visualization.

⭐ Project Overview

This project allows users to simulate digital circuits, verify Boolean expressions, and explore logic gate operations. It demonstrates the practical implementation of fundamental digital logic concepts using C++.

🚀 Key Features

* Logic Gate Simulation Engine (AND, OR, NOT, XOR, NAND, NOR)
* Binary arithmetic modules including Half-Adder and Full-Adder
* Boolean law verification and expression minimization
* Interactive ASCII-based logic visualization
* Robust input validation to ensure correct simulation results

⚙️ Technical Details
Component | Implementation
--- | ---
Logic Gates | Low-level C++ functions for primary and universal gates with ASCII signal mapping
Arithmetic Modules | Half-Adder and Full-Adder logic with carry propagation
Boolean Verifier | Truth table comparison and live law verification for circuit simplification
Data Validation | Custom `numValidation` layer for bit-level checking and type safety

💡 Future Improvements

* Add more complex combinational circuit simulations
* Expand ASCII visualization to support larger circuits

▶️ How to Run

Compile using a standard C++ compiler (G++ or MSVC):

```bash
g++ Digital_Logic_Circuit_Simulator.cpp -o LogicSim
./LogicSim
---
