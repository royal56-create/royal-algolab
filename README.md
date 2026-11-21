# Royal AlgoLab

**Royal AlgoLab** is a local, offline, menu-driven algorithms and data structures laboratory built with standard C++17.

## Privacy and connectivity
This project runs locally. It does **not** use external APIs, API keys, access tokens, credentials, online services, or network requests.

## Features
- Sorting: Bubble, Selection, Insertion, Merge and an in-house Quick Sort
- Searching: Linear and Binary Search (binary search validates sorted input)
- Data structures: Linked Queue and Binary Search Tree demonstrations
- Graphs: Breadth-First Search, Depth-First Search and Dijkstra shortest paths
- Built-in complexity guide
- CMake build and automated CTest checks

## Requirements
- C++17 compiler (GCC, Clang or MSVC)
- CMake 3.16 or newer

## Build
```bash
git clone https://github.com/royal56-create/royal-algolab.git
cd royal-algolab
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build --output-on-failure
```

Run `./build/royal_algolab`. On Windows with a multi-configuration generator, run `build/Release/royal_algolab.exe`.

## Repository layout
- `include/royal/algorithms.hpp` — sorting and searching
- `include/royal/structures.hpp` — queue and binary search tree
- `include/royal/graph.hpp` — graph traversals and shortest paths
- `src/main.cpp` — interactive terminal application
- `tests/test_algolab.cpp` — automated tests
- `docs/ALGORITHMS.md` — time and space complexity reference
- `.github/workflows/ci.yml` — GitHub Actions build and test workflow

## Contributing
See [CONTRIBUTING.md](CONTRIBUTING.md).

## License
MIT. See [LICENSE](LICENSE).

## Educational use, safety and responsibility

This repository is provided for educational, demonstration, and informational purposes. Review code and commands before use. Use it only with files, devices, repositories, and networks you own or are explicitly authorized to access. You are responsible for keeping backups, protecting personal information, and following applicable laws and policies. Use is at your own risk. The project is provided “as is” without warranties, to the maximum extent permitted by applicable law. Nothing in this notice excludes liability, rights, or obligations that cannot legally be excluded. This notice does not grant permission to access or test third-party systems.
