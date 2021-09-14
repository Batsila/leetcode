class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        stack<char> l;
        
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            
            if (c >= 'A' and c <= 'Z' or c >= 'a' and c <= 'z')
            {
                l.push(c);
                s[i] = 'A';
            }
        }
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'A')
            {
                s[i] = l.top();
                l.pop();
            }
        }
        
        return s;
    }
};