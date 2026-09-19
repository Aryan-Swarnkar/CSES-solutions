#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){

  int n;
  cin >> n;

  for(int i = 0;i < (1LL << n);i++){
    long long grey = i ^ (i >> 1);
    
    string s = "";
    for(int j = n-1;j >= 0;j--){
      s += ((grey >> j) & 1) ? '1' : '0';
    }
    cout << s << endl;
  }
  
  return 0;
}