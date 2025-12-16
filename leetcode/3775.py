class Solution:
    def reverseWords(self, s: str) -> str:
        l = s.split(' ')
        ret = l[0]
        cnt = 0
        vowels = ['a', 'e', 'i', 'o', 'u']
        for i in range(len(l[0])):
            if l[0][i] in vowels:
                cnt += 1

        for i in range(1, len(l)):
            curr_cnt = 0
            ret += ' '
            for j in range(len(l[i])):
                if l[i][j] in vowels:
                    curr_cnt += 1
            if (curr_cnt == cnt):
                ret += l[i][::-1]
            else:
                ret += l[i]

        return ret
