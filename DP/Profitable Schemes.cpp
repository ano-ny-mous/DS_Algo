class Solution {
public:
    int sz;
    int tprofit;
    int tppl;
    int dp[101][101][101];
    const int MOD=1e9+7;

    int rec(int idx,int totalppl, int totalpro, vector<int>& group, vector<int>& profit)
    {
        
        if(totalppl>tppl)
        {
            return 0;
        }
        if(idx==sz)
        {
            if(totalpro<tprofit)
            {
                return 0;
            }
            return 1;
        }
        if(dp[idx][totalppl][totalpro]!=-1)
        {
            return dp[idx][totalppl][totalpro];
        }
       
        unsigned long long ntk =rec(idx+1,totalppl,totalpro,group,profit)%MOD;
        unsigned long long tk = rec(idx+1,totalppl+group[idx],min(totalpro+profit[idx],tprofit),group,profit)%MOD;
        return dp[idx][totalppl][totalpro]=((tk%MOD)+(ntk%MOD))%MOD;
        
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        tppl=n;
        tprofit=minProfit;
        sz=group.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,group,profit);
    }
};