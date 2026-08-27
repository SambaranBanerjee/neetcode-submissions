class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)] #Adjacency matrix
        in_degree = [0] * numCourses #Edge count
        
        for [crs,pre] in prerequisites:
            adj[pre].append(crs)
            in_degree[crs] += 1 #Counting incoming edges

        q = deque([i for i in range(numCourses) if in_degree[i] == 0])
        completed = 0

        while q:
            curr = q.popleft()
            completed += 1

            for neighbor in adj[curr]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    q.append(neighbor)
        
        return completed == numCourses

