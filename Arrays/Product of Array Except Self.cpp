// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);
        int prefixProd = 1;
        int suffixProd = 1;

        for (int i = 0; i < n; ++i)
        {
            answer[i] *= prefixProd;
            prefixProd *= nums[i];
        }

        for (int i = n - 1; i >= 0; --i)
        {
            answer[i] *= suffixProd;
            suffixProd *= nums[i];
        }
        return answer;
    }
};