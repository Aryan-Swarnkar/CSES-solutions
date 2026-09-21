#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin>>n;

  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      cout << (i ^ j);

      if(j != n-1){
        cout << ' ';
      }
    }
    cout << '\n';
  }
  
  return 0;
}