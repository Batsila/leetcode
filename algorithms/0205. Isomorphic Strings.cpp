class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> m1;
        map<char, char> m2;
        
        for (int i = 0; i < s.size(); ++i)
        {
            auto it1 = m1.find(s[i]);
            auto it2 = m2.find(t[i]);
            
            if (it1 == m1.end() and it2 == m2.end())
            {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else if (it1 == m1.end() 
                     or it2 == m2.end()
                     or it1->second != t[i]
                     or it2->second != s[i])
            {
                return false;
            }
        }
        
        return true;
    }
};