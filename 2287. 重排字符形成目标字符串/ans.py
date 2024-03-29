
from cmath import inf
from collections import Counter

class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        ans = inf
        cnt_s = Counter(s)
        for c, cnt in Counter(target).items():
            ans = min(ans, cnt_s[c] // cnt)
            if ans == 0:
                return 0
        return ans


c = Solution()
c.rearrangeCharacters("ilovecodingonleetcode","code")