class Solution
{
private:
    string get_rank(int place)
    {
        if (place > 3)
        {
            return to_string(place);
        }

        if (place == 1)
        {
            return "Gold Medal";
        }

        if (place == 2)
        {
            return "Silver Medal";
        }

        if (place == 3)
        {
            return "Bronze Medal";
        }

        return "";
    }

public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        priority_queue<pair<int, int>> athletes_by_score;

        for (int i = 0; i < score.size(); ++i)
        {
            athletes_by_score.push({ score[i], i });
        }

        vector<string> ans(score.size());

        for (int i = 0; i < score.size(); ++i)
        {
            auto current = athletes_by_score.top();
            athletes_by_score.pop();
            ans[current.second] = get_rank(i + 1);
        }

        return ans;   
    }
};