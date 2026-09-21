#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        long long k;
        cin >> k;

        long long digits = 1;
        long long start = 1;

        while (true) {
            // How many numbers have this many digits?
            long long count = 9 * start;

            // How many digits does this whole group contain?
            __int128 total = (__int128)count * digits;

            if ((__int128)k > total) {
                // Skip this entire group
                k -= (long long)total;

                digits++;
                start *= 10;
            } else {
                // Find the number containing position k
                long long number = start + (k - 1) / digits;

                // Find the digit inside that number
                int index = (k - 1) % digits;

                string s = to_string(number);

                cout << s[index] << '\n';

                break;
            }
        }
    }

    return 0;
}