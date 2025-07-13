class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players1 = []
        trainers1 = []
        for p in players:
            heappush(players1, -p)
        for t in trainers:
            heappush(trainers1, -t)

        ret = 0
        while players1 and trainers1:
            while players1 and trainers1[0] > players1[0]:
                heappop(players1)
            if players1:
                heappop(trainers1)
                heappop(players1)
                ret += 1
        
        return ret
