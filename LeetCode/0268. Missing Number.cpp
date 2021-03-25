class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            ans ^= (i + 1) ^ nums[i];
        }
        
        return ans;
    }
};