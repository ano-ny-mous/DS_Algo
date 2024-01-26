// Time Complexity: O(4^maxMove)
// Space Complexity: O(m*n*maxMove)
class Solution
{
public:
    const int MOD = 1000000007;
    int M, N;
    int dp[51][51][51];
    long long move(int i, int j, int moves)
    {
        if ((i >= M || j >= N || i < 0 || j < 0) && moves >= 0)
        {
            return 1;
        }
        if (moves < 0)
        {
            return 0;
        }
        if (dp[i][j][moves] != -1)
        {
            return dp[i][j][moves];
        }
        return (dp[i][j][moves] =
                    (move(i + 1, j, moves - 1) % MOD +
                     move(i - 1, j, moves - 1) % MOD +
                     move(i, j + 1, moves - 1) % MOD +
                     move(i, j - 1, moves - 1) % MOD) %
                    MOD);
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        M = m;
        N = n;
        memset(dp, -1, sizeof(dp));
        return move(startRow, startColumn, maxMove);
    }
};