class Solution
{
    string morseCodes[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        set<string> s;
        
        for (string word : words)
        {
            string morse = "";
            
            for (char c : word)
            {
                morse += morseCodes[c - 'a'];
            }
            
            s.insert(morse);
        }
        
        return s.size();
    }
};