import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int [] dnaCharsInteger = new int[4];
    static int [] subDnaCharsInteger = new int[4];

    public static void main(String[] args) throws IOException
    {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int s, p;
        s = Integer.parseInt(stringTokenizer.nextToken());
        p = Integer.parseInt(stringTokenizer.nextToken());

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        String dna = stringTokenizer.nextToken();

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        for (int i = 0; i < 4; i++)
        {
            dnaCharsInteger[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        int count = 0;

        String subString = dna.substring(0, p);

        for (int i = 0; i < subString.length(); i++)
        {
            addCountChar(subString.charAt(i));
        }

        if (validCharCount())
        {
            count++;
        }

        for (int i = p; i < dna.length(); i++)
        {
            deleteCountChar(dna.charAt(i - p));
            addCountChar(dna.charAt(i));

            if(validCharCount())
            {
                count++;
            }
        }

        System.out.println(count);
    }

    private static void addCountChar(char ch)
    {
        switch (ch)
        {
            case 'A' -> subDnaCharsInteger[0]++;
            case 'C' -> subDnaCharsInteger[1]++;
            case 'G' -> subDnaCharsInteger[2]++;
            case 'T' -> subDnaCharsInteger[3]++;
        }
    }

    private static void deleteCountChar(char ch)
    {
        switch (ch)
        {
            case 'A' -> subDnaCharsInteger[0] = subDnaCharsInteger[0] == 0 ? 0 : subDnaCharsInteger[0] - 1;
            case 'C' -> subDnaCharsInteger[1] = subDnaCharsInteger[1] == 0 ? 0 : subDnaCharsInteger[1] - 1;
            case 'G' -> subDnaCharsInteger[2] = subDnaCharsInteger[2] == 0 ? 0 : subDnaCharsInteger[2] - 1;
            case 'T' -> subDnaCharsInteger[3] = subDnaCharsInteger[3] == 0 ? 0 : subDnaCharsInteger[3] - 1;
        }
    }



    private static boolean validCharCount()
    {
        for (int k = 0; k < 4; k++)
        {
            if (subDnaCharsInteger[k] < dnaCharsInteger[k])
            {
                return false;
            }
        }

        return true;
    }

}
