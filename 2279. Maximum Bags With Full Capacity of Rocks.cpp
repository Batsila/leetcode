class Solution
{
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks)
    {
        vector<int> l(rocks.size());

        for (int i = 0; i < rocks.size(); ++i)
        {
            l[i] = capacity[i] - rocks[i];
        }

        sort(l.begin(), l.end());
        int ind = 0;

        while (ind < l.size() and l[ind] <= additionalRocks)
        {
            additionalRocks -= l[ind];
            ++ind;
        }

        return ind;
    }
};