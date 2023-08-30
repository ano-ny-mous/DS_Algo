// Time Complexity: O(n) + O(v+2e)
// Space Complexity: O(n) + O(n)
class Solution {
public:
    unordered_map<int,vector<int>> adj;

    void dfs(int u,vector<bool> &visited)
    {
        visited[u]=true;
        for(int &i:adj[u])
        {
            if(visited[i]==false)
            {
                dfs(i,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz=isConnected.size();
        vector<bool> visited(sz,false); 
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
        int province=0;
        for(int i=0;i<sz;i++)
        {
            if(visited[i]==false)
            {
                province++;
                dfs(i,visited);
            }
        }
        return province;
    }
};
