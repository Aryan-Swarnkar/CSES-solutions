#include <iostream>
#include <vector>
using namespace std;

long long number_spiral(long long x, long long y) {
    long long result;

    if (x > y) {
        if (x % 2 == 0) {
            result = x * x - y + 1;
        } else {
            result = (x - 1) * (x - 1) + y;
        }
    } else {
        if (y % 2 == 0) {
            result = (y - 1) * (y - 1) + x;
        } else {
            result = y * y - x + 1;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<long long> res;
    while (n--) {
        long long x, y;
        cin >> x >> y;
        long long number = number_spiral(x, y);
        res.push_back(number);
    }

    for(long long num : res){
      cout << num << endl;
    }

    return 0;
}
