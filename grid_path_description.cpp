#include <bits/stdc++.h>

using namespace std;

string s;

bool visited[7][7];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

char dir[] = {'D', 'U', 'L', 'R'};

long long dfs(int r, int c, int step){

  if(step == 48){
    return (r == 6 && c == 0);
  }

  if(r == 6 && c == 0){
    return 0;
  }

  bool up = (r == 0 || visited[r-1][c]);
  bool down = (r == 6 || visited[r+1][c]);
  bool left = (c == 0 || visited[r][c-1]);
  bool right = (c == 6 || visited[r][c+1]); 

  if(up && down && !left && !right){
    return 0;
  }

  if(left && right && !up && !down){
    return 0;
  }

  long long ways = 0;

  for(int i = 0;i < 4;i++){

    if(s[step] != '?' && s[step] != dir[k])
      continue;

    int nr = r + dr[i];
    int nc = c + dc[i];

    if(nr < 0 || nr >= 7 || nc >= 7 && nc < 0){
      continue;
    }

    if(visited[nr][nc])
      continue;

    visited[nr][nc] = true;

    ways += dfs(nr, nc, step + 1);

    visited[nr][nc] = false;
    
  }

  return ways;
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>s;

  visited[0][0] = true;

  cout << dfs(0, 0, 0) << endl;
  
  return 0;
}