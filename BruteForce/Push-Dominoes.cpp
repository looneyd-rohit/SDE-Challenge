// Leetcode 838

class Solution {
public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size();
    string process = "L";
    process = process + dominoes + "R";
    int p = process.length();
    for (int i = 0; i < p; i++) {
      if (process[i] == '.')
        continue;
      int j = i + 1;
      while (j < p && process[j] == '.')
        j++;

      if (j < p) {
        if (process[i] == 'L' && process[j] == 'L') {
          int k = i;
          while (k <= j)
            process[k++] = 'L';
        } else if (process[i] == 'L' && process[j] == 'R') {
          // remains unchanged
        } else if (process[i] == 'R' && process[j] == 'R') {
          int k = j;
          while (k >= i)
            process[k--] = 'R';
        } else {
          int num = (j - i + 1);
          if (num & 1) {
            int mid = (j + i) >> 1;
            int k = i;
            while (k < mid)
              process[k++] = 'R';
            k = j;
            while (k > mid)
              process[k--] = 'L';
          } else {
            int mid = (j + i) >> 1;
            int k = i;
            while (k <= mid)
              process[k++] = 'R';
            k = j;
            while (k > mid)
              process[k--] = 'L';
          }
        }
      } else {
        if (process[i] == 'R') {
          int k = i;
          while (k < p)
            process[k++] = 'R';
        }
      }
      i = j - 1;
    }
    return process.substr(1, n);
  }
};