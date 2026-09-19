#include <iostream>
#include <vector>
using namespace std;

int main(){

  int t;
  cin >> t;
  vector<std::string> vec; 

  while(t--){
    long long a, b;
    cin >> a >> b;

    if(((a + b) % 3 == 0) && (2 * a >= b && 2 * b >= a)){
      vec.push_back("YES\n");
    } else {
      vec.push_back("NO\n");
    }
  }

  for(std::string s : vec){
    cout << s;
  }
  
  return 0;
}