class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" or num2 == "0")
        {
            return "0";
        }
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string ans(num1.size() + num2.size(), '0');
        
        for (int i = 0; i < num1.size(); ++i)
        {
            int a = num1[i] - '0';
            
            for (int j = 0; j < num2.size(); ++j)
            {
                int b = num2[j] - '0';
                
                int c = ans[i + j] - '0';
                int mul = a * b + c;
                
                ans[i + j] = (mul % 10) + '0';
                ans[i + j + 1] += (mul / 10);
            }
        }
        
        if (ans.back() == '0')
        {
            ans.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};