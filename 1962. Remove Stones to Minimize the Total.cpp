class Solution
{
public:
    int minStoneSum(vector<int>& piles, int k)
    {
        priority_queue<int> pq(piles.begin(), piles.end());

        while (k > 0)
        {
            int t = pq.top();
            pq.pop();
            pq.push(t - t / 2);
            --k;
        }

        int ans = 0;

        while (not pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};