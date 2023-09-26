// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> last(26, 0);
        vector<bool> seen(26, false);
        string ans;
        set<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            while (ans.size() > 0 && ans.back() > s[i] && last[ans.back() - 'a'] > i && !seen[s[i] - 'a'])
            {
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
                flag = true;
            }
            if (flag)
            {
                ans.push_back(s[i]);
                seen[s[i] - 'a'] = true;
            }
            else if (!seen[s[i] - 'a'])
            {
                ans.push_back(s[i]);
                seen[s[i] - 'a'] = true;
            }
        }
        return ans;
    }
};