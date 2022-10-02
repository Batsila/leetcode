class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int ans = 0;
        int c = 0;
        
        for (int num : nums)
        {
            if (num)
            {
                ++c;
            }
            else
            {
                ans = max(ans, c);
                c = 0;
            }
        }
        
        ans = max(ans, c);
        
        return ans;
    }
};