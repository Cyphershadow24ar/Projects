# Slot Machine Simulation 🎰

This is a Python-based terminal game that simulates a slot machine. Players can deposit money, place bets on multiple lines, and spin the reels to test their luck. The game is interactive, user-friendly, and allows you to manage your balance while enjoying the thrill of gambling (virtually)!

---

## Features
- **Flexible Betting:** Bet on 1 to 3 lines with customizable amounts.
- **Symbolic Rewards:** Different symbols have different probabilities and payout values:
  - `A`: Rare, high payout.
  - `B`, `C`, `D`: Increasingly common with decreasing payouts.
- **Realistic Gameplay:** Randomized spins and dynamic win/loss calculations.
- **Balance Management:** Track deposits, bets, and winnings seamlessly.

---

## How to Play
1. **Deposit Money:** Enter the amount you want to deposit to start playing.
2. **Choose Lines:** Decide how many lines (1–3) you want to bet on.
3. **Place Bets:** Set your bet amount per line, within the minimum and maximum limits.
4. **Spin:** Watch the reels spin and check for winnings!
5. **Repeat or Quit:** Keep playing until you choose to quit or your balance runs out.

---

## Rules
1. **Symbols and Values:**
   - `A`: 2 occurrences, payout multiplier 5x.
   - `B`: 4 occurrences, payout multiplier 4x.
   - `C`: 6 occurrences, payout multiplier 3x.
   - `D`: 8 occurrences, payout multiplier 2x.
2. **Winning Lines:** A line wins if all symbols on it match across all columns.
3. **Bet Limits:** Minimum ₹100 and maximum ₹1,000,000 per line.

---

## Setup
1. Ensure Python is installed on your system.
2. Download the `Solt_machine.py` file from this repository.
3. Run the file in a terminal using the command:
   ```bash
   python Solt_machine.py
