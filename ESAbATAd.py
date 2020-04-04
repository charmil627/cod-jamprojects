from itertools import combinations
import numpy as np
import sys

def hit(bit): return [
    '_' if byte == '_' else
    '1' if byte =='0' else '0'
    for byte in bit
]

class Quantum():
    def __init__(self, byte):
        self.bit = ['_'] * byte
        self.unkown = list(range(byte))
        self.read(10)
        self.run()

    def read(self, nn):
        for _ in range(nn):
            i = self.unkown.pop()
            self.bit[i] = self.readbits(i+1)
            self.unkown = self.unkown[::-1]
        self.updatestates()

    def readbits(self, i):
        print(i, flush=True)
        return input()

    def updatestates(self):
        self.bitsc  = hit(self.bit)
        self.bitscr = self.bitsc[::-1]
        self.bitsr  = hit(self.bitscr)
        self.state = [self.bit, self.bitsc, self.bitscr, self.bitsr]

    def get_test_index(self):
        candid = list(set(range(BB)) - set(self.unkown))
        maxstates = len(set(map(tuple, self.state)))
        for index in combinations(candid, 2):
            nums = len(set(
                tuple(np.take(state, index))
                for state in self.state
            ))
            if nums == maxstates: return index

    def colle(self):
        test_index = self.get_test_index()
        test = [self.readbits(i+1) for i in test_index]

        self.bit = next(state
            for state in self.state
            if test == list(np.take(state, test_index))
        )

    def run(self):
        while True:
            self.colle()
            try: self.read(8)
            except IndexError: break


TT, BB = map(int, input().split())
print('B:', BB, file=sys.stderr)
for _ in range(TT):
    Quantumay = Quantum(BB)
    print('guess:', ''.join(Quantumay.bit), file=sys.stderr)
    print(''.join(Quantumay.bit), flush=True)
    if input() == 'N': sys.exit()
