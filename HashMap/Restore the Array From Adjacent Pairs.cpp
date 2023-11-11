class Solution
{
public:
    vector<int> res;

    void dfs(unordered_map<int, vector<int>> &adj, int u, unordered_map<int, bool> &visited)
    {
        if (!visited[u])
        {
            visited[u] = true;
            res.push_back(u);
        }
        for (auto &child : adj[u])
        {
            if (!visited[child])
            {
                dfs(adj, child, visited);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> visited;
        int startIndex = INT_MIN;
        for (auto &pair : adjacentPairs)
        {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        for (auto &unique : adj)
        {
            auto child = unique.second;
            if (child.size() == 1)
            {
                startIndex = unique.first;
                break;
            }
        }
        dfs(adj, startIndex, visited);
        return res;
    }
};

class Solution
{
public:
    vector<int> res;

    void dfs(unordered_map<int, vector<int>> &adj, int u, int prev)
    {
        res.push_back(u);
        for (auto &child : adj[u])
        {
            if (child != prev)
            {
                dfs(adj, child, u);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> visited;
        int startIndex = INT_MIN;
        for (auto &pair : adjacentPairs)
        {
            int u = pair[0], v = pair[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (auto &unique : adj)
        {
            auto child = unique.second;
            if (child.size() == 1)
            {
                startIndex = unique.first;
                break;
            }
        }
        dfs(adj, startIndex, INT_MIN);
        return res;
    }
};