package com.study.out;

import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static final int inf = 99999999;
    static final int dy[] = {0, 1, 0, -1};
    static final int dx[] = {-1, 0, 1, 0};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        scanner.nextLine();
        int[][] dist = new int[n + 1][n + 1];
        int[][] arr = new int[n + 1][n + 1];
        boolean[][] check = new boolean[n + 1][n + 1];

        for (int i = 0; i < n; i++)
        {
            String str = scanner.nextLine();
            for (int j = 0; j < str.length(); j++)
            {
                arr[i][j] = str.charAt(j) - '0';
                dist[i][j] = inf;
            }
        }

        PriorityQueue<Edge> queue = new PriorityQueue<>();
        queue.add(new Edge(0, 0, 0));
        dist[0][0] = 0;

        while (!queue.isEmpty())
        {
            Edge edge = queue.poll();
            if (check[edge.getY()][edge.getX()])
                continue;

            check[edge.getY()][edge.getX()] = true;

            for (int i = 0; i < 4; i++)
            {
                int ny = dy[i] + edge.getY();
                int nx = dx[i] + edge.getX();

                if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                    continue;

                int num = arr[ny][nx];
                num = 1 - num;
                if (dist[ny][nx] > dist[edge.getY()][edge.getX()] + num)
                {
                    dist[ny][nx] = dist[edge.getY()][edge.getX()] + num;
                    queue.add(new Edge(ny, nx, dist[ny][nx]));
                }
            }
        }

        System.out.println(dist[n - 1][n - 1]);
    }
}

class Edge implements Comparable<Edge> {
    int y; int x;
    int cost;

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public int getCost() {
        return cost;
    }

    public Edge(int y, int x, int cost) {
        this.y = y;
        this.x = x;
        this.cost = cost;
    }

    @Override
    public int compareTo(Edge o) {
        return this.getCost() - o.getCost();
    }
}

