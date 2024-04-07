class Solution {
public:
    string getSmallestString(string MagicallyCreatedString, int AvailableTransformations) {
        int TotalMagicians = MagicallyCreatedString.size();
        string FinalResult = "";
        
        for(int MagicianIndex = 0; MagicianIndex < TotalMagicians; MagicianIndex++) {
            int PossibleTransformation = min(MagicallyCreatedString[MagicianIndex] - 'a', 26 - (MagicallyCreatedString[MagicianIndex] - 'a'));
            if(AvailableTransformations >= PossibleTransformation) {
                FinalResult += 'a';
                AvailableTransformations -= PossibleTransformation;
            }
            else {
                FinalResult += char((int)MagicallyCreatedString[MagicianIndex] - AvailableTransformations);
                AvailableTransformations = 0;
            }
        }
        
        return FinalResult;
    }
};