//brute force
//Time Complexity O(sz1*sz2*log(k))
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> arr;
        int sz1=nums1.size(),sz2=nums2.size();
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<sz1;i++)
        {
            for(int j=0;j<sz2;j++)
            {
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)
                {
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if(pq.top().first>sum)
                {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else
                {
                    break;
                }
            }
        }
        while(!pq.empty())
        {
            auto ele=pq.top().second;
            pq.pop();
            arr.push_back({ele.first,ele.second});
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};