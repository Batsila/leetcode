function maximumBeauty(items: number[][], queries: number[]): number[] {
    items.sort(([price1, beauty1], [price2, beauty2]) => price1 == price2 ? beauty2 - beauty1 : price1 - price2);
    let maxBeauty = items[0][1];
    for (let i = 0; i < items.length; ++i) {
        maxBeauty = Math.max(maxBeauty, items[i][1]);
        items[i][1] = maxBeauty;
    }

    const result = [];
    for (let query of queries) {
        result.push(getMaxBeauty(items, query));
    }
    
    return result;
};

function getMaxBeauty(items: number[][], price: number): number {
    let left = 0;
    let right = items.length - 1;
    let maxBeauty = 0;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (items[mid][0] > price) {
            right = mid - 1;
        } else {
            maxBeauty = Math.max(maxBeauty, items[mid][1]);
            left = mid + 1;
        }
    }
    return maxBeauty;
}