//Approach - 1
//Time Complexity: O(log(n))
//Space Complexity: O(1)
class Solution {
public:
    int binaryGap(int n) {
        int prev=-1, res=0;
        for(int i=0;n>0;i++)
        {
            int value=n%2;
            n=n>>1;
            if(value)
            {
                if(prev>=0)
                {
                    res=max(res,i-prev);
                }
                prev=i;
            }
        }
        return res;
    }
};

//Approach - 2
//Time Complexity: O(1)
//Space Complexity: O(1)
class Solution {
public:
    int binaryGap(int n) {
        int prev=-1, res=0;
        for(int i=0;i<32;i++)
        {
            int value=n%2;
            n=n>>1;
            if(value)
            {
                if(prev>=0)
                {
                    res=max(res,i-prev);
                }
                prev=i;
            }
        }
        return res;
    }
};
