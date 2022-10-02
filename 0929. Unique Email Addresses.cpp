class Solution
{
public:
    int numUniqueEmails(vector<string>& emails)
    {
        set<string> s;
        
        for (string email : emails)
        {
            string t = "";
            bool is_domain = false;
            bool skip = false;
            
            for (char c : email)
            {
                if (is_domain)
                {
                    t += c;
                }
                else
                {
                    if (c == '@')
                    {
                        is_domain = true;
                        t += c;
                    }
                    else
                    {
                        if (not skip)
                        {
                            if (c == '+')
                            {
                                skip = true;
                            }
                            else
                            {
                                if (c != '.')
                                {
                                    t += c;
                                }
                            }
                        }
                    }
                }
            }
            
            s.insert(t);
        }
        
        return s.size();
    }
};