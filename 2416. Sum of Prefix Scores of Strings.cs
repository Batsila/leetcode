public class Solution
{
    public class Trie
    {
        public class TrieNode
        {
            public TrieNode[] Children { get; set; } = new TrieNode[26];

            public int Count { get; set;}
        }

        private TrieNode _root = new TrieNode();

        public void Add(string word)
        {
            var current = _root;

            foreach (var c in word)
            {
                if (current.Children[c - 'a'] == null)
                {
                    current.Children[c - 'a'] = new TrieNode();
                }

                current.Children[c - 'a'].Count += 1;
                current = current.Children[c - 'a'];
            }
        }

        public int CountScore(string word)
        {
            var current = _root;
            var score = 0;

            foreach (var c in word)
            {
                score += current.Children[c - 'a'].Count;
                current = current.Children[c - 'a'];
            }

            return score;
        }
    }

    public int[] SumPrefixScores(string[] words)
    {
        var trie = new Trie();

        foreach (var word in words)
        {
            trie.Add(word);
        }

        var result = new List<int>();

        foreach (var word in words)
        {
            result.Add(trie.CountScore(word));
        }

        return result.ToArray();
    }
}