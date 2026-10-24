# CyberKnight Security – Login Monitor

**A C-based cybersecurity project that simulates user authentication, monitors login attempts, and detects repeated failed login activity.**

![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Linux-lightgrey)
![Version](https://img.shields.io/badge/Version-1.0-green)
![Project](https://img.shields.io/badge/Project-Educational-orange)

## Overview

CyberKnight Security – Login Monitor is a command-line application developed in C to demonstrate fundamental authentication and security monitoring concepts.

The application allows users to register accounts, authenticate using usernames and passwords, monitor failed login attempts, and generate basic security reports.

This project was developed as a practical application of C programming fundamentals and introductory cybersecurity principles.

## Features

- **User Registration:** Register new users with unique usernames.
- **Authentication:** Verify usernames and passwords.
- **Duplicate Detection:** Prevent registration with an existing username.
- **Login Monitoring:** Track successful and failed login attempts.
- **Account Lockout:** Simulate account locking after three consecutive incorrect password attempts.
- **Security Reports:** Display registered users, login statistics, and account statuses.
- **Command-Line Interface:** Simple menu-driven navigation.

## Technologies Used

- C Programming Language
- GCC Compiler
- Linux Environment
- Git and GitHub

## Project Structure

```text
CyberKnight-Login-Monitor/
│
├── README.md
│
└── main.c
```

## Installation and Execution

### 1. Clone the repository

```bash
git clone https://github.com/brian7nyamasyo-coder/CyberKnight-Login-Monitor.git
```

### 2. Enter the project directory

```bash
cd CyberKnight-Login-Monitor
```

### 3. Compile the program

```bash
gcc -Wall -Wextra -std=c11 main.c -o cyberknight
```

### 4. Run the application

```bash
./cyberknight
```

## Application Menu

```text
====================================
       CYBERKNIGHT SECURITY
          LOGIN MONITOR
====================================

============ MAIN MENU ============

1. Register User
2. Login
3. Security Report
4. About System
5. Exit

===================================
```

## Learning Objectives

This project demonstrates practical use of:

- Variables and data types
- Conditional statements
- Loops
- Functions
- Arrays and multidimensional arrays
- String manipulation using `string.h`
- User input and output
- Basic authentication logic
- Security event counting and reporting

## Security Limitations

This is an educational simulation and is not intended for production authentication systems.

Current limitations include:

- Passwords are stored in plain text in memory.
- User accounts are not persistent after the application closes.
- No password hashing or encryption is implemented.
- Security reports are not saved to permanent audit logs.
- Account lockout is simulated locally.

## Future Improvements

Potential future development includes:

- Secure password hashing.
- Persistent user storage.
- Timestamped security event logging.
- Improved authentication controls.
- More detailed security analytics.
- Modular application architecture.

## Author

**Brian Nyamasyo**

Cybersecurity Enthusiast | C Programmer | Aspiring Security Engineer

GitHub: [@brian7nyamasyo-coder](https://github.com/brian7nyamasyo-coder)

## Disclaimer

This project is intended strictly for educational purposes and demonstrates simulated authentication and security monitoring concepts.
