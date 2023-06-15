class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int res=1;
        int maxsumlevel=INT_MIN;
        while(!q.empty())
        {
            int sz=q.size();
            int levelsum=0;
            level++;
            while(sz>0)
            {
                TreeNode* cur=q.front();
                if(cur)
                levelsum=levelsum+cur->val;
                q.pop();
                if(cur->left)
                {
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    q.push(cur->right);
                }
               sz--;
            }
            if(maxsumlevel<levelsum)
            {
                maxsumlevel=levelsum;
                res=level;
            }
        }
        return res;
    }
};