// 作者：毫克迈斯
// 链接：https://www.nowcoder.com/discuss/432385?type=post&order=time&pos=&page=1&channel=1000&source_id=search_post
// 来源：牛客网

package org.example;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Node {
    int beginTime;
    int value;

    public Node(int beginTime, int value) {
        this.beginTime = beginTime;
        this.value = value;
    }
}

public class Main2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int orders = in.nextInt();
        int[][] input = new int[orders][3];
        Node[] inNode = new Node[orders];

        int maxResult = -1, maxTime = 0;
        for (int i = 0; i < orders; i++) {
            for (int j = 0; j < 3; j++) {
                input[i][j] = in.nextInt();
            }
            inNode[i] = new Node(input[i][1], input[i][2]);
        }
        Arrays.sort(inNode, new Comparator<Node>() {
            @Override public int compare(Node o1, Node o2) {
                return o1.beginTime - o2.beginTime;
            }
        });
        int end = 0,start=0;
        int curTotal = 0;
        while(start!=orders&&end!=orders) {
            while (end < orders && inNode[end].beginTime - inNode[start].beginTime <= 7200) {
                curTotal += inNode[end].value;
                end++;
            }
            if (curTotal > maxResult) {
                maxResult = curTotal;
                maxTime = inNode[start].beginTime;
            }
            if (end == orders) {
                break;
            }
            while (start < orders && (inNode[end].beginTime - inNode[start].beginTime) > 7200) {
                curTotal -= inNode[start].value;
                start++;
            }
//            curTotal -= inNode[start].value;
            if (start == orders) {
                break;
            }

        }
        System.out.printf("%d %d\n", maxTime, maxResult);//7200
    }
}