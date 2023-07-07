class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        #we need to convert T to F and F to T atmost k times
        #so we need to find the longest subarray with atmost k F's or T's

        #we can use sliding window to find the longest subarray with atmost k F's or T's
        #we can use two pointers to keep track of the start and end of the window
        #we can use a hashmap to keep track of the number of F's and T's in the window
        #we can use a variable to keep track of the max length of the window

        #we can use a variable to keep track of the max length of the window
        maxLen = 0

        #we can use a hashmap to keep track of the number of F's and T's in the window
        hashMap = {}

        #we can use two pointers to keep track of the start and end of the window
        start = 0
        end = 0

        #we can use a variable to keep track of the number of F's and T's in the window
        numF = 0
        numT = 0


        #we can use a while loop to iterate through the string
        while end < len(answerKey):
            #we can add the current character to the hashmap
            if answerKey[end] not in hashMap:
                hashMap[answerKey[end]] = 1
            else:
                hashMap[answerKey[end]] += 1

            #we can increment the number of F's or T's in the window
            if answerKey[end] == 'F':
                numF += 1
            else:
                numT += 1

            #we can use a while loop to increment the start pointer until the number of F's or T's in the window is greater than k
            while numF > k and numT > k:
                #we can decrement the number of F's or T's in the window
                if answerKey[start] == 'F':
                    numF -= 1
                else:
                    numT -= 1

                #we can decrement the number of F's or T's in the hashmap
                hashMap[answerKey[start]] -= 1

                #we can increment the start pointer
                start += 1

            #we can update the max length of the window
            maxLen = max(maxLen, end - start + 1)

            #we can increment the end pointer
            end += 1

        #we can return the max length of the window
        return maxLen

        