function decrypt(code: number[], k: number): number[] {
    const n = code.length;
    const result = Array(code.length).fill(0);
    if (k != 0) {
        let left = k > 0 ? 1 : n + k;
        let right = k > 0 ? k + 1 : n;
        let sum = code.slice(left, right).reduce((sum, current) => sum + current);
        for (let i = 0; i < n; ++i) {
            result[i] = sum;
            sum -= code[left % n];
            sum += code[right % n]
            ++left;
            ++right;
        }
    }

    return result;
};