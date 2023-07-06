class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        #find the element that appears only once
        #use a dictionary to store the number of times each element appears


        #create a dictionary
        dict = {}

        #iterate through the list
        for i in nums:
            #if the element is not in the dictionary, add it
            if i not in dict:
                dict[i] = 1
            #if the element is in the dictionary, increment its value
            else:
                dict[i] += 1

        #iterate through the dictionary
        for key, value in dict.items():
            #if the value is 1, return the key
            if value == 1:
                return key

                    