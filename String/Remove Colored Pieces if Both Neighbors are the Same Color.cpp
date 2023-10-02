// Time Complexity: O(n)
// Space Compexity: O(1)

class Solution
{
public:
    int acount = 0, bcount = 0;

    void countab(string &colors)
    {
        for (int i = 0; i < colors.size() - 2 && i < colors.size() - 1; i++)
        {
            if (colors[i] == colors[i + 1] && colors[i + 1] == colors[i + 2])
            {
                if (colors[i] == 'A')
                {
                    acount++;
                }
                else
                {
                    bcount++;
                }
            }
        }
    }

    bool winnerOfGame(string colors)
    {
        countab(colors);
        if (acount > bcount)
        {
            return true;
        }
        return false;
    }
};