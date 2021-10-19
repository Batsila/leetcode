class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> inds(10001, -1);
        
        for (int i = 0; i < nums2.size(); ++i)
        {
            inds[nums2[i]] = i;
        }
        
        vector<int> ans;
        
        for (int num : nums1)
        {
            int ind = inds[num];
            
            int gnum = -1;
            
            for (int i = ind + 1; i < nums2.size(); ++i)
            {
                if (nums2[i] > num)
                {
                    gnum = nums2[i];
                    break;
                }
            }
            
            ans.push_back(gnum);
        }
        
        return ans;
    }
};