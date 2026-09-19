#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;

    int t = n;
    vector<long long> vec(t);

    long long inp_sum = 0;

    for (int i = 0; i < t; i++) {
        cin >> vec[i];
        inp_sum += vec[i];
    }

    long long difference = LLONG_MAX;

    for (long long mask = 0; mask < (1LL << t); mask++) {
        long long x = 0;

        for(int i = 0;i < n;i++){
          if(mask & (1LL << i)){
            x += vec[i];
          }
        }

        difference = min(difference, llabs(inp_sum - 2 * x));
    }

    cout << difference << '\n';

    return 0;
}