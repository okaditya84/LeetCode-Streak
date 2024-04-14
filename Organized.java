package JPMorgan;

import java.util.*;
public class Organized {
    public static int function(int[] arr){
        int c = 0;
        int n = arr.length;
        for(int i=0;i<n-1;i++){
            if(arr[i]%2== arr[i+1]%2){
                while(arr[i]%2 == arr[i+1]%2){
                    arr[i+1] = arr[i+1]/2;
                    c++;
                }
            }
        }
        return c;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(function(arr));
        sc.close();
    }
}
