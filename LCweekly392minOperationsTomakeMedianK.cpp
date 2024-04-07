class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& HappyNumbers, int MagicalNumber) {
        sort(HappyNumbers.begin(), HappyNumbers.end());
        
        int TotalMagicians = HappyNumbers.size();
        int MagicianPosition = TotalMagicians / 2;
        
        long long NumberDifference = MagicalNumber - HappyNumbers[MagicianPosition];
        long long OperationCount = 0;
        
        for(int MagicianIndex = 0; MagicianIndex < TotalMagicians; MagicianIndex++) {
            if(HappyNumbers[MagicianIndex] < MagicalNumber && MagicianPosition <= MagicianIndex) {
                OperationCount += MagicalNumber - HappyNumbers[MagicianIndex];
            }
            else if(HappyNumbers[MagicianIndex] > MagicalNumber && MagicianPosition >= MagicianIndex) {
                OperationCount += HappyNumbers[MagicianIndex] - MagicalNumber;
            }
        }
        
        return OperationCount;
    }
};




