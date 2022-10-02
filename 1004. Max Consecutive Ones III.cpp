class Solution
{
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int l = 0;
        int r = 0;
        
        int kn = 0;
        int ans = 0;
        
        while (r < nums.size())
        {
            if (nums[r])
            {
                ++r;
            }
            else
            {
                if (kn < k)
                {
                    ++kn;
                    ++r;
                }
                else
                {
                    if (nums[l])
                    {
                        ++l;
                    }
                    else
                    {
                        ++l;
                        --kn;
                    }
                }
            }
            
            ans = max(ans, r - l);
        }
        
        return ans;
    }
};