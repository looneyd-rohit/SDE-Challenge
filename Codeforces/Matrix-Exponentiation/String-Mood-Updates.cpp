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

class Matrix {
public:
  int arr[2][2];
  Matrix() { REP(i, 2) REP(j, 2) arr[i][j] = 0; }
  Matrix operator*(const Matrix &mat2) {
    Matrix mat3;
    REP(i, 2) {
      REP(j, 2) {
        REP(k, 2) {
          mat3.arr[i][j] += (this->arr[i][k] * mat2.arr[k][j]) % M;
          mat3.arr[i][j] %= M;
          mat3.arr[i][j] += M;
          mat3.arr[i][j] %= M;
        }
      }
    }
    return mat3;
  }
  static Matrix unit() {
    Matrix mat;
    mat.arr[0][0] = mat.arr[1][1] = 1;
    return mat;
  }
  static Matrix generate(char ch) {
    Matrix mat;
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
      mat.arr[0][1] = mat.arr[1][0] = 1;
    } else if (ch == 'S' || ch == 'D') {
      mat.arr[0][1] = mat.arr[1][1] = 1;
    } else if (ch == 'H') {
      mat.arr[0][0] = mat.arr[1][0] = 1;
    } else if (ch == '?') {
      mat.arr[0][0] = 19;
      mat.arr[0][1] = 7;
      mat.arr[1][0] = 6;
      mat.arr[1][1] = 20;
    } else {
      mat.arr[0][0] = mat.arr[1][1] = 1;
    }
    return mat;
  }
};

ostream &operator<<(ostream &out, const Matrix &mat) {
  out << mat.arr[0][0];
  out << " | ";
  out << mat.arr[0][1];
  out << endl;

  out << mat.arr[1][0];
  out << " | ";
  out << mat.arr[1][1];
  out << endl;

  out << "---------------------";
  out << endl;
  return out;
}

class SGTREEMAT {
public:
  vector<Matrix> segArr;
  SGTREEMAT(int n = 1) { segArr.resize(4 * n + 1); }
  void build(int index, int low, int high, vector<Matrix> &input) {
    if (low == high) {
      this->segArr[index] = input[low];
      return;
    }
    int mid = low + ((high - low) >> 1);
    build(2 * index + 1, low, mid, input);
    build(2 * index + 2, mid + 1, high, input);

    // form the nodes operation at intermediate levels
    this->segArr[index] =
        this->segArr[2 * index + 1] * this->segArr[2 * index + 2];
  }
  Matrix query(int index, int low, int high, int l, int h) {
    // no overlap
    if (high < l || low > h) {
      return Matrix::unit();
    }
    // complete overlap
    if (l <= low && high <= h) {
      return this->segArr[index];
    }
    // partial overlap
    int mid = low + ((high - low) >> 1);
    Matrix left = query(2 * index + 1, low, mid, l, h);
    Matrix right = query(2 * index + 2, mid + 1, high, l, h);
    return (left * right);
  }
  void update(int index, int low, int high, int i, Matrix &mat) {
    if (low == high) {
      this->segArr[index] = mat;
      return;
    }
    int mid = low + ((high - low) >> 1);
    if (i <= mid) {
      update(2 * index + 1, low, mid, i, mat);
    } else {
      update(2 * index + 2, mid + 1, high, i, mat);
    }
    this->segArr[index] =
        this->segArr[2 * index + 1] * this->segArr[2 * index + 2];
  }
};

void printArray(vector<int> &arr) {
  for (auto &e : arr)
    cout << e << " ";
  cout << endl;
  cout << "-----------" << endl;
}

int32_t main() {
  // H. String Mood Updates
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // sieve();
  // int t;
  // cin >> t;
  // while (t--) {

  // }

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  // generate input matrices for input string
  vector<Matrix> inputMatrices;
  REP(i, n) { inputMatrices.push_back(Matrix::generate(s[i])); }

  // build the tree
  SGTREEMAT segTree(n);
  segTree.build(0, 0, n - 1, inputMatrices);

  // get the initial number of ways
  Matrix res = segTree.query(0, 0, n - 1, 0, n - 1);
  int val = res.arr[0][0];
  cout << val << endl;

  // get the number of ways after updating each
  REP(i, q) {
    int ind;
    char ch;
    cin >> ind >> ch;
    Matrix newMat = Matrix::generate(ch);
    segTree.update(0, 0, n - 1, ind - 1, newMat);
    res = segTree.query(0, 0, n - 1, 0, n - 1);
    int v = res.arr[0][0];
    cout << v << endl;
  }

  return 0;
}
