# 🎮 Tic Tac Toe (C++ Console Game)

A sarcastic, dramatic, two-player Tic Tac Toe game in a single C++ file.  
Fully runs in the terminal using standard input/output.

# 💡 Features

- 2- Player Console Gameplay  
- Smart Input Validation:  
Catches invalid or out-of-bounds moves and prevents overwriting filled spaces.  

- Live Grid Display:  
Updated and redrawn after every move with easy to read Basic ASCII formatting. 

- Score Tracking And Rounds:  
Can be played upto 5 rounds  
Tracks and display score after each round followed by an option for rematch with a final scoreboard at the end.  

- Entertaining In-Game Commentary:  
Invalid moves? Mocked.  
Losing? Mocked harder.  
Tied? Everyone loses.  
(Had a litle too much time on my hands)  
Adds humor and flavor beyond your average Tic Tac Toe clone.

# 🧾 File Structure

.  
├── tictactoe.cpp     # 🔹 All-in-one game logic  
├── README.md         # 📘 You're reading it  
└── .gitignore        # 🧼 Keeps repo clean  


## 🛠 Requirements
- A C++17-compatible compiler (e.g. `g++`)
- Terminal or Command Prompt

## 🚀 How to Compile & Run (Windows)

```bash
g++ -std=c++17 -Wall tictactoe.cpp -o tictactoe.exe
.\tictactoe.exe

## Enjoy the Madness