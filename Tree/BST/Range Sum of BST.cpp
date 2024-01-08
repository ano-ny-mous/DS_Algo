// Time Complexity:O(n)
// Space Complexity: O(h)
class Solution
{
public:
    int sum = 0, Low, High;

    void rangeSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->val >= Low && root->val <= High)
        {
            sum += root->val;
        }
        if (root->val > Low)
        {
            rangeSum(root->left);
        }
        if (root->val < High)
        {
            rangeSum(root->right);
        }
    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        Low = low, High = high;
        rangeSum(root);
        return sum;
    }
};