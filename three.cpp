#include <iostream>
using namespace std;

int repetitions(string s){
    if(s.empty()) return 0;
    int greatest = 1;
    int great = 1;
    for(int i = 1;i < s.size();i++){
        if(s[i] == s[i-1]){
            great++;
            greatest = std::max(greatest, great);
        } else {
            great = 1;
        }
    }
    return greatest;
}

int main(){
    string str;
    cin >> str;
    cout << repetitions(str) << endl;
    
    return 0;
}