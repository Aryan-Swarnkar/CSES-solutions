
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    // Count frequency of every character.
    int freq[26] = {0};

    for (char c : s) {
        freq[c - 'A']++;
    }

    // Check if rearrangement is possible.
    int mx = 0;

    for (int i = 0; i < 26; i++) {
        mx = max(mx, freq[i]);
    }

    if (mx > (n + 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }

    string ans = "";
    int prev = -1;

    for (int pos = 0; pos < n; pos++) {

        int remaining = n - pos - 1;

        // Find largest and second-largest frequencies.
        int largest = 0, second = 0, largestCount = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > largest) {
                second = largest;
                largest = freq[i];
                largestCount = 1;
            }
            else if (freq[i] == largest && freq[i] > 0) {
                largestCount++;
            }
            else if (freq[i] > second) {
                second = freq[i];
            }
        }

        // Try characters alphabetically.
        for (int c = 0; c < 26; c++) {

            if (freq[c] == 0 || c == prev)
                continue;

            int newMax = largest;

            if (freq[c] == largest && largestCount == 1) {
                newMax = max(largest - 1, second);
            }

            // Check whether remaining characters can be arranged.
            if (newMax > (remaining + 1) / 2)
                continue;

            // IMPORTANT FIX:
            // The newly selected character cannot appear
            // more than remaining / 2 times.
            if (freq[c] - 1 > remaining / 2)
                continue;

            ans += char('A' + c);
            freq[c]--;
            prev = c;

            break;
        }
    }

    cout << ans << '\n';

    return 0;
}