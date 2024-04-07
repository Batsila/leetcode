class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> star_ind;
        stack<int> left_ind;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                left_ind.push(i);
            }
            else if (s[i] == ')')
            {
                if (star_ind.empty() and left_ind.empty())
                {
                    return false;
                }
                else if (left_ind.empty())
                {
                    star_ind.pop();
                }
                else
                {
                    left_ind.pop();
                }
            }
            else
            {
                star_ind.push(i);
            }
        }

        while (not star_ind.empty() and not left_ind.empty())
        {
            if (left_ind.top() < star_ind.top())
            {
                star_ind.pop();
                left_ind.pop();
            }
            else
            {
                return false;
            }
        }

        return left_ind.empty();
    }
};