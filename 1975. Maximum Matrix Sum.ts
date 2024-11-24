function maxMatrixSum(matrix: number[][]): number {
    let sum = 0;
    let minAbs = Number.MAX_VALUE;
    let negativeCount = 0;
    matrix.flat().forEach(num => {
        sum += Math.abs(num);
        minAbs = Math.min(minAbs, Math.abs(num));
        negativeCount += num < 0 ? 1 : 0;
    });
    if (negativeCount % 2 == 1) {
        sum -= 2 * minAbs;
    }

    return sum;
};