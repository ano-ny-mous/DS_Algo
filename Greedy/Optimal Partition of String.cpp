class Solution {
public:
    int partitionString(string s) {
        int count=0;
        unordered_set<char> uniq;
        int sz=s.size();
        for(int i=0;i<sz;i++)
        {
            if(uniq.find(s[i])==uniq.end())
            {
                uniq.insert(s[i]);
            }
            else
            {
                count++;
                uniq.clear();
                uniq.insert(s[i]);
            }
        }
        return count+1;
    }
};