#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin>>s;

  int n = s.size();

  map<char, int> freq;

  for(char c : s){
    freq[c]++;
  }

  int mx = 0;

  for(auto [ch, count] : freq){
    mx = max(mx, count);
  }

  if(mx > (n + 1) / 2){
    cout << -1 << endl;
    return 0;
  }

  string ans;
  ans.reserve(n);

  char prev = '#';

  for(int pos = 0;pos < n;pos++){

    for(char c = 'A';c <= 'Z';c++){

      if(freq[c] == 0){
        continue;
      }

      if(c == prev){
        continue;
      }

      freq[c]--;

      int remaining = n - pos - 1;

      int maxFreq = 0;
      for(auto [ch, count] : freq){
        maxFreq = max(maxFreq, count);
      }

      if(maxFreq <= (remaining + 1) / 2){
        
        ans += c;
        prev = c;

        break;
      }

      freq[c]++;
    }
  }

  cout << ans << endl;
  
  return 0;
}