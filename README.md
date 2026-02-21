# OOP Bank System – Enhanced with User Management, Permissions, Login, Transfers & Encryption, with Currency Exchange

## 📌 Overview

**OOP Bank System** is a fully featured C++ console-based banking application built using Object-Oriented Programming principles.

The system evolved from procedural programming into a structured OOP architecture and now includes:

- 👤 Client Management
- 🔐 Secure Login & Authentication
- 🛡 Role-Based Access Control (Bitwise Permissions)
- 💰 Deposit & Withdraw Operations
- 🔁 Secure Inter-Account Transfers with Audit Trail
- 📝 Login Activity Register
- 🔒 Password Encryption
- 💱 Integrated Currency Exchange Module
- 📂 Persistent File-Based Storage

---

# 🎯 Project Objectives

- Apply Object-Oriented Design Principles
- Implement Encapsulation, Inheritance & Abstraction
- Design a secure authentication system
- Implement fine-grained permission control
- Track and audit financial operations
- Build a modular, scalable console architecture
- Integrate real-world currency exchange functionality

---

# 🏗 System Architecture

The project follows a layered structure:

- **Core Classes** → Business Logic (Clients, Users, Currency)
- **Screen Layer** → UI Navigation & Interaction
- **Utility Layer** → Validation, Date, String, Encryption
- **File Layer** → Data Persistence

---

# 👤 Client Management

✔ List Clients
✔ Add New Client (duplicate prevention)
✔ Delete Client (Soft Delete)
✔ Update Client Information
✔ Find Client (with optional PIN verification)

### 📄 Client Record Format

`FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#Balance`

---

📁 Stored in: `Clients.txt`

---

# 💰 Transactions Module

✔ Deposit
✔ Withdraw (Balance validation)
✔ Total Balances Summary
✔ Inter-Account Transfers
✔ Transfer Logging

### 📋 Transfer Log Format

`Date - Time#//#SenderAccount#//#RecipientAccount#//#Amount#//#SenderBalanceAfter#//#RecipientBalanceAfter#//#UserName`

📁 Stored in: `TransferLog.txt`

Provides a complete audit trail for all monetary operations.

---

# 🔐 User Management & Authentication

✔ Secure Login System
✔ Add / Update / Delete / Find Users
✔ Bitwise Permission Control
✔ Login History Tracking
✔ Encrypted Password Storage

### 📄 User Record Format

`FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#Password#//#Permissions`

📁 Stored in: `Users.txt`
🔒 Passwords are encrypted before saving.

---

# 📝 Login Register System

Every successful login is recorded in:

📁 `LoginRegister.txt`

### Format

`Date - Time#//#UserName#//#Password#//#Permissions`

✔ Tracks system access
✔ Monitors administrative activity
✔ Improves auditing & security

---

# 💱 Currency Exchange Module (NEW)

Integrated directly into the Main Menu.

## 🌍 Features

### 📋 List Currencies

Displays:

- Country
- ISO Code
- Currency Name
- Exchange Rate (Relative to 1 USD)

---

### 🔎 Find Currency

Search by:

- Currency Code (USD, EUR, GBP)
- Country Name (Case-insensitive)

---

### ✏️ Update Exchange Rate

- Enter Currency Code
- View Current Data
- Confirm Update
- Enter New Rate
- Automatically Saved

---

### 🧮 Currency Calculator

Conversion Logic:
Source Currency → USD → Target Currency

Example:

- 1 USD = 1.18 EUR
- 1 EUR = 1 / 1.18 USD

📁 Currency Data Stored in: `Currencies.txt`

### 📄 Currency File Format

## `Country#//#Code#//#Name#//#Rate`

# 🔑 Permission System (Bitwise)

| Bit | Permission          | Value |
| --- | ------------------- | ----- |
| 0   | Show Client List    | 1     |
| 1   | Add New Client      | 2     |
| 2   | Delete Client       | 4     |
| 3   | Update Client Info  | 8     |
| 4   | Find Client         | 16    |
| 5   | Transactions        | 32    |
| 6   | Manage Users        | 64    |
| 7   | Show Login Register | 128   |
| 8   | Currency Exchange   | 256   |

## Permission = -1 → Full System Access

# 🧠 OOP Concepts Applied

## 🔒 Encapsulation

- Private members
- Controlled access via getters/setters
- Business logic inside domain classes

## 🧬 Inheritance

- `clsBankClient` → `clsPerson`
- `clsBankUser` → `clsPerson`
- All screens inherit from `clsScreen`

## 🔁 Polymorphism

- Overloaded `Find()` methods

## 🎯 Abstraction

High-level screens interact with public static methods only:

```cpp
clsBankClient::Find();
clsBankClient::Transfer();
clsCurrency::FindByCode();
```

# 📁 Files Structure

| File              | Purpose                     |
| ----------------- | --------------------------- |
| Clients.txt       | Client records              |
| Users.txt         | Users (Encrypted passwords) |
| LoginRegister.txt | Login activity              |
| TransferLog.txt   | Transfer history            |
| Currencies.txt    | Exchange rates              |

# 🖥 Main Menu

```
[1] Show Clients List
[2] Add New Client
[3] Delete Client
[4] Update Client Info
[5] Find Client
[6] Transactions
[7] Manage Users
[8] Login Register
[9] Currency Exchange
[10] Logout
```

# ⚙ Requirements

- Windows OS
- Visual Studio 2019
- C++17

# 🔐 Default Admin (Manual Creation if Needed)

Mohammed#//#Abu-Hadhoud#//#Msa@Gmail.com#//#838838#//#User6#//#1234#//#-1

# 🚀 Final Result

A complete banking management system featuring:

- Secure authentication
- Role-based permissions
- Financial auditing
- Transfer tracking
- Currency management
- Currency conversion
- Encrypted user data
- Structured OOP architecture
- Modular scalable design

# OOP Bank System

```
OOP Bank System
├── References
├── External Dependencies
├── Header Files
│   ├── core
│   ├── lib
│   ├── screens
│   │   ├── client screens
│   │   ├── currency screens
│   │   ├── transaction screen
│   │   └── user screen
│   ├── clsMainScreen.h
│   ├── clsScreen.h
│   └── Global.h
├── Resource Files
└── Source Files
    └── OOP Bank System.cpp
```
