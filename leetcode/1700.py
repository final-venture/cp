class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        one = students.count(1)
        zero = students.count(0)
        sandwiches = deque(sandwiches)
        students = deque(students)

        while sandwiches:
            if (sandwiches[0] == 1 and not one) or (sandwiches[0] == 0 and not zero):
                return len(students)
            t = students.popleft()
            if sandwiches[0] == t:
                if t == 1:
                    one -= 1
                else:
                    zero -= 1
                sandwiches.popleft()
            else:
                students.append(t)
        
        return 0
