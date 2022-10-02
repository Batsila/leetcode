class Solution
{
public:
    int calculate(string str)
    {
        stack<int> s;
        
        int cn = 0;
        char o = '+';
        
        for (int i = 0; i < str.size(); ++i)
        {
            if (isdigit(str[i]))
            {
                cn *= 10;
                cn += (str[i] - '0');
            }
            
            if (i == str.size() - 1
               or not (isdigit(str[i]) or iswspace(str[i])))
            {
                if (o == '+')
                {
                    s.push(cn);
                }
                else if (o == '-')
                {
                    s.push(-cn);
                }
                else if (o == '*')
                {
                    int t = s.top();
                    s.pop();
                    s.push(t * cn);
                }
                else if (o == '/')
                {
                    int t = s.top();
                    s.pop();
                    s.push(t / cn);
                }
                
                o = str[i];
                cn = 0;
            }
        }
        
        int ans = 0;
        
        while (s.size())
        {
            ans += s.top();
            s.pop();
        }
        
        return ans;
    }
};