
import java.util.*;
public class SystemAndStrings {

    public static List<String> getWho(List<String> s) {
        List<String> ans = new ArrayList<>();
        for (String x : s) {
            int vowels = 0;
            int oddCnt = 0, evenCnt = 0;

            for (int i = 0; i < x.length(); i++) {
                char ch = x.charAt(i);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowels++;
                } else {
                    if ((vowels & 1) == 1 && vowels != 0) oddCnt++;
                    else if (vowels != 0 && vowels % 2 == 0) evenCnt++;
                    vowels = 0;
                }
            }
            if (vowels != 0) {
                if (vowels % 2 == 0) evenCnt++;
                else oddCnt++;
            }

            if (oddCnt == 0 && evenCnt == 0) ans.add("Chris");
            else if (oddCnt >= evenCnt) ans.add("Alex");
            else ans.add("Chris");
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        List<String> s = new sayList<>();
        for (int i = 0; i < n; i++) {
            s.add(scanner.nextLine());
        }
        List<String> ans = solve(s);
        for (String s : ans) {
            System.out.println(s);
        }
        scanner.close();
    }
}
