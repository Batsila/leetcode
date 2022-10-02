class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int r = 0;
        int w = 0;
        int b = 0;
        
        for (int num : nums)
        {
            switch (num)
            {
                case 0:
                {
                    ++r;
                    break;
                }
                case 1:
                {
                    ++w;
                    break;
                }
                case 2:
                {
                    ++b;
                    break;
                }
            }
        }
        
        int ind = 0;
        
        while (r)
        {
            nums[ind] = 0;
            --r;
            ++ind;
        }
        
        while (w)
        {
            nums[ind] = 1;
            --w;
            ++ind;
        }
        
        while (b)
        {
            nums[ind] = 2;
            --b;
            ++ind;
        }
    }
};