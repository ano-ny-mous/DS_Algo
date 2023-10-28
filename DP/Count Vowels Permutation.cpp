// Time Complexity: O(n)

class Solution
{
public:
    vector<vector<long long>> dp;
    int MOD = 1e9 + 7, a = 0, e = 1, i = 2, o = 3, u = 4;

    long long rec(int prev, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (dp[prev][n] != -1)
        {
            return dp[prev][n];
        }
        if (prev == a)
        {
            return dp[prev][n] = rec(e, n - 1) % MOD;
        }
        else if (prev == e)
        {
            return dp[prev][n] = (rec(a, n - 1) + rec(i, n - 1)) % MOD;
        }
        else if (prev == i)
        {
            return dp[prev][n] = (rec(a, n - 1) + rec(e, n - 1) + rec(o, n - 1) + rec(u, n - 1)) % MOD;
        }
        else if (prev == o)
        {
            return dp[prev][n] = (rec(i, n - 1) + rec(u, n - 1)) % MOD;
        }
        else if (prev == u)
        {
            return dp[prev][n] = rec(a, n - 1) % MOD;
        }
        else
        {
            return dp[prev][n] = 0;
        }
    }

    int countVowelPermutation(int n)
    {
        dp.resize(5, vector<long long>(n + 1, -1));
        long res = 0;
        res = (res + rec(a, n - 1)) % MOD;
        res = (res + rec(e, n - 1)) % MOD;
        res = (res + rec(i, n - 1)) % MOD;
        res = (res + rec(o, n - 1)) % MOD;
        res = (res + rec(u, n - 1)) % MOD;
        return res;
    }
};
