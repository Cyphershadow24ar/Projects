import random

# word bank for the game 
word_bank = [
    "python", "java", "kotlin", "javascript", "ruby", "swift", "go", "rust",
    "typescript", "scala", "perl", "haskell", "clojure", "elixir", "dart",
    "lua", "groovy", "matlab", "racket", "fsharp"
]
word = random.choice(word_bank)

# finishing the setup
guessedword = ['_'] * len(word)
attempts = 14

# game loop
while attempts > 0:
    print('\nCurrent word: ' + ' '.join(guessedword))
    print(f'Attempts left: {attempts}')
    
    guess = input('Guess a letter: ').lower()
    
    if guess in word:
        for i in range(len(word)):
            if word[i] == guess:
                guessedword[i] = guess
        print('Correct guess!')
    else:
        attempts -= 1
        print('Wrong guess! Attempts left: ' + str(attempts))
    
    # check win condition
    if '_' not in guessedword:
        print('\n🎉 Congratulations! You guessed the word: ' + word)
        break
    
    # check lose condition
    if attempts == 0:
        print('\n❌ You\'ve run out of attempts! The word was: ' + word)

