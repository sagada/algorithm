package com.study.out;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    static final int inf = 99999999;
    static final int dy[] = {0,1,0,-1};
    static final int dx[] = {-1,0,1,0};
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        String str = in.readLine();
        String tt [] = str.split(" ");

        int m = Integer.parseInt(tt[0]);
        int n = Integer.parseInt(tt[1]);
        int [][] arr = new int[n + 1][m + 1];
        int [][] dist = new int[n + 1][m + 1];
        boolean [][] check = new boolean[n + 1][m + 1];
        for (int i = 0; i <n ; i++)
        {
            String s = in.readLine();
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = s.charAt(j) - '0';
                dist[i][j] = inf;
            }
        }

        PriorityQueue<Edge> queue= new PriorityQueue<>();
        dist[0][0] = 0;

        queue.add(new Edge(0, 0, 0));

        while(!queue.isEmpty())
        {
            Edge edge = queue.poll();
            if (check[edge.getY()][edge.getX()])
                continue;

            check[edge.getY()][edge.getX()] = true;
            for (int i = 0; i < 4; i++)
            {
                int ny = dy[i] + edge.getY();
                int nx = dx[i] + edge.getX();
                if (ny <0 || nx < 0 || ny >= n || nx >= m)
                    continue;
                int nextSum = arr[ny][nx];

                if (dist[ny][nx] > dist[edge.getY()][edge.getX()] + nextSum)
                {
                    dist[ny][nx] = dist[edge.getY()][edge.getX()] + nextSum;
                    queue.add(new Edge(ny, nx, dist[ny][nx]));
                }
            }
        }

        System.out.println(dist[n - 1][m - 1]);
    }
}

class Edge implements Comparable<Edge>{
    int y; int x;
    int cost;

    public Edge(int y, int x, int cost) {
        this.y = y;
        this.x = x;
        this.cost = cost;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getCost() {
        return cost;
    }

    public void setCost(int cost) {
        this.cost = cost;
    }

    @Override
    public int compareTo(Edge o) {
        return this.getCost() - o.getCost();
    }
}



