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

# 2. Data Structures
go
type Direction int

const (
	Up Direction = iota
	Down
	Left
	Right
)

type Point struct {
	x int
	y int
}

type Game struct {
	snake       []Point
	direction   Direction
	food        Point
	gameOver    bool
	score       int
	lastMove    time.Time
	changeDirCh chan Direction
}

Direction: Enum to represent the snake's movement direction.
Point: Represents coordinates on the grid.
Game: Holds all game-related states, including the snake's body, direction, food position, score, and game status.

# 3. Game Initialization
go
func NewGame() *Game {
	// Initialization logic
}

Initializes the snake in the middle of the screen.
Places the first piece of food randomly on the grid.

# 4. Game Logic
Updating the Game State
go
func (g *Game) Update() error {
	// Update logic
}

Handles direction changes based on user input.
Moves the snake at set intervals.
Checks for collisions and food consumption.

Moving the Snake
go
func (g *Game) move() {
	// Movement logic
}

Calculates the new head position based on the current direction.
Checks for collisions with walls or itself.
Grows the snake if food is eaten; otherwise, moves the snake forward.

# 5. Rendering the Game
go
func (g *Game) Draw(screen *ebiten.Image) {
	// Drawing logic
}

Clears the screen.
Draws the snake and food as colored rectangles.
Displays the current score.
Shows a "Game Over" message when applicable.

# 6. Handling Input
go
func (g *Game) handleKeys() {
	// Input handling logic
}

Listens for arrow keys or WASD to change the snake's direction.
Allows restarting the game by pressing R after a game over.

# 7. Main Function
go
func main() {
	// Entry point of the game
}

Seeds the random number generator.
Initializes the game.
Sets up the window properties.
Starts the game loop and input handling concurrently.

