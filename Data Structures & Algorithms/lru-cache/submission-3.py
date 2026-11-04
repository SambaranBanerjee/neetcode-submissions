class Node:
    def __init__(self, key = 0, value = 0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove(self, curr):
        n = curr.next
        p = curr.prev
        p.next = n
        n.prev = p
    
    def _insert_at_head(self, curr):
        n = self.head.next
        curr.next = n
        curr.prev = self.head
        self.head.next = curr
        n.prev = curr

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            self._remove(node)
            self._insert_at_head(node)
            return node.value       
        return -1
    
    def put(self, key: int, value: int) -> None:
        
        if key in self.cache:
            node = self.cache[key]
            self._remove(node)
        node = Node(key, value)
        self._insert_at_head(node)
        self.cache[key] = node

        if len(self.cache) > self.capacity:
            lru = self.tail.prev
            self._remove(lru)
            del self.cache[lru.key]    
        
