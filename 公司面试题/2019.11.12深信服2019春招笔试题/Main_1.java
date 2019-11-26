// 链接：https://www.nowcoder.com/questionTerminal/340e0d941b614a12a661d8d0285decf3
// 来源：牛客网

//其实可以优化成为滚动数组的...

import java.util.Scanner;
public class Main_1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String s = sc.next();
            String sub = sc.next();
            int num[]=new int[1];
            if (isMatch(s, sub,num)) {
                System.out.println(num[0]);
            } else {
                System.out.println("-1");
            }
        }
    }

    public static Boolean isMatch(String s, String sub,int num[]) {
        boolean tmp[][]=new boolean[sub.length()+1][s.length()+1];
        tmp[0][0]=true;
        for (int i = 1; i < tmp.length; i++) {
            int index=0;
            if (sub.charAt(i-1)=='?') {
                index=3;
            }
            for (int j = i; j < tmp[0].length; j++) {
                if (index>0) {
                    if (s.charAt(j-1)!='\u0000' && (tmp[i-1][j-1]||tmp[i][j-1])) {
                        tmp[i][j]=true;
                        index--;
                    }else if (s.charAt(j-1)=='\u0000') {
                        tmp[i][j]=false;
                        index=0;
                    }
                }
                else {
                    if (s.charAt(j-1)==sub.charAt(i-1)) {
                        tmp[i][j]=tmp[i-1][j-1];
                    }
                    else {
                        tmp[i][j]=false;
                    }
                }
            }
        }
        for (int i = 0; i < tmp.length; i++) {
            for (int j = 0; j < tmp[0].length; j++) {
                System.out.print(tmp[i][j]+" ");
            }
            System.out.println();
        }

        int len=tmp.length-1;
        for (int j = 1; j < tmp[0].length; j++) {
            if (tmp[len][j]==true) {
                num[0]=j;
                return true;
            }
        }
        return false;
    }
}