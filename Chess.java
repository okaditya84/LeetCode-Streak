

import java.util.*;
public class Chess {
    public static int chessTournament(int[] arr, int k) {
        int temp = arr[0];
        Queue<Integer> q = new LinkedList<>();
        int count = 0;
        for (int i = 1; i < arr.length; i++) {
            q.offer(arr[i]);
        }
        while (count < k) {
            int opp = q.poll();
            if (temp > opp) {
                q.offer(opp);
                count++;
            } else {
                q.offer(temp);
                temp = opp;
                count = 1;
            }
        }
        return temp;
    }
    // public static void main(String[] args) {
    //     Scanner sc = new Scanner(System.in);
    //     int n = sc.nextInt();
    //     int[] arr = new int[n];
    //     for (int i = 0; i < n; i++) {
    //         arr[i] = sc.nextInt();
    //     }
    //     int k = sc.nextInt();
    //     System.out.println(chessTournament(arr, k));
    // }


// Time Complexity: O(N)
// Space Complexity: O(N)

    public static void main(String[] args) {
        // Example test case
        int[] arr = {1,2,3,4,5}; // Strength of players
        int k = 3; // Number of rounds
        System.out.println("Winner's strength after " + k + " rounds: " + Chess.chessTournament(arr, k));
    }
}