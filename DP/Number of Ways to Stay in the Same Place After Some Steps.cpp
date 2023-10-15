// Time Complexity: O(3^n)
// Space Complexity: O(steps*min(n,steps))
class Solution
{
public:
    int ways = 0, n;
    const unsigned int MOD = 1000000007;
    vector<vector<int>> dp;

    int rec(int steps, int idx)
    {
        if (idx < 0 || idx >= n)
        {
            return 0;
        }
        if (steps == 0)
        {
            if (idx == 0)
            {
                return 1;
            }
            return 0;
        }
        if (dp[steps][idx] != -1)
        {
            return dp[steps][idx];
        }
        return dp[steps][idx] = ((rec(steps - 1, idx - 1)) % MOD + (rec(steps - 1, idx)) % MOD + (rec(steps - 1, idx + 1)) % MOD) % MOD;
    }

    int numWays(int steps, int arrLen)
    {
        n = arrLen;
        int maxpos = min(n, steps);
        dp.resize(steps + 1, vector<int>(maxpos + 1, -1));
        return rec(steps, 0);
    }
};