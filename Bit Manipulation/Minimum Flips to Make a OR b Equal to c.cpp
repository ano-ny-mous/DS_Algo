class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip=0;
        while(c>0||a>0||b>0)
        {
            int bit1=(a&1);
            int bit2=(b&1);
            int bit3=(c&1);
            if(bit1==0&&bit2==0&&bit3==1)
            {
                flip++;
            }
            else if(bit1==1&&bit2==0&&bit3==0)
            {
                flip++;
            }
            else if(bit1==0&&bit2==1&&bit3==0)
            {
                flip++;
            }
            else if(bit1==1&&bit2==1&&bit3==0)
            {
                flip++;
                flip++;
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return flip;
    }
};