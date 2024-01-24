// Approach - 1
// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution
{
public:
    int palindrom = 0;

    void dfs(TreeNode *root, vector<int> &freq)
    {
        if (root == NULL)
        {
            return;
        }
        freq[root->val]++;
        if (root->left == NULL && root->right == NULL)
        {
            int countOdd = 0;
            for (int &num : freq)
            {
                if (num % 2 == 1)
                {
                    countOdd++;
                }
            }
            if (countOdd <= 1)
            {
                palindrom++;
            }
        }
        dfs(root->left, freq);
        dfs(root->right, freq);
        freq[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> freq(10, 0);
        dfs(root, freq);
        return palindrom;
    }
};

// Approach - 2
// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution
{
public:
    int palindrom = 0;
    int countOdd = 0;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        countOdd ^= (1 << root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if ((countOdd & (countOdd - 1)) == 0)
            {
                palindrom++;
            }
        }
        dfs(root->left);
        dfs(root->right);
        countOdd ^= (1 << root->val);
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        dfs(root);
        return palindrom;
    }
};

// Approach - 2.1
// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution
{
public:
    int palindrom = 0;
    void dfs(TreeNode *root, int countOdd)
    {
        if (root == NULL)
        {
            return;
        }
        countOdd ^= (1 << root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if ((countOdd & (countOdd - 1)) == 0)
            {
                palindrom++;
            }
        }
        dfs(root->left, countOdd);
        dfs(root->right, countOdd);
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        dfs(root, 0);
        return palindrom;
    }
};