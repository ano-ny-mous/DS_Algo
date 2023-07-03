class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if(s==goal)
        {
            set<char> freq;
            for(int k=0;k<s.size();k++)
            {
                freq.insert(s[k]);
            }

            if(freq.size()<s.size())
            {
                return true;
            }
        }

        unordered_map<char,int> freq;
        int maxi=0;
        vector<int> swapind;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
            {
                swapind.push_back(i);
            }
        }

        if(swapind.size()==2)
        {
            swap(s[swapind[0]],s[swapind[1]]);
            if(s==goal)
            {
                return true;
            }
        }
        return false;
    }
};