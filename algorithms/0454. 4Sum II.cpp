class Solution
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        map<int, int> m;
        
        for (int num1 : nums1)
        {
            for (int num2 : nums2)
            {
                ++m[num1 + num2];
            }
        }
        
        int ans = 0;
        
        for (int num3 : nums3)
        {
            for (int num4 : nums4)
            {
                ans += m[-(num3 + num4)];
            }
        }
        
        return ans;
    }
};