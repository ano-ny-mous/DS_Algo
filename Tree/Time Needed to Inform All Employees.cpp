class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int res=0;
    void dfs(int u,vector<bool> &visited,int time,vector<int>& informTime)
    {
        cout<<u<<" "<<time<<endl;
        visited[u]=true;
        res=max(res,time);
        for(int &i:adj[u])
        {
            if(visited[i]==false)
            dfs(i,visited,time+informTime[i],informTime);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<n;i++)
        {
            adj[manager[i]].push_back(i);
            //cout<<manager[i]<<" "<<i<<endl;
        }
        vector<bool> visited(n,false);
        dfs(headID,visited,informTime[headID],informTime);
        return res;
    }
};