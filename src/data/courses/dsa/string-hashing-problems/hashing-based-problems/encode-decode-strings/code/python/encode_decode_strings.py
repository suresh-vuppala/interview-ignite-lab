class Codec:
    def encode(self, strs: List[str]) -> str:
        # Encode: "length#string" format — handles any character
        return ''.join(f'{len(s)}#{s}' for s in strs)

    def decode(self, s: str) -> List[str]:
        result, i = [], 0
        while i < len(s):
            j = s.index('#', i)           # Find '#'
            length = int(s[i:j])           # Parse length
            result.append(s[j+1:j+1+length])  # Extract string
            i = j + 1 + length
        return result