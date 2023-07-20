// https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

// [IMP]: one of the hardest to think of Binary Search, check() funtion

// Approach 1: Brute Force
// Logic: We initially assume that between every pair of adjacent stations we have
// 0 new stations placed, then we iterate the whole array and find the maximum diff
// in the station space, and place a new station there. Repeat this process for k times
// and get the maximum dist
#include<bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k){
	// brute force:
	// we will go on and find the maximum distance between two adjacent stations
	// after placing stations one by one
	int n = arr.size();
	vector<int> store(n-1, 0);
	for(int i=0; i<k; i++){
		long double maxi = 0;
		int maxiInd = -1;
		for(int station=1; station<n; station++){
			long double initial_diff = arr[station] - arr[station-1];
			long double new_diff = (initial_diff * 1.0) / (store[station-1] + 1);
			if(new_diff > maxi){
				maxi = new_diff;
				maxiInd = station-1;
			}
		}
		store[maxiInd]++;
	}
	long double dist = 0;
	for(int station=1; station<n; station++){
		long double initial_diff = arr[station] - arr[station-1];
		long double curr_diff = (initial_diff * 1.0) / (store[station-1] + 1);
		dist = max(dist, curr_diff);
	}
	return dist;
}

// Approach 2: Using Priority Queue
// Logic: Use a priority queue to optimize the inner loop where the O(N) operation
// can be performed in just log(N) since we need the maximum difference
#include<bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> store(n-1, 0);
	priority_queue<pair<long double, int>> maxheap;    // <diff, index>
	for(int station=1; station<n; station++){
		maxheap.push({arr[station]-arr[station-1], station});
	}
	for(int i=0; i<k; i++){
		auto top = maxheap.top(); maxheap.pop();
		int station = top.second;
		// cout<<top.first<<" "<<top.second<<endl;
		long double initial_diff = arr[station] - arr[station-1];
		long double new_diff = (initial_diff*1.0) / (long double)(store[station-1] + 2);
		// cout<<initial_diff<<" "<<new_diff<<endl;
		maxheap.push({new_diff, station});
		store[station-1]++;
	}
	return maxheap.top().first;
}

// Approach 3: Using Binary Search [IMP], different template
// Template for Binary Search involving long double is given below
#include<bits/stdc++.h>
using namespace std;

long placeStations(vector<int> &arr, long double gap){
	int n = arr.size();
	int count = 0;
	if(gap == 0) return INT_MAX;
	for(int i=1; i<n; i++){
		int cnt = ceil((arr[i]-arr[i-1]) / gap);
		count += cnt - 1;
	}
	return count;
}
long double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	long double low = 0, high = 0;
	for(int i=1; i<n; i++) high = max(high, (long double)arr[i]-arr[i-1]);
	while(high - low > 1e-6){
		long double mid = (low + high) / 2.0;
		long double gap = mid;
		long stations = placeStations(arr, gap);
		if(stations > k){
			// more no. of stations required to fulfill this gap
			// hence, increase the gap to reduce stations
			low = mid;
		}else{
			high = mid;
		}
	}
	return high;
}