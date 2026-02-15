# OOP Bank System – Enhanced with User Management & Permissions

A C++ console application for managing bank clients, demonstrating a transition from procedural to object-oriented programming.
This version adds a complete user management system with login, role-based permissions, and secure access control.

---

## 📌 Project Goal

The main goal of this project was to:

- Practice converting procedural code into object-oriented design
- Understand class relationships and responsibility separation
- Apply file handling for data persistence
- Improve code organization and modularity
- Implement a realistic user authentication and permission system

---

## 🚀 Features

### 👤 Client Management

- **List Clients** – Display all clients in a formatted table.
- **Add New Client** – Prevent duplicate account numbers with validation.
- **Delete Client** – Mark a client as deleted (soft delete) and update the file.
- **Update Client Info** – Modify first name, last name, email, phone, PIN, and balance.
- **Find Client** – Search by account number (with optional PIN) and view full details.

---

### 💰 Transactions

- **Deposit** – Add funds to a client’s account.
- **Withdraw** – Deduct funds with balance validation.
- **Total Balance** – Display individual balances and the total sum of all accounts.

---

### 🔐 User Management & Authentication

- **Login System** – Secure authentication with username and password verification.
- **User Management** – Add, delete, update, list, and find system users (requires admin permission).
- **Permission System** – Fine-grained access control using bitwise permissions.
- **Access Control** – Each menu option is enabled only if the logged-in user has the corresponding permission.

---

## 📂 Data Storage

- Clients stored in `Clients.txt`
- Users stored in `Users.txt`

### Client record format:

`FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#Balance`

### User record format:

`FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#Password#//#Permissions`

Deleted records are marked and excluded when saving back to the file.

---

## 🔑 Permission System (Bitwise)

Permissions are managed as a single integer where each bit represents a specific right:

| Bit | Permission         | Value |
| --- | ------------------ | ----- |
| 0   | Show Client List   | 1     |
| 1   | Add New Client     | 2     |
| 2   | Delete Client      | 4     |
| 3   | Update Client Info | 8     |
| 4   | Find Client        | 16    |
| 5   | Transactions       | 32    |
| 6   | Manage Users       | 64    |

A permission value of `-1` grants full access to all features.

---

## 🧠 OOP Concepts Used

### Encapsulation

- All data members are private.
- Access is controlled via getters and setters.
- Business logic (Deposit, Withdraw, Save, Delete) is handled inside the class.
- MSVC extension `__declspec(property)` is used to simulate C#-like properties for cleaner syntax.

### Inheritance

- `clsBankClient` inherits from `clsPerson`.
- All screen classes inherit from `clsScreen`, which provides common header-drawing methods.

### Polymorphism (Function Overloading)

The `Find` method is overloaded:

- Find by account number
- Find by account number + PIN

### Abstraction

High-level operations like `Save()`, `Delete()`, `Deposit()`, and `Withdraw()` hide internal file handling and data conversion logic.

Screens interact with business classes only through public static methods
(e.g., `clsBankClient::Find`, `clsBankClient::GetClientsList`).

---

# 📁 Project Structure (Based on Current Solution)

```
OOP Bank System/
│
├── References
├── External Dependencies
│
├── Header Files/
│ ├── clsAddNewClientScreen.h
│ ├── clsAddnewUserScreen.h
│ ├── clsBankClient.h
│ ├── clsBankUser.h
│ ├── clsClientsListScreen.h
│ ├── clsDate.h
│ ├── clsDeleteClientScreen.h
│ ├── clsDeleteUserScreen.h
│ ├── clsDepositScreen.h
│ ├── clsFindClientScreen.h
│ ├── clsFindUserScreen.h
│ ├── clsInputValidate.h
│ ├── clsListUsersScreen.h
│ ├── clsLoginScreen.h
│ ├── clsMainScreen.h
│ ├── clsManageUsersScreen.h
│ ├── clsPerson.h
│ ├── clsScreen.h
│ ├── clsString.h
│ ├── clsTotalBalancesScreen.h
│ ├── clsTransactionsScreen.h
│ ├── clsUpdateClientScreen.h
│ ├── clsUpdateUserScreen.h
│ ├── clsUtil.h
│ ├── clsWithdrawScreen.h
│ └── Global.h
│
├── Resource Files/
│
└── Source Files/
└── OOP Bank System.cpp

```

---

## ▶️ How to Run

### Requirements

- Windows OS (due to `__declspec(property)` and `system("pause>0")`)
- Visual Studio 2019 or later (MSVC compiler)

### Steps

1. Clone the repository or download all source files.
2. Open the solution in Visual Studio
   (or create a new Console App project and add all `.h` files and `OOP Bank System.cpp`).
3. Build the solution (`Ctrl + Shift + B`).
4. Run the executable.

The program will automatically create `Clients.txt` and `Users.txt` in the same directory if they don’t exist.

---

## 🔐 Default Admin User

If no users exist, you can manually create an admin in `Users.txt`:

`Mohammed#//#Abu-Hadhoud#//#Msa@Gmail.com#//#838838#//#User5#//#5555#//#-1`

---

> Note: The project is under active development; manual testing has been performed, but no formal u
