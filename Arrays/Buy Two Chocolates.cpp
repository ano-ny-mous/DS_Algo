// Approach - 1
// Time Complexity: O(n*log(n))
// Space Complexity: O(1)
class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int twoChocolatesPrice = 0;
        sort(prices.begin(), prices.end());
        twoChocolatesPrice += prices[0];
        twoChocolatesPrice += prices[1];
        if (twoChocolatesPrice <= money)
        {
            money -= twoChocolatesPrice;
            return money;
        }
        return money;
    }
};

// Approach - 2
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        long long twoChocolatesPrice = 0;
        int n = prices.size(), least = INT_MAX, secondLeast = INT_MAX, first = -1;
        for (int i = 0; i < n; i++)
        {
            if (least >= prices[i])
            {
                secondLeast = least;
                least = min(least, prices[i]);
                first = i;
            }
            else if (i != first && secondLeast >= prices[i])
            {
                secondLeast = min(secondLeast, prices[i]);
            }
        }
        twoChocolatesPrice += least;
        twoChocolatesPrice += secondLeast;
        if (twoChocolatesPrice <= money)
        {
            money -= twoChocolatesPrice;
            return money;
        }
        return money;
    }
};