class Solution 
{
    int b, a, l, o, n;
    
public:
    int maxNumberOfBalloons(string text) 
    {
        for (int i = 0; i < text.size(); ++i)
        {
            switch (text[i])
            {
                case 'b':
                    ++b;
                    break;
                case 'a':
                    ++a;
                    break;
                case 'l':
                    ++l;
                    break;
                case 'o':
                    ++o;
                    break;
                case 'n':
                    ++n;
                    break;
            }
        }
        
        int ans = 0;
        
        while (check())
        {
            ++ans;
            --b;
            --a;
            --n;
            o -= 2;
            l -= 2;
        }
        
        return ans;
    }
    
    bool check()
    {
        return b > 0 
            and a > 0 
            and l > 1 
            and o > 1 
            and n > 0;
    }
};