//Approach - 1
class Solution {
public:
    int mindepth=INT_MAX;
    void traverse(TreeNode* root,int height)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            mindepth=min(mindepth,height);
        }
        traverse(root->left,height+1);
        traverse(root->right,height+1);
    }
    int minDepth(TreeNode* root) {
        traverse(root,1);
        if(mindepth==INT_MAX)
        {
            return 0;
        }
        return mindepth;
    }
};

//Approach - 2
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int level =0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            level++;
            int sz=q.size();
            while(sz)
            {
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left==NULL&&cur->right==NULL)
                {
                    return level;
                }
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
        }
        return 0;
    }
};