#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int helper){
  if(n == 0) return;

  hanoi(n-1, from, helper, to);

  cout << from << " " << to << endl;

  hanoi(n-1, helper, to, from);
}

int main(){

  int n;
  cin >> n;

  long long num = (1LL << n) - 1;
  cout << num << endl;

  hanoi(n, 1, 3, 2);
  
  return 0;
}