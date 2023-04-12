class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        int count=0;
        vector<int> left;
        vector<int> right;
        for(int i=0;i<n/2;i++)
        {
            left.push_back(arr[i]);
        }
        for(int i=n/2;i<n;i++)
        {
            right.push_back(arr[i]);
        }
        sort(left.begin(),left.end(),greater<int>());
        sort(right.begin(),right.end(),greater<int>());
        int i=0,j=0;
        while(i<left.size()&&j<right.size())
        {
            if(left[i]>=5*right[j])
            {
                count=count+(right.size()-j);
                i++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }  
};