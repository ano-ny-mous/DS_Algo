// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        string notPresent;
        for (int i = 0; i < n; i++)
        {
            if (nums[i][i] == '1')
            {
                notPresent.push_back('0');
            }
            else
            {
                notPresent.push_back('1');
            }
        }
        return notPresent;
    }
};