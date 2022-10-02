class Solution
{
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int even_ind = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 2 == 0)
            {
                swap(nums[even_ind], nums[i]);
                ++even_ind;
            }
        }
        
        return nums;
    }
};