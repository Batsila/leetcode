class Trie
{
public:
    Trie* children[26];
    bool isEnd = false;
    
    void insert(string word)
    {
        auto current = this;
        
        for (char c : word)
        {
            if (current->children[c - 'a'] == nullptr)
            {
                current->children[c - 'a'] = new Trie();
            }
            
            current = current->children[c - 'a'];
        }
        
        current->isEnd = true;
    }
    
    bool search(string word)
    {
        auto current = this;
        
        for (char c : word)
        {
            if (current->children[c - 'a'] == nullptr)
            {
                return false;
            }
            
            current = current->children[c - 'a'];
        }
        
        return current->isEnd;
    }
    
    bool startsWith(string prefix)
    {
        auto current = this;
        
        for (char c : prefix)
        {
            if (current->children[c - 'a'] == nullptr)
            {
                return false;
            }
            
            current = current->children[c - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */