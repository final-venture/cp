# Own
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
    
# Model
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_dict = defaultdict(list)

        for word in strs:
            occurrences = [0] * 26
            for character in word:
                occurrences[ord(character) - ord('a')] += 1
            anagram_dict[tuple(occurrences)].append(word)
        
        return anagram_dict.values()
