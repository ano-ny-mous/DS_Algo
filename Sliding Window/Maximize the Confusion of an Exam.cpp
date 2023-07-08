//Approach - 1
class Solution {
public:
    int res=0;
    void findmaximum(string &answerKey)
    {
        int cont=0;
        for(int i=0;i<answerKey.size()-1;i++)
        {
            if(answerKey[i]==answerKey[i+1])
            {
                cont++;
                res=max(res,cont);
            }
            else
            {
                cont=0;
            }
        }
    }

    void rec(string answerKey, int k, int i)
    {
        findmaximum(answerKey);
        if(i>=answerKey.size()||k<=0)
        {
            return;
        }
        rec(answerKey,k--,i+1);
        if(answerKey[i]=='T')
        {
            answerKey[i]='F';
        }
        else
        {
            answerKey[i]='T';
        }
        rec(answerKey,k--,i+1);
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        rec(answerKey,k,0);
        return res+1;
    }
};

//Approach - 2
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res = 0;
        int n = answerKey.size();
        int i = 0, j = 0;
        int countFalse = 0;
        int countTrue = 0;
        while(j < n) {
            if(answerKey[j] == 'F')
            {
                countFalse++;
            }
            while(countFalse > k) {
            if(answerKey[i] == 'F')
            {
                countFalse--;
            }
                i++;
            }
            res = max(res, abs(j-i)+1);
            j++;
        }
        
        i = 0, j = 0;
        while(j < n) {
            if(answerKey[j] == 'T')
            {
                countTrue++;
            }  
            while(countTrue > k) {
                if(answerKey[i] == 'T')
                {
                    countTrue--;
                }
                i++;
            }     
            res = max(res, abs(j-i)+1);
            j++;
        }
        return res;
    }
};

//Approach - 3
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res = 0;
        int n = answerKey.size();
        int i = 0, j = 0;
        unordered_map<char,int> mp;
        while(j<n)
        {
            mp[answerKey[j]]++;
            while(min(mp['T'],mp['F'])>k)
            {
                mp[answerKey[i]]--;
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};