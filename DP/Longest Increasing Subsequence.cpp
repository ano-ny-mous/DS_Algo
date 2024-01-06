// Approach - 1
// Time Complexity: O(2^n)
// Space Complexity: O(n)
class Solution
{
public:
    int n;
    vector<vector<int>> dp;
    int rec(vector<int> &nums, int i, int prev)
    {
        if (i >= n)
        {
            return 0;
        }
        if (prev != -1 && dp[i][prev] != -1)
        {
            return dp[i][prev];
        }
        int take = 0;

        if (prev == -1 || nums[i] > nums[prev])
        {
            take = 1 + rec(nums, i + 1, i);
        }
        int nottake = rec(nums, i + 1, prev);
        if (prev != -1)
        {
            return dp[i][prev] = max(take, nottake);
        }
        return max(take, nottake);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        n = nums.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return rec(nums, 0, -1);
    }
};

// Approach - 2
// Time Complexity: O(nlog(n))
// Space Complexity: O(n)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> bucket;
        for (int num : nums)
        {
            auto nearMax = lower_bound(begin(bucket), end(bucket), num);
            if (nearMax == bucket.end())
            {
                bucket.push_back(num);
            }
            else
            {
                *nearMax = num;
            }
        }
        return bucket.size();
    }
};