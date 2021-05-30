class Solution 
{
public:
    int minOperations(int n) 
    {
        int ans = 0;
        int c = n - 1;
        
        while (c > 0)
        {
            ans += c;
            c -= 2;
        }
        
        return ans;
    }
};