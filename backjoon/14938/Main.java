package com.study.out;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static int maxVal = 0;
    static int inf = 9999999;
    public static void main(String[] args) {
        int n, m, r;
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        m = scanner.nextInt();
        r = scanner.nextInt();

        int [] itemCnt = new int[n + 1];

        for (int i = 1; i <= n; i++)
        {
            itemCnt[i] = scanner.nextInt();
        }
        List<Edge>[] edges= (List<Edge>[]) new List[n + 1];

        for (int i = 0; i <= n; i++)
        {
            edges[i] = new ArrayList<>();
        }

        for (int i = 0; i < r; i++)
        {
            int a,b,c;
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();

            edges[a].add(new Edge(b, c));
            edges[b].add(new Edge(a, c));
        }

        for (int i = 1; i <= n; i++)
        {
            dijkstra(i, n, edges, m, itemCnt);
        }

        System.out.println(maxVal);

    }

    static void dijkstra(int start, int n, List<Edge>[] edges, int m, int[] itemCnt)
    {
        boolean [] check = new boolean[n + 1];
        int [] dist = new int[n + 1];
        PriorityQueue<Edge> queue = new PriorityQueue<>();

        for (int i = 1; i <= n; i++)
        {
            dist[i] = inf;
        }

        queue.add(new Edge(start, 0));
        dist[start] = 0;

        while(!queue.isEmpty())
        {
            Edge edge = queue.poll();

            if (check[edge.getNum()])
                continue;
            check[edge.getNum()] = true;

            for (int i = 0; i < edges[edge.getNum()].size(); i++)
            {
                Edge nextEdge = edges[edge.getNum()].get(i);
                if (dist[nextEdge.getNum()] > dist[edge.getNum()] + nextEdge.getCost())
                {
                    if (dist[edge.getNum()] + nextEdge.getCost() > m)
                        continue;

                    dist[nextEdge.getNum()] = dist[edge.getNum()] + nextEdge.getCost();
                    queue.add(new Edge(nextEdge.getNum(), nextEdge.getCost()));
                }
            }
        }

        int val = 0;
        for (int i = 1; i <= n; i++)
        {
            if (check[i])
            {
                val += itemCnt[i];
            }
        }

        maxVal = Math.max(maxVal, val);
    }
}

class Edge implements Comparable<Edge>
{
    int num;
    int cost;

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public int getCost() {
        return cost;
    }

    public void setCost(int cost) {
        this.cost = cost;
    }

    public Edge(int num, int cost) {
        this.num = num;
        this.cost = cost;
    }

    @Override
    public int compareTo(Edge o) {
        return this.getCost() - o.getCost();
    }
}