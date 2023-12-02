// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size(), area = 0;
        for (int i = 0; i < col; i++)
        {
            int height = 0;
            for (int j = 0; j < row; j++)
            {
                height += matrix[j][i];
                if (matrix[j][i] != 0)
                {
                    matrix[j][i] = height;
                }
                else
                {
                    height = 0;
                }
            }
        }
        for (auto &vec : matrix)
        {
            sort(vec.begin(), vec.end(), greater<int>());
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int curArea = matrix[i][j] * (j + 1);
                area = max(area, curArea);
            }
        }
        return area;
    }
};