class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int sz1=nums1.size();
        int sz2=nums2.size();
        vector<vector<int>> res;
        vector<int> arr1;
        vector<int> arr2;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        vector<int> temp={0,0};
        for(int i=0;i<sz1;i++)
        {
            mp1[nums1[i]]++;
        }
        for(int i=0;i<sz2;i++)
        {
            mp2[nums2[i]]++;
        }
        for(int i=0;i<sz2;i++)
        {
            auto it1 = mp1.find(nums2[i]);  
            if (it1 != mp1.end())
            {
                mp1.erase(nums2[i]);
            }   
        }
        for(int i=0;i<sz1;i++)
        {
            auto it2 = mp2.find(nums1[i]);  
            if (it2 != mp2.end())
            {
                mp2.erase(nums1[i]);
            }    
        }
        for (auto i :mp1)
        {
            arr1.push_back(i.first);
        }
        for (auto i :mp2)
        {
            arr2.push_back(i.first);
        }
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        res.push_back(arr1);
        res.push_back(arr2);
        return res;
    }
};