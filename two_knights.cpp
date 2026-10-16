#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin>>n;

  for(int k = 1;k <= n;k++){
    long long t_cells = k * k;
    if(k == 1){
      cout<<0<<endl;
    } else {
      long long total = (t_cells * (t_cells - 1)) / 2;
      long long slabs = (k - 2) * (k - 1) * 2 * 2;
      cout << total - slabs << endl;
    }
  }
  
  return 0;
}