#include <bits/stdc++.h>

using namespace std;

string path;
bool vis[9][9];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};

int dfs(int x, int y, int step){
  if(x == 7 && y == 1){
    return step == 48;
  }

  if(step == 48) return 0;

  if((vis[x-1][y] && vis[x+1][y] &&
    !vis[x][y-1] && !vis[x][y+1]) ||
    (!vis[x-1][y] && !vis[x+1][y] && 
      vis[x][y-1] && vis[x][y+1])) {
        return 0;
      }
  int ans = 0;
  for(int d = 0;d < 4;d++){
    int nx = x + dx[d];
    int ny = y + dy[d];

    if(path[step] != '?' && path[step] != dir[d])
      continue;

    if(vis[nx][ny])
      continue;

    vis[nx][ny] = true;

    ans += dfs(nx, ny, step + 1);

    vis[nx][ny] = false;
  }

  return ans;
}

int main(){
  cin>>path;

  for(int i = 0;i < 9;i++){
    vis[0][i] = true;
    vis[8][i] = true;
    vis[i][0] = true;
    vis[i][8] = true;
  }

  vis[1][1] = true;

  cout << dfs(1, 1, 0) << '\n';
  return 0;
}