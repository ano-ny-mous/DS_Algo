class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int maxwidth=0;
        while(!q.empty())
        {
            int sz=q.size();
            pair<TreeNode*,unsigned long long> stnode=q.front();
            pair<TreeNode*,unsigned long long> ednode=q.back();
            int stindex=stnode.second;
            int edindex=ednode.second;
            while(sz>0)
            {
                pair<TreeNode*,unsigned long long> cur=q.front();
                q.pop();
                if(cur.first->left)
                {
                    q.push({cur.first->left,cur.second*2+1});
                }
                if(cur.first->right)
                {
                    q.push({cur.first->right,cur.second*2+2});
                }
                sz--;
            }
            maxwidth=max(maxwidth,(edindex-stindex)+1);
        }
        return maxwidth;
    }
};