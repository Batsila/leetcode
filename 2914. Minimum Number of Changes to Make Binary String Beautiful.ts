function minChanges(s: string): number {
    let changesCount = 0;
    for (let i = 0; i < s.length; ++i) {
        if (s[2 * i] != s[2 * i + 1]) {
            ++changesCount;
        }
    }
    return changesCount;
};