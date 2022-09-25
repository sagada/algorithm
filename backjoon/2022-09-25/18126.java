package com.algo.ri.problem.doy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    static long result = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine());
        int [][] distance = new int[n + 1][n + 1];

        for (int i = 0;  i < n - 1; i++)
        {
            String [] input = bufferedReader.readLine().split(" ");
            int a, b;
            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);
            distance[a][b] = Integer.parseInt(input[2]);
            distance[b][a] = Integer.parseInt(input[2]);
        }

        boolean [] visited = new boolean[n + 1];
        visited[1] = true;
        dfs(1, visited, n, 0, distance);
        System.out.println(result);
    }

    private static void dfs(int cur, boolean[] visited, int n, long sum, int [][] distance)
    {
        if (result < sum)
        {
            result = sum;
        }

        for (int i = 2; i <= n; i++)
        {
            if (!visited[i] && distance[cur][i] != 0)
            {
                visited[i] = true;
                sum += distance[cur][i];
                dfs(i, visited, n, sum, distance);
                sum -= distance[cur][i];
            }
        }
    }

}
