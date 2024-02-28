// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/?purpose=login&source=problem-page&update=github

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

// constants
const int M = (int)(1e9 + 7);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);

const int N = 1e6;
bool sieve[N + 1];
int lprimes[N + 1], hprimes[N + 1];
void generateSieve() {
  memset(sieve, true, sizeof(sieve));
  memset(lprimes, -1, sizeof(lprimes));
  sieve[0] = sieve[1] = false;
  for (int i = 2; i <= N; i++) {
    if (sieve[i]) {
      lprimes[i] = i;
      for (int j = 2 * i; j <= N; j += i) {
        sieve[j] = false;
        if (lprimes[j] == -1)
          lprimes[j] = i;
      }
    }
  }
}

vector<int> primeFactorization(int n) {
  vector<int> factors;
  while (n > 1) {
    int lowprime = lprimes[n];
    factors.push_back(lowprime);
    while (n % lowprime == 0) {
      n /= lowprime;
    }
  }
  return factors;
}

void markPowers(vector<bool> &powers, vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int el = arr[i];
    if (el <= 1) {
      powers[el] = true;
      continue;
    }
    for (int j = el; j <= 1000000; j *= el) {
      powers[j] = true;
    }
  }
}

bool solve(vector<bool> &powers, vector<int> &uniquePrimeFactors, int x) {
  for (int i = 0; i < uniquePrimeFactors.size(); i++) {
    for (int j = i; j < uniquePrimeFactors.size(); j++) {
      int pdt = uniquePrimeFactors[i] * uniquePrimeFactors[j];
      if (i == j && x % pdt != 0)
        continue;
      int rem = x / pdt;
      if (powers[rem] || rem == 1) {
        return true;
      }
    }
  }
  return false;
}

int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // Hacker Decrypting Messages

  // int t;
  // cin >> t;
  // while (t--) {

  // }
  generateSieve();
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  REP(i, n) cin >> arr[i];
  vector<bool> powers(N + 1, false);
  // mark all the powers of all elements of the arr
  markPowers(powers, arr);
  while (q--) {
    int x;
    cin >> x;
    // compute the prime factorization of x
    vector<int> uniquePrimeFactors = primeFactorization(x);
    if (solve(powers, uniquePrimeFactors, x)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}