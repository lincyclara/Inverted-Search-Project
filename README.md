# 🔍 Inverted Search Project

> “Efficiently search and index words from text using data structures.”

---

## 🚀 Project Overview
The **Inverted Search** project is a **C-based application** that allows users to quickly **search for words and their occurrences** in a set of documents or text files.  

It implements an **Inverted Index** using **Data Structures (DSA)** like arrays, linked lists, or hash tables to store word positions, enabling **fast and efficient search operations**.  

This project is modular, separating core logic, utilities, and main program files, making the code **maintainable, extendable, and reusable**.

---

## ✨ Features
- Build an **Inverted Index** for text files.  
- **Search for words** and display all occurrences with line numbers or positions.  
- **Efficient data structure usage** for fast lookup.  
- Modular code: separates main logic, indexing, and utility functions.  
- Works with **multiple text files** for scalable search.

---

## 📂 Project Structure

| File | Description |
|------|-------------|
| `main.c`        | Entry point and menu-driven interface |
| `create.c`      | Functions to build the inverted index |
| `operation.c`   | Functions to perform search and query operations |
| `update.c`      | Functions to update or modify indexed data |
| `head.h`        | Header file with all function declarations and data structures |
| `f1.txt, f2.txt, f3.txt` | Sample text files for testing |
| `backup.txt`    | Optional backup data for the index |
| `README.md`     | Project documentation and instructions |

---

## 💻 How to Compile & Run
```bash
# Compile all source files
gcc main.c create.c operation.c update.c -o inverted_search

# Run the program
./inverted_search
