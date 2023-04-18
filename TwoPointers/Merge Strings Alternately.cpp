class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merge="";
        int i=0;
        int j=0;
        int sz1=word1.size();
        int sz2=word2.size();
        while(i<sz1&&j<sz2)
        {
            merge.push_back(word1[i]);
            merge.push_back(word2[j]);
            i++;
            j++;
        }
        while(i<sz1)
        {
            merge.push_back(word1[i]);
            i++;
        }
        while(j<sz2)
        {
            merge.push_back(word2[j]);
            j++;
        }
        return merge;
    }
};