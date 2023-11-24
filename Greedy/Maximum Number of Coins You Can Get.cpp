// Time Complexity: O(nlog(n))
// Space Complexity: O(1)
class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int n = piles.size(), coins = 0;
        sort(piles.begin(), piles.end());
        for (int i = n / 3; i < n; i = i + 2)
        {
            coins += piles[i];
        }
        return coins;
    }
};