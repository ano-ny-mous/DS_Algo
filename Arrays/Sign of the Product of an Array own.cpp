class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sz=nums.size();
        int prod=1;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]==0)
            {
                return 0;
            } 
            else if(nums[i]<0)
            {
                prod=-prod;
            }
        }
        return prod;
    }
};