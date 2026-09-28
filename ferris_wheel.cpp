#include <bits/stdc++.h>

using namespace std;

int ferris_wheel(){
  int n;
  int k;
  cin>>n>>k;

  vector<int> a(n);

  for(int i = 0;i < n;i++){
    cin>>a[i];
  }

  sort(a.begin(), a.end());

  int i = 0;
  int j = n-1;
  int counter = 0;

  while(i <= j){
    if(a[i] + a[j] <= k){
      i++;
      j--;
    } else {
      j--;
    }
    
    counter++;
  }
  return counter;
}

int main(){
  int res = ferris_wheel();
  cout << res << endl;
  return 0;
}