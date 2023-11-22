// Time Complexity: O(n+log(n))
// Space Complexity: O(n)
class Solution
{
public:
    const int MOD = 1e9 + 7;

    int rev(int num)
    {
        int reverse = 0;
        while (num > 0)
        {
            int rem = num % 10;
            reverse = reverse * 10 + rem;
            num /= 10;
        }
        return reverse;
    }

    int countNicePairs(vector<int> &nums)
    {
        int n = nums.size();
        int nice = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            int Rev = rev(nums[i]);
            int Val = nums[i] - Rev;
            nums[i] = Val;
        }
        for (int i = 0; i < n; i++)
        {
            nice = (nice + freq[nums[i]]) % MOD;
            freq[nums[i]]++;
        }
        return nice;
    }
};