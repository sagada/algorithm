package com.algo.ri.problem.stream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int [][] dirs = new int[][]{
            {0,1}, {1,0}, {-1, 0}, {0, -1}
    };
    public static void main(String[] args) throws IOException
    {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bufferedReader.readLine());

        int [][] arr = new int[n][n];

        int minHeight = 100;
        int maxHeight = 0;

        for (int i = 0; i < n; i++)
        {
            String input = bufferedReader.readLine();
            String[] s = input.split(" ");

            for (int j = 0; j < s.length; j++)
            {
                arr[i][j] = Integer.parseInt(s[j]);
                if (arr[i][j] < minHeight)
                {
                    minHeight = arr[i][j];
                }

                if (arr[i][j] > maxHeight)
                {
                    maxHeight = arr[i][j];
                }
            }
        }

        int result = 1;
        for (int i = minHeight;  i <= maxHeight; i++)
        {
            int height = bfsHeight(i, arr);

            result = Math.max(height, result);
        }

        System.out.println(result);
    }

    private static int bfsHeight(int height, int[][] arr)
    {
        int [][] copy = arr.clone();

        for (int i = 0; i < copy.length;  i++)
        {
            for (int j = 0; j < copy[i].length; j++)
            {
                if (height >= copy[i][j])
                {
                    copy[i][j] = -1;
                }

            }
        }

        boolean [][] isVisit = new boolean[copy.length][copy.length];
        int count = 0;
        for (int i = 0; i < copy.length;  i++)
        {
            for (int j = 0; j < copy[i].length; j++)
            {
                if (copy[i][j] != -1 && !isVisit[i][j])
                {
                    count++;
                    Queue<Pair> queue = new ArrayDeque<>();
                    queue.add(new Pair(i, j));
                    isVisit[i][j] = true;

                    while(!queue.isEmpty())
                    {
                        Pair poll = queue.poll();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int ny = dirs[dir][0] + poll.getY();
                            int nx = dirs[dir][1] + poll.getX();

                            if (ny >= 0 && nx >= 0 && ny < copy.length && nx < copy.length && copy[ny][nx] != -1 && !isVisit[ny][nx])
                            {
                                isVisit[ny][nx] = true;
                                queue.add(new Pair(ny, nx));
                            }
                        }
                    }
                }

            }
        }

        return count;
    }
}

class Pair
{
    int x;
    int y;

    public Pair(int y, int x) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
}