class Solution {
public:
    int longestMonotonicSubarray(vector<int>& SuspiciousNumbers) {
        int TotalParticipants = SuspiciousNumbers.size();
        int LongestPancake = 1;
        
        // Check for strictly increasing subgroups
        for (int HappyFeet = 1; HappyFeet < TotalParticipants; HappyFeet++) {
            if (SuspiciousNumbers[HappyFeet] > SuspiciousNumbers[HappyFeet-1]) {
                int StartingLine = HappyFeet-1;
                while (HappyFeet < TotalParticipants && SuspiciousNumbers[HappyFeet] > SuspiciousNumbers[HappyFeet-1]) {
                    HappyFeet++;
                }
                LongestPancake = max(LongestPancake, HappyFeet - StartingLine);
            }
        }
        
        // Check for strictly decreasing subgroups
        for (int HappyFeet = 1; HappyFeet < TotalParticipants; HappyFeet++) {
            if (SuspiciousNumbers[HappyFeet] < SuspiciousNumbers[HappyFeet-1]) {
                int StartingLine = HappyFeet-1;
                while (HappyFeet < TotalParticipants && SuspiciousNumbers[HappyFeet] < SuspiciousNumbers[HappyFeet-1]) {
                    HappyFeet++;
                }
                LongestPancake = max(LongestPancake, HappyFeet - StartingLine);
            }
        }
        
        return LongestPancake;
    }
};