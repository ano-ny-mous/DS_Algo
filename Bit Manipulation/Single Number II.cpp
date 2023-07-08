//Approach - 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

//Approach - 2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int bit=0;bit<32;bit++)
        {
            int zero=0;
            int nonzero=0;
            for(int i=0;i<n;i++)
            {
                int tempbit=1<<bit;
                int set=nums[i]&tempbit;
                if(set==0)
                {
                    zero++;
                }
                else
                {
                    nonzero++;
                }
            }
            if(nonzero%3!=0)
            {
                ans=(ans|1<<bit);
            }
        }
        return ans;
    }
};