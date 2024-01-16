// Time Complexity: O(1)
// Space Complexity: O(2n)
class RandomizedSet
{
public:
    unordered_map<int, int> mp;
    vector<int> arr;

    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
        {
            return false;
        }
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (mp.find(val) != mp.end())
        {
            int index = mp[val];
            int back = arr.back();
            arr[index] = back;
            mp[back] = index;
            arr.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        if (arr.size() != 0)
            return arr[rand() % arr.size()];
        return 0;
    }
};
