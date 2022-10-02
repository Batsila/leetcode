class TrieNode
{
public:
    TrieNode* children[27];
    int weight;
};

class WordFilter 
{
    TrieNode* trie;
public:
    WordFilter(vector<string>& words) 
    {
        trie = new TrieNode();
        
        for (int i = 0; i < words.size(); ++i)
        {
            string word = words[i] + "{";
            
            for (int j = 0; j < word.size(); ++j)
            {
                TrieNode* current = trie;
                current->weight = i;
                
                for (int k = j; k < 2 * word.size() - 1; ++k)
                {
                    int ind = word[k % word.size()] - 'a';
                    
                    if (!current->children[ind])
                    {
                        current->children[ind] = new TrieNode();
                    }
                    
                    current = current->children[ind];
                    current->weight = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) 
    {
        TrieNode* current = trie;
        
        string query = suffix + "{" + prefix;
        
        for (char c : query)
        {
            if (!current->children[c - 'a'])
            {
                return -1;
            }
            
            current = current->children[c - 'a'];
        }
        
        return current->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */