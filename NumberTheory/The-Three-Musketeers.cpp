// https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/

// Approach 1: DP
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define nsync                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

// constant
const int M = (int)(1e9 + 7);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);

void fun() { cout << "Magi World!!!" << endl; }

const int N = 1e4;
int maskOfVowels[N + 1];
int vowelIndex(char ch) {
  if (ch == 'a')
    return 0;
  else if (ch == 'e')
    return 1;
  else if (ch == 'i')
    return 2;
  else if (ch == 'o')
    return 3;
  else if (ch == 'u')
    return 4;
  else
    return -1;
  return -1;
}

int dp[N + 1][32][4];
int solve(int i, int mask, int taken, int n) {
  if (i >= n) {
    if (taken == 3 && mask > 0)
      return 1;
    return 0;
  }
  if (dp[i][mask][taken] != -1)
    return dp[i][mask][taken];
  // not taking the current index i
  int ans = solve(i + 1, mask, taken, n);
  // taking the current index if possible
  if (taken < 3) {
    ans += solve(i + 1, mask & (maskOfVowels[i]), taken + 1, n);
  }
  return dp[i][mask][taken] = ans;
}

int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // The Three Musketeers
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    // for each word generate the mask of the
    // vowels present inside the word
    memset(maskOfVowels, 0, sizeof(maskOfVowels));
    memset(dp, -1, sizeof(dp));

    REP(i, n) {
      string word;
      cin >> word;
      int mask = 0;
      REP(j, word.length()) {
        int k = vowelIndex(word[j]);
        if (k != -1) {
          mask = mask | (1 << k);
        }
      }
      maskOfVowels[i] = mask;
    }
    cout << solve(0, (1 << 5) - 1, 0, n) << endl;
  }

  return 0;
}

// Approach 2: Inclusion Exclusion Principle
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define nsync                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

// constant
const int M = (int)(1e9 + 7);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);

void fun() { cout << "MF World!!!" << endl; }

bool isVowel(char ch) {
  if (ch == 'a')
    return true;
  else if (ch == 'e')
    return true;
  else if (ch == 'i')
    return true;
  else if (ch == 'o')
    return true;
  else if (ch == 'u')
    return true;
  else
    return false;
  return false;
}

vector<string> computeSubsets(string &str) {
  int sz = (1 << str.size());
  int mask = 0;
  vector<string> subsets;
  REP(mask, sz) {
    string sub = "";
    REP(i, sz) {
      if (mask & (1 << i)) {
        sub.push_back(str[i]);
      }
    }
    if (sub.length() > 0)
      subsets.push_back(sub);
  }
  return subsets;
}

int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // The Three Musketeers
  // using inclusion exclusion principle
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> names(n);
    REP(i, n) cin >> names[i];
    unordered_map<string, int> freq;
    REP(i, n) {
      string name = names[i];
      set<char> curr_vowels;
      for (int j = 0; j < name.size(); j++) {
        for (int v = 0; v < 5; v++) {
          if (name[j] == vowels[v]) {
            curr_vowels.insert(vowels[v]);
          }
        }
      }
      string curr_vowels_str(begin(curr_vowels), end(curr_vowels));
      // generate all subsets
      vector<string> subsets = computeSubsets(curr_vowels_str);
      for (const auto &sub : subsets) {
        freq[sub]++;
      }
    }
    // compute final answer (inclusion-exclusion)
    int ans = 0;
    for (const auto &p : freq) {
      int f = p.second;
      if (f < 3)
        continue;
      int select = f * (f - 1) * (f - 2) / 6;
      if (p.first.size() % 2) {
        ans += select;
      } else {
        ans -= select;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
