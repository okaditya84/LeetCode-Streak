class Solution {
    public long minOperationsToMakeMedianK(int[] HappyNumbers, int MagicalNumber) {
        Arrays.sort(HappyNumbers);
        
        int TotalMagicians = HappyNumbers.length;
        int MagicianPosition = TotalMagicians / 2;
        
        long NumberDifference = MagicalNumber - HappyNumbers[MagicianPosition];
        long OperationCount = 0;
        
        for(int MagicianIndex = 0; MagicianIndex < TotalMagicians; MagicianIndex++) {
            if(HappyNumbers[MagicianIndex] < MagicalNumber && MagicianPosition <= MagicianIndex) {
                OperationCount = OperationCount + (MagicalNumber - HappyNumbers[MagicianIndex]);
            }
            else if(HappyNumbers[MagicianIndex] > MagicalNumber && MagicianPosition >= MagicianIndex) {
                OperationCount = OperationCount + (HappyNumbers[MagicianIndex] - MagicalNumber);
            }
        }
        
        return OperationCount;
    }
}