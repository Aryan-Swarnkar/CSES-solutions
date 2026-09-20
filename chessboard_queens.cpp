#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

    vector<string> chessboard(8);

    for (int i = 0; i < 8; i++) {
        cin >> chessboard[i];
    }

    int count = 0;

    // columns[i] = column where queen is placed in row i
    vector<int> columns(8);
    iota(columns.begin(), columns.end(), 0);

    do {
        bool valid = true;

        // Check reserved cells
        for (int i = 0; i < 8; i++) {
            if (chessboard[i][columns[i]] != '.') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            // This permutation already fails
            continue;
        }

        // Check diagonal: row + column
        vector<bool> diagonalOccupied(15, false);

        for (int i = 0; i < 8; i++) {
            int diagonal = i + columns[i];

            if (diagonalOccupied[diagonal]) {
                valid = false;
                break;
            }

            diagonalOccupied[diagonal] = true;
        }

        if (!valid) {
            continue;
        }

        // Check other diagonal: row - column
        fill(diagonalOccupied.begin(), diagonalOccupied.end(), false);

        for (int i = 0; i < 8; i++) {
            int diagonal = i + 7 - columns[i];

            if (diagonalOccupied[diagonal]) {
                valid = false;
                break;
            }

            diagonalOccupied[diagonal] = true;
        }

        if (valid) {
            count++;
        }

    } while (next_permutation(columns.begin(), columns.end()));

    cout << count << '\n';

    return 0;
}