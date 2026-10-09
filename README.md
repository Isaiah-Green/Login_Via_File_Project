# Login Via File Project

A secure and lightweight user authentication and login management system implemented in C++, featuring secure password handling and file-based data persistence.

## Features
*User Registration & Login: Create new accounts and authenticate existing users securely.
- File-Based Persistence: Stores user records efficiently using local file structures.
- Secure Password Handling: Implements cryptographic password hashing (utilizing modern security standards like `bcrypt` or `libsodium`) to ensure plain-text passwords are never stored.
- Modular Design:Clean separation of concerns for input parsing, authentication logic, and file I/O operations.
Tech Stack
- Language: C++
- Security / Cryptography:
- Version Control:** Git & GitHub
Getting Started
Prerequisites
Make sure you have a modern C++ compiler installed (supporting C++17 or later) along with Make or CMake, plus your required cryptographic dependencies (`bcrypt`/`libsodium`).
Building and Running
