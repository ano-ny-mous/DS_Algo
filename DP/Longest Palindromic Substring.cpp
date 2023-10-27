// Approach - 1

class Solution
{
public:
    bool ispalandrome(int i, int j, string &s)
    {
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        int start, maxlen = 0, n;
        n = s.size();
        string longestpal;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (ispalandrome(i, j, s))
                {
                    if (maxlen < j - i + 1)
                    {
                        start = i;
                        maxlen = j - i + 1;
                        longestpal = s.substr(start, maxlen);
                    }
                }
            }
        }
        return longestpal;
    }
};

// Approach - 2

class Solution
{
public:
    bool rec(int i, int j, string &s)
    {
        if (i > j)
        {
            return true;
        }
        if (s[i] == s[j])
        {
            return rec(i + 1, j - 1, s);
        }
        else
        {
            return false;
        }
    }
    string longestPalindrome(string s)
    {
        int start, maxlen = 0, n;
        n = s.size();
        string longestpal;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (rec(i, j, s))
                {
                    if (maxlen < j - i + 1)
                    {
                        start = i;
                        maxlen = j - i + 1;
                        longestpal = s.substr(start, maxlen);
                    }
                }
            }
        }
        return longestpal;
    }
};

// Approach - 3

class Solution
{
public:
    int dp[1001][1001];
    bool rec(int i, int j, string &s)
    {
        if (i > j)
        {
            return true;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s[i] == s[j])
        {
            return dp[i][j] = rec(i + 1, j - 1, s);
        }
        return dp[i][j] = false;
    }
    string longestPalindrome(string s)
    {
        int start, maxlen = 0, n;
        n = s.size();
        memset(dp, -1, sizeof(dp));
        string longestpal;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (rec(i, j, s))
                {
                    if (maxlen < j - i + 1)
                    {
                        start = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }
        return longestpal = s.substr(start, maxlen);
    }
};