# ============================================================
# Encode and Decode Strings
# ============================================================

from typing import List

# ============================================================
# Solution: Length-Prefix Encoding (Optimal)
# Time: O(N) | Space: O(1) extra
# ============================================================
class Codec:

    def encode(self, strs: List[str]) -> str:
        # Encode: prefix each string with 'length#'
        return ''.join(f'{len(s)}#{s}' for s in strs)

    def decode(self, s: str) -> List[str]:
        # Decode: read length, skip #, extract characters
        result = []
        i = 0

        while i < len(s):
            # Find the '#' separator
            j = s.index('#', i)

            # Parse the length
            length = int(s[i:j])

            # Extract the string
            result.append(s[j + 1: j + 1 + length])

            # Advance past this string
            i = j + 1 + length

        return result
