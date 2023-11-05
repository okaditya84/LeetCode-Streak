public long minSum(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        long sum1 = 0, sum2 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < m; i++) {
            if (nums1[i] == 0) {
                count1++;
            }
            sum1 += nums1[i];
        }
        for (int i = 0; i < n; i++) {
            if (nums2[i] == 0) {
                count2++;
            }
            sum2 += nums2[i];
        }
        long r = sum1 + count1;
        long s = sum2 + count2;
        if (r > s && count2 == 0) {
            return -1;
        }
        if (s > r && count1 == 0) {
            return -1;
        }
        return Math.max(r, s);
    }