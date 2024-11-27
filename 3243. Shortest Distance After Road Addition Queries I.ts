function shortestDistanceAfterQueries(n: number, queries: number[][]): number[] {
    const result = [];
    const graph: number[][] = Array(n).fill(null).map(() => [])
    for (let i = 0; i < n - 1; ++i) {
        graph[i].push(i + 1);
    }
    for (let [start, end] of queries) {
        graph[start].push(end);
        result.push(findMinDistence(n, graph));
    }

    return result;
};

function findMinDistence(n: number, graph: number[][]): number {
    const distances = Array(n).fill(Number.MAX_VALUE);
    distances[0] = 0;
    for (let node = 0; node < n; ++node) {
        for (let dist of graph[node]) {
            distances[dist] = Math.min(distances[dist], distances[node] + 1);
        }
    }

    return distances.at(-1);
}