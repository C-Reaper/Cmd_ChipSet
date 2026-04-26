# Project README

## Overview
This project is a C-based digital circuit simulator that allows users to design, test, and visualize logic circuits using graphical interfaces. The system supports various basic logical gates like AND, OR, NAND, NOR, XOR, XNOR, along with more complex custom circuits such as a simple OR gate implementation, an XOR-HALF ADDER, and a 7-segment display. It provides functionalities to load, execute, and visualize circuit behavior in real-time.

## Features
- Basic logic gates: AND, OR, NAND, NOR, XOR, XNOR.
- Support for custom circuit creation using logical gates.
- Real-time visualization of circuit outputs based on inputs.
- Integration with a simple 7-segment display simulation.

## Project Structure
```
<Project>/
├── build/              # .exe files produced by Main.c
├── bin/                # .so / .dll produced by *.c in libs
├── libs/               # *.c for bin
├── lib/                # librarys for my own languages
├── code/               # scripts from my custom languages for example .rex, .ll, .omml
├── data/               # Datafile for example .txt or dumped files
├── assets/             # images and sound files
├── src/                # src code
│   ├── Main.c          # Entry point
│   └── *.h             # stand alone Header-based C-files, without *.c files that implement it
├── Makefile.linux      # Linux Build configuration
├── Makefile.windows    # Windows Build configuration
├── Makefile.wine       # Wine Build configuration
└── README.md           # This file
└── LICENCE
└── .gitignore
```

### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools
- Libraries needed in specific projects:
  - For Window Engine: `alx`, `dd7segment`
  - For DD7Segment library: None specified

## Build & Run
### Linux
```bash
cd <Project>
make -f Makefile.linux all
make -f Makefile.linux exe
./build/Main.exe
```

### Windows
```cmd
cd <Project>
make -f Makefile.windows all
make -f Makefile.windows exe
build\Main.exe
```

### Clean Build
To clean the build artifacts and start a fresh build:
- For Linux:
  ```bash
  make -f Makefile.linux clean
  make -f Makefile.linux all
  ```
- For Windows:
  ```cmd
  make -f Makefile.windows clean
  make -f Makefile.windows all
  ```

### Build Options
- `make -f Makefile.(os) all`: Build output files.
- `make -f Makefile.(os) do`: Build and execute the application.
- `make -f Makefile.(os) clean`: Remove build artifacts.