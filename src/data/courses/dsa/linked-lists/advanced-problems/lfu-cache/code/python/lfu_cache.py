# ============================================================
# LFU Cache
# ============================================================
from collections import defaultdict, OrderedDict
class LFUCache:
    def __init__(self, capacity):
        self.cap = capacity
        self.key_val = {}    # key -> (val, freq)
        self.freq_keys = defaultdict(OrderedDict)  # freq -> OrderedDict of keys
        self.min_freq = 0

    def _touch(self, key):
        val, freq = self.key_val[key]
        del self.freq_keys[freq][key]
        if not self.freq_keys[freq] and self.min_freq == freq:
            self.min_freq += 1
        self.key_val[key] = (val, freq + 1)
        self.freq_keys[freq + 1][key] = None

    def get(self, key):
        if key not in self.key_val: return -1
        self._touch(key)
        return self.key_val[key][0]

    def put(self, key, value):
        if self.cap <= 0: return
        if key in self.key_val:
            self.key_val[key] = (value, self.key_val[key][1])
            self._touch(key); return
        if len(self.key_val) >= self.cap:
            evict, _ = self.freq_keys[self.min_freq].popitem(last=False)
            del self.key_val[evict]
        self.key_val[key] = (value, 1)
        self.freq_keys[1][key] = None
        self.min_freq = 1
