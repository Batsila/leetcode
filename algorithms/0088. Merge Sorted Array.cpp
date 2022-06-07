class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int ind1 = m - 1;
        int ind2 = n - 1;
        
        for (int i = m + n - 1; i >= 0; --i)
        {
            if (ind1 >= 0 and ind2 >= 0)
            {
                if (nums2[ind2] > nums1[ind1])
                {
                    nums1[i] = nums2[ind2--];
                }
                else
                {
                    nums1[i] = nums1[ind1--];
                }
            }
            else if (ind1 >= 0)
            {
                nums1[i] = nums1[ind1--];
            }
            else
            {
                nums1[i] = nums2[ind2--];
            }
        }
    }
};