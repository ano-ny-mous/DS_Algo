class Solution {
public:

int dp[1001][1001];
    int t1,t2;

    int rec(string &text1, string &text2,int i,int j)
    {
        if(i>=t1||j>=t2)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(text1[i]==text2[j])
        {
            return dp[i][j]=1+rec(text1,text2,i+1,j+1);
        }
        
        return dp[i][j]=max(rec(text1,text2,i+1,j),rec(text1,text2,i,j+1));
    }
  
    int longestPalindromeSubseq(string s) {
        string text1=s;
        
        reverse(s.begin(),s.end());
        string text2=s;
       t1=text1.size();
        t2=text2.size();
        memset(dp,-1,sizeof(dp));
        return rec(text1,text2,0,0);      
    }
};