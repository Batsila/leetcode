class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int ind1 = 0;
        int ind2 = 0;
        
        while (ind1 < version1.size() or ind2 < version2.size())
        {
            int num1 = 0;
            int num2 = 0;
            
            while (ind1 < version1.size() and version1[ind1] != '.')
            {
                num1 *= 10;
                num1 += version1[ind1] - '0';
                ++ind1;
            }
            
            while (ind2 < version2.size() and version2[ind2] != '.')
            {
                num2 *= 10;
                num2 += version2[ind2] - '0';
                ++ind2;
            }
            
            if (num1 > num2)
            {
                return 1;
            }
            
            if (num2 > num1)
            {
                return -1;
            }
            
            ++ind1;
            ++ind2;
        }
        
        return 0;
    }
};