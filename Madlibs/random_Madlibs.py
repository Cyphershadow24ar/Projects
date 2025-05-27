from Sample_madlibs import hp, code, zombie, hungergames
import random

if __name__ == "__main__":
    choices = [hp.hp_madlib, code.code_madlib, zombie.zombie_madlib, hungergames.hungergames_madlib]
    m = random.choice(choices)
    m()
