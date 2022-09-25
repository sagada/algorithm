package com.algo.ri.problem.doy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static boolean [] visited = new boolean[101];
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine());
        int [][] arr = new int[n + 1][n + 1];

        String [] personNumbers = bufferedReader.readLine().split(" ");
        int a, b;

        a = Integer.parseInt(personNumbers[0]);
        b = Integer.parseInt(personNumbers[1]);

        int m = Integer.parseInt(bufferedReader.readLine());

        for (int i = 0; i < m; i++)
        {
            String [] numbers = bufferedReader.readLine().split(" ");
            int p, q;
            p = Integer.parseInt(numbers[0]);
            q = Integer.parseInt(numbers[1]);

            arr[p][q] = 1;
            arr[q][p] = 1;
        }

        visited[a] = true;
        boolean dfs = dfs(a, b, arr, n, 0);
        if (!dfs)
        {
            System.out.println(-1);
        }
    }

    private static boolean dfs(int start, int end, int[][] arr, int n, int count)
    {
        if (start == end)
        {
            System.out.println(count);
            return true;
        }

        count++;
        for (int i = 1;  i <= n; i++)
        {
            if (!visited[i] && arr[start][i] == 1)
            {
                visited[i] = true;
                boolean dfs = dfs(i, end, arr, n, count);

                if (dfs)
                {
                    return true;
                }
            }
        }

        return false;
    }
}
