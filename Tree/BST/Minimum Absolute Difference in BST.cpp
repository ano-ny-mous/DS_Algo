class Solution {
public:

    vector<int> elements;
    int absmin=INT_MAX;

    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            elements.push_back(cur->val);
            if(cur->left)
            {
                q.push(cur->left);
            }
            if(cur->right)
            {
                q.push(cur->right);
            }
        }
        sort(elements.begin(),elements.end());
        int sz=elements.size();
        for(int i=0;i<sz-1;i++)
        {
            int dif=elements[i+1]-elements[i];
            if(absmin>dif)
            {
                absmin=dif;
            }
        }
        return absmin;
    }
};