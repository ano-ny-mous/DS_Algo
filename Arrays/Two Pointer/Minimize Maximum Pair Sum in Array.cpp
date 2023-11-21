// Time Complexity: O(nlog(n))
// Space Complexity: O(1)
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int minSum = INT_MIN, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0, j = n - 1; i < n / 2; i++, j--)
        {
            int sum = nums[i] + nums[j];
            minSum = max(minSum, sum);
        }
        return minSum;
    }
};