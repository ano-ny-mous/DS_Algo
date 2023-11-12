class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> res(V, INT_MAX);
        res[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int dist = cur.first;
            int node = cur.second;
            for (auto &nei : adj[node])
            {
                int adjnode = nei[0];
                int wt = nei[1];
                if (dist + wt < res[adjnode])
                {
                    res[adjnode] = dist + wt;
                    pq.push({dist + wt, adjnode});
                }
            }
        }
        return res;
    }
};