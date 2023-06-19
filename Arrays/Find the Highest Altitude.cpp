class Solution {
public:
    int largestAltitude(vector<int>& gain) {
    vector<int> arr;
    int maxno=INT_MIN;
    arr.push_back(0);
    for(int i=0;i<gain.size();i++)
    {
        arr.push_back(arr[i]+gain[i]);
    }
    for(int j=0;j<arr.size();j++)
    {
        maxno=max(maxno,arr[j]);
    }
    return maxno;    
    }
};