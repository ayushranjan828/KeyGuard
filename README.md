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
```
