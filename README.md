# Data Structures and Algorithms

This repository contains basic implementations of common data structures and algorithms in C++.

## Folder Structure

- **basics/**: Simple programs for basic C++ tasks (e.g., separating odd/even numbers, arithmetic).
- **algorithms/**: Sorting algorithm implementations (Bubble Sort, Insertion Sort, Selection Sort).
- **data_structures/**: Core data structure implementations (Queue, Stack) using OOP principles.

## Building and Running

This project uses CMake to compile the standalone programs. To build:

```bash
mkdir build
cd build
cmake ..
make
```

This will generate executables for all the files (e.g., `./queue`, `./bubblesort`).

## Improvements Made

- Encapsulated global state into classes for Queue and Stack.
- Extracted sorting logic into reusable functions with parameterized lengths.
- Fixed logical bugs, off-by-one errors, and uninitialized variables in basics implementations.
- Refactored project structure for modularity and easy builds.
