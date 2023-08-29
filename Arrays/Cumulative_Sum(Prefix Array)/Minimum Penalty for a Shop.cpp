// Approach - 1
// TLE
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();
        int minhour = 0;
        int minPenality = INT_MAX;
        int hour = 0;
        while (hour <= n)
        {
            int penality = 0;
            for (int i = hour; i < n; i++)
            {
                if (customers[i] == 'Y')
                {
                    penality++;
                }
            }
            for (int j = hour - 1; j >= 0; j--)
            {
                if (customers[j] == 'N')
                {
                    penality++;
                }
            }
            if (penality < minPenality)
            {
                minPenality = penality;
                minhour = hour;
            }
            hour++;
            cout << penality << endl;
        }
        int lastPenalityNth = count(begin(customers), end(customers), 'N');
        if (lastPenality < minPenality)
        {
            lastPenality = minPenality;
            minhour = n;
        }
        return minhour;
    }
};

// Approach - 2
// Time Complexity: O(n) + O(n) + O(n)
// Space Complexity: O(n) + O(n)
class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();
        vector<int> prefix(n + 1);
        vector<int> suffix(n + 1);
        int minhour = -1;
        int penality = INT_MAX;
        prefix[0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'N')
            {
                prefix[i + 1] = prefix[i] + 1;
            }
            else
            {
                prefix[i + 1] = prefix[i];
            }
        }
        suffix[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (customers[i] == 'Y')
            {
                suffix[i] = suffix[i + 1] + 1;
            }
            else
            {
                suffix[i] = suffix[i + 1];
            }
        }
        for (int i = 0; i < n + 1; i++)
        {
            if (penality > prefix[i] + suffix[i])
            {
                minhour = i;
                penality = prefix[i] + suffix[i];
            }
        }
        return minhour;
    }
};

// Approach - 3
// Time Complexity: O(n) + O(n)
// Space Complexity: O(1)
class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();
        int minhour = 0;
        int yesCount = count(begin(customers), end(customers), 'Y');
        int minPenality = yesCount;
        int penality = yesCount;
        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'Y')
            {
                penality--;
            }
            else
            {
                penality++;
            }
            if (minPenality > penality)
            {
                minPenality = penality;
                minhour = i + 1;
            }
        }
        return minhour;
    }
};