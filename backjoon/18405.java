import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int [] dy = {0, 1, 0, -1};
    static int [] dx = {-1, 0, 1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int n, k;

        String[] s = bufferedReader.readLine().split(" ");

        n = Integer.parseInt(s[0]);
        k = Integer.parseInt(s[1]);

        int [][] arr = new int[n + 1][n + 1];
        int [][] times = new int[n + 1][n + 1];

        Queue<Virus> queue = new LinkedList<>();
        for (int i = 0; i < n; i++)
        {
            String[] s1 = bufferedReader.readLine().split(" ");

            for (int j = 0; j < n; j++)
            {
                arr[i][j] = Integer.parseInt(s1[j]);

                if (arr[i][j] != 0)
                {
                    Virus virus = new Virus(i, j, arr[i][j], 0);
                    queue.add(virus);
                }
            }
        }

        String[] s1 = bufferedReader.readLine().split(" ");

        int _s, _x, _y;

        _s =Integer.parseInt(s1[0]);
        _x =Integer.parseInt(s1[1]);
        _y =Integer.parseInt(s1[2]);

        while (!queue.isEmpty())
        {
            Virus curVirus = queue.poll();

            for (int i = 0; i < 4; i++)
            {
                int ny = dy[i] + curVirus.y;
                int nx = dx[i] + curVirus.x;

                if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                    continue;

                if (arr[ny][nx] == 0)
                {
                    arr[ny][nx] = curVirus.value;
                    times[ny][nx] = curVirus.time + 1;
                    queue.add(new Virus(ny, nx, arr[ny][nx], times[ny][nx]));
                    continue;
                }

                if (arr[ny][nx] > arr[curVirus.y][curVirus.x] && curVirus.time + 1 <= times[ny][nx])
                {
                    times[ny][nx] = curVirus.getTime() + 1;
                    arr[ny][nx] = curVirus.value;
                    queue.add(new Virus(ny, nx, arr[ny][nx], times[ny][nx]));
                }
            }
        }

        if (times[_x - 1][_y - 1] <= _s)
        {
            System.out.println(arr[_x - 1][_y - 1]);
        }else
        {
            System.out.println(0);
        }
    }

    public static class Virus
    {
        private int y;
        private int x;
        private int value;
        private int time;

        public int getTime() {
            return time;
        }

        public void setTime(int time) {
            this.time = time;
        }

        public Virus(int y, int x, int value, int time) {
            this.y = y;
            this.x = x;
            this.value = value;
            this.time = time;
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

        public int getValue() {
            return value;
        }

        public void setValue(int value) {
            this.value = value;
        }

        public Virus(int y, int x, int value) {
            this.y = y;
            this.x = x;
            this.value = value;
        }
    }
}