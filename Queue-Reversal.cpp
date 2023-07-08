// https://practice.geeksforgeeks.org/problems/queue-reversal/1

//Function to reverse the queue.
class Solution
{
    public:
    void reverse(queue<int>& q){
        if(q.empty()) return;
        int e = q.front(); q.pop();
        reverse(q);
        q.push(e);
    }
    queue<int> rev(queue<int> q)
    {
        reverse(q);
        return q;
    }
};