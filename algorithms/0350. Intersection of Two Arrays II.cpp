class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        map<int, int> m;
        
        for (int num : nums1)
        {
            ++m[num];
        }
        
        vector<int> ans;
        
        for (int num : nums2)
        {
            if (m[num] > 0)
            {
                ans.push_back(num);
                --m[num];
            }
        }
        
        return ans;
    }
};