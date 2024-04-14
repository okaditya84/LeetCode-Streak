
import java.util.*;
public class StringReplacement2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String s1 = scanner.next();
        String s2 = scanner.next();
        
        int n = s1.length();
        int m = s2.length();
        
        StringBuilder neww = new StringBuilder();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) == '?') cnt++;
        }

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s1.charAt(i) == '?' && s2.charAt(j) != '?') {
                neww.append(s2.charAt(j));
            } else if (s1.charAt(i) != '?' && s2.charAt(j) != '?') {
                neww.append(s2.charAt(j));
            } else {
                neww.append(s1.charAt(i));
            }
            i++;
            j++;
        }

        if (j < m)
            neww.append(s2.substring(j, m));

        if (i < n)
            neww.append(s1.substring(i, n));

        if (cnt > m){
            System.out.println("-1");
        } else {
            System.out.println(neww);
        }
    }
}
