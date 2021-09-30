class Solution
{
    vector<int> sums;
    int n;
    int k;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        this->k = k;
        int sum = 0;
        
        for (int num : nums)
        {
            sum += num;
        }
        
        if (sum % k)
        {
            return false;
        }
        
        n = sum / k;
        
        sums = vector<int>(k, 0);
        
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        return check(nums, 0);
    }
    
    bool check(vector<int>& nums, int ind)
    {
        for (auto sum : sums)
        {
            if (sum > n)
            {
                return false;
            }
        }
        
        if (ind == nums.size())
        {      
            for (auto sum : sums)
            {
                if (sum != n)
                {
                    return false;
                }
            }
            
            return true;
        }
        
        bool res = false;
        
        for (int i = 0; i < k; ++i)
        {
            sums[i] += nums[ind];
            
            if (check(nums, ind + 1))
            {
                return true;
            }
            
            sums[i] -= nums[ind];
        }
        
        return false;
    }
};