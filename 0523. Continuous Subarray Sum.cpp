class Solution
{
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        map<int, int> m;
        m[0] = 0;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            
            if (m.find(sum % k) == m.end())
            {
                m[sum % k] = i + 1;
            }
            else if (m[sum % k] < i)
            {
                return true;
            }
        }
        
        return false;
    }
};