// Approach - 1
// Time Complexity: O(nlog(n))
// Space Complexity: O(2*n)
class Solution
{
public:
    string sortVowels(string s)
    {
        vector<int> vowelIndex;
        int n = s.size(), ind = 0;
        vector<char> allVowels;
        for (int i = 0; i < n; i++)
        {
            char vowelCheck = tolower(s[i]);
            if (vowelCheck == 'a' || vowelCheck == 'e' || vowelCheck == 'i' || vowelCheck == 'o' || vowelCheck == 'u')
            {
                vowelIndex.push_back(i);
                allVowels.push_back(s[i]);
            }
        }
        sort(allVowels.begin(), allVowels.end());
        for (auto &ch : allVowels)
        {
            s[vowelIndex[ind]] = ch;
            ind++;
        }
        return s;
    }
};

// Approach - 2
// Time Complexity: O(nlog(n))
// Space Complexity: O(n)
class Solution
{
public:
    string sortVowels(string s)
    {
        int n = s.size(), ind = 0;
        vector<char> allVowels;
        for (auto &ch : s)
        {
            char vowelCheck = tolower(ch);
            if (vowelCheck == 'a' || vowelCheck == 'e' || vowelCheck == 'i' || vowelCheck == 'o' || vowelCheck == 'u')
            {
                allVowels.push_back(ch);
            }
        }
        sort(allVowels.begin(), allVowels.end());
        for (auto &ch : s)
        {
            char vowelCheck = tolower(ch);
            if (vowelCheck == 'a' || vowelCheck == 'e' || vowelCheck == 'i' || vowelCheck == 'o' || vowelCheck == 'u')
            {
                ch = allVowels[ind];
                ind++;
            }
        }
        return s;
    }
};

// Approach - 3
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    string sortVowels(string s)
    {
        string vowel = "AEIOUaeiou";
        int n = s.size(), i = 0, j = 0, m = vowel.size();
        unordered_map<char, int> mp;
        for (auto &ch : s)
        {
            char vowelCheck = tolower(ch);
            if (vowelCheck == 'a' || vowelCheck == 'e' || vowelCheck == 'i' || vowelCheck == 'o' || vowelCheck == 'u')
            {
                mp[ch]++;
            }
        }
        while (i < n && j < m)
        {
            char vowelCheck = tolower(s[i]);
            if (vowelCheck == 'a' || vowelCheck == 'e' || vowelCheck == 'i' || vowelCheck == 'o' || vowelCheck == 'u')
            {
                while (mp[vowel[j]] == 0)
                {
                    j++;
                }
                s[i] = vowel[j];
                mp[vowel[j]]--;
            }
            i++;
        }
        return s;
    }
};