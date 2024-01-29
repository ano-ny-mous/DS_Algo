// Approach - 1
// TLE
// Time Complexity: O(n^3)
// Space Complexity: O(1)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), equalToK = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                if (sum == k)
                {
                    equalToK++;
                }
            }
        }
        return equalToK;
    }
};

// Approach - 2
// Test Cases Passed But TLE
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), equalToK = 0;
        vector<int> prefix;
        prefix.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            prefix.push_back(prefix[i - 1] + nums[i]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = (i == 0) ? prefix[j] : prefix[j] - prefix[i - 1];
                if (sum == k)
                {
                    equalToK++;
                }
            }
        }
        return equalToK;
    }
};

// Approach - 3
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), equalToK = 0, prefix = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        for (int i = 0; i < n; i++)
        {
            prefix += nums[i];
            int target = prefix - k;
            if (prefixSumCount.find(target) != prefixSumCount.end())
            {
                equalToK += prefixSumCount[target];
            }
            prefixSumCount[prefix]++;
        }
        return equalToK;
    }
};