public class Solution
{
    public int MaxScoreWords(string[] words, char[] letters, int[] score)
    {
        var availableLetters = Enumerable.Repeat(0, 26).ToArray();

        foreach (var letter in letters)
        {
            ++availableLetters[letter - 'a'];
        }

        return Backtrack(0, words, availableLetters, score);
    }

    private int Backtrack(
        int current,
        string[] words,
        int[] availableLetters,
        int[] letterScores,
        int currentScore = 0)
    {
        if (current < words.Length)
        {
            var resultWithoutCurrent = Backtrack(current + 1, words, availableLetters, letterScores, currentScore);

            if (TryAddWord(words[current], availableLetters, letterScores, out var score))
            {
                var resultWithCurrent = Backtrack(current + 1, words, availableLetters, letterScores, currentScore + score);
                AddLettersFromWord(words[current], availableLetters);

                return Math.Max(resultWithoutCurrent, resultWithCurrent);
            }
            else
            {
                return resultWithoutCurrent;
            }
        }
        else
        {
            return currentScore;
        }
    }

    private bool TryAddWord(
        string word,
        int[] availableLetters,
        int[] letterScores,
        out int score)
    {
        score = 0;
        int i;

        for (i = 0; i < word.Length; ++i)
        {
            var letterInd = word[i] - 'a';

            if (availableLetters[letterInd] > 0)
            {
                --availableLetters[letterInd];
                score += letterScores[letterInd];
            }
            else
            {
                break;
            }
        }

        if (i == word.Length)
        {
            return true;
        }
        else
        {
            AddLettersFromWord(word.Substring(0, i), availableLetters);
            score = 0;

            return false;
        }
    }

    private void AddLettersFromWord(string word, int[] availableLetters)
    {
        foreach (var letter in word)
        {
            ++availableLetters[letter - 'a'];
        }
    }
}