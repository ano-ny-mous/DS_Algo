class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        st.push(pushed[0]);
        int sz=pushed.size();
        int i=1,j=0;
        while(i<sz&&j<sz)
        {
            if(!st.empty()&&st.top()==popped[j])
            {
                st.pop();
                j++;
                continue;
            }
            if(i<sz)
            {
                st.push(pushed[i]);
                i++;
            }
        }
        while(!st.empty()&&j<sz)
        {
            if(st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            else
            {
                return false;
            }
        }
        return(st.empty());
    }
};