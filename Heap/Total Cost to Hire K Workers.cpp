class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long totalcos=0;
        priority_queue <int, vector<int>, greater<int> > leftpq;
        priority_queue <int, vector<int>, greater<int> > rightpq;
        int left=0;
        int right=costs.size()-1;
        for(int i=0;i<k;i++)
        {
            while(left<=right&&leftpq.size()<candidates)
            {
                leftpq.push(costs[left]);
                left++;
            }
            while(left<=right&&rightpq.size()<candidates)
            {
                rightpq.push(costs[right]);
                right--;
            }
            if(leftpq.size()==0)
            {
                leftpq.push(INT_MAX);
            }
            if(rightpq.size()==0)
            {
                 rightpq.push(INT_MAX);
            }
            if(leftpq.top()<=rightpq.top())
            {
                totalcos=totalcos+leftpq.top();
                cout<<leftpq.top()<<" ";
                leftpq.pop();
            }
            else
            {
                totalcos=totalcos+rightpq.top();
                rightpq.pop();
            }
        }
        return totalcos;
    }
};