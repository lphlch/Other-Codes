class TreeNode:
    def __init__(self, val=None) -> None:
        self.val = val
        self.children = {}
        self.isEnd = False

    def __str__(self) -> str:
        return str(self.val) + str(self.children)


class Trie:
    def __init__(self):
        self.root = TreeNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for c in word:
            # insert a node
            if c not in cur.children:
                cur.children[c] = TreeNode(c)
            cur = cur.children[c]
        cur.isEnd = True

    def search(self, word: str) -> bool:
        cur = self.root
        for c in word:
            cur = cur.children.get(c, None)
            if not cur:
                return False
        return cur.isEnd

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for c in prefix:
            cur = cur.children.get(c, None)
            if not cur:
                return False
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
