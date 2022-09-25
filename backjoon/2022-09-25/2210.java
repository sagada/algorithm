package com.algo.ri.problem.doy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    static Set<String> sets = new HashSet<>();
    static int [][] dirs = new int[][]{
            {0, 1},
            {1, 0},
            {-1, 0},
            {0, -1}
    };
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int [][] arr = new int[6][6];

        for (int i = 0;  i < 5; i++)
        {
            String [] input = bufferedReader.readLine().split(" ");

            for (int j = 0; j < input.length; j++)
            {
                arr[i][j] = Integer.parseInt(input[j]);
            }
        }

        for (int i = 0; i < 5; i++)
        {
            boolean [][] visited = new boolean[6][6];
            int [] result = new int[6];
            for (int j = 0; j < 5; j++)
            {
                result[0] = arr[i][j];
                dfs(visited, 1, result, i, j, arr);
            }
        }
        System.out.println(sets.size());
    }

    private static void dfs(boolean[][] visited, int count, int [] result, int y, int x, int [][] arr)
    {
        if (count == 6)
        {
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < 6; i++)
            {
                stringBuilder.append(String.valueOf(result[i]));
            }

            sets.add(stringBuilder.toString());
            return ;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = dirs[i][0] + y;
            int nx = dirs[i][1] + x;

            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
                continue;

            result[count] = arr[ny][nx];
            count += 1;
            dfs(visited, count, result, ny, nx, arr);
            count -= 1;
        }
    }

}
