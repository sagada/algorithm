package com.study.out;

import java.util.*;

public class Main {
    static boolean [] check = new boolean[16];
    static List<Character> characterList = new ArrayList<>();
    static int L;
    static int C;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        L = scanner.nextInt();
        C = scanner.nextInt();
        for (int i = 0; i < C; i++)
        {
            String next = scanner.next();
            char c = next.charAt(0);
            characterList.add(c);
        }

        Collections.sort(characterList);
        find(0, new String(""), 0);
    }

    public static void find(int cur, String str, int fi)
    {
        if (cur == L)
        {
            int ja = 0;
            int mo = 0;
            for (int i = 0; i < str.length(); i++)
            {
                if (str.charAt(i) == 'a' ||
                        str.charAt(i) == 'e' ||
                        str.charAt(i) == 'i' ||
                        str.charAt(i) == 'o' ||
                        str.charAt(i) == 'u'
                )
                {
                    mo++;
                }
                else
                {
                    ja++;
                }
            }

            if (!(mo >= 1 && ja >= 2))
            {
                return;
            }

            System.out.println(str);
            return ;
        }

        for (int i = fi; i < C; i++)
        {
            if (!check[i])
            {
                check[i] = true;
                find(cur + 1, str + characterList.get(i), i);
                check[i] = false;
            }
        }
    }

}
