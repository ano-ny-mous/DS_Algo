// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long sz = 0;
        int n = s.size();
        for (auto &ch : s)
        {
            if (isalpha(ch))
            {
                sz++;
            }
            else
            {
                sz = sz * (ch - '0');
            }
        }
        for (int i = n - 1; i >= 0 && sz > 0; i--)
        {
            k = k % sz;
            if (k == 0 && isalpha(s[i]))
            {
                return string(1, s[i]);
            }
            else if (isdigit(s[i]))
            {
                sz = sz / (s[i] - '0');
            }
            else
            {
                sz--;
            }
        }
        return "";
    }
};
