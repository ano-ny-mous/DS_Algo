// Approach - 1
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int op = 0;
        unordered_map<int, int> freq;
        for (int &num : nums)
        {
            freq[num]++;
        }
        for (auto &num_count : freq)
        {
            int count = num_count.second;
            while (count)
            {
                if (count % 3 == 0)
                {
                    op += count / 3;
                    break;
                }
                else if (count == 1)
                {
                    return -1;
                }
                else
                {
                    op++;
                    count -= 2;
                }
            }
        }
        return op;
    }
};

// Approach - 2
// Time Complexity: O(nlog(n))
// Space Complexity: O(1)
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int op = 0, idx = 0, counter = 0, n = nums.size(), count = 0, prev;
        sort(nums.begin(), nums.end());
        prev = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (prev == nums[i])
            {
                count++;
            }
            else
            {
                if (count == 1)
                {
                    return -1;
                }
                nums[idx] = count;
                idx++;
                count = 1;
                prev = nums[i];
            }
        }
        if (count != 1)
        {
            nums[idx] = count;
        }
        else
        {
            return -1;
        }
        for (int i = 0; i <= idx; i++)
        {
            int count = nums[i];
            while (count)
            {
                if (count % 3 == 0)
                {
                    op += count / 3;
                    break;
                }
                else
                {
                    op++;
                    count -= 2;
                }
            }
        }
        return op;
    }
};

// Approach - 3
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int op = 0;
        unordered_map<int, int> freq;
        for (int &num : nums)
        {
            freq[num]++;
        }
        for (auto &num_count : freq)
        {
            int count = num_count.second;
            if (count == 1)
            {
                return -1;
            }
            op += ceil((double)count / 3);
        }
        return op;
    }
};