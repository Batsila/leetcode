function largestCombination(candidates: number[]): number {
    const bitCounts = Array(30).fill(0);
    for (let num of candidates) {
        for (let i = 0; i < 30 && num > 0; ++i) {
            if (num & 1) {
                ++bitCounts[i];
            }
            num >>= 1;
        }
    }
    return Math.max(...bitCounts);
};