package JPMorgan;

import java.util.*;

public class ServerSelection {
    public static int getMinServer(int[] arr, int load) {
        int[] dp = new int[load + 1];
        for (int i = 1; i <= load; i++) {
            int mini = Integer.MAX_VALUE;
            for (int j = 0; j < arr.length; j++) {
                if (i >= arr[j] && dp[i - arr[j]] != -1) {
                    mini = Math.min(mini, dp[i - arr[j]]);
                }
            }
            dp[i] = (mini == Integer.MAX_VALUE) ? -1 : mini + 1;
            if (mini == Integer.MAX_VALUE) {
                dp[i] = -1;
            } else {
                dp[i] = mini + 1;
            }

        }
        return dp[load];
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
        }
        int l = s.nextInt();
        int server = coinChange(arr, l);
        System.out.println(server);
    }

}
