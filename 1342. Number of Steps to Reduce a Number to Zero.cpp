class Solution
{
public:
    int numberOfSteps(int num)
    {
        int ans = 0;
        
        while (num != 0)
        {
            if (num % 2)
            {
                --num;
            }
            else
            {
                num /= 2;
            }
            
            ++ans;
        }
        
        return ans;
    }
};