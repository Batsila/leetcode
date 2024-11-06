function countBits(num: number): number {
    let count = 0;
    while (num > 0) {
        if ((num & 1) == 1) {
            ++count;
        }
        num >>= 1;
    }
    return count;
}

function canSortArray(nums: number[]): boolean {
    const numsWithBitsCount = nums.map(num => [num, countBits(num)]);
    let currentBitCount = 0;
    let maxNum = 0;
    let setMaxNum = 0;

    for (let [num, bitCount] of numsWithBitsCount) {
        if (bitCount == currentBitCount) {
            setMaxNum = Math.max(setMaxNum, num);
        } else {
            maxNum = Math.max(maxNum, setMaxNum);
            setMaxNum = num;
            currentBitCount = bitCount;
        }
        
        if (maxNum > num) {
            return false;
        }
    }

    return true;
};