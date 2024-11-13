function countFairPairs(nums: number[], lower: number, upper: number): number {
    nums.sort((a, b) => a - b);
    let result = 0;
    for (let i = 0; i < nums.length; ++i) {
        let lowerPairsCount = lowerBound(nums, i + 1, nums.length, lower - nums[i]);
        let upperPaitCount = upperBound(nums, i + 1, nums.length, upper - nums[i]);
        result += upperPaitCount - lowerPairsCount;
    }
    return result;
};

function lowerBound(nums: number[], left: number, right: number, value: number): number {
    while (left < right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

function upperBound(nums: number[], left: number, right: number, value: number): number {
    while (left < right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}