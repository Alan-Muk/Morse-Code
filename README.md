# Morse Code Console Interpreter

![C++](https://img.shields.io/badge/C++-17-00599C?logo=cplusplus)
![Platform](https://img.shields.io/badge/Platform-Console-lightgrey)
![Build](https://img.shields.io/badge/Build-g++-blue)
![License](https://img.shields.io/badge/License-MIT-green)

A simple C++ console-based Morse code interpreter that converts dot/dash input into readable text in real time.

The project is structured as a small pipeline:

InputHandler → MorseDecoder → OutputDisplay

---

## Features

- Real-time Morse input via console
- Dot (`.`) and dash (`-`) symbol entry
- Letter separation using space (` `)
- Word separation using slash (`/`)
- Live decoded output display
- Simple modular architecture

---

## Controls

| Input | Meaning        |
|------|----------------|
| `.`  | Dot            |
| `-`  | Dash           |
| ` `  | End of letter  |
| `/`  | End of word    |
| `q`  | Quit program   |

---

## Project Structure

/src
  main.cpp
  input-handler.cpp
  morse-decoder.cpp
  output-display.cpp

/include
  input-handler.h
  morse-decoder.h
  output-display.h

---

## Components

### InputHandler
Reads user input from the console and converts it into Morse events:
- symbols (`.` or `-`)
- letter endings
- word endings

---

### MorseDecoder
Converts Morse sequences into characters using a lookup table.

Supports:
- A–Z decoding
- Unknown sequences return `?`

---

### OutputDisplay
Handles console output and maintains:
- decoded text
- current Morse sequence being built

Displays:
- incoming symbols
- decoded letters
- word separators

---

## Build Instructions

### Using g++

g++ -std=c++17 main.cpp input-handler.cpp morse-decoder.cpp output-display.cpp -o morse

---

### Run

./morse

---

## Example Usage

Input:
.-
.

Output:
Letter: A | Text: A  
Letter: E | Text: AE  

---

## Design Notes

This project is intentionally simple and educational. It demonstrates:

- Modular C++ design
- Basic event-driven input flow
- State-based decoding logic
- Separation of concerns across components

---

## Limitations

- Console-based input only (requires Enter key)
- No timing-based Morse detection (manual separation only)
- No punctuation or number support
- Blocking input loop
- Minimal error handling

---

## Future Improvements

- Timing-based Morse input (real keypress duration decoding)
- Non-blocking input (real-time capture)
- Full Morse table (numbers + punctuation)
- GUI version
- FSM-based decoder instead of string matching
- Unit tests for decoder logic

---

## License

This project is open for learning and experimentation.
