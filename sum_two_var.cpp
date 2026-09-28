#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = a[left].first + a[right].first;

        if (sum == x) {
            cout << a[left].second + 1 << " "
                 << a[right].second + 1 << '\n';
            return 0;
        }

        if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}