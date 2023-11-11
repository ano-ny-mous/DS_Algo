// Time Complexity: O(n)
class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int res = 0;

        for (auto &ele : left)
        {
            res = max(ele, res);
        }
        for (auto &ele : right)
        {
            res = max(res, n - ele);
        }
        return res;
    }
};