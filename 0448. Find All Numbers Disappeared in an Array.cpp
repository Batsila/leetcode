class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {   
            int num = abs(nums[i]);
            
            if (nums[num- 1] > 0)
            {
                nums[num - 1] *= -1;
            }
        }
        
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); ++i)
        {    
            if (nums[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};