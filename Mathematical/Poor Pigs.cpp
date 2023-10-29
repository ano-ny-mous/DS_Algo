// Approach - 1
class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int trial = minutesToTest / minutesToDie, pig = 0;
        while (pow(trial + 1, pig) < buckets)
        {
            pig++;
        }
        return pig;
    }
};

// Approach - 2
class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        return ceil(log2(buckets) / log2(minutesToTest / minutesToDie + 1));
    }
};