class Solution {
public:
    int maxVowels(string s, int k) {
        int sz=s.size();
        int maxcount=0;
        int i=0,j=0;
        int vcount=0;
        while(j<sz)
        {
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
            {
                vcount++;
            }
            if(j<k)
            {
                j++;
            }
            else
            {
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                    vcount--;
                }
                i++;
                j++;
            }
            maxcount=max(maxcount,vcount);
        }
        return maxcount;
    }
};