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
