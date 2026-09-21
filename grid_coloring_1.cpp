#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    const string colors = "ABCD";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            for (char color : colors) {

                // Cannot keep the original character
                if (color == grid[i][j])
                    continue;

                // Cannot match the left cell
                if (j > 0 && color == grid[i][j - 1])
                    continue;

                // Cannot match the upper cell
                if (i > 0 && color == grid[i - 1][j])
                    continue;

                // Found a valid color
                grid[i][j] = color;
                break;
            }
        }
    }

    for (const string &row : grid) {
        cout << row << '\n';
    }

    return 0;
}