class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int ind = 0;
        
        for (int num : nums)
        {
            if (ind < 2 or num > nums[ind - 2])
            {
                nums[ind] = num;
                ++ind;
            }
        }
        
        return ind;
    }
};