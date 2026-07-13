# Morse Code Console Interpreter

![C++](https://img.shields.io/badge/C++-17-00599C?logo=cplusplus)
![Platform](https://img.shields.io/badge/Platform-Console-lightgrey)
![Build](https://img.shields.io/badge/Build-g++-blue)
![License](https://img.shields.io/badge/License-MIT-green)

A modular C++ console application that decodes Morse code input into readable text.

The project demonstrates fundamental software engineering concepts including:

- modular architecture
- input processing
- state management
- lookup-based decoding
- separation of responsibilities

---

# Overview

Morse Code Console Interpreter converts dot and dash sequences into text through a simple decoding pipeline.

The system flow:

```text
User Input

     ↓

Input Handler

     ↓

Morse Decoder

     ↓

Output Display
```

The application processes Morse symbols in real time and builds decoded messages interactively.

---

# Features

## Morse Input Processing

Supports:

- Dot (`.`) input
- Dash (`-`) input
- Letter separation
- Word separation

Controls:

| Input | Action |
|---|---|
| `.` | Add dot symbol |
| `-` | Add dash symbol |
| ` ` | Decode current letter |
| `/` | Insert word separator |
| `q` | Exit application |

---

## Decoder System

The decoder converts Morse sequences into characters using a lookup table.

Supported:

- Alphabet characters (A-Z)
- Unknown sequence handling

Example:

```text
Input:

....

Output:

H
```

---

## Modular Architecture

The application follows a simple pipeline architecture:

```text
InputHandler

      ↓

MorseDecoder

      ↓

OutputDisplay
```

Each component has a dedicated responsibility.

---

# Architecture

## InputHandler

Responsible for:

- reading console input
- detecting Morse symbols
- identifying letter boundaries
- identifying word boundaries

Produces structured input events for the decoder.

---

## MorseDecoder

Responsible for:

- Morse lookup
- symbol translation
- character generation

Example:

```text
.-

↓

A
```

Unknown patterns return:

```text
?
```

---

## OutputDisplay

Responsible for:

- displaying decoded characters
- maintaining current output text
- showing decoding progress

---

# Project Structure

```text
morse-code-interpreter/

├── src/
│
│   ├── main.cpp
│   ├── input-handler.cpp
│   ├── morse-decoder.cpp
│   └── output-display.cpp
│
├── include/
│
│   ├── input-handler.h
│   ├── morse-decoder.h
│   └── output-display.h
│
└── README.md
```

---

# Data Flow

```text
Console Input

".-"

 ↓

InputHandler

 ↓

Morse Sequence

".-"

 ↓

MorseDecoder

 ↓

Character

"A"

 ↓

OutputDisplay

 ↓

Decoded Message
```

---

# Example Usage

Input:

```text
.- 
.
```

Output:

```text
Letter: A
Letter: E

Text: AE
```

---

# Build Instructions

## Compile

Using g++:

```bash
g++ -std=c++17 \
main.cpp \
input-handler.cpp \
morse-decoder.cpp \
output-display.cpp \
-o morse
```

---

## Run

```bash
./morse
```

---

# Engineering Concepts Demonstrated

This project demonstrates:

- object-oriented C++ design
- modular component architecture
- state-based processing
- event-driven input handling
- lookup table algorithms
- separation of concerns

---

# Design Decisions

## Component Separation

The application separates:

```text
Input

↓

Processing

↓

Output
```

This makes each component easier to:

- test
- modify
- extend

---

## Lookup-Based Decoding

Morse patterns are mapped using a lookup structure rather than complex conditional logic.

Benefits:

- simple implementation
- fast character lookup
- easy extension

---

# Limitations

Current limitations:

- console-only interface
- manual letter separation
- no timing-based Morse detection
- limited character support
- blocking input loop

---

# Future Improvements

## Input System

- real-time keyboard capture
- timing-based Morse recognition
- Morse key support

## Decoder

- numbers support
- punctuation support
- configurable Morse mappings
- finite state machine decoder

## Application

- graphical interface
- audio Morse input
- unit testing framework
- cross-platform packaging

---

# What This Project Demonstrates

This project demonstrates foundational engineering skills:

- writing maintainable C++ code
- designing small modular systems
- handling user input states
- building reusable processing pipelines

---

# License

MIT License
