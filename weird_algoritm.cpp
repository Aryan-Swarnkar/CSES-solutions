#include <iostream>
#include <cstdint>
using namespace std;



void weird_algorithm(int64_t val){

    cout << val << " ";

    while(val != 1){
        if(val % 2 == 0){
            val /= 2;
        } else {
            val = (val*3) + 1;
        }
        cout << val << " ";
    }
    return;
}

int main() {
    int64_t n;

    cin >> n;

    weird_algorithm(n);
    
    return 0;
}