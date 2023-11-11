// TLE
// Time Complexity: O(8^n)
class Solution
{
public:
    int Fx, Fy;

    bool rec(int sx, int sy, int t)
    {
        if (sx < 0 || sy < 0 || t < 0)
        {
            return false;
        }
        if (sx == Fx && sy == Fy && t == 0)
        {
            return true;
        }
        return (rec(sx + 1, sy, t - 1) ||
                rec(sx - 1, sy, t - 1) ||
                rec(sx, sy + 1, t - 1) ||
                rec(sx, sy - 1, t - 1) ||
                rec(sx + 1, sy + 1, t - 1) ||
                rec(sx - 1, sy - 1, t - 1) ||
                rec(sx + 1, sy - 1, t - 1) ||
                rec(sx - 1, sy + 1, t - 1));
    }

    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        Fx = fx, Fy = fy;
        return rec(sx, sy, t);
    }
};

// Time Complexity: O(1)
class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int horizontalSteps = abs(fx - sx), verticalSteps = abs(fy - sy), minSteps;
        if (horizontalSteps == 0 && verticalSteps == 0 && t == 1)
        {
            return false;
        }
        minSteps = max(horizontalSteps, verticalSteps);
        return t >= minSteps;
    }
};