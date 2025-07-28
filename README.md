🔐 KeyGuard
KeyGuard is a secure file unlocking system implemented in C++, using Shamir’s Secret Sharing Algorithm. It requires exactly 5 valid keys to unlock a protected file. If any officer (or participant) provides an invalid or corrupt key, the file remains locked — ensuring high security and trust.

🚀 Features
✅ Implements Shamir’s Secret Sharing

✅ Unlock secret files with 5 valid key shares

✅ Access Denied if even one key is wrong

✅ Pure C++ (no external libraries)

✅ Manual JSON parsing

✅ Modular arithmetic (add, sub, mul, div, inverse) via separate functions

✅ Designed to handle large integer values (long long used)

📁 Files
File

Description

main.cpp

Core C++ implementation

secret.json

Stores the threshold and all share keys

secret.txt

The protected file revealed upon successful unlock

🧪 Sample JSON (secret.json)
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

🖥️ How to Compile & Run
To compile the KeyGuard system, navigate to the project directory in your terminal and use a C++ compiler (like g++):

g++ main.cpp -o keyguard

After successful compilation, run the executable:

./keyguard

📥 Input Format
At runtime, you'll be prompted to enter 5 (x, y) key pairs. Each pair should be entered on a new line, separated by a space:

Enter key 1 (x y): 1 12345
Enter key 2 (x y): 2 23456
Enter key 3 (x y): 3 34567
Enter key 4 (x y): 4 45678
Enter key 5 (x y): 5 56789

✅ Output (if keys are valid)
If all 5 provided keys are correct and valid, you will see the following output, revealing the secret content from secret.txt:

✅ Access Granted! Secret is correct.
 
📂 Secret Content:
🔐 Secret File: Launch Code = XTZ-42B-KLM

❌ Output (if any key is invalid)
If even one of the provided keys is incorrect or corrupt, access will be denied:

❌ Access Denied! Incorrect or corrupt officer keys.
