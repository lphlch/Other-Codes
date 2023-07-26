'''
380. O(1) 时间插入、删除和获取随机元素

实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。

380. Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

'''

# use list + hash map, when remove, move the last element to the removed position

from random import choice


class RandomizedSet:

    def __init__(self):
        self.l = []
        self.h = {}

    def insert(self, val: int) -> bool:
        if self.h.get(val, None) is not None:
            return False
        else:
            self.l.append(val)
            self.h[val] = len(self.l) - 1
            return True

    def remove(self, val: int) -> bool:
        if self.h.get(val, None) is None:
            return False
        else:
            self.l[self.h[val]] = self.l[-1]
            self.h[self.l[-1]] = self.h[val]

            # remove specified key and return the corresponding value
            self.h.pop(val)

            self.l.remove(self.l[-1])
            return True

    def getRandom(self) -> int:
        # Choose a random element from a non-empty sequence.
        return choice(self.l)
