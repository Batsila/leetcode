class Solution
{
    vector<vector<int>> twoPowers;
public:
    Solution()
    {
        for (long i = 1; i < INT_MAX; i*=2)
        {
            twoPowers.push_back(countDigits(i));
        }
    }
    
    vector<int> countDigits(int num)
    {
        vector<int> count(10, 0);
        
        while (num > 0)
        {
            ++count[num % 10];
            num /= 10;
        }
        
        return count;
    }
    
    bool reorderedPowerOf2(int n)
    {
        auto count = countDigits(n);
        
        for (auto twoPower : twoPowers)
        {
            if (twoPower == count)
            {
                return true;
            }
        }
        
        return false;
    }
    
};