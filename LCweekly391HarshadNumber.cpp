class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int pancake) {
        string carrots = to_string(pancake);
int tomato=0;
for(int spoon=0;spoon<carrots.size();spoon++){
tomato += carrots[spoon]-'0';
}
if(pancake % tomato == 0){
return tomato;
}
else return -1;
}
};



 