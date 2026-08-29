class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = list(range(n + 1))
        rank = [1] * (n + 1)

        def find(node: int) -> int:
            if parent[node] != node:
                parent[node] = find(parent[node])
            return parent[node]

        def union(u: int,v: int) -> bool:
            p1, p2 = find(u), find(v)
            if p1 == p2:
                return False
            
            if rank[p1] < rank[p2]:
                parent[p1] = p2
            elif rank[p2] < rank[p1]:
                parent[p2] = p1
            else:
                parent[p1] = p2
                rank[p2] += 1
            
            return True

        for u, v in edges:
            if not union(u, v):
                return [u, v]

        return []