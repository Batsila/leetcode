class Solution
{
public:
    int superpalindromesInRange(string left, string right)
    {
        unsigned long long l = stoll(left);
        unsigned long long r = stoll(right);
        int ans = 0;
        
        for (int k = 1; k < 100000; ++k)
        {
            string ks = to_string(k);
            
            string rks = ks;
            reverse(rks.begin(), rks.end());
            
            unsigned long long en = stoll(ks + rks.substr(1));
            en *= en;
            
            if (en > r)
            {
                break;
            }
            
            if (en >= l and en <= r and check(en))
            {
                ++ans;
            }
            
            
            unsigned long long on = stoll(ks + rks);
            on *= on;
            
            if (on >= l and on <= r and check(on))
            {
                ++ans;
            }
        }
        
        return ans;
    }
    
    bool check(unsigned long long n)
    {
        string s = to_string(n);
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        return s == rs;
    }
};