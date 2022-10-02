class Solution
{
public:
    int stoneGameVII(vector<int>& stones)
    {
        vector<int> dpCurr(stones.size());
        vector<int> dpLast(stones.size());
        
        for (int i = stones.size() - 2; i >= 0; --i)
        {
            int total = stones[i];
            dpLast.swap(dpCurr);
            
            for (int j = i + 1; j < stones.size(); ++j)
            {
                total += stones[j];
                dpCurr[j] = max(total - stones[i] - dpLast[j], total - stones[j] - dpCurr[j - 1]);
            }
        }
        
        return dpCurr[stones.size() - 1];
    }
};