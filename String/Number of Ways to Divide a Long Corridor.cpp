// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    const int MOD = 1e9 + 7;

    int numberOfWays(string corridor)
    {
        int n = corridor.size(), sz, prev;
        long long ways = 1;
        vector<int> sIndex;
        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
            {
                sIndex.push_back(i);
            }
        }
        sz = sIndex.size();
        if (sz % 2 != 0 || sz == 0)
        {
            return 0;
        }
        prev = sIndex[1];
        for (int i = 2; i < sz; i += 2)
        {
            ways = (ways * (sIndex[i] - prev)) % MOD;
            prev = sIndex[i + 1];
        }
        return ways;
    }
};