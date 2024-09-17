'''
1 for snake
-1 for water
0 for gun
'''

import random 
computer = random.choice([-1, 0 ,1])
youstr = input("Enter your choice (s for snake, w for water, g for gun): ")
youDict = {"s": 1, "w": -1, "g": 0}
reverseDict = {1: "Snake", -1: "Water", 0: "Gun"}

you = youDict[youstr]

print(f"You chose {reverseDict[you]} & Computer chose {reverseDict[computer]}.")

if computer == you:
    print("It's a draw.")
else:
    if computer == -1 and you == 1:
        print("You Win!")
    elif computer == -1 and you == 0:
        print("You lose!")
    elif computer == 1 and you == -1:
        print("You lose!")
    elif computer == 1 and you == 0:
        print("You Win!")
    elif computer == 0 and you == -1:
        print("You Win!")
    elif computer == 0 and you == 1:
        print("You lose!")
    else:
        print("Something went wrong.")
