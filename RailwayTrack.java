

import java.util.*;
public class RailwayTrack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int teamSize_1 = sc.nextInt();
        int teamSize_2 = sc.nextInt();
        int p = sc.nextInt();
        int max_teams_1 = p / teamSize_1;
        int min_teams = Integer.MAX_VALUE;
        for (int i = 0; i <= max_teams_1; i++) {
            int remain = p - i * teamSize_1;
            if (remain % teamSize_2 == 0) {
                int num_teams_2 = remain / teamSize_2;
                min_teams = Math.min(min_teams, i + num_teams_2);
            }
        }
        if(min_teams == Integer.MAX_VALUE){
            System.out.println(-1);
        }else{
            System.out.println(min_teams);
        }
        sc.close();
    }
}
