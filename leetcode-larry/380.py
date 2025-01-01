class RandomizedSet:

    def __init__(self):
        self.data = {}
        self.array = []

    def insert(self, val: int) -> bool:
        if val not in self.data:
            self.data.update({val: len(self.array)})
            self.array.append(val)
            return True
        return False

    def remove(self, val: int) -> bool:
        if val in self.data:
            if self.array[-1] != val:
                tmpvar = self.array.pop()
                tmpidx = self.data[val]
                self.array[tmpidx] = tmpvar
                self.data.update({tmpvar: tmpidx})
            else:
                self.array.pop()
            self.data.pop(val)
            return True
        return False

    def getRandom(self) -> int:
        rand = randint(0, len(self.array) - 1)
        return self.array[rand]

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
    