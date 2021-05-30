class Solution 
{
public:
    string removeDuplicates(string str) 
    {
        stack<char> s;
        s.push(str[0]);
        
        int i = 1;
        
        while (i < str.size())
        {
            if (!s.empty() && s.top() == str[i])
            {
                s.pop();
            }
            else
            {
                s.push(str[i]);
            }
            
            ++i;
        }
        
        string ans = "";
        
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};