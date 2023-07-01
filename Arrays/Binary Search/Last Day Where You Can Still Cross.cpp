//Brute Force
class Solution {
public:
    int ROW;
    int COL;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<int>> grid, int i, int j) {
        
        if(i < 0 || i >= ROW || j < 0 || j >= COL || grid[i][j] == 1) {
            return false;
        }
        
        if(i == ROW-1)
            return true;
        
        grid[i][j] = 1;
        for(vector<int> &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if(dfs(grid, new_i, new_j))
                return true;
        }
        
        
        return false;
    }
      

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int day=0;
        ROW=row;
        COL=col;
        dfs(cells,0,0);
	    vector<int> temp(COL, 0);
	    vector<vector<int>> temp2d(ROW, temp);
        for(int i=0;i<cells.size();i++)
        {
            vector<int> ones=cells[i];
            temp2d[ones[0]-1][ones[1]-1]=1;
            for(int k=0;k<COL;k++)
            {
                if(dfs(temp2d,0,k))
                {
                    day++;
                    break;
                }
            }
        }
    return day;
    }
};


//Optimal
class Solution {
public:
    int ans;
    int day=0;
    int ROW;
    int COL;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<int>> &grid, int i, int j) {
        
        if(i < 0 || i >= ROW || j < 0 || j >= COL || grid[i][j] == 1) {
            return false;
        }
        
        if(i == ROW-1)
            return true;
        
        grid[i][j] = 1;
        for(vector<int> &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if(dfs(grid, new_i, new_j))
                return true;
        }
        return false;
    }
    
    void binarysearch(int start,int end,vector<vector<int>>& cells)
    {
        ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(checkpos(mid,cells))
            {
                ans=mid;
                start=mid+1;
                
            }
            else
            {
                end=mid-1;
            }
        }
    }

    bool checkpos(int mid,vector<vector<int>>& cells)
    {
        vector<int> temp(COL, 0);
	    vector<vector<int>> temp2d(ROW, temp);
        for(int i=0;i<mid;i++)
        {
            vector<int> ones=cells[i];
            temp2d[ones[0]-1][ones[1]-1]=1;
        }
        for(int k=0;k<COL;k++)
            {
                if(temp2d[0][k]==0&&dfs(temp2d,0,k))
                {
                    return true;
                }
            }
        return false;
    }
    

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW=row;
        COL=col;
        binarysearch(0,cells.size()-1,cells);
        return ans;
    }
};