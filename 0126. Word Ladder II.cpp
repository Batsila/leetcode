class Solution
{
    vector<vector<string>> ans;
    unordered_set<string> words;
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        words = unordered_set<string>(wordList.begin(), wordList.end());
        
        if (words.find(endWord) == words.end())
        {
            return ans;
        }
        
        queue<vector<string>> q;
        q.push({ beginWord });
        
        while (not q.empty())
        {
            vector<string> nw;
            int qs = q.size();
            
            for (int i = 0; i < qs; ++i)
            {
                vector<string> cp = q.front();
                q.pop();
                
                string cur = cp.back();
                
                if (cur == endWord)
                {
                    ans.push_back(cp);
                }
                else
                {
                    for (int j = 0; j < cur.length(); ++j)
                    {
                        string temp = cur;
                        
                        for (char c = 'a'; c <= 'z'; ++c)
                        {
                            if (c != cur[j])
                            {
                                temp[j] = c;
                            
                                if (words.find(temp) != words.end())
                                {
                                    auto tp = cp;
                                    tp.push_back(temp);
                                    q.push(tp);
                                    nw.push_back(temp);
                                }
                            }
                        }
                    }
                }
            }
            
            for (auto word : nw)
            {
                if (words.find(word) != words.end())
                {
                    words.erase(word);
                }
            }
        }
        
        return ans;
    }
};