#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> dist(n, vector<int>(n, -1));

  queue<pair<int, int>> q;

  int dr[] = {2, 2, -2, -2, 1, 1, -1, -1};
  int dc[] = {1, -1, 1, -1, 2, -2, 2, -2};

  dist[0][0] = 0;
  q.push({0, 0});

  while(!q.empty()){
    auto [r, c] = q.front();
    q.pop();

    for(int k = 0;k < 8;k++){
      int nr = r + dr[k];
      int nc = c + dc[k];

      if(nr >= 0 && nr < n && nc >= 0 && nc < n){

        if(dist[nr][nc] == -1){
          dist[nr][nc] = dist[r][c] + 1;
          q.push({nr, nc});
        }
      }
    }
  }

  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      cout << dist[i][j];

      if(j != n-1){
        cout << ' ';
      }
    }
    cout << '\n';
  }
  
  return 0;
}