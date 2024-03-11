// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    string customSortString(string order, string s)
    {
        string res;
        int freq[27] = {0};
        for (char &ch : s)
        {
            freq[ch - 'a']++;
        }
        for (char &ch : order)
        {
            if (freq[ch - 'a'] > 0)
            {
                res += string(freq[ch - 'a'], ch);
                freq[ch - 'a'] = 0;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                res += string(freq[i], i + 'a');
            }
        }
        return res;
    }
};