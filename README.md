# 🔐 KeyGuard

**KeyGuard** is a secure file unlocking system written in **C++**, built using **Shamir’s Secret Sharing Algorithm**. It ensures that a protected file can only be accessed when **exactly 5 correct key shares** are provided. If even **one key** is incorrect (e.g., from a corrupt officer), access is denied — keeping your secrets safe.

---

## 🛡️ How It Works

KeyGuard implements a threshold secret sharing mechanism where a secret (used to unlock a file) is divided into multiple key shares. Only when all required keys are submitted correctly, the original secret is reconstructed using **Lagrange Interpolation** over modular arithmetic.

---

## 🚀 Features

- ✅ Implements Shamir's Secret Sharing (threshold = 5)
- ✅ Pure C++ solution (no external libraries)
- ✅ Manual JSON file parsing
- ✅ Large number support using `long long`
- ✅ Modular arithmetic functions in separate logic
- ✅ File remains locked if even **one officer is corrupt**
- ✅ Secure and educational cryptographic demonstration

---

## 📁 File Structure

| File           | Description                                     |
|----------------|-------------------------------------------------|
| `main.cpp`     | Core implementation with all logic              |
| `secret.json`  | Stores threshold and share key pairs            |
| `secret.txt`   | Secret file that gets revealed if keys are valid|

---

## 🧪 Sample `secret.json`

```json
{
  "threshold": 5,
  "shares": [
    {"x": 1, "y": 12345},
    {"x": 2, "y": 23456},
    {"x": 3, "y": 34567},
    {"x": 4, "y": 45678},
    {"x": 5, "y": 56789}
  ]
}

---
## 📂 Sample secret.txt
```
    🔐 Secret File: Launch Code = XTZ-42B-KLM
    
---
## ⚙️ How to Compile & Run

```
    g++ main.cpp -o keyguard
    ./keyguard

---
## 🧑‍💻 Input Format
      You will be prompted to enter 5 key shares as x y pairs. For example:

```
    Enter key 1 (x y): 1 12345
    Enter key 2 (x y): 2 23456
    Enter key 3 (x y): 3 34567
    Enter key 4 (x y): 4 45678
    Enter key 5 (x y): 5 56789

---
## ✅ Sample Output (Correct Keys)
```
✅ Access Granted! Secret is correct.

📂 Secret Content:
🔐 Secret File: Launch Code = XTZ-42B-KLM
