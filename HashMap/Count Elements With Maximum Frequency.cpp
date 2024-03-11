// Time Complexity: O(n+m)
// Space Complexity: O(1)
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int freq[101] = {0}, maxFreq = INT_MIN, count = 0;
        for (int &num : nums)
        {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }
        for (int &fre : freq)
        {
            if (fre == maxFreq)
            {
                count++;
            }
        }
        return count * maxFreq;
    }
};
