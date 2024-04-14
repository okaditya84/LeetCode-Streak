
import java.util.*;
public class MinimumCost {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[n];

        for(int i = 0;i<n;i++){
            arr[i] = s.nextInt();
        }
        int sum = 0;
        for(int i = 1;i<n;i++){
            sum += Math.abs(arr[i-1] - arr[i]);
            // System.out.println(sum);
        }

        System.out.println(sum);
    }
}


int findMinimumCost(int tree_node, vector<int> tree_from, vector<int> tree_to, vector<int> tree_weight, int start, int end) {
    int sum =0;
    for(int i=0;i<tree_weight.size();i++){
        sum += weights[i];
    }
    return sum;
}