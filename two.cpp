#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// You are given all numbers between 1,2,....,n except one. Your task is to find the missing number.

// Input : 
// The first input line contains an integer n.
// The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).

// Output
// Print the missing number.


// Input:
// 5
// 2 3 1 5

// Output:
// 4



int main(){
    int n;
    cin >> n;

    int xor_them = 0;
    for(int i = 1;i <= n;i++){
        xor_them ^= i;
    }

    for(int i = 0;i < n-1;i++){
        int temp;
        cin >> temp;
        xor_them ^= temp;
    }

    cout << xor_them << endl;

    return 0;
}
