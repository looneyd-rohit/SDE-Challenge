// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&st, int N)
    {
        if(st.size() == (N+1)/2){
          st.pop();
          return;
       }
    
       int t = st.top(); st.pop();
       deleteMid(st, N);
       st.push(t);
    }
};