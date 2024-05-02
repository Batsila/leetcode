class Solution
{
public:
    int findMaxK(vector<int>& nums)
    {
        unordered_set<int> negative_nums;

        for (int num : nums)
        {
            if (num < 0)
            {
                negative_nums.insert(num);
            }
        }

        int ans = -1;

        for (int num : nums)
        {
            if (num > 0 && negative_nums.find(-num) != negative_nums.end())
            {
                ans = max(ans, num);
            }
        }

        return ans;
    }
};