#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        // Impossible:
        // 1. Total wins cannot exceed n.
        // 2. If only one player has a positive score, impossible.
        if (a + b > n || (a == 0) != (b == 0)) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        // Player 1: 1 2 3 ... n
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';

        int draw = n - a - b;

        // Player 2:
        // First 'draw' cards -> draws
        for (int i = 1; i <= draw; i++) {
            cout << i << ' ';
        }

        // Next 'b' cards -> Player 2 wins
        for (int i = n - b + 1; i <= n; i++) {
            cout << i << ' ';
        }

        // Remaining 'a' cards -> Player 1 wins
        for (int i = draw + 1; i <= draw + a; i++) {
            cout << i << ' ';
        }

        cout << '\n';
    }

    return 0;
}