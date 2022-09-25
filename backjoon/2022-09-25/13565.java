package com.algo.ri.problem.doy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int [][] dirs = new int[][]{
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
    };
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String [] inputs = bufferedReader.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int m = Integer.parseInt(inputs[1]);

        int [][] arr = new int[n + 1][m + 1];

        for (int i = 0;  i < n; i++)
        {
            String input = bufferedReader.readLine();

            for (int j = 0;  j < m; j++)
            {
                arr[i][j] = input.charAt(j) - '0';
            }

        }

        Queue<Pair> queue = new ArrayDeque<>();
        for (int i = 0;  i < m; i++)
        {
            if (arr[0][i] == 0)
            {
                queue.add(new Pair(0, i));
            }
        }

        if (bfs(queue, n, m, arr))
        {
            System.out.println("YES");
        }
        else
        {
            System.out.println("NO");
        }
    }

    private static boolean bfs(Queue<Pair> queue, int n, int m, int [][] arr)
    {
        boolean [][] visited = new boolean[n][m];

        while(!queue.isEmpty())
        {
            Pair pair = queue.poll();

            if (pair.getY() == n - 1)
            {
                return true;
            }

            for (int i = 0; i < 4; i++)
            {
                int ny = dirs[i][0] + pair.getY();
                int nx = dirs[i][1] + pair.getX();


                if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                    continue;

                if (!visited[ny][nx]&& arr[ny][nx] == 0)
                {
                    visited[ny][nx] = true;
                    queue.add(new Pair(ny, nx));
                }
            }
        }

        return false;
    }
}

class Pair{
    int y; int x;

    public Pair(int y, int x) {
        this.y = y;
        this.x = x;
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
}
