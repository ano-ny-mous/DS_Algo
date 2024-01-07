// TLE
// Approach - 1
// Time Complexity: O(2^n)
// Space Complexity: O(n*n)
class Solution
{
public:
    int n;
    vector<vector<int>> dp;

    int rec(vector<int> &startTime, vector<int> &endTime, vector<int> &profit, int i, int prev)
    {
        if (i >= n)
            return 0;

        if (dp[i][prev] != -1)
        {
            return dp[i][prev];
        }
        int notTake = rec(startTime, endTime, profit, i + 1, prev);
        int take = 0;
        if (prev <= startTime[i])
        {
            take = profit[i] + rec(startTime, endTime, profit, i + 1, endTime[i]);
        }
        return dp[i][prev] = max(take, notTake);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        n = profit.size();
        dp.resize(n, vector<int>(n, -1));
        return rec(startTime, endTime, profit, 0, 0);
    }
};

// Approach - 2
// TLE
// Time Complexity: O(2^n)
// Space Complexity: O(n)
class Solution
{
public:
    int n;
    int dp[50001];

    int rec(vector<vector<int>> &sorted, int cur)
    {
        if (cur >= n)
            return 0;

        if (dp[cur] != -1)
        {
            return dp[cur];
        }
        int notTake = rec(sorted, cur + 1);
        int nextjob = n;
        for (int i = cur + 1; i < n; i++)
        {
            if (sorted[i][0] >= sorted[cur][1])
            {
                nextjob = i;
                break;
            }
        }
        int take = sorted[cur][2] + rec(sorted, nextjob);
        return dp[cur] = max(take, notTake);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        n = profit.size();
        vector<vector<int>> sorted(n, vector<int>(3, 0));
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            sorted[i][0] = startTime[i];
            sorted[i][1] = endTime[i];
            sorted[i][2] = profit[i];
        }
        sort(sorted.begin(), sorted.end());
        return rec(sorted, 0);
    }
};

// Approach - 3
// Time Complexity: O(2^n)
// Space Complexity: O(n)
class Solution
{
public:
    int n;
    int dp[50001];

    int binarySearch(vector<vector<int>> &sorted, int cur)
    {
        int l = cur + 1, r = n - 1, mid, ans = n + 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (sorted[mid][0] >= sorted[cur][1])
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }

    int rec(vector<vector<int>> &sorted, int cur)
    {
        if (cur >= n)
        {
            return 0;
        }
        if (dp[cur] != -1)
        {
            return dp[cur];
        }
        int notTake = rec(sorted, cur + 1);
        int nextjob = binarySearch(sorted, cur);
        int take = sorted[cur][2] + rec(sorted, nextjob);
        return dp[cur] = max(take, notTake);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        n = profit.size();
        vector<vector<int>> sorted(n, vector<int>(3, 0));
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            sorted[i][0] = startTime[i];
            sorted[i][1] = endTime[i];
            sorted[i][2] = profit[i];
        }
        sort(sorted.begin(), sorted.end());
        return rec(sorted, 0);
    }
};
