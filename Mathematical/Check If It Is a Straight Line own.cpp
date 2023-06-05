class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int sz=coordinates.size();
        for(int i=0;i<sz-2;i++)
        {
            int xl=coordinates[i][0];
            int xm=coordinates[i+1][0];
            int yl=coordinates[i][1];
            int ym=coordinates[i+1][1];
            int xr=coordinates[i+2][0];
            int yr=coordinates[i+2][1];
            if((ym-yl)*(xr-xm)!=(yr-ym)*(xm-xl))
            {
                return false;
            }
        }
        return true;
    }
};