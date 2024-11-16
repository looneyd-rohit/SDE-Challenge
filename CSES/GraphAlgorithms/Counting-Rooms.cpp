#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPR(i, m, n) for (int(i) = (m); (i) < (n); (i)++)
#define REPRR(i, m, n) for (int(i) = (m); (i) > (n); (i)--)
#define nsync                       \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

// constant
const int M = (int)(1e9 + 7);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);


int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

int lcm(int a, int b){
  int g = gcd(a, b);
  return (a * b) / g;
}

vector<pair<int, int> > moves = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool check_bounds(int x, int y, int n, int m){
  if(x<0 || y<0 || x>=n || y>=m) return false;
  return true;
}

void traverse(int i, int j, vector<vector<bool> >& visited, vector<vector<char> >& grid){
  int n = grid.size(), m = grid[0].size();
  queue<pair<int, int> > q;
  q.push({i, j});
  visited[i][j] = true;
  while(!q.empty()){
    auto f = q.front(); q.pop();
    int x = f.first, y = f.second;
    // visit neighbours
    for(auto& mv: moves){
      int dx = mv.first, dy = mv.second;
      int new_x = x + dx, new_y = y + dy;
      if(check_bounds(new_x, new_y, n, m)){
        if(grid[new_x][new_y] == '.'){
          if(!visited[new_x][new_y]){
            q.push({new_x, new_y});
            visited[new_x][new_y] = true;
          }
        }
      }
    }
  }
}



int32_t main()
{
  nsync;

  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  //   freopen("error.txt", "w", stderr);
  // #endif

  // CSES - Counting Rooms

  // int t;
  // cin >> t;
  // while (t--)
  // {
    
  // }

  int n, m;
  cin>>n>>m;
  vector<vector<char> > grid(n, vector<char>(m, '#'));
  REP(i, n){
    REP(j, m){
      cin>>grid[i][j];
    }
  }
  vector<vector<bool> > visited(n, vector<bool>(m, false));
  int count = 0;
  REP(i, n){
    REP(j, m){
      if(grid[i][j] == '.'){
        if(!visited[i][j]){
          traverse(i, j, visited, grid);
          count++;
        }
      }
    }
  }
  cout<<count<<endl;
  return 0;
}