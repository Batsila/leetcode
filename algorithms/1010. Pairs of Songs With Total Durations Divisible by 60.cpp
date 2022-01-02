class Solution
{
public:
    int numPairsDivisibleBy60(vector<int>& times)
    {
        vector<int> r(60, 0);
        int ans = 0;
        
        for (int time : times)
        {
            ans += r[(60 - time % 60) % 60];
            ++r[time % 60];
        }
        
        return ans;
    }
};