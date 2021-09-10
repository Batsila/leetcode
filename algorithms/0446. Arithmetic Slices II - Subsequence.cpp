class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        long ans = 0;
        vector<map<long, long>> cnt(nums.size());
        
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                long d = (long)nums[i] - nums[j];
                long sum = 0;
                
                if (cnt[j].find(d) != cnt[j].end())
                {
                    sum = cnt[j][d];
                }
                
                cnt[i][d] += sum + 1;
                ans += sum;
            }
        }
        
        return ans;
    }
};