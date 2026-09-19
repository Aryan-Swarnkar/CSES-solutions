#include <iostream>
#include <vector>
using namespace std;

void two_sets(long long n) {
    long long sum = 0;
    vector<long long> sets_num;

    for (long long i = 1; i <= n; i++) {
        sum += i;
        sets_num.push_back(i);
    }

    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    long long target = sum / 2;
    long long check_sum = 0;
    long long end = sets_num.size() - 1;

    vector<long long> set_one;

    while (check_sum != target) {

        if (check_sum + sets_num[end] <= target) {
            check_sum += sets_num[end];

            set_one.push_back(sets_num[end]);
            sets_num[end] = 0;
        }

        end--;
    }

    vector<long long> set_two;

    for (long long i = 0; i < sets_num.size(); i++) {
        if (sets_num[i] != 0) {
            set_two.push_back(sets_num[i]);
        }
    }

    cout << set_one.size() << endl;

    for (long long x : set_one) {
        cout << x << " ";
    }

    cout << endl;

    cout << set_two.size() << endl;

    for (long long x : set_two) {
        cout << x << " ";
    }

    cout << endl;
}

int main() {
    long long inp;
    cin >> inp;

    two_sets(inp);

    return 0;
}