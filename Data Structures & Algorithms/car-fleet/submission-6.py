class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        if n == 0:
            return 0
        time = [0.0] * n
        cars = [[position[i],speed[i]] for i in range(n)]
        cars.sort(key=lambda x: x[0], reverse=True)

        for i in range(n):
            time[i] = (target - cars[i][0]) / cars[i][1]

        maxTime = time[0]
        fleet = 1
        for i in range(1, n):
            if time[i] > maxTime:
                fleet += 1
                maxTime = time[i]
        return fleet