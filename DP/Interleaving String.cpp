// Time Complexity: O(m*n)
// Space Complexiy: O(1)
class Solution
{
public:
    int s1len, s2len, s3len;
    int dp[101][101];

    bool rec(string &s1, string &s2, string &s3, int i, int j)
    {
        if (i == s1len && j == s2len && i + j == s3len)
        {
            return dp[i][j] = true;
        }
        if (i + j >= s3len)
        {
            return false;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        bool take = false;
        if (i < s1len && s1[i] == s3[i + j])
        {
            take = rec(s1, s2, s3, i + 1, j);
        }
        if (take)
        {
            return dp[i][j] = take;
        }
        if (j < s2len && s2[j] == s3[i + j])
        {
            take = rec(s1, s2, s3, i, j + 1);
        }
        return dp[i][j] = take;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        s1len = s1.size();
        s2len = s2.size();
        s3len = s3.size();
        if (s3len != s1len + s2len)
        {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return rec(s1, s2, s3, 0, 0);
    }
};