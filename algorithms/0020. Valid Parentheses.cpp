class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        
        for (char c : s)
        {
            if (c == '(' or c == '{' or c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                
                char t = st.top();
                
                if (c == ')' and t != '(')
                {
                    return false;
                }
                
                if (c == ']' and t != '[')
                {
                    return false;
                }
                
                if (c == '}' and t != '{')
                {
                    return false;
                }
                
                st.pop();
            }
        }
        
        return st.empty();
    }
};