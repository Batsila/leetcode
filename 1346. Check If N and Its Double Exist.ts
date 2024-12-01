function checkIfExist(arr: number[]): boolean {
    const set = new Set<Number>();
    for (let num of arr) {
        if (set.has(num * 2) || (num % 2 == 0 && set.has(num / 2))) {
            return true;
        } else {
            set.add(num);
        }
    }
    return false;
};