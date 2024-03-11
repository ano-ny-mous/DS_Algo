//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0,j=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        int score=0,maxScore=0;
        while (i<=j) 
        {
            if(power>=tokens[i]) 
            {
                power-=tokens[i];
                i++;
                score++;
                maxScore = max(maxScore, score);
            }
            else if (score > 0) 
            {
                power += tokens[j];
                j--;
                score--;
            } 
            else 
            {
                break;
            }
        }
        return maxScore;
    }
};