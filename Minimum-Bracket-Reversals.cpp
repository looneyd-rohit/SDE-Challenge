// https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1

// NOTE: here using the stack is redundant since, we only need invalid count we can
// do that by using variables
int countRev (string s)
{
    int n = s.length();
    if(n & 1) return -1;
    stack<char> st;
    int cntLeft = 0, cntRight = 0;
    for(int i=0; i<n; i++){
        char ch = s[i];
        if(ch == '{'){
            st.push(ch);
            cntLeft++;
        }else{
            if(!st.empty()){
                if(st.top()=='{'){
                    cntLeft--; st.pop();
                }
                else{
                    cntRight++;
                    st.push(ch);
                }
            }else{
                cntRight++;
                st.push(ch);
            }
        }
    }
    return (cntLeft+1)/2 + (cntRight+1)/2;
}