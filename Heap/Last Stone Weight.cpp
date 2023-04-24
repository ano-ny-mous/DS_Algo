//Approach 1: brute force - O(n^2*log(n))
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int sz=stones.size();
        while(sz>=2)
        {
            sort(stones.begin(),stones.end());
            int x=stones[sz-2];
            int y=stones[sz-1];
            if(x==y)
            {
                stones.pop_back();
                stones.pop_back();
            }
            else if(x>y)
            {
                stones.pop_back();
                stones.pop_back();
                stones.push_back(x-y);
            }
            else
            {
                stones.pop_back();
                stones.pop_back();
                stones.push_back(y-x);
            }
            sz=stones.size();
        }
        if(!stones.empty())
        {
            return stones[0];
        }
        return 0;
    }
};

//Approach 2: using max heap - O(n*log(n))
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> pq;
       int sz=stones.size();
       for(int i=0;i<sz;i++)
       {
           pq.push(stones[i]);
       }
       while(pq.size()>=2)
       {
           int y=pq.top();
           pq.pop();
           int x=pq.top();
           pq.pop();
           if(x>y)
           {
               pq.push(x-y);
           }
           else if(y>x)
           {
               pq.push(y-x);
           }
       }
       if(!pq.empty())
       {
           return pq.top();
       }
       return 0;
    }
};