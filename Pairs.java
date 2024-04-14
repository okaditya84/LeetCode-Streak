
import java.util.*;
public class Pairs {

    public static int pairCount(int[] arr1,int[] arr2){
        int n = arr1.length;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(arr1[i]>arr2[i]){
                cnt++;
            }
        }
        return cnt;
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n1 = s.nextInt();
        int [] arr1 = new int[n1];
        int n2 = s.nextInt();
        int[] arr2 = new int[n2];

        for(int i = 0;i<n1;i++){
            arr1[i] = s.nextInt();
        }
        for(int i = 0;i<n2;i++){
            arr2[i] = s.nextInt();
        }

        int ans = pairCount(arr1,arr2);
        System.out.println(ans);
    }
    
}
