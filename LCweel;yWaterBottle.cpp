int maxBottlesDrunk(int numBottles,int numExchange){
    int ans=0;
    ans=numBottles;
    int empty=numBottles;
    while(true){
        int currbottles=empty;
        int add=empty/numExchange;
        if(add==0){
            break;
        }
        ans=ans+1;
        empty=empty-numExchange+1;
        numExchange++;
    }
    return ans;
}