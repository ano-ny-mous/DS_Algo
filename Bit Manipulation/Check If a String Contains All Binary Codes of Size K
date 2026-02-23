//Time Complexity: O(n*k)
//Space Complexity: O((2^k)*k)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        int codes=pow(2,k);
        unordered_set<string> bits;
        for(int i=k;i<=n;i++)
        {
            string substring=s.substr(i-k,k);
            bits.insert(substring);
            if(bits.size()==codes)
            {
                return true;
            }
        }
        return false;
    }
};
