class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() == word2.size())
        {
            set<char> s1;
            set<char> s2;
            map<char, int> m1;
            map<char, int> m2;
            
            for (int i = 0; i < word1.size(); ++i)
            {
                s1.insert(word1[i]);
                s2.insert(word2[i]);
                
                ++m1[word1[i]];
                ++m2[word2[i]];
            }
            
            if (s1 == s2)
            {
                multiset<int> f1;
                multiset<int> f2;
                
                for (auto p : m1)
                {
                    f1.insert(p.second);
                }
                
                for (auto p : m2)
                {
                    f2.insert(p.second);
                }
                
                if (f1 == f2)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};