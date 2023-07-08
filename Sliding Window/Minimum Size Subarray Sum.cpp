//Approach - 1
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int miniindex=INT_MAX;
        long long sum=0;
        int i=0;
        int j=0;
        while(i<n)
        {
            if(j<n&&abs(j-i)+1<miniindex)
            {
                sum=sum+nums[j];
            }
            else
            {
                sum=0;
                i++;
                j=i;
                continue;
            }
            if(sum<target)
            {
                j++;
            }
            else
            {
                sum=0;
                miniindex=min(miniindex,abs(j-i)+1);
                i++;
                j=i;
            }
        }
        
        if(miniindex==INT_MAX)
        {
            return 0;
        }
        return miniindex;
    }
};

//Approach - 2
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int miniindex=INT_MAX;
        long long sum=0;
        int i=0;
        int j=0;
        while(j<n)
        {
           
            sum=sum+nums[j];
            
            while(sum>=target)
            {
                miniindex=min(miniindex,abs(j-i)+1);
                if(i<n)
                {
                    sum=sum-nums[i];
                    i++;
                }
                else
                {
                    break;
                }
            }
            if(sum<target)
            {
                j++;
            }
            
        }
        
        if(miniindex==INT_MAX)
        {
            return 0;
        }
        return miniindex;
    }
};