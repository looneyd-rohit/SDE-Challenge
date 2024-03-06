// Leetcode 1622

// [IMP] Approach: reversal of operation on addtion of new values
class Fancy {
public:
  const int M = 1e9 + 7;
  vector<long long> sequence;
  long long index;
  long long increment, multiply;
  Fancy() {
    this->sequence.resize(1e5 + 1, 0);
    this->index = 0;
    this->increment = 0;
    this->multiply = 1;
  }

  int bin_exp(unsigned long long a, int b) {
    int res = 1;
    while (b) {
      if (b & 1) {
        res = (res * a) % M;
      }
      a = (a * a) % M;
      b >>= 1;
    }
    return res;
  }

  void append(int val) {
    // apply reverse operation on val
    // as we have already performed some operation of the previous numbers
    // and don't want to alter the getIndex function and want to keep it same
    // for all val = (val - increment) / multiply -> translates to modulo
    // inverse
    this->sequence[index++] = (((val - this->increment + M) % M) *
                               (bin_exp(this->multiply, M - 2) % M)) %
                              M;
  }

  void addAll(int inc) { this->increment = (this->increment + (inc % M)) % M; }

  void multAll(int m) {
    this->multiply = (this->multiply * (m % M)) % M;
    this->increment = (this->increment * (m % M)) % M;
  }

  int getIndex(int idx) {
    if (idx >= index)
      return -1;
    return ((this->sequence[idx] * this->multiply) % M + this->increment) % M;
  }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */