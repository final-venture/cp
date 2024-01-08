class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_dict = defaultdict(list)

        for word in strs:
            occurrences = [0] * 26
            for character in word:
                occurrences[ord(character) - ord('a')] += 1
            anagram_dict[tuple(occurrences)].append(word)
        
        return anagram_dict.values()
