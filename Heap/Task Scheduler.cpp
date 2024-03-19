// Time Complexity: O(n) + log(size(26))
// Space Complexity: O(n)
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        priority_queue<int> pq;
        unordered_map<char, int> freq;
        int count = 0;
        for (char &ch : tasks)
        {
            freq[ch]++;
        }
        for (auto &keyVal : freq)
        {
            pq.push(keyVal.second);
        }
        while (!pq.empty())
        {
            vector<int> temp;
            for (int i = 0; i < n + 1; i++)
            {
                if (!pq.empty())
                {
                    int freq = pq.top();
                    freq--;
                    temp.push_back(freq);
                    pq.pop();
                }
            }
            for (int &num : temp)
            {
                if (num > 0)
                {
                    pq.push(num);
                }
            }
            if (!pq.empty())
            {
                count += n + 1;
            }
            else
            {
                count += temp.size();
            }
        }
        return count;
    }
};