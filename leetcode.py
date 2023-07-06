class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money<children:
            return -1
        if money==children:
            return -1
        
        if children*8==money:
            return children

        if children*8<money:
            count=0
            for i range (children,0,-1):
                if i*8<money:
                    count=count+1
                    money=money-i*8
                if 

