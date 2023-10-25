lass Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        //find the unique elements from the vector
        unordered_set<int> s;
        for(int i=0;i<candyType.size();i++){
            s.insert(candyType[i]);
        }
        if (s.size()>=candyType.size()/2){
            return candyType.size()/2;
        }
        else return s.size();
        
    }
};