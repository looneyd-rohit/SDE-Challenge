// https://codeforces.com/contest/1954/problem/B

#include <bits/stdc++.h>
using namespace std;
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

void fun() { cout << "MF World!!!" << endl; }

void solve(){
  string str_x, str_y;
  cin>>str_x;
  cin>>str_y;
  int n = str_x.length();
  
  int ind = 0;
  while(ind<n && str_x[ind]==str_y[ind]) ind++;

  if(str_y[ind] > str_x[ind]) swap(str_x, str_y);
  
  REPR(i, ind+1, n){
    if(str_x[ind] < str_y[ind]){
      if(str_x[i] < str_y[i]){
        swap(str_x[i], str_y[i]);
      }
    }else if(str_x[ind] > str_y[ind]){
      if(str_x[i] >= str_y[i]){
        swap(str_x[i], str_y[i]);
      }
    }
  }
  
  cout<<str_x<<"\n";
  cout<<str_y<<"\n";
}

int32_t main(){
  nsync;
  /*
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif
  */

  // B. Make It Ugly

  int t;
  cin >> t;
  while (t--){
    int n;
		cin>>n;
		vector<int> arr(n);
    unordered_map<int, int> mp;
		for(int i=0; i<n; i++) cin>>arr[i], mp[arr[i]]++;
		if(mp.size()==1){
			cout<<-1<<endl;
		}else{
      int k = 0, res = n;
      REP(i, n){
        if(arr[i]==arr[0]){
          k++;
        }else{
          res = min(res, k);
          k = 0;
        }
      }
      res = min(res, k);
      cout<<res<<endl;
    }
  }
  return 0; 
}