class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        rank = [1] * n
        parent = list(range(n))
        comp_Count = n

        def find(node: int) -> int:
            if parent[node] != node:
                parent[node] = find(parent[node])
            return parent[node]

        def union(n1: int, n2: int) -> bool:
            p1, p2 = find(n1), find(n2)
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
            if union(u, v):
                comp_Count -= 1

        return comp_Count
        