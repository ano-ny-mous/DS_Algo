// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        int freq1[1001] = {0};
        int freq2[1001] = {0};
        for (int &num : nums1)
        {
            freq1[num]++;
        }
        for (int &num : nums2)
        {
            freq2[num]++;
        }
        for (int i = 0; i <= 1000; i++)
        {
            if (freq1[i] > 0 && freq2[i] > 0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};