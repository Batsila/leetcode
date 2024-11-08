function getMaximumXor(nums: number[], maximumBit: number): number[] {
    const result = [];
    let xor = nums.reduce((x, num) => x ^ num);
    for (let i = nums.length - 1; i >= 0; --i) {
        let k = 0;
        for (let bit = 0; bit < maximumBit; ++bit) {
            if (((xor >> bit) & 1) == 0) {
                k += 1 << bit;
            }
        }
        result.push(k);
        xor ^= nums[i];
    }

    return result;
};