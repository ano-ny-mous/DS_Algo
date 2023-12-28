// Approach - 1
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int time = 0;
        vector<int> same;
        int n = colors.size();
        for (int i = 1; i < n; i++)
        {
            if (colors[i - 1] == colors[i])
            {
                if (same.empty())
                {
                    same.push_back(neededTime[i - 1]);
                }
                same.push_back(neededTime[i]);
                continue;
            }
            if (same.size() == 2)
            {
                time += min(same[0], same[1]);
                same.clear();
            }
            else if (!same.empty())
            {
                int maxTime = 0, sz = same.size(), sum = 0;
                for (int i = 0; i < sz; i++)
                {
                    sum += same[i];
                    maxTime = max(maxTime, same[i]);
                }
                time += sum - maxTime;
                same.clear();
            }
        }
        if (same.size() == 2)
        {
            time += min(same[0], same[1]);
        }
        else if (!same.empty())
        {
            int maxTime = 0, sz = same.size(), sum = 0;
            for (int i = 0; i < sz; i++)
            {
                sum += same[i];
                maxTime = max(maxTime, same[i]);
            }
            time += sum - maxTime;
        }
        return time;
    }
};

// Approach - 2
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int time = 0, maxTime = 0;
        bool same = false;
        int n = colors.size();
        for (int i = 1; i < n; i++)
        {
            if (colors[i - 1] == colors[i])
            {
                if (!same)
                {
                    maxTime = max(maxTime, neededTime[i - 1]);
                    same = true;
                    time += neededTime[i - 1];
                }
                time += neededTime[i];
                maxTime = max(maxTime, neededTime[i]);
            }
            else if (same)
            {
                same = false;
                time -= maxTime;
                maxTime = 0;
            }
        }
        time -= maxTime;
        return time;
    }
};