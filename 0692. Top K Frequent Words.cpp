class Solution
{
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string, int> frequencies;
        
        for (auto word : words)
        {
            ++frequencies[word];
        }
        
        map<int, vector<string>, std::greater<int>> wordsByfrequencies;
        
        for (auto pair : frequencies)
        {
            wordsByfrequencies[pair.second].push_back(pair.first);
        }
        
        vector<string> ans;
        
        for (auto wordsByfrequency : wordsByfrequencies)
        {
            for (auto word : wordsByfrequency.second)
            {
                if (ans.size() == k)
                {
                    break;
                }
                
                ans.push_back(word);
            }
            
        }
        
        return ans;
    }
};