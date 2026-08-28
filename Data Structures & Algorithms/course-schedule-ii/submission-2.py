class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        in_degree = [0] * numCourses

        for a, b in prerequisites: # a -> b 
            adj[b].append(a)
            in_degree[a] += 1 # because we are counting multiple neighbors of a

        q = deque([i for i in range(numCourses) if in_degree[i] == 0])
        result = []

        while q:
            curr = q.popleft()
            result.append(curr)
            
            for neighbor in adj[curr]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    q.append(neighbor)

        return result if len(result) == numCourses else []


