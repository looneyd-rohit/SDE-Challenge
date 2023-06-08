// Approach 1: Maths Based
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// maths approach --> summation type
	long long sum = (1LL*n*(n+1)) / 2;
	long long sumOfSquares = (1LL*n*(n+1)*(2*n + 1)) / 6;
	long long arrSum = 0;
	long long arrSumOfSquares = 0;
	for(int i=0; i<n; i++){
		arrSum += arr[i];
		arrSumOfSquares += (1LL*arr[i])*arr[i];
	}
	// x - y (repeating - missing)
	long long diffOfSum = arrSum - sum;
	// x^2 - y^2 
	long long diffOfSquaresSum = arrSumOfSquares - sumOfSquares;
	// x + y
	diffOfSquaresSum = diffOfSquaresSum / diffOfSum;
	long long x = (diffOfSum + diffOfSquaresSum) / 2;
	long long y = x - diffOfSum;
	return {y, x};
}


// Approach 2: XOR Based (Bit Manipulation)
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// bit manipulation based --> xor type
	int xorr = 0;
	for(int i=1; i<=n; i++) xorr = xorr ^ i;
	for(int i=0; i<n; i++) xorr = xorr ^ arr[i];
	// xor = (missing ^ repeating)
	// take the first bit in which they differ and segregate the two arrays
	// one being the given array and one being the numbers [1...n]
	int index = 0, temp = xorr;
	while(temp){
		if(temp & (1<<index)){
			break;
		}else{
			index++;
		}
	}
	// now segregate
	int left_xor = 0, right_xor = 0;
	for(int i=1; i<=n; i++){
		if((1<<index) & i) left_xor = left_xor ^ i;
		else right_xor = right_xor ^ i;
	}
	for(int i=0; i<n; i++){
		if((1<<index) & arr[i]) left_xor = left_xor ^ arr[i];
		else right_xor = right_xor ^ arr[i];
	}
	// now identify which one is the missing and which is the repeating
	bool flag = false;
	for(int i=0; i<n; i++){
		if(arr[i] == left_xor){
			// left_xor is not missing
			return {right_xor, left_xor};
		}
	}
	return {left_xor, right_xor};
}
