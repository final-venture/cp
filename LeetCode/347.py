class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        occurrences_dict = defaultdict(int)
        output = []

        for i in nums:
            occurrences_dict[i] += 1
            
        for i in range(k):
            max_key = max(occurrences_dict, key=occurrences_dict.get)
            output.append(max_key)
            occurrences_dict.pop(max_key)

        return output
    