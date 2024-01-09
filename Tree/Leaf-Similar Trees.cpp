// Approach - 1
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    vector<vector<int>> sequence;
    bool seq = true;
    void postorder(TreeNode *root, int i)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left, i);
        postorder(root->right, i);
        if (root->left == NULL && root->right == NULL)
        {
            sequence[i].push_back(root->val);
            if (i == 1 && sequence[i - 1][sequence[i].size() - 1] != sequence[i].back())
            {
                seq = false;
                return;
            }
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        sequence.push_back({});
        sequence.push_back({});
        postorder(root1, 0);
        postorder(root2, 1);
        if (sequence[0].size() != sequence[1].size())
        {
            return false;
        }
        return seq;
    }
};

// Approach - 2
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    vector<int> sequence;
    bool seq = true;
    int sz = 0;
    void postorder(TreeNode *root, int i)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left, i);
        postorder(root->right, i);
        if (root->left == NULL && root->right == NULL)
        {
            if (i == 0)
            {
                sequence.push_back(root->val);
            }
            else if (sequence[sz++] != root->val)
            {
                seq = false;
                return;
            }
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        postorder(root1, 0);
        postorder(root2, 1);
        if (sequence.size() != sz)
        {
            return false;
        }
        return seq;
    }
};

// Approach - 3
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    void postorder(TreeNode *&root, string &s)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left, s);
        postorder(root->right, s);
        if (root->left == NULL && root->right == NULL)
        {
            s.push_back(root->val);
            s.push_back('#');
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        string s1 = "", s2 = "";
        postorder(root1, s1);
        postorder(root2, s2);
        cout << s1 << endl
             << s2;
        if (s1 == s2)
        {
            return true;
        }
        return false;
    }
};