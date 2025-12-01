## 🗳️ Plurality Voting (C)
A C implementation of a plurality voting system, where each voter casts a single vote for one candidate.
The program tallies votes and prints the winner(s). 
If multiple candidates tie with the highest vote count, all winners are displayed.

## 🎯 Features
- Accepts candidate names via command-line arguments
- Validates maximum number of candidates (up to 9)
- Records votes from user input
- Handles invalid votes gracefully
- Supports ties by printing multiple winners

## 🛠️ How to Compile
Use `gcc` or any C compiler:

```bash
gcc plurality.c -o plurality
./plurality Alice Bob Charlie

Number of voters: 5
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Vote: Bob
Bob
Alice
