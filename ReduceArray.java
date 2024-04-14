import java.util.*;

public class ReduceArray {
    public static int minimumSteps(int[] arr) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int num : arr) {
            pq.offer(num);
        }
        int steps = 0;
        while(pq.size() > 1){
            int a = pq.poll();
            int b = pq.poll();
            pq.offer(a + b);
            steps += (a + b);
        }
        return steps;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(minimumSteps(arr));
        sc.close();
    }
}
