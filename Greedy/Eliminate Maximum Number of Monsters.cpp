// Time Complexity: O(nlog(n))
// Space Complexity: O(n)
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size(), monsters = 1, unitTime = 1;
        vector<int> time;
        for (int i = 0; i < n; i++)
        {
            time.push_back(ceil((float)dist[i] / speed[i]));
        }
        sort(time.begin(), time.end());
        for (int i = 1; i < n; i++, unitTime++)
        {
            if (time[i] - unitTime <= 0)
            {
                return monsters;
            }
            monsters++;
        }
        return monsters;
    }
};