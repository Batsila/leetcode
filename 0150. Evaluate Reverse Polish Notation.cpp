class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> s;
        
        int ans = 0;
        
        for (string token : tokens)
        {
            if (token == "+")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a + b);
            }
            else if (token == "-")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            }
            else if (token == "*")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a * b);
            }
            else if (token == "/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);
            }
            else
            {
                int number = stoi(token);
                s.push(number);
            }
        }
        
        return s.top();
    }
};