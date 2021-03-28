class Solution 
{
    string ds[10] = { "zero", "wto", "ufor", "xsi", "geiht", "one", "three", "five", "seven", "inne" };
    int dc[10] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int dl[10][26];
    
    int a[10];
    
    int l[26];
public:
    string originalDigits(string s) 
    {
        for (char c : s)
        {
            ++l[c - 'a'];
        }
        
        for (int i = 0; i < 10; ++i)
        {
            for (char c : ds[i])
            {
                ++dl[i][c - 'a'];
            }
        }
        
        for (int i = 0; i < 10; ++i)
        {
            int c = l[ds[i][0] - 'a'];
            
            for (int j = 0; j < 26; ++j)
            {
                l[j] -= dl[i][j] * c;
            }
            
            a[dc[i]] = c;
        }
        
        string ans = "";
        
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < a[i]; ++j)
            {
                ans += to_string(i);
            }
        }
        
        return ans;
    }
};