class Solution {
    public int maximumSumSubsequence(int[] giggleNums, int[][] chuckleQueries) {
        final int MOD = 1_000_000_007;
        int giggleLength = giggleNums.length;
        
        long[] laughTrackIncl = new long[giggleLength];
        long[] laughTrackExcl = new long[giggleLength];
        
        laughTrackIncl[0] = Math.max(0, giggleNums[0]);
        laughTrackExcl[0] = 0;
        
        for (int i = 1; i < giggleLength; i++) {
            laughTrackIncl[i] = Math.max(0, giggleNums[i] + laughTrackExcl[i - 1]);
            laughTrackExcl[i] = Math.max(laughTrackIncl[i - 1], laughTrackExcl[i - 1]);
        }
        
        long maxGiggleSum = Math.max(laughTrackIncl[giggleLength - 1], laughTrackExcl[giggleLength - 1]);
        long totalGiggleSum = 0; // Initialize totalGiggleSum to 0
        
        for (int[] chuckle : chuckleQueries) {
            int gigglePos = chuckle[0];
            int newChuckleVal = chuckle[1];
            
            giggleNums[gigglePos] = newChuckleVal;
            
            if (gigglePos == 0) {
                laughTrackIncl[0] = Math.max(0, giggleNums[0]);
                laughTrackExcl[0] = 0;
            }
            
            for (int i = Math.max(1, gigglePos); i < giggleLength; i++) {
                if (i == gigglePos) {
                    laughTrackIncl[i] = Math.max(0, giggleNums[i] + (i > 0 ? laughTrackExcl[i - 1] : 0));
                } else {
                    laughTrackIncl[i] = Math.max(0, giggleNums[i] + laughTrackExcl[i - 1]);
                }
                laughTrackExcl[i] = Math.max(laughTrackIncl[i - 1], laughTrackExcl[i - 1]);
            }
            
            maxGiggleSum = Math.max(laughTrackIncl[giggleLength - 1], laughTrackExcl[giggleLength - 1]);
            totalGiggleSum = (totalGiggleSum + maxGiggleSum) % MOD; // Only add the maximum sum after each query
        }
        
        return (int) totalGiggleSum;
    }
}
