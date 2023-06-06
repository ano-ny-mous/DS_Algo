class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int sz=arr.size();
        sort(arr.begin(),arr.end());
        int globald=arr[1]-arr[0];
        for(int i=0;i<sz-1;i++)
        {
            int tempd=arr[i+1]-arr[i];
            if(tempd!=globald)
            {
                return false;
            }
        }
        return true;
    }
};