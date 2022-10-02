class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> m;
        
        int i1 = 0;
        int i2 = 0;
        
        while (i1 < nums1.size() && i2 < nums2.size())
        {
            if (nums1[i1] <= nums2[i2])
            {
                m.push_back(nums1[i1]);
                ++i1;
            }
            else
            {
                m.push_back(nums2[i2]);
                ++i2;
            }
        }
        
        while (i1 < nums1.size())
        {
            m.push_back(nums1[i1]);
            ++i1;
        }
        
        while (i2 < nums2.size())
        {
            m.push_back(nums2[i2]);
            ++i2;
        }

        return m.size() % 2 ? m[m.size() / 2] : (double)(m[m.size() / 2 - 1] + m[m.size() / 2]) / 2;
    }
};