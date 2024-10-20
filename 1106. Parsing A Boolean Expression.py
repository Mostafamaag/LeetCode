class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        
        ops = []
        st = []
        mp = {'f' : False, 't': True}

        for c in expression:
            if c == 't' or c == 'f' or c == '(':
                st.append(c)

            elif c == ')':
                op = ops.pop()
                cur = mp[st[-1]]
                while st[-1] != '(':
                    if op == '!':
                        cur = not cur
                    elif op == '&':
                        cur &= mp[st[-1]]
                    elif op == '|':
                        cur |= mp[st[-1]]
                    st.pop()
 
                st.pop()
                st.append('f' if cur == False else 't')

            elif c != ',':
                ops.append(c)

        return mp[st[-1]]
