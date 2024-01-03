// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int m = bank.size(), prev = 0, cur = 0, lazer = 0;
        for (int i = 0; i < m; i++)
        {
            cur = 0;
            for (char &ch : bank[i])
            {
                if (ch == '1')
                {
                    cur++;
                }
            }
            if (cur != 0)
            {
                lazer += (prev * cur);
                prev = cur;
            }
        }
        return lazer;
    }
};