function maximumSubarraySum(nums: number[], k: number): number {
    const frequencies = new Map<number, number>();
    let sum = 0;
    let left = 0;
    let right = 0;
    let result = 0;
    while (right < nums.length) {
        let num = nums[right];
        sum += num;
        frequencies.set(num, (frequencies.get(num) ?? 0) + 1);
        ++right;
        while (frequencies.get(num)! > 1 || right - left > k) {
            frequencies.set(nums[left], frequencies.get(nums[left])! - 1);
            sum -= nums[left];
            ++left;
        }
        if (right - left == k) {
            result = Math.max(result, sum);
        }
    }

    return result;
};