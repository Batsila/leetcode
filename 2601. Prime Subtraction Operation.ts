function primeSubOperation(nums: number[]): boolean {
    let maxItem = Math.max(...nums);
    const isPrime = getPrimes(maxItem);

    let ind = 0;
    let val = 1;
    while (ind < nums.length) {
        let delta = nums[ind] - val;
        if (delta >= 0) {
            if (delta == 0 || isPrime[delta]) {
                ++ind;
            }
            ++val;
        } else {
            return false;
        }
    }

    return true;
};

function getPrimes(n: number): number[] {
    const isPrime = Array(n).fill(true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (let i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (let j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}