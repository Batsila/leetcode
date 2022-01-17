class Solution(object):
    def wordPattern(self, pattern, s):
        words = s.split()
        words2pattern = dict()
        
        if len(pattern) != len(words) or len(set(pattern)) != len(set(words)):
            return False
        
        for word, p in zip(words, pattern):
            if word not in words2pattern:
                words2pattern[word] = p
            elif words2pattern[word] != p:
                return False
        
        return True