function findChampion(n: number, edges: number[][]): number {
    const isWeaker = Array(n).fill(false);
    for (let edge of edges) {
        isWeaker[edge[1]] = true;
    }
    if (isWeaker.reduce((weakerCount, current) => current ? weakerCount + 1 : weakerCount, 0) == n - 1) {
        return isWeaker.map((isWeaker, index) => [isWeaker, index]).find(x => x[0] == false)[1];
    } else {
        return -1;
    }
};