class Solution {
public:
    unordered_map<string,vector<string>> adj;
    int groups=0;
    unordered_map<string,int> check;
    void dfs(string u)
    {
        if(check[u]==true)
        {
            return;
        }
        check[u]=true;
        for(string v:adj[u])
        {
            if(!check[v])
            {
                dfs(v);
            }
        }
    }

    void similar(string str1,string str2)
    {
        int diff=0;
        for(int i=0;i<str1.size();i++)
        {
            if(str1[i]!=str2[i])
            {
                diff++;
            }
        }
        if(diff==0||diff==2)
        {
            adj[str1].push_back(str2);
            adj[str2].push_back(str1);
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int sz=strs.size();
        for(int i=0;i<sz;i++)
        {
            check[strs[i]]=false;
        }
        for(int i=0;i<sz;i++)
        {
            for(int j=i+1;j<sz;j++)
            {
                similar(strs[i],strs[j]);
            }
        }

        for(int i=0;i<sz;i++)
        {
            
            
            if(check[strs[i]]==false)
            {
                dfs(strs[i]);
                groups++;
            }   
        }
        return groups;
    }
};