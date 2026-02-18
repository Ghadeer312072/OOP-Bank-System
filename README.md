# OOP Bank System – Enhanced with User Management, Permissions, Login, Transfers & Encryption

A C++ console application for managing bank clients, demonstrating a full transition from **procedural programming** to a structured **object-oriented design**.

This version includes:

- Complete **user management system**
- Secure **login & authentication**
- **Role-based permissions** (bitwise)
- Login activity register
- Inter-account transfers with logging
- Password encryption
- Full audit trail for financial operations

---

## 📌 Project Goal

The main goals of this project:

- Practice converting procedural code into object-oriented design
- Understand class relationships and separation of responsibilities
- Apply file handling for data persistence
- Improve code organization and modularity
- Implement a realistic user authentication & permission system
- Track and audit user login activity
- Add secure money transfers with a full audit trail
- Protect sensitive user data using password encryption

---

## 🚀 Features

### 👤 Client Management

- **List Clients** – Display all clients in a formatted table
- **Add New Client** – Prevent duplicate account numbers with validation
- **Delete Client** – Soft delete (mark as deleted and update file)
- **Update Client Info** – Modify:
  - First Name
  - Last Name
  - Email
  - Phone
  - PIN
  - Balance
- **Find Client** – Search by account number (optional PIN verification)

---

### 💰 Transactions

- **Deposit** – Add funds to client account
- **Withdraw** – Deduct funds with balance validation
- **Total Balance** – Display individual balances and total sum
- **Transfer** – Transfer money between accounts:
  1. Enter sender account number → display sender card
  2. Enter recipient account number → display recipient card
  3. Enter amount (≤ sender balance)
  4. Confirm operation
  5. Execute transfer
  6. Log operation in dedicated file

- **Transfer Log** – View formatted table of all transfers including:
  - Date/Time
  - Sender & Recipient accounts
  - Amount
  - Balances after transfer
  - User who performed the operation

---

## 🔐 User Management & Authentication

- **Login System** – Username & password verification
- **User Management** – Add, update, delete, list, and find users (Admin only)
- **Permission System** – Fine-grained access control using bitwise flags
- **Access Control** – Menu options enabled based on user permissions
- **Login Register Logging** – Every successful login is logged
- **Login Register Screen** – View full login history (requires permission)

---

## 🔒 Password Encryption

- Passwords are stored **encrypted** in `Users.txt`
- Simple reversible encryption algorithm
- Automatically decrypted when loaded
- Prevents plain-text password exposure in files

---

## 📝 Login Register System

Each successful login is stored in:

### 📄 Login record format:

`Date - Time#//#UserName#//#Password#//#Permissions`

### Example:

`16/2/2026 - 12:19:17#//#User6#//#1234#//#-1`

This allows:

- Tracking system access
- Auditing user activity
- Monitoring administrative usage
- Improving system security

## 📋 Transfer Log System

TransferLog.txt

### 📄 Transfer Record Format

`Date - Time#//#SenderAccount#//#RecipientAccount#//#Amount#//#SenderBalanceAfter#//#RecipientBalanceAfter#//#UserName`

### Example:

`17/2/2026 - 16:33:17#//#A114#//#A113#//#500.000000#//#3517.000000#//#3800.000000#//#User5`
Provides a complete audit trail for all monetary movements.

---

## 📂 Data Storage

| File                | Purpose                               |
| ------------------- | ------------------------------------- |
| `Clients.txt`       | Store client data                     |
| `Users.txt`         | Store user data (encrypted passwords) |
| `LoginRegister.txt` | Login history                         |
| `TransferLog.txt`   | Transfer history                      |

### 🧾 Client Record Format

`FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#Balance`

### User record format:

`FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#Password#//#Permissions`

> Password is encrypted before saving.
> Deleted records are marked and excluded when saving back to the file.

---

## 🔑 Permission System (Bitwise)

Permissions are managed as a single integer where each bit represents a specific right:

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

## A permission value of `-1` grants full access to all features.

## 🧠 OOP Concepts Used

### Encapsulation

- All data members are private.
- Access is controlled via getters and setters.
- Business logic (Deposit, Withdraw, Save, Delete,Transfer) is handled inside the class.

### Inheritance

- `clsBankClient` inherits from `clsPerson`.
- `clsBankUser` inherits from `clsPerson`.
- All screen classes inherit from `clsScreen`, which provides common header-drawing methods.

### Polymorphism (Function Overloading)

The `Find` method is overloaded:

- Find by account number
- Find by account number + PIN

### Abstraction

High-level operations hide:

- File handling
- Data parsing
- Encryption logic
  Screens interact only through public static methods like:

```cpp
clsBankClient::Find();
clsBankClient::GetClientsList();`
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
│ ├── clsLoginRegisterScreen.h
│ ├── clsLoginScreen.h
│ ├── clsMainScreen.h
│ ├── clsManageUsersScreen.h
│ ├── clsPerson.h
│ ├── clsScreen.h
│ ├── clsString.h
│ ├── clsTotalBalancesScreen.h
│ ├── clsTransactionsScreen.h
│ ├── clsTransferScreen.h
│ ├── clsTransferLogScreen.h
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
- Visual Studio 2019

### Steps

1. Clone the repository or download all source files.
2. Open the solution in Visual Studio
   (or create a new Console App project and add all `.h` files and `OOP Bank System.cpp`).
3. Build the solution (`Ctrl + Shift + B`).
4. Run the executable.

The program automatically creates:

Clients.txt

Users.txt

LoginRegister.txt

TransferLog.txt

(if they don’t already exist)

---

## 🔐 Default Admin User

If no users exist, you can manually create an admin in `Users.txt`:

`Mohammed#//#Abu-Hadhoud#//#Msa@Gmail.com#//#838838#//#User6//#1234#//#-1`

---

```
