class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []
        rows, cols = len(heights), len(heights[0])

        pac_visited = set()
        atl_visited = set()

        pac_q = deque()
        atl_q = deque()

        for r in range(rows):
            pac_visited.add((r,0))
            pac_q.append((r,0))

            atl_visited.add((r,cols - 1))
            atl_q.append((r,cols - 1))

        for c in range(cols):
            pac_visited.add((0,c))
            pac_q.append((0,c))

            atl_visited.add((rows - 1, c))
            atl_q.append((rows - 1, c))

        directions = [(1,0) , (-1,0), (0,1), (0, -1)]
        
        def bfs(visited:set, q:deque):
            while q:
                row, col = q.popleft()
                for dr, dc in directions:
                    r = row + dr
                    c = col + dc
                    if (0 <= r < rows and 
                       0 <= c < cols and 
                       (r,c) not in visited and
                       heights[r][c] >= heights[row][col]
                    ):
                        visited.add((r,c))
                        q.append((r,c))

        bfs(pac_visited,pac_q)
        bfs(atl_visited,atl_q)  

        return [[r,c] for r,c in (pac_visited & atl_visited)]