class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int stream = 1, sz = target.size(), i = 0;
        vector<string> res;
        while (i < sz && stream <= n)
        {
            res.push_back("Push");
            if (target[i] == stream)
            {
                i++;
            }
            else
            {
                res.push_back("Pop");
            }
            stream++;
        }
        return res;
    }
};