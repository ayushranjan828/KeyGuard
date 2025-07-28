#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
using ll = long long;

// A large prime number for modulo operations
const ll PRIME = 1000003; 

struct Share {
    ll x, y;
};

// ------------------ Modular Arithmetic ------------------

ll modAdd(ll a, ll b) {
    return (a + b) % PRIME;
}

ll modSub(ll a, ll b) {
    return (a - b + PRIME) % PRIME;
}

ll modMul(ll a, ll b) {
    return (a * b) % PRIME;
}

ll modInverse(ll a) {
    ll m = PRIME, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    return (x1 + PRIME) % PRIME;
}

ll modDiv(ll a, ll b) {
    return modMul(a, modInverse(b));
}

// ------------------ Manual JSON Parsing ------------------

vector<Share> parseJSON(const string& filename, int& threshold) {
    ifstream file(filename);
    vector<Share> shares;
    string line;

    while (getline(file, line)) {
        if (line.find("threshold") != string::npos) {
            threshold = stoi(line.substr(line.find(":") + 1));
        } else if (line.find("{\"x\"") != string::npos) {
            ll x = 0, y = 0;
            size_t xStart = line.find("x") + 3;
            size_t xEnd = line.find(",", xStart);
            x = stoll(line.substr(xStart, xEnd - xStart));

            size_t yStart = line.find("y") + 3;
            size_t yEnd = line.find("}", yStart);
            y = stoll(line.substr(yStart, yEnd - yStart));

            shares.push_back({x, y});
        }
    }

    return shares;
}

// ------------------ Lagrange Interpolation ------------------

ll reconstructSecret(const vector<Share>& inputs) {
    ll secret = 0;

    for (size_t i = 0; i < inputs.size(); i++) {
        ll xi = inputs[i].x;
        ll yi = inputs[i].y;
        ll li = 1;

        for (size_t j = 0; j < inputs.size(); j++) {
            if (i == j) continue;
            ll xj = inputs[j].x;

            li = modMul(li, modDiv(modSub(0, xj), modSub(xi, xj)));
        }

        secret = modAdd(secret, modMul(yi, li));
    }

    return secret;
}

// ------------------ Main Function ------------------

int main() {
    int threshold;
    vector<Share> originalShares = parseJSON("secret.json", threshold);

    cout << "\n Secure Unlock System using Shamir's Secret Sharing\n";
    cout << "You must enter exactly " << threshold << " correct shares.\n\n";

    vector<Share> inputShares;
    for (int i = 0; i < threshold; ++i) {
        ll x, y;
        cout << "Enter key " << i + 1 << " (x y): ";
        cin >> x >> y;
        inputShares.push_back({x, y});
    }

    // Reconstruct from input
    ll reconstructedSecret = reconstructSecret(inputShares);

    // Validate against original shares (ground truth)
    ll trueSecret = reconstructSecret(vector<Share>(originalShares.begin(), originalShares.begin() + threshold));

    if (reconstructedSecret == trueSecret) {
        cout << "\n Access Granted! Secret is correct.\n";
        ifstream secretFile("secret.txt");
        string content((istreambuf_iterator<char>(secretFile)), istreambuf_iterator<char>());
        cout << "\n Secret Content:\n" << content << endl;
    } else {
        cout << "\n Access Denied! Incorrect or corrupt officer keys.\n";
    }

    return 0;
}
