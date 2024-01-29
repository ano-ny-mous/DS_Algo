// Approach - 1
// TLE
// Time Complexity: O(m^2*n^2)
// Space Complexity: O(1)
class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int rsz = matrix.size(), csz = matrix[0].size(), equalToK = 0;
        for (int rs = 0; rs < rsz; rs++)
        {
            for (int cs = 0; cs < csz; cs++)
            {
                for (int re = rs; re < rsz; re++)
                {
                    for (int ce = cs; ce < csz; ce++)
                    {
                        int sum = 0;
                        for (int i = rs; i <= re; i++)
                        {
                            for (int j = cs; j <= ce; j++)
                            {
                                sum += matrix[i][j];
                            }
                        }
                        if (sum == target)
                        {
                            equalToK++;
                        }
                    }
                }
            }
        }
        return equalToK;
    }
};

// Approach - 2
// Time Complexity: O(n*n*m)
// Space Complexity: O(m)
class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int rsz = matrix.size(), csz = matrix[0].size(), equalToK = 0;
        for (int r = 0; r < rsz; r++)
        {
            for (int c = 1; c < csz; c++)
            {
                matrix[r][c] += matrix[r][c - 1];
            }
        }
        for (int sc = 0; sc < csz; sc++)
        {
            for (int j = sc; j < csz; j++)
            {
                int cumSum = 0;
                unordered_map<int, int> prefixSumCount;
                prefixSumCount[0] = 1;
                for (int r = 0; r < rsz; r++)
                {
                    cumSum += matrix[r][j] - (sc > 0 ? matrix[r][sc - 1] : 0);
                    int search = cumSum - target;
                    if (prefixSumCount.find(search) != prefixSumCount.end())
                    {
                        equalToK += prefixSumCount[search];
                    }
                    prefixSumCount[cumSum]++;
                }
            }
        }
        return equalToK;
    }
};