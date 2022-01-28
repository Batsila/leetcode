class WordDictionary
{
    unordered_map<int, vector<string>> m;
public:
    void addWord(string word)
    {
        m[word.size()].push_back(word);
    }
    
    bool search(string word)
    {
        for (string s : m[word.size()])
        {
            if (check(s, word))
            {
                return true;
            }
        }
        
        return false;
    }
    
    bool check(string str, string word)
    {
        for (int i = 0; i < str.size(); ++i)
        {
            if (word[i] != '.' and str[i] != word[i])
            {
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */