class Solution
{
    int decimal[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
public:
    string intToRoman(int num)
    {
        string ans = "";
        
        for (int i = 0; i < 13; ++i)
        {
            while(num >= decimal[i])
            {
                ans += roman[i];
                num -= decimal[i];
            }
        }
        
        return ans;
    }
};