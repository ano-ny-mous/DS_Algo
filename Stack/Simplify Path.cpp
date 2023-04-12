class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int sz=path.size();
        stringstream tokenization(path);
        string tocken;
        string dot1=".";
        string dot2="..";
        while(getline(tokenization, tocken, '/'))
        {
            int cmp=tocken.compare("");
            if(cmp!=0)
            {
                string dot2="..";
                int cmp2=dot2.compare(tocken);
                if(cmp2==0)
                {
                    if(!st.empty())
                    st.pop();
                    continue;
                }
                int cmp1=dot1.compare(tocken);
                if(cmp1==0)
                {
                    continue;
                }
                st.push(tocken);
            }
        }
        string ans="";
        while(!st.empty())
        {
            string temp=st.top();
            reverse(temp.begin(),temp.end());
            ans=ans+temp+"/";
            st.pop();
        }
        if(ans=="")
        return "/";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};