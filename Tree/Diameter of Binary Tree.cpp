// Time complexity: O(n)
// Space complexity: O(h)
class Solution
{
public:
    int diameter = 0;

    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        // int leftHeight = 1 + height(root->left);
        // int rightHeight = 1 + height(root->right);
        // diameter = max(diameter, leftHeight + rightHeight - 2);
        // return max(leftHeight, rightHeight);
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root);
        return diameter;
    }
};