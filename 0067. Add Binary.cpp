class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string ans = "";
        int ai = 0;
        int bi = 0;
        int rem = 0;
        
        while (ai < a.size() or bi < b.size())
        {
            int c = rem;
            
            if (ai < a.size())
            {
                c += a[ai] - '0';
            }
            
            if (bi < b.size())
            {
                c += b[bi] - '0';
            }
            
            ans += '0' + c % 2;
            rem = c / 2;
            
            ++ai;
            ++bi;
        }
        
        if (rem)
        {
            ans += '1';
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};