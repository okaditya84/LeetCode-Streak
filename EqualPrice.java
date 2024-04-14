
import java.util.*;

public class EqualPrice {
    public static List<Integer> minOperationsToEqualPrices(List<Integer> prices, List<Integer> queries) {
        List<Integer> minOperations = new ArrayList<>();
        for(int i:queries){
            int sum = 0;
            for(int j:prices){
                sum += Math.abs(i-j);
            }
            minOperations.add(sum);
        }
        return minOperations;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int q = s.nextInt();
        List<Integer> arr = new ArrayList<>();
        List<Integer> queries = new ArrayList<>();

        for(int i = 0;i<n;i++){
            arr.add(s.nextInt());
        }
        for(int i = 0;i<q;i++){
            queries.add(s.nextInt());
        }
        List<Integer> result = minOperationsToEqualPrices(arr, queries);
        System.out.println(result);
        s.close();   
    }    
}

// Time Complexity: O(N*Q)
// Space Complexity: O(Q)
