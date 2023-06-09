class Solution {
public:

    int binarysearch(int start,int end,vector<int> &row)
    {
        int ans=end+1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(row[mid]<0)
            {
                end=mid-1;
                ans=mid;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++)
        {
            count=count+(cols-binarysearch(0,cols-1,grid[i]));
        }
        return count;
    }
};