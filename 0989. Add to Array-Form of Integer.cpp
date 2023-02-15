class Solution
{
public:
    vector<int> addToArrayForm(vector<int>& num, int k)
    {
        int c = k;
        vector<int> ans;
        int ind = num.size() - 1;

        while (ind >= 0 or c > 0)
        {
            if (ind >= 0)
            {
                c += num[ind];
            }

            ans.push_back(c % 10);
            c /= 10;
            --ind;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};