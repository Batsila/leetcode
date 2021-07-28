class Solution
{
public:
    vector<int> beautifulArray(int n)
    {
        vector<int> ans;
        
        for (int i = n; i > 0; --i)
        {
            ans.push_back(i);
        }
        
        sort(ans.begin(), ans.end(), [](int a, int b)
             {
                 for (int i = 0; i < 12; ++i)
                 {
                     int a_bit = (a & (1 << i)) >> i;
                     int b_bit = (b & (1 << i)) >> i;
                     
                     if (a_bit != b_bit)
                     {
                         return a_bit > b_bit;
                     }
                 }
                 
                 return true;
             });
        
        return ans;
    }
};