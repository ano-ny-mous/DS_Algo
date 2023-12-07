// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        for(int i=n-1;i>=0;i--)
        {
          int mod=num[i]%2;
          if(mod)
          {
            string largestOdd=num.substr(0,i+1);
            return largestOdd;
          }
        }
        return "";
    }
};