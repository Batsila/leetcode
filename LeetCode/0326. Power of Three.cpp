class Solution 
{
public:
    bool isPowerOfThree(int n) 
    {
        if (n == 0)
        {
            return false;
        }
        
        if (n == 1)
        {
            return true;
        }
        
        return n % 3 == 0 and isPowerOfThree(n / 3);
    }
};