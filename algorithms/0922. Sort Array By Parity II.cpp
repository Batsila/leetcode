class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int even_ind = 0;
        int odd_ind = 1;
        int n = nums.size();
        
        while (even_ind < n and odd_ind < n)
        {
            if (nums[even_ind] % 2 == 0)
            {
                even_ind += 2;
            }
            else if (nums[odd_ind] % 2 == 1)
            {
                odd_ind += 2;
            }
            else
            {
                swap(nums[even_ind], nums[odd_ind]);
            }
        }
        
        return nums;
    }
};