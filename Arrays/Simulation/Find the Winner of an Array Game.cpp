// Time Complexity: O(n*n*k)
class Solution
{
public:
    void rotate(vector<int> &arr, int n)
    {
        int temp = arr[1];
        for (int i = 1; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
    }

    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size(), winCount = 0, prevVal = -1;
        while (k != winCount)
        {
            if (arr[0] < arr[1])
            {
                swap(arr[0], arr[1]);
            }
            rotate(arr, n);
            if (prevVal != -1 && prevVal == arr[0])
            {
                winCount++;
            }
            else
            {
                winCount = 1;
                prevVal = arr[0];
            }
        }
        return arr[0];
    }
};

// Time Complexity: O(n*k)
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size(), winCount = 0, prevVal = -1, cur = 1;
        bool flag = false;
        flag = k < n;
        while (flag && k != winCount)
        {
            cur = cur % n;
            if (cur == 0)
            {
                cur = 1;
            }
            if (arr[0] < arr[cur])
            {
                swap(arr[0], arr[cur]);
            }
            cur++;
            if (prevVal != -1 && prevVal == arr[0])
            {
                winCount++;
            }
            else
            {
                winCount = 1;
                prevVal = arr[0];
            }
        }
        if (flag)
            return arr[0];
        return *max_element(arr.begin(), arr.end());
    }
};

// Time Complexity: O(n)
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size(), winCount = 0, maxElement, winner = arr[0];
        maxElement = *max_element(arr.begin(), arr.end());
        if (k >= n)
        {
            return maxElement;
        }
        for (int i = 1; i < n; i++)
        {
            if (winner < arr[i])
            {
                winner = arr[i];
                winCount = 1;
            }
            else
            {
                winCount++;
            }
            if (winner == maxElement || winCount == k)
            {
                return winner;
            }
        }
        return -1;
    }
};
