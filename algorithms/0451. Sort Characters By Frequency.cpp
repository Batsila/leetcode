class Solution
{
    map<char, int> m;
public:
    string frequencySort(string s)
    {
        for (char c : s)
        {
            m[c]++;
        }
        
        vector<pair<char, int>> v(m.begin(), m.end());
        
        sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b){
            return a.second > b.second;
        });
        
        string ans = "";
        
        for (pair<char, int> p : v)
        {
            for (int i = 0; i < p.second; ++i)
            {
                ans += p.first;
            }
        }
        
        return ans;
    }
};