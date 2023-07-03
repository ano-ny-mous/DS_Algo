class Solution {
public:

    int row;
    int col;
    int ans=0;
    int nonobs=0;
    void findpath(vector<vector<int>>& grid, int i,int j, int count)
    {
        if(i<0||i>=row||j<0||j>=col||grid[i][j]==-1)
        {
            return;
        }
        
        if(grid[i][j]==2)
        {
            if(count==nonobs)
            {
                ans++;
            }
            return;       
        }

        grid[i][j]=-1;

        findpath(grid,i+1,j,count+1);
        findpath(grid,i-1,j,count+1);
        findpath(grid,i,j+1,count+1);
        findpath(grid,i,j-1,count+1);
        
        grid[i][j]=0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        bool startfound=false;
        row=grid.size();
        col=grid[0].size();
        int x,y;
        for(int i = 0; i<row; i++) {
            for(int j = 0; j<col; j++) {
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                }
                else if(grid[i][j]==0)
                {
                    nonobs++;
                }
            }
        }
        nonobs=nonobs+1;
        findpath(grid,x,y,0);
        return ans;
    }
};