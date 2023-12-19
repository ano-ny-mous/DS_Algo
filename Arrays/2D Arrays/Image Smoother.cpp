// Approach - 1
// Time Complexity: O(m*n)
//  Space Complexity: O(m*n)
class Solution
{
public:
    int m, n;

    bool vaild(int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return false;
        }
        return true;
    }

    int filter(vector<vector<int>> &img, int i, int j)
    {
        int sum = 0, avg, count = 0;
        if (vaild(i, j))
        {
            sum += img[i][j];
            count++;
        }
        if (vaild(i - 1, j))
        {
            sum += img[i - 1][j];
            count++;
        }
        if (vaild(i + 1, j))
        {
            sum += img[i + 1][j];
            count++;
        }
        if (vaild(i, j - 1))
        {
            sum += img[i][j - 1];
            count++;
        }
        if (vaild(i, j + 1))
        {
            sum += img[i][j + 1];
            count++;
        }
        if (vaild(i + 1, j + 1))
        {
            sum += img[i + 1][j + 1];
            count++;
        }
        if (vaild(i + 1, j - 1))
        {
            sum += img[i + 1][j - 1];
            count++;
        }
        if (vaild(i - 1, j - 1))
        {
            sum += img[i - 1][j - 1];
            count++;
        }
        if (vaild(i - 1, j + 1))
        {
            sum += img[i - 1][j + 1];
            count++;
        }
        avg = sum / count;
        return avg;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        m = img.size(), n = img[0].size();
        vector<vector<int>> grayScale(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grayScale[i][j] = filter(img, i, j);
            }
        }
        return grayScale;
    }
};

// Approach - 2
// Time Complexity: O(m*n)
//  Space Complexity: O(n)
class Solution
{
public:
    int m, n;

    bool vaild(int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return false;
        }
        return true;
    }

    int filter(vector<vector<int>> &img, int i, int j, int prevCol, vector<int> &grayScaleRow)
    {
        int sum = 0, avg, count = 0;
        if (vaild(i, j))
        {
            sum += img[i][j];
            count++;
        }
        if (vaild(i - 1, j))
        {
            sum += grayScaleRow[j];
            count++;
        }
        if (vaild(i + 1, j))
        {
            sum += img[i + 1][j];
            count++;
        }
        if (vaild(i, j - 1))
        {
            sum += prevCol;
            count++;
        }
        if (vaild(i, j + 1))
        {
            sum += img[i][j + 1];
            count++;
        }
        if (vaild(i + 1, j + 1))
        {
            sum += img[i + 1][j + 1];
            count++;
        }
        if (vaild(i + 1, j - 1))
        {
            sum += img[i + 1][j - 1];
            count++;
        }
        if (vaild(i - 1, j - 1))
        {
            sum += grayScaleRow[j - 1];
            count++;
        }
        if (vaild(i - 1, j + 1))
        {
            sum += grayScaleRow[j + 1];
            count++;
        }
        avg = sum / count;
        return avg;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        m = img.size(), n = img[0].size();
        int prevCol;
        vector<int> grayScaleRow;
        for (int i = 0; i < m; i++)
        {
            vector<int> temp = img[i];
            for (int j = 0; j < n; j++)
            {
                int temp = img[i][j];
                img[i][j] = filter(img, i, j, prevCol, grayScaleRow);
                prevCol = temp;
            }
            grayScaleRow = temp;
        }
        return img;
    }
};