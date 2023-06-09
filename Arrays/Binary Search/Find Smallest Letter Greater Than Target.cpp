class Solution {
public:

    char binarysearch(int start,int end,vector<char>& letters, char target)
    {
        char ans=letters[start];
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(letters[mid]>target)
            {
                end=mid-1;
                ans=letters[mid];
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        int sz=letters.size();
        return binarysearch(0,sz-1,letters,target);
    }
};