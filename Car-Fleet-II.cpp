// Leetcode 1776
// One of the hardest
// [IMP]
// [NOTE]: solve this patiently

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        stack<int> st;
        // assuming collision time for each car is infinity i.e., they don't collide
        vector<double> store(n, INT_MAX);
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            vector<int> car = cars[i];

            // current car can collide with next car only if, next has lesser speed
            while(!st.empty() && cars[st.top()][1] >= car[1]) st.pop();

            // now if some car exists, then collsion will surely occur
            if(!st.empty()){
                // it may also happen that the next turn collides in future with some other car
                // so we need to loop to find the car with which current car collides finally
                while(!st.empty()){
                    vector<int> nextCar = cars[st.top()];
                    double timeToCollide = (nextCar[0] - car[0]) * 1.0 / (car[1] - nextCar[1]);
                    if(timeToCollide <= store[st.top()]){
                        store[i] = timeToCollide;
                        break;
                    }
                    // else pop this element and try with next to next car
                    st.pop();
                }
            }
            st.push(i);
        }
        for(auto& e: store) if(e == INT_MAX) e = -1;
        return store;
    }
};