#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    string inp;
    cin >> inp;

    unordered_map<char, int> mp;
    for (char c : inp) {
        mp[c]++;
    }

    int odd_c = 0;
    char middle = '\0';

    // Fixed variable name from 'pair' to 'p'
    for (const auto& p : mp) {
        if (p.second % 2 != 0) {
            odd_c++;
            middle = p.first;
        }
    }

    if (odd_c > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string left = "";

    for (const auto& pair : mp) {
        left += string(pair.second / 2, pair.first);
    }

    string result = left;

    if (odd_c == 1) {
        result += middle;
    }

    // Fixed loop decrement condition (i-- instead of i++)
    for (int i = left.size() - 1; i >= 0; i--) {
        result += left[i];
    }

    cout << result << endl;

    return 0;
}