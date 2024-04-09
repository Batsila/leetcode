class Solution
{
public:
    int timeRequiredToBuy(vector<int>& tickets, int k)
    {
        int time = 0;

        for (int i = 0; i < tickets.size(); ++i)
        {
            time += min(i <= k ? tickets[k] : tickets[k] - 1, tickets[i]);
        }

        return time;
    }
};