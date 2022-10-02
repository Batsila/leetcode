class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b)
             {
                 return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
             });
        
        vector<vector<int>> ans;
        
        for (auto person : people)
        {
            ans.insert(ans.begin() + person[1], person);
        }
        
        return ans;
    }
};