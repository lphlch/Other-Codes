'''
146. LRU 缓存
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
'''


class ListNode:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

    def __repr__(self) -> str:
        return f'key {self.key}, val {self.val}'


class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}
        self.capacity = capacity
        self.head = ListNode(0, 0)
        self.tail = ListNode(0, 0)
        self.tail.prev = self.head
        self.head.next = self.tail

    def moveToFront(self, list_node):
        print('\nbefore move to front')
        self.printList()
        if self.head.next == list_node:
            return
        # move to front
        n1 = self.head.next
        n2 = list_node.prev
        n4 = list_node.next

        self.head.next, list_node.next = list_node, n1
        n1.prev, list_node.prev = list_node, self.head

        n2.next, n4.prev = n4, n2
        print('\nafter move to front')
        self.printList()

    def printList(self):
        h = self.head
        while h:
            print(h, end='->')
            h = h.next

    def get(self, key: int) -> int:
        print('\nget', key, self.cache)
        self.printList()
        list_node = self.cache.get(key, None)

        if not list_node:
            return -1

        self.moveToFront(list_node)
        # self.printList()
        return list_node.val

    def put(self, key: int, value: int) -> None:
        print('\nput', key, self.cache, 'head', self.head)
        self.printList()

        if key in self.cache:
            list_node = self.cache[key]
            list_node.val = value

            self.moveToFront(list_node)
        else:
            if len(self.cache) >= self.capacity:
                out_node = self.tail.prev
                print('out', out_node.key)
                self.cache.pop(out_node.key)
                self.cache[key] = out_node
                out_node.key = key
                out_node.val = value
                self.moveToFront(out_node)

            else:
                list_node = ListNode(key, value)
                self.cache[key] = list_node
                pre_head = self.head.next
                self.head.next, list_node.next = list_node, self.head.next
                pre_head.prev, list_node.prev = list_node, self.head

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

from 