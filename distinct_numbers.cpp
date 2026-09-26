#include <bits/stdc++.h>

using namespace std;

long long distinct_numbers(){
  int n;
  cin>>n;

  set<int> st;
  while(n--){
    int x;
    cin>>x;
    st.insert(x);
  }

  return st.size();
}

int main(){

  long long  res = distinct_numbers();

  cout << res << endl;
  
  return 0;
}