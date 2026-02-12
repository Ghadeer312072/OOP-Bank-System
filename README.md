# OOP Bank System (C++ Practice Project)

A C++ console application for managing bank clients, demonstrating a transition from procedural to object-oriented programming. The system implements core banking operations with file-based storage and showcases the four pillars of OOP: Encapsulation, Inheritance, Polymorphism, and Abstraction.

## Overview

This project was initially built using a functional/procedural approach. Later, it was completely refactored into an object-oriented design to improve modularity, reusability, and maintainability. The system stores all client data in a text file (Clients.txt) and provides a menu-driven interface for performing banking operations.

## 📌 Project Goal

The main goal of this project was to:

- Practice converting procedural code into object-oriented design
- Understand class relationships and responsibility separation
- Apply file handling for data persistence
- Improve code organization and modularity

### 🚀 Features

### **👤 Client Management**

- **List Clients** – Display all clients in a formatted table.

- **Add New Client** – Prevent duplicate account numbers with validation.

- **Delete Client** – Mark a client as deleted (soft delete) and update the file.

- **Update Client Info** – Modify first name, last name, email, phone, PIN, and balance.

- **Find Client** – Search by account number (with optional PIN) and view full details.

### Transactions

- **Deposit**: Add funds to a client's account.
- **Withdraw**: Deduct funds from a client's account with balance validation.
- **Total Balance**: Display the balance of all clients and calculate the total across the system.

---

## 🧠 OOP Concepts Used

### Encapsulation

- All data members are private.
- Access is controlled using getters and setters.
- Business logic (Deposit, Withdraw, Save) is handled inside the class.

### Inheritance

- `clsBankClient` inherits from `clsPerson`
- Shared attributes like name, email, and phone are defined in the base class.

### Polymorphism (Function Overloading)

- The `Find` method is overloaded:
  - Find by account number
  - Find by account number + PIN

### Abstraction

- High-level operations like `Save()`, `Delete()`, `Deposit()`, and `Withdraw()` hide internal file handling and data conversion logic.

---

## 💾 Data Storage

Client data is stored in a text file:

`Clients.txt`

Format:

`FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#Balance`

The system reads from and writes to this file to maintain persistence.

---

### Requirements

- C++ compiler (Visual Studio)

### Project Structure

```
📁 OOP-Bank-System/
│
├── OOP Bank System.cpp          # Entry point (main function)
│
├── Header Files/
│   ├── clsPerson.h              # Base class that stores common person data
│   ├── clsBankClient.h          # Bank client entity (inherits from clsPerson)
│   ├── clsScreen.h              # Base class for shared screen formatting
│   ├── clsMainScreen.h          # Controls the main menu and navigation
│   ├── clsClientsListScreen.h   # Displays all clients
│   ├── clsAddNewClientScreen.h  # Handles adding a new client
│   ├── clsDeleteClientScreen.h  # Handles client deletion
│   ├── clsUpdateClientScreen.h  # Handles updating client information
│   ├── clsFindClientScreen.h    # Handles client search functionality
│   ├── clsTransactionsScreen.h  # Transactions menu controller
│   ├── clsDepositScreen.h       # Deposit operation screen
│   ├── clsWithdrawScreen.h      # Withdraw operation screen
│   ├── clsTotalBalancesScreen.h # Displays total balances
│   ├── clsManageUsersScreen.h   # (Basic structure for user management)
│   ├── clsInputValidate.h       # Input validation helper functions
│   ├── clsString.h              # String utility functions (e.g., split)
│   ├── clsDate.h                # (Planned) Date handling utilities
│   └── clsUtil.h                # (Planned) General helper utilities
│
└── Clients.txt                  # Text file used for data storage (auto-generated)
```

### Structure Explanation

- **Entity Classes** (`clsPerson`, `clsBankClient`)
  Responsible for representing and managing business data.

- **Screen Classes**
  Each feature has its own screen class to separate UI logic from business logic.

- **Utility Classes**
  Provide helper functions such as input validation and string manipulation.

- **Clients.txt**
  Acts as a simple file-based database for storing client records.

This structure improves readability, maintainability, and separation of concerns.

```

```
