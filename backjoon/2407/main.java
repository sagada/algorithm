
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BigInteger[][] dp = new BigInteger[101][101];
    static BigInteger one = BigInteger.valueOf(1);
    static BigInteger zero = BigInteger.valueOf(0);
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        init();
        int N = sc.nextInt();
        int M = sc.nextInt();
        System.out.println(dp[N][M]);
    }

    static void init()
    {
       dp[1][0] = dp[1][1] = BigInteger.ONE;

       for (int i = 2; i <= 100; i++)
       {
           for (int j = 0; j <= i; j++)
           {
               if (j == 0 || i == j) dp[i][j] = BigInteger.ONE;
               else dp[i][j] = dp[i - 1][j].add(dp[i - 1][j - 1]);
           }
       }
    }
}
