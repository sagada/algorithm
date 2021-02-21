


import java.util.*;

public class Main {
    private static int dy[] = {-1,0,1,0};
    private static int dx[] = {0,1,0,-1};
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N, M,K;

        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();
        int d[][] =new int[N + 1][M + 1];
        int dist[][][] = new int [N + 1][M + 1][K + 1];
        sc.nextLine();

        for (int i = 0; i < N; i++) {
            String str = sc.nextLine();
            for (int j = 0; j < str.length(); j++) {
                d[i][j] = str.charAt(j) -'0';
            }
        }

        dist[0][0][0] = 1;

        Queue<Pair> q = new LinkedList<>();

        q.add(new Pair(0,0,0));

        while(!q.isEmpty())
        {
            int _y = q.peek().y;
            int _x = q.peek().x;
            int ct = q.peek().c; // 벽을 부순 횟수

            q.poll();

            if (_y == N - 1 && _x == M - 1)
            {
                System.out.println(dist[_y][_x][ct]);
                return;
            }

            for (int i = 0; i < 4; i++)
            {
                int ny = dy[i] + _y;
                int nx = dx[i] + _x;

                if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                    continue;

                if (d[ny][nx] == 0 && dist[ny][nx][ct] == 0) // 다음칸이 벽이 아니면서,
                {
                    dist[ny][nx][ct] = dist[_y][_x][ct] + 1;
                    q.add(new Pair(ny, nx, ct));
                }

                if (ct + 1 <= K  && d[ny][nx] == 1 && dist[ny][nx][ct + 1] == 0 ) // 다음 칸이 벽이면서, 벽을 부순 횟수가 0번이고 그리고 다음행 벽을 부수고 간적이 없을때
                {
                    dist[ny][nx][ct + 1] = dist[_y][_x][ct] + 1;
                    q.add(new Pair(ny, nx, ct + 1));
                }
            }
        }

        System.out.println(-1);
    }
}

class Pair{
    Integer y;
    Integer x;
    Integer c;

    public Pair(Integer y, Integer x, Integer c) {
        this.y = y;
        this.x = x;
        this.c = c;
    }

    public Integer getY() {
        return y;
    }

    public void setY(Integer y) {
        this.y = y;
    }

    public Integer getX() {
        return x;
    }

    public void setX(Integer x) {
        this.x = x;
    }

    public Integer getC() {
        return c;
    }

    public void setC(Integer c) {
        this.c = c;
    }
}