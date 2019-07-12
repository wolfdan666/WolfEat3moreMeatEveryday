class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        paren_map = {')':'(',']':'[','}':'{'}
        for c in s:
            # 这里是 C 是和paren_map的序列值进行比较的
            # 不是右括号，就加到stack里面
            if c not in paren_map:
                stack.append(c)
            elif not stack or paren_map[c] != stack.pop():
                return False
        return not stack