class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        available_rooms = list(range(n))
        busy_rooms = []
        meetings_cnt = [0] * n

        meetings.sort()

        for start, end in meetings:
            while busy_rooms and busy_rooms[0][0] <= start:
                _end_time, room_number = heappop(busy_rooms)
                heappush(available_rooms, room_number)

            duration = end - start
            
            if available_rooms:
                room_to_use = heappop(available_rooms)
                meetings_cnt[room_to_use] += 1
                heappush(busy_rooms, (start + duration, room_to_use))
            else:
                earliest_free_time, room_to_use = heappop(busy_rooms)
                meetings_cnt[room_to_use] += 1
                new_end_time = earliest_free_time + duration
                heappush(busy_rooms, (new_end_time, room_to_use))

        return meetings_cnt.index(max(meetings_cnt))
        