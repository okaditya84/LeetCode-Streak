package JPMorgan;
import java.util.*;
public class DistincDigitNumbers {
    public static boolean diff(int n){
        Set<Integer> s = new HashSet<>();
        if(n<0) n = -1*n;
        while(n>0){
            if(s.contains(n%10)){
                return false;
            }
            else{
                s.add(n%10);
            }
            n/=10;
        }
        
        return true;
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int m = s.nextInt();
        int count = 0;
        for(int i = n;i<=m;i++){
            if(diff(i)){
                count++;
                System.out.println(i);
            }
        }
        System.out.println(count);
    }
    
}
