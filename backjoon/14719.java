package com.algo.ri;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int w = scanner.nextInt();
		int [] map = new int[w];
		int result = 0;

		for (int i = 0; i < w; i++)
			map[i] = scanner.nextInt();

		for (int i = 1; i < w - 1; i++)
		{
			int leftMax = 0;
			int rightMax = 0;

			for (int k = 0; k <= i - 1; k ++)
				leftMax = Math.max(leftMax, map[k]);

			for (int j = i + 1; j < w; j++)
				rightMax = Math.max(rightMax, map[j]);

			int curHeight = map[i];
			int minHeight = Math.min(rightMax, leftMax);
			if (curHeight < minHeight)
				result += minHeight - curHeight;

		}
		System.out.println(result);
	}
}
