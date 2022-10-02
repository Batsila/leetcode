class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (!nums.size())
        {
            return 0;
        }
        
        int i = 0;
        
        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[i] != nums[j])
            {
                ++i;
                nums[i] = nums[j];
            }
        }
        
        int size = i + 1;
        
        nums = vector<int>(nums.begin(), nums.begin() + size);
        
        return size;
    }
};