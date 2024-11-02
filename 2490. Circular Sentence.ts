function isCircularSentence(sentence: string): boolean {
    const words = sentence.split(" ");
    for (let i = 0; i < words.length; ++i) {
        if (words[i].at(-1) != words[(i + 1) % words.length][0]) {
            return false;
        }
    }

    return true;
};