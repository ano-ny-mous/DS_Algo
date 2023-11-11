// Time Complexity: O(n)
class Solution
{
public:
    int MOD = 1e9 + 7;

    int countHomogenous(string s)
    {
        int n = s.size();
        long long total = 0, similar = 0;
        char prev = s[0];
        for (int i = 0; i < n; i++)
        {
            if (prev == s[i])
            {
                similar++;
            }
            else
            {
                prev = s[i];
                total += (((similar * (similar + 1)) / 2) % MOD);
                similar = 1;
            }
        }
        total += (((similar * (similar + 1)) / 2) % MOD);
        return total;
    }
};