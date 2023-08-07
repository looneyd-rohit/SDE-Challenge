// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/lis-revisted-0b3ed24b/?purpose=login&source=problem-page&update=github

// [IMP]: LNDS (Longest Non Decreasing Subsequence)
#include<bits/stdc++.h>
using namespace std;

vector<int> LIS (int N, vector<int> Arr) {
   // Write your code here
   vector<int> result(N, 1);
   vector<int> lnds;
   lnds.push_back(Arr[0]);
   for(int i=1; i<N; i++){
    int el = Arr[i];
    auto it = upper_bound(begin(lnds), end(lnds), el);
    if(it == lnds.end()){
        // upper bound doesn't exists
        lnds.push_back(el);
        result[i] = lnds.size();
    }else{
        // upper bound exists
        *it = el;
        result[i] = it - begin(lnds) + 1;
    }
   }
   return result;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> Arr(N);
    for(int i_Arr = 0; i_Arr < N; i_Arr++)
    {
    	cin >> Arr[i_Arr];
    }

    vector<int> out_;
    out_ = LIS(N, Arr);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}