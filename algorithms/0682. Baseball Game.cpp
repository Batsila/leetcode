class Solution
{
public:
    int calPoints(vector<string>& ops)
    {
        vector<int> scores;
        
        for (string op : ops)
        {
            if (op == "+")
            {
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            }
            else if (op == "D")
            {
                scores.push_back(scores[scores.size() - 1] * 2);
            }
            else if (op == "C")
            {
                scores.pop_back();
            }
            else
            {
                int x = stoi(op);
                scores.push_back(x);
            }
        }
        
        int ans = 0;
        
        for (int score : scores)
        {
            ans += score;
        }
        
        return ans;
    }
};