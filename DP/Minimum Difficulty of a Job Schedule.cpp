class Solution {
public:
    int dp[301][11];

    int rec(vector<int>& jobDifficulty, int n, int idx, int d)
    {
        if(d==1)
        {
            int maxWork=jobDifficulty[idx];
            for(int i=idx;i<n;i++)
            {
                maxWork=max(maxWork,jobDifficulty[i]);
            }
            return maxWork;
        }
        if(dp[idx][d]!=-1)
        {
            return dp[idx][d];
        }
        int maxWork=jobDifficulty[idx];
        int finalRes=INT_MAX;
        for(int i=idx;i<=n-d;i++)
        {
            maxWork=max(maxWork,jobDifficulty[i]);
            int res=maxWork+rec(jobDifficulty,n,i+1,d-1);
            finalRes=min(finalRes,res);
        }
        return dp[idx][d]=finalRes;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d)
        {
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        return rec(jobDifficulty,n,0,d);
    }
};