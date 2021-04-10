import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.*;

public class Main {

    public static int upperBound(int[] arr, int target)
    {
        int left = 0;
        int right = arr.length -1;
        int ans = -1;
        while(left <= right)
        {
            int mid = (left + right) / 2;

            if (arr[mid] == target)
            {
                ans = mid;
                left = mid + 1;
            }
            else if (arr[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }


    public static int lowerBound(int[] arr, int target)
    {
        int left = 0;
        int right = arr.length - 1;
        int ans = -1;
        while(left <= right)
        {
            int mid = (left + right) / 2;

            if (arr[mid] == target)
            {
                ans = mid;
                right = mid - 1;
            }
            else if (arr[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.valueOf(br.readLine());

        String [] line = br.readLine().split(" ");
        int [] cardNumbers = new int [n];
        for (int i = 0; i < n; i++) {
            cardNumbers[i] = Integer.valueOf(line[i]);
        }

        Arrays.sort(cardNumbers);

        int m = Integer.valueOf(br.readLine());

        line = br.readLine().split(" ");
        StringBuilder ans = new StringBuilder();
        int[] checkNum = new int[m + 1];
        for (int i = 0; i < m; i++)
        {
            int target = Integer.valueOf(line[i]);
            int l = lowerBound(cardNumbers, target);
            int r = upperBound(cardNumbers, target);
            if (l == -1)
                ans.append("0 ");
            else
                ans.append((r - l + 1) + " ");

        }
        System.out.println(ans);

    }


}
