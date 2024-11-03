function rotateString(s: string, goal: string): boolean {
    if (s.length == goal.length) {
        let source = s + s;
        return source.includes(goal);
    } else {
        return false;
    }
};