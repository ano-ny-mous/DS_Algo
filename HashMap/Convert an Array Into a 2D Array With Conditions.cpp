// Approach - 1
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int &num : nums)
        {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }
        vector<vector<int>> ans(maxFreq);
        for (auto &fre : freq)
        {
            int count = fre.second;
            int number = fre.first;
            while (count)
            {
                count--;
                ans[count].push_back(number);
            }
        }
        return ans;
    }
};

// Approach - 2
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        vector<vector<int>> ans;
        for (int &num : nums)
        {
            int row = freq[num];
            if (row == ans.size())
            {
                ans.push_back({});
            }
            ans[row].push_back(num);
            freq[num]++;
        }
        return ans;
    }
};

// Approach - 3
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> mp(n + 1, 0);
        vector<vector<int>> ans;
        for (int &num : nums)
        {
            int row = mp[num];
            if (row == ans.size())
            {
                ans.push_back({});
            }
            ans[row].push_back(num);
            mp[num]++;
        }
        return ans;
    }
};