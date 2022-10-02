class Solution
{
public:
    int partitionDisjoint(vector<int>& nums)
    {
        vector<int> maxl(nums.size(), nums[0]);
        
        for (int i = 1; i < nums.size(); ++i)
        {
            maxl[i] = max(maxl[i - 1], nums[i]);
        }
        
        vector<int> minr(nums.size(), nums[nums.size() - 1]);
        
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            minr[i] = min(minr[i + 1], nums[i]);
        }
        
        int ind = 0;
        
        while (maxl[ind] > minr[ind + 1])
        {
            ++ind;
        }
        
        return ind + 1;
    }
};