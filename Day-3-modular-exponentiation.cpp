#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	unsigned long long xx = x % m;
	unsigned long long ans = 1;
	while(n){
		if(n & 1){
			ans = (ans * xx) % m;
			n--;
		}else{
			xx = (xx * xx) % m;
			n = n / 2;
		}
	}
	return ans;
}