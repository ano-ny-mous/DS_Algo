//Using Stack
class Solution {
public:
    string removeStars(string s) {
       stack<char> st;
       int sz=s.size();
       for(int i=0;i<sz;i++)
       {
           if(s[i]!='*')
           {
               st.push(s[i]);
           }
           else
           {
               st.pop();
           }
       }
       string ans="";
       int stacksz=st.size();
       while(!st.empty())
       {
           ans.push_back(st.top());
           st.pop();
       }
       reverse(ans.begin(), ans.end());
       return ans; 
    }
};

//Using String as Stack
class Solution {
public:
    string removeStars(string s) {
       string ans="";
       int sz=s.size();
       for(int i=0;i<sz;i++)
       {
           if(s[i]=='*')
           {
               ans.pop_back();
           }
           else
           {
               ans.push_back(s[i]);
           }
       }
       return ans;
    }
};

//Using Two pointers
class Solution {
public:
    string removeStars(string s) {
       int sz=s.size();
       vector<char> ans(sz);
       int j=0;
       for(int i=0;i<sz;i++)
       {
           if(s[i]=='*')
           {
               j--;
           }
           else
           {
               ans[j]=s[i];
               j++;
           }
       }
       string res="";
       for(int i=0;i<j;i++)
       {
           res.push_back(ans[i]);
       }
       return res;
    }
};


