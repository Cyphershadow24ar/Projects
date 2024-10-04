# Setting Up the Environment
Initialize a New Go Module

Open your terminal or command prompt, navigate to your desired project directory, and initialize a new Go module:

# bash

mkdir snake-game
cd snake-game
go mod init snake-game
Install Ebiten

Fetch the Ebiten library using go get:

# bash

go get github.com/hajimehoshi/ebiten/v2

This command downloads the Ebiten library and adds it to your go.mod file.

# Running the Game
# Navigate to Your Project Directory
Ensure you're in the snake-game directory where main.go is located.

# Build and Run the Game
You can run the game directly using the go run command:
bash
go run main.go

# Alternatively, you can build an executable:
bash
go build

This command creates an executable file named snake-game (or snake-game.exe on Windows) in your directory. Run it by executing:

# On macOS/Linux:
bash
./snake-game

# On Windows:
bash
snake-game.exe

# Gameplay Instructions
# Controls:
Arrow Keys or W/A/S/D to change the snake's direction.
R to restart the game after a game over.

# Objective:
Guide the snake to eat the red food squares.
Each time the snake eats food, it grows longer, and your score increases.
Avoid colliding with the walls or the snake's own body.

# Game Over:
If the snake collides with a wall or itself, the game ends.
Press R to restart the game.

# Understanding the Code
Let's break down the main components of the Snake game code:

# 1. Imports and Constants
go
import (
	"fmt"
	"image/color"
	"log"
	"math/rand"
	"time"

	"github.com/hajimehoshi/ebiten/v2"
	"github.com/hajimehoshi/ebiten/v2/ebitenutil"
)

# Packages:

fmt, log, math/rand, and time for standard functionalities.
image/color for defining colors.
github.com/hajimehoshi/ebiten/v2 and ebitenutil for game development.

# Constants:

Define screen dimensions, grid size, initial snake size, and game speed.
