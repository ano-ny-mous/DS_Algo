// Approach - 1
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        int n = arr.size();
        map<int, vector<int>> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            long long bit = 1;
            int counter = 0;
            for (int j = 0; j < 32; j++)
            {
                if (bit & arr[i])
                {
                    counter++;
                }
                bit = bit * 2;
            }
            mp[counter].push_back(arr[i]);
        }
        for (auto &ele : mp)
        {
            auto &vec = ele.second;
            sort(vec.begin(), vec.end());
        }
        for (auto &ele : mp)
        {
            for (auto &vec : ele.second)
            {
                ans.push_back(vec);
            }
        }
        return ans;
    }
};

// Approach - 2
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        int n = arr.size();
        map<int, vector<int>> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int counter = 0, num = arr[i];
            while (num > 0)
            {
                counter += (num & 1);
                num >>= 1;
            }
            mp[counter].push_back(arr[i]);
        }
        for (auto &ele : mp)
        {
            auto &vec = ele.second;
            sort(vec.begin(), vec.end());
        }
        for (auto &ele : mp)
        {
            for (auto &vec : ele.second)
            {
                ans.push_back(vec);
            }
        }
        return ans;
    }
};

// Approach - 3
class Solution
{
public:
    int countSetBits(int num)
    {
        int counter = 0;
        while (num > 0)
        {
            counter += (num & 1);
            num >>= 1;
        }
        return counter;
    }

    vector<int> sortByBits(vector<int> &arr)
    {
        auto lambda = [&](int &a, int &b)
        {
            int ca = countSetBits(a);
            int cb = countSetBits(b);
            if (ca == cb)
            {
                return a < b;
            }
            return ca < cb;
        };

        sort(arr.begin(), arr.end(), lambda);

        return arr;
    }
};

// Approach - 4
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        auto lambda = [&](int &a, int &b)
        {
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);
            if (ca == cb)
            {
                return a < b;
            }
            return ca < cb;
        };

        sort(arr.begin(), arr.end(), lambda);

        return arr;
    }
};