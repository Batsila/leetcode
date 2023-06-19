class Solution
{
public:
    int largestAltitude(vector<int>& gain)
    {
        int c = 0;
        int ans = 0;

        for (int g : gain)
        {
            c += g;
            ans = max(ans, c);
        }

        return ans;
    }
};