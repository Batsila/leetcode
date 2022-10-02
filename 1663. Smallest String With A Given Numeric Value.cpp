class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string ans = "";
        
        int r = k;
        
        for (int i = 0; i < n; ++i)
        {
            int c = r - n + i + 1;
            
            if (c >= 26)
            {
                ans += 'z';
                r -= 26;
            }
            else
            {
                ans += ('a' + c - 1);
                r -= c;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};