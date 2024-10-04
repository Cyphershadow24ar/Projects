package main

import (
	"fmt"
	"image/color"
	"log"
	"math/rand"
	"time"

	"github.com/hajimehoshi/ebiten/v2"
	"github.com/hajimehoshi/ebiten/v2/ebitenutil"
)

// Constants for the game
const (
	screenWidth      = 640
	screenHeight     = 480
	gridSize         = 20
	initialSnakeSize = 5
	gameSpeed        = 100 // Milliseconds per move
)

// Direction represents the movement direction of the snake
type Direction int

const (
	Up Direction = iota
	Down
	Left
	Right
)

// Point represents a position on the grid
type Point struct {
	x int
	y int
}

// Game holds the game state
type Game struct {
	snake       []Point
	direction   Direction
	food        Point
	gameOver    bool
	score       int
	lastMove    time.Time
	changeDirCh chan Direction
}

// NewGame initializes a new game
func NewGame() *Game {
	g := &Game{
		snake:       make([]Point, initialSnakeSize),
		direction:   Right,
		changeDirCh: make(chan Direction),
		lastMove:    time.Now(),
	}
	// Initialize the snake in the middle of the screen
	startX := screenWidth/(2*gridSize) - initialSnakeSize/2
	startY := screenHeight / (2 * gridSize)
	for i := 0; i < initialSnakeSize; i++ {
		g.snake[i] = Point{x: startX - i, y: startY}
	}
	g.placeFood()
	return g
}

// placeFood randomly places food on the grid, not on the snake
func (g *Game) placeFood() {
	for {
		g.food = Point{
			x: rand.Intn(screenWidth / gridSize),
			y: rand.Intn(screenHeight / gridSize),
		}
		// Ensure food is not on the snake
		occupied := false
		for _, p := range g.snake {
			if p.x == g.food.x && p.y == g.food.y {
				occupied = true
				break
			}
		}
		if !occupied {
			break
		}
	}
}

// Update updates the game state
func (g *Game) Update() error {
	if g.gameOver {
		return nil
	}

	// Handle direction changes
	select {
	case dir := <-g.changeDirCh:
		// Prevent the snake from reversing
		if (g.direction == Up && dir != Down) ||
			(g.direction == Down && dir != Up) ||
			(g.direction == Left && dir != Right) ||
			(g.direction == Right && dir != Left) {
			g.direction = dir
		}
	default:
		// No direction change
	}

	// Move the snake based on game speed
	if time.Since(g.lastMove) >= time.Duration(gameSpeed)*time.Millisecond {
		g.lastMove = time.Now()
		g.move()
	}

	return nil
}

// move moves the snake in the current direction
func (g *Game) move() {
	// Calculate new head position
	head := g.snake[0]
	newHead := head
	switch g.direction {
	case Up:
		newHead.y--
	case Down:
		newHead.y++
	case Left:
		newHead.x--
	case Right:
		newHead.x++
	}

	// Check for collisions with walls
	if newHead.x < 0 || newHead.x >= screenWidth/gridSize ||
		newHead.y < 0 || newHead.y >= screenHeight/gridSize {
		g.gameOver = true
		return
	}

	// Check for collisions with itself
	for _, p := range g.snake {
		if p.x == newHead.x && p.y == newHead.y {
			g.gameOver = true
			return
		}
	}

	// Add new head to the snake
	g.snake = append([]Point{newHead}, g.snake...)

	// Check if food is eaten
	if newHead.x == g.food.x && newHead.y == g.food.y {
		g.score++
		g.placeFood()
	} else {
		// Remove the tail
		g.snake = g.snake[:len(g.snake)-1]
	}
}

// Draw renders the game screen
func (g *Game) Draw(screen *ebiten.Image) {
	// Clear the screen
	screen.Fill(color.RGBA{0, 0, 0, 255})

	// Draw the snake
	for _, p := range g.snake {
		ebitenutil.DrawRect(screen, float64(p.x*gridSize), float64(p.y*gridSize), float64(gridSize), float64(gridSize), color.RGBA{0, 255, 0, 255})
	}

	// Draw the food
	ebitenutil.DrawRect(screen, float64(g.food.x*gridSize), float64(g.food.y*gridSize), float64(gridSize), float64(gridSize), color.RGBA{255, 0, 0, 255})

	// Draw the score
	msg := fmt.Sprintf("Score: %d", g.score)
	ebitenutil.DebugPrintAt(screen, msg, 10, 10)

	// If game over, display message
	if g.gameOver {
		gameOverMsg := "Game Over! Press R to Restart"
		ebitenutil.DebugPrintAt(screen, gameOverMsg, screenWidth/2-100, screenHeight/2)
	}
}

// Layout defines the screen layout
func (g *Game) Layout(outsideWidth, outsideHeight int) (int, int) {
	return screenWidth, screenHeight
}

// handleKeys handles user input
func (g *Game) handleKeys() {
	if g.gameOver {
		if ebiten.IsKeyPressed(ebiten.KeyR) {
			// Restart the game
			*g = *NewGame()
		}
		return
	}

	if ebiten.IsKeyPressed(ebiten.KeyUp) || ebiten.IsKeyPressed(ebiten.KeyW) {
		g.changeDirCh <- Up
	}
	if ebiten.IsKeyPressed(ebiten.KeyDown) || ebiten.IsKeyPressed(ebiten.KeyS) {
		g.changeDirCh <- Down
	}
	if ebiten.IsKeyPressed(ebiten.KeyLeft) || ebiten.IsKeyPressed(ebiten.KeyA) {
		g.changeDirCh <- Left
	}
	if ebiten.IsKeyPressed(ebiten.KeyRight) || ebiten.IsKeyPressed(ebiten.KeyD) {
		g.changeDirCh <- Right
	}
}

// main function
func main() {
	rand.Seed(time.Now().UnixNano())
	game := NewGame()
	ebiten.SetWindowSize(screenWidth, screenHeight)
	ebiten.SetWindowTitle("Snake Game in Go - Press Arrow Keys to Move")
	// Run the game loop in a separate goroutine for key handling
	go func() {
		for {
			game.handleKeys()
			time.Sleep(10 * time.Millisecond)
		}
	}()
	if err := ebiten.RunGame(game); err != nil {
		log.Fatal(err)
	}
}
