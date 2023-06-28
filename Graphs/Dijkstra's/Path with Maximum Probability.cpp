//Time Complexity: O(E*log(V)) E->edges V->vertices
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>> pq;
        unordered_map<int,vector<pair<int,double>>> mp;
        vector<double> res(n,0);

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            mp[u].push_back({v,succProb[i]});
            mp[v].push_back({u,succProb[i]});
        }

        res[start]=1;
        pq.push({1.0,start});

        while(!pq.empty())
        {
            double prob=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &nei:mp[node])
            {
                int adjv=nei.first;
                double adjp=nei.second;
                if(res[adjv]<adjp*prob)
                {
                    res[adjv]=adjp*prob;
                    pq.push({res[adjv],adjv});
                }
            }
        }
        
        return res[end];
    }
};