from collections import deque

def potentialOfWinner(potential,k):
    n=len(potential)
    x=potential[0]
    m=0
    for i in range(1,n):
        if m!=k:
            if(x>potential[i]):
                m+=1
            else:
                x=potential[i]    
                m=1
    return x
potential = [4,3,4,2,1,4,3]  # Strength of players
k = 3  # Number of rounds
print("Winner's strength after", k, "rounds:", potentialOfWinner(potential, k))                