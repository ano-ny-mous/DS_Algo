class Solution {
public:
unordered_map<int,vector<int>> adj;
    void dfs(int u,unordered_set<int> &visited)
    {
        visited.insert(u);
        for(int &i:adj[u])
        {
            if(visited.find(i)==visited.end())
            dfs(i,visited);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int sz=bombs.size();
        
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)
            {
                if(i==j)
                continue;
                long long x1=bombs[i][0];
                long long y1=bombs[i][1];
                long long r1=bombs[i][2];
                long long x2=bombs[j][0];
                long long y2=bombs[j][1];
                long long x=abs(x1-x2)*abs(x1-x2);
                long long y=abs(y1-y2)*abs(y1-y2);
                long long distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if((long long)(r1*r1) >= distance) {
                    adj[i].push_back(j);
            }
        }
        }
        unordered_set<int> visited;
        int ans=INT_MIN;
        for(int i=0;i<sz;i++)
        {
            dfs(i,visited);
            int blast= visited.size();
            ans=max(ans,blast);
            visited.clear();
        }
        return ans;
    }
};