class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }
        
        vector<int> m1(26, 0);
        vector<int> m2(26, 0);
        
        int ind = 0;
        
        for (; ind < s1.size(); ++ind)
        {
            ++m1[s1[ind] - 'a'];
            ++m2[s2[ind] - 'a'];
        }
        
        if (m1 == m2)
        {
            return true;
        }
        
        for (; ind < s2.size(); ++ind)
        {
            ++m2[s2[ind] - 'a'];
            --m2[s2[ind - s1.size()] - 'a'];
            
            if (m1 == m2)
            {
                return true;
            }
        }
        
        return false;
    }
};