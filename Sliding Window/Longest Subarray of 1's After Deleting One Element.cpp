//Approach - 1
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int leftcount=0;
        int rightcount=0;
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            leftcount=0;
            rightcount=0;
            if(nums[i]==0)
            {
                int temp=i-1;
                while(temp>=0&&nums[temp]==1)
                {
                    leftcount++;
                    temp--;
                }

                temp=i+1;
                while(temp<n&&nums[temp]==1)
                {
                    rightcount++;
                    temp++;
                }
            }
            maxi=max((leftcount+rightcount),maxi);
        }
        sort(nums.begin(),nums.end());
        if(nums[0]==1)
        {
            return n-1;
        }
    return maxi;
    }
};

//Approach - 2
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cur=0;
        int n=nums.size();
        int maxi=0;
        int precount=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {    
                maxi=max((precount+cur),maxi);
                precount=cur;
                cur=0;
            }
            else
            {
                cur++;
            }
        }
        maxi=max((precount+cur),maxi);
        sort(nums.begin(),nums.end());
        if(nums[0]==1)
        {
            return n-1;
        }
        return maxi;
    }
};

//Approach - 3
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int i=0,j=0;
        int zero=0;
        while(j<n)
        {
            if(nums[j]==0)
            {
                zero++;
            }
            else
            {
                if(zero)
                maxi=max(maxi,j-i);
                else
                maxi=max(maxi,j-i+1);
            }
            while(zero>1)
            {
                if(nums[i]==0)
                {
                    zero--;
                }
                i++;
                
            }
            j++;
        }
        sort(nums.begin(),nums.end());
        if(nums[0]==1)
        {
            return n-1;
        }
        return maxi;
    }
};

//Approach - 4
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int i=0,j=0;
        int idx=-1;
        while(j<n)
        {
            if(nums[j]==0)
            {
                if(idx!=-1)
                {
                    i=idx+1;
                }
                idx=j;
            }
            maxi=max(maxi,j-i);
            j++;
        }
        sort(nums.begin(),nums.end());
        if(nums[0]==1)
        {
            return n-1;
        }
        return maxi;
    }
};