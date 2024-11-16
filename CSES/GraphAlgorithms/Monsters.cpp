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

vector<vector<int> > monster_traverse(vector<vector<char> >& grid){
  int n = grid.size(), m = grid[0].size();
  priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > pq;
  vector<vector<int> > distances(n, vector<int>(m, INF));
  REP(i, n){
    REP(j, m){
      if(grid[i][j] == 'M'){
        pq.push({0, i, j});
        distances[i][j] = 0;
      }
    }
  }
  while(!pq.empty()){
    auto t = pq.top(); pq.pop();
    int dist = t[0], x = t[1], y = t[2];

    // visit neighbours
    for(auto& mv: moves){
      int dx = mv.first, dy = mv.second;
      int new_x = x + dx, new_y = y + dy;
      if(check_bounds(new_x, new_y, n, m)){
        if(grid[new_x][new_y] != '#'){
          if(distances[new_x][new_y] > dist+1){
            pq.push({dist+1, new_x, new_y});
            distances[new_x][new_y] = dist + 1;
          }
        }
      }
    }
  }
  return distances;
}

pair<int, int> character_traverse(vector<vector<int> >& distances, vector<vector<char> >&grid){
  int n = grid.size(), m = grid[0].size();
  priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > pq;
  REP(i, n){
    REP(j, m){
      if(grid[i][j]=='A'){
        pq.push({0, i, j});
        break;
      }
    }
  }

  // here check logic is different since we already have some distance value
  // assigned to each cell
  while(!pq.empty()){
    auto t = pq.top(); pq.pop();
    int dist = t[0], x = t[1], y = t[2];
    if(distances[x][y] <= dist) continue;
    else distances[x][y] = dist;
    if(x == n-1 || y == m-1 || x == 0 || y == 0) return make_pair(x, y);
    // visit neighbours
    for(auto& mv: moves){
      int dx = mv.first, dy = mv.second;
      int new_x = x + dx, new_y = y + dy;
      if(check_bounds(new_x, new_y, n, m)){
        if(grid[new_x][new_y]!='#'){
          pq.push({dist+1, new_x, new_y});
        }
      }
    }
  }
  return {-1, -1};
}

int32_t main()
{
  nsync;

  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  //   freopen("error.txt", "w", stderr);
  // #endif

  // CSES - Monsters

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
  // traverse the monsters first
  vector<vector<int> > distances = monster_traverse(grid);
  
  // secondly, traverse the character to see if it can reach the borders
  auto p = character_traverse(distances, grid);
  int x = p.first, y = p.second;
  if(x == -1 || y == -1) cout<<"NO"<<endl;
  else{
    cout<<"YES"<<endl;
    int dist = distances[x][y];
    cout<<dist<<endl;
    string ans = "";
    while(dist > 0){
      int new_dist = dist - 1;

      for(auto& mv: moves){
        int dx = mv.first, dy = mv.second;
        int new_x = x + dx, new_y = y + dy;
        if(check_bounds(new_x, new_y, n, m)){
          int new_dist = distances[new_x][new_y];
          if(new_dist == dist - 1){
            // possible path for us
            dist = new_dist;
            x = new_x, y = new_y;
            if(dx == 1){
              ans.push_back('U');
            }
            if(dx == -1){
              ans.push_back('D');
            }
            if(dy == 1){
              ans.push_back('L');
            }
            if(dy == -1){
              ans.push_back('R');              
            }
          }
        }
      }
    }
    reverse(begin(ans), end(ans));
    cout<<ans<<endl;
  }
  return 0;
}