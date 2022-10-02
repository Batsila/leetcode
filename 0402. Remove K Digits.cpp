class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.size() <= k)
        {
            return "0";
        }
        
        if (not k)
        {
            return num;
        }
        
        stack<char> s;
        
        s.push(num[0]);
        
        for (int i = 1; i < num.size(); ++i)
        {
            while (k and not s.empty() and s.top() > num[i])
            {
                s.pop();
                --k;
            }
            
            s.push(num[i]);
            
            if (s.size() == 1 and num[i] == '0')
            {
                s.pop();
            }
        }
        
        while (k and not s.empty())
        {
            s.pop();
            --k;
        }
        
        string ans = "";
        
        
        while (s.size())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        if (not ans.size())
        {
            return "0";
        }
        
        return ans;
    }
};