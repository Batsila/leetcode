class Solution 
{
public:
    bool detectCapitalUse(string word) 
    {
        if (word.empty())
        {
            return true;
        }
        
        bool is_1st_capital = word[0] < 'a';
        
        if (!is_1st_capital)
        {
            for (int i = 1; i < word.size(); ++i)
            {
                if (word[i] < 'a')
                {
                    return false;
                }
            }
        }
        else
        {
            if (word.size() == 1)
            {
                return true;
            }
            
            bool is_2nd_capital = word[1] < 'a';
            
            if (!is_1st_capital and is_2nd_capital)
            {
                return false;
            }
            
            for (int i = 2; i < word.size(); ++i)
            {
                if ((is_2nd_capital && word[i] >= 'a')
                   or (!is_2nd_capital && word[i] < 'a'))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};