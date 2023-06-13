class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int sz=grid.size();
        unordered_map<int,vector<int>> row;
        unordered_map<int,vector<int>> col;
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)
            {
                row[i].push_back(grid[i][j]);
            }
        }
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)
            {
                col[j].push_back(grid[i][j]);
            }
        }
        int counter=0;
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)
            {
                if(row[i]==col[j])
                {
                    counter++;
                }
            }
        }
        return counter;
    }
};