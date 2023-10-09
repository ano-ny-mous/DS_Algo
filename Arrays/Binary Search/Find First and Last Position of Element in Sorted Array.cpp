// Apporach - 1
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size(), i = 0, j = n - 1, start = -1, end = -1;
        while (start == -1 && i < n)
        {
            if (nums[i] == target)
            {
                start = i;
            }
            i++;
        }
        while (end == -1 && j >= 0 && j >= start)
        {
            if (nums[j] == target)
            {
                end = j;
            }
            j--;
        }
        return {start, end};
    }
};

// Apporach - 2
// Time Complexity: O(log(n))
// Space Complexity: O(1)
class Solution
{
public:
    int startpos = -1, endpos = -1;

    int binarysearch(int start, int end, int target, vector<int> &nums)
    {
        int mid, res = -1;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] >= target)
            {
                if (nums[mid] == target)
                {
                    res = mid;
                }
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size(), i = 0, j = n - 1;
        startpos = binarysearch(i, j, target, nums);
        if (startpos != -1)
        {
            endpos = startpos;
            while (endpos + 1 < n)
            {
                if (nums[++endpos] != target)
                {
                    endpos--;
                    break;
                }
            }
        }
        return {startpos, endpos};
    }
};