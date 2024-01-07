class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_dict = defaultdict(list)
        output = []
        for word in strs:
            word_sorted = ''.join(sorted(word))
            anagram_dict[word_sorted].append(word)
        
        for anagram in anagram_dict:
            output.append(anagram_dict[anagram])

        return output
    