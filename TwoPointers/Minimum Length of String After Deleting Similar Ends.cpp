// Approach - 1
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.size(), i = 0, j = n - 1;
        while (i < j && s[i] == s[j])
        {
            char ch = s[i];
            while (i <= j && s[i] == ch)
            {
                i++;
            }
            while (i <= j && s[j] == ch)
            {
                j--;
            }
        }
        return j - i + 1;
    }
};

// Approach - 2
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int minimumLength(string s)
    {
        deque<char> myDeque;
        for (char &ch : s)
        {
            myDeque.push_back(ch);
        }
        while (myDeque.size() > 1 && myDeque.front() == myDeque.back())
        {
            char ch = myDeque.front();
            while (!myDeque.empty() && ch == myDeque.back())
            {
                myDeque.pop_back();
            }
            while (!myDeque.empty() && ch == myDeque.front())
            {
                myDeque.pop_front();
            }
        }
        return myDeque.size();
    }
};
