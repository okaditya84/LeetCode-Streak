class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        #return all possible permutations
        #use backtracking
        #use a list to store the current permutation
        #use a list to store the result
        #use a set to store the used numbers
        #if the length of the current permutation is equal to the length of the nums, add the current permutation to the result
        #else, for each number in nums, if the number is not in the used set, add the number to the current permutation, add the number to the used set, call the function recursively, remove the number from the current permutation, remove the number from the used set
        #return the result
        result = []
        def backtrack(current, used):
            if len(current) == len(nums):
                result.append(current[:])
            else:
                for num in nums:
                    if num not in used:
                        current.append(num)
                        used.add(num)
                        backtrack(current, used)
                        current.pop()
                        used.remove(num)
        backtrack([], set())
        return result
        