package JPMorgan;
import java.util.*;
public class Meeting {
    public static int meetingRooms(int[][] arr) {
        Arrays.sort(arr, Comparator.comparingInt(a -> a[0]));
        int rooms = 1;
        int minRooms = 0;
        int end = arr[0][1];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i][0] < end) {
                rooms++;
            } else {
                rooms = 1;
            }
            minRooms = Math.max(minRooms, rooms);
            end = arr[i][1];
        }
        return minRooms;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = sc.nextInt();
            arr[i][1] = sc.nextInt();
        }
        System.out.println(meetingRooms(arr));
        sc.close();
    }
}
