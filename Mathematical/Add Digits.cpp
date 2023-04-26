class Solution {
public:
    int addDigits(int num) {
        while(num>=10)
        {
            int rem=num%10;
            num=num/10;
            num=num+rem;
        }
        return num;
    }
};