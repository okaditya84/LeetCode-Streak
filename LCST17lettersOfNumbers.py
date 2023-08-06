class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        d1={2:["a","b","c"],3:["d","e","f"],4:["g","h","i"],5:["j","k","l"],6:["m","n","o"],7:["p","q","r","s"],8:["t","u","v"],9:["w","x","y","z"]}
        #user will input any number as a string 
        #split the numbers and find all the possible combinations
        #return the list of all the possible combinations


        #if the user input is empty return empty list
        if len(digits)==0:
            return []
        #if the user input is 1 return empty list
        if len(digits)==1:
            return d1[int(digits)]
        #now generalize the solution for any length of input
        #for example if the user input is 23    
        #we will first find the possible combinations of 2 and 3
        #then we will find the possible combinations of 2 and 3
        if len(digits)>=2:
            #split digits and store in a list
            digits=list(digits)
            #convert each element of the list to integer
            digits=[int(i) for i in digits]
            #now find all the possible combinations of each element of the list
            for j in digits:
                digits[digits.index(j)]=d1[j]
            #now we have a list of lists
            #we need to find all the possible combinations of the elements of the list
            #we will use itertools.product to find all the possible combinations
            #we will use * to unpack the list of lists
            #we will use map to convert the tuples to list
            #we will use join to convert the list to string
            return list(map("".join,product(*digits)))
            