class Solution
{
public:
    int subsetXORSum(vector<int>& nums)
    {
        return get_xor(nums, 0, 0);
    }

private:
    int get_xor(vector<int>& nums, int index, int current_xor)
    {
        if (index < nums.size())
        {
            int xor_with_item = get_xor(nums, index + 1, current_xor ^ nums[index]);
            int xor_without_item = get_xor(nums, index + 1, current_xor);

            return xor_with_item + xor_without_item;
        }

        return current_xor;
    }
};