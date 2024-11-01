function makeFancyString(s: string): string {
    if (s.length > 2) {
        const stack = [s[0], s[1]];
        for (let i = 2; i < s.length; ++i) {
            if (stack.at(-2) != stack.at(-1) || stack.at(-1) != s[i]) {
                stack.push(s[i]);
            }
        }
        return stack.filter(x => x).join("");
    } else {
        return s;
    }
};