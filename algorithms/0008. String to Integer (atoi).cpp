class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1;
        int ans = 0;
        int ind = 0;
        
        while (ind < s.size() and s[ind] == ' ')
        {
            ++ind;
        }
        
        if (ind < s.size() and s[ind] == '+')
        {
            sign = 1;
            ++ind;
        }
        else if (ind < s.size() and s[ind] == '-')
        {
            sign = -1;
            ++ind;
        }
        
        while (ind < s.size() and isdigit(s[ind]))
        {
            int d = s[ind] - '0';
            
            if (ans > INT_MAX / 10
               or ans == INT_MAX / 10 and d > INT_MAX % 10)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            ans *= 10;
            ans += d;
            ++ind;
        }
        
        return ans * sign;
    }
};