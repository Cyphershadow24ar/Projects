🎮 Word Guessing Game

A simple command-line word guessing game (similar to Hangman) built with Python. The game randomly selects a programming language name from a predefined word bank, and the player must guess the word letter by letter before running out of attempts.

🚀 Features

Random word selection from a word bank of programming languages.

14 attempts to guess the word correctly.

Feedback after each guess:

✅ Correct guess updates the word.

❌ Wrong guess reduces attempts.

Win/Loss conditions with messages.

🛠️ Requirements

Python 3.x
(No external libraries are required.)

▶️ How to Run

Clone this repository or download the file.

Navigate to the project directory.

Run the game using:

python main.py

Start guessing letters!

🎯 Gameplay Example
Current word: \_ \_ \_ \_ \_ \_
Attempts left: 14
Guess a letter: p
Correct guess!

Current word: p \_ \_ \_ \_ \_
Attempts left: 14
Guess a letter: x
Wrong guess! Attempts left: 13
...

🎉 If you guess all letters → You win!

❌ If attempts run out → Game over, word revealed.

📚 Word Bank

The word bank includes popular programming languages:

python, java, kotlin, javascript, ruby, swift, go, rust,
typescript, scala, perl, haskell, clojure, elixir, dart,
lua, groovy, matlab, racket, fsharp

📌 Future Improvements

Add difficulty levels (easy, medium, hard).

Show guessed letters history.

Add ASCII art for wrong guesses (like Hangman).

✨ Have fun testing your programming language knowledge!
