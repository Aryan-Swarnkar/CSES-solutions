#include <bits/stdc++.h>

using namespace std;

int apartments() {
    int n;
    int m;
    int k;

    cin >> n >> m >> k;

    vector<int> desired(n);
    vector<int> apartment(m);

    for (int i = 0; i < n; i++) {
        cin >> desired[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> apartment[i];
    }

    sort(desired.begin(), desired.end());
    sort(apartment.begin(), apartment.end());

    int i = 0;
    int j = 0;
    int counter = 0;

    while (i < n && j < m) {

        if (apartment[j] < desired[i] - k) {
            j++;
        }
        else if (apartment[j] > desired[i] + k) {
            i++;
        }
        else {
            counter++;
            i++;
            j++;
        }
    }

    return counter;
}

int main() {
    int res = apartments();
    cout << res << endl;

    return 0;
}