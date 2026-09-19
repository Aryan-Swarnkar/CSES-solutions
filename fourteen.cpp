#include <iostream>
#include <map>
#include <string>
using namespace std;

void print_permutation(map<char, int>& fm, string& aux, int n) {
    if (aux.size() == n) {
        cout << aux << '\n';
        return;
    }

    for (int i = 0; i < 26; i++) {
        char ch = 'a' + i;

        if (fm.find(ch) == fm.end()) {
            continue;
        }

        aux.push_back(ch);

        if (fm[ch] == 1) {
            fm.erase(ch);
        } else {
            fm[ch]--;
        }

        print_permutation(fm, aux, n);

        fm[ch]++;
        aux.pop_back();
    }
}

int main() {
    string inp;
    cin >> inp;

    map<char, int> fm;

    for (char ch : inp) {
        fm[ch]++;
    }

    // Calculate n! / (freq1! * freq2! * ...)
    long long total = 1;

    for (int i = 2; i <= inp.size(); i++) {
        total *= i;
    }

    for (auto& pair : fm) {
        for (int i = 2; i <= pair.second; i++) {
            total /= i;
        }
    }

    cout << total << '\n';

    string aux;
    print_permutation(fm, aux, inp.size());

    return 0;
}