class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        salary[0]=0;
        int sz=salary.size();
        salary[sz-1]=0;
        double sum=0;
        for(int i=1;i<sz-1;i++)
        {
            sum=sum+salary[i];
        }
        return sum/(sz-2);
    }
};