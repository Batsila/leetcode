class Solution
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        int l = nums.size();
        int r = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (sorted_nums[i] != nums[i])
            {
                l = min(l, i);
                r = max(r, i);
            }
        }
        
        if (r - l < 0)
        {
            return 0;
        }
        
        return r - l + 1;
    }
};