function compressedString(word: string): string {
    const stack: [char: string, num: number][] = [[word[0], 1]];
    for (let i = 1; i < word.length; ++i) {
        if (word[i] == stack.at(-1)![0] && stack.at(-1)![1] < 9) {
            stack.at(-1)![1] += 1;
        } else {
            stack.push([word[i], 1]);
        }
    }
    return stack.map(([char, num]) => `${num}${char}`).join("");
};