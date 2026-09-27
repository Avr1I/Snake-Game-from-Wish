# Snake Game (from Wish)

A simple Snake-style game written in C++ with SDL2 and SDL2_ttf. Control a moving block around the screen, grab coins to score points, and try to survive as the game speeds up.

## Overview

- 2D arcade game rendered with SDL2
- Arrow-key controls (up / down / left / right)
- Horizontal screen wraparound (going off the left/right edge brings you back on the other side)
- Game over when hitting the top or bottom edge
- Coins spawn at random positions; collecting one increases your score and speeds up movement
- Score displayed on screen using a custom font (`Milker.otf`) via SDL2_ttf

## Requirements

The project is set up for **Visual Studio** (`.sln` / `.vcxproj` files) and targets **Windows**.

Dependencies (installed via NuGet, see `packages.config`):

| Library | Version |
|---|---|
| SDL2 | 2.32.8 |
| SDL2 (redist) | 2.32.8 |
| SDL2_ttf | 2.24.0 |
| SDL2_ttf (redist) | 2.24.0 |

## ⚠️ Before you build

The source files (`main.cpp`, `decla.h`, `Ini.cpp`) currently `#include` SDL2/SDL2_ttf headers and the font file using **hardcoded absolute paths** (e.g. `C:\Users\fingx\OneDrive\Dokumente\Programming\C++\Snake Game\...`). These paths point to the original author's machine and won't exist elsewhere. Before building on another computer, you'll need to either:

- Update those include paths / the font path to match where you cloned the repo, or
- Switch to relative includes and add the NuGet `packages\...\include` folders to the project's "Additional Include Directories" in Visual Studio.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Avr1I/Snake-Game-from-Wish.git
   ```
2. Open `Snake Game.sln` in Visual Studio.
3. Restore the NuGet packages (Visual Studio usually does this automatically when the project opens; otherwise, right-click the solution → **Restore NuGet Packages**).
4. Fix the hardcoded paths described above (includes and font path).
5. Build and run (F5) using the **x86** or **x64** configuration, matching the installed SDL2 packages.

## Controls

| Key | Action |
|---|---|
| ↑ | Move up |
| ↓ | Move down |
| ← | Move left |
| → | Move right |
| Esc | Quit the game |

## Project structure

```
Snake-Game-from-Wish/
├── main.cpp                     # Entry point
├── decla.h                      # Game class declaration
├── Ini.cpp                      # Game logic: init, input, update, render, cleanup
├── Milker.otf                   # Font used for the score display
├── Snake Game.sln               # Visual Studio solution
├── Snake Game.vcxproj           # Project file
├── Snake Game.vcxproj.filters
├── Snake Game.vcxproj.user
└── packages.config              # NuGet dependencies
```

## How it works

The `Game` class handles the whole lifecycle:

- `Initialize()` — sets up SDL, creates the window/renderer, initializes SDL_ttf, and places the snake and the first coin.
- `Runloop()` — the main loop, calling `ProcessInput()`, `UpdateGame()`, and `ProcessOutput()` each frame.
- `ProcessInput()` — reads keyboard state to set the current movement direction, and handles quitting (Esc or window close).
- `UpdateGame()` — moves the block, wraps it around the screen horizontally, ends the game on vertical collision, and checks proximity to the coin to trigger scoring and re-spawning.
- `ProcessOutput()` — clears the screen and draws the snake, the coin, and the score text.
- `Endloop()` — releases SDL resources.

## Known limitations

- The "snake" is currently a single moving rectangle with no growing tail/body segments.
- Include and asset paths are hardcoded to the original developer's machine (see warning above).
- Windows/Visual Studio only; no cross-platform build setup (CMake, etc.) is provided.
