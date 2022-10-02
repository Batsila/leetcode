class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string ans;
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int r = 0;
        
        for (int i = 0; i < max(num1.size(), num2.size()); ++i)
        {
            int a = i < num1.size() ? num1[i] - '0' : 0;
            int b = i < num2.size() ? num2[i] - '0' : 0;
            
            int sum = a + b + r;
            r = sum / 10;
            ans += to_string(sum % 10);
        }
        
        if (r)
        {
            ans += to_string(r);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};