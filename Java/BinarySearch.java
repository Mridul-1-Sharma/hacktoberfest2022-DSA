package com.dsa.search;

public class BinarySearch {

	/** Recursion */
	public static int binarySearch(int[] arr, int start, int end, int t) {
		if (end < start)
			return -1;
		int mid = (start + end) / 2;
		if (t == arr[mid])
			return mid;
		else if (t > arr[mid]) {
			return binarySearch(arr, mid + 1, end, t);
		} else if (t < arr[mid]) {
			return binarySearch(arr, start, mid - 1, t);
		}
		return -1;
	}

	/** Loop */
	public static int binarySearchV2(int[] arr, int t) {
		int start = 0, end = arr.length - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (t == arr[mid])
				return mid;
			else if (t > arr[mid]) {
				start = mid + 1;
			} else if (t < arr[mid]) {
				end = mid - 1;
			}
		}
		return -1;
	}

	public static void main(String[] args) {

		int[] arr = { 1, 3, 5, 6, 10, 12, 15, 20, 21, 28 };
		int start = 0, end = arr.length - 1;
		int t = 21; // target/key
		int pos = binarySearch(arr, start, end, t);
		System.out.println("(Recursion)Target Found at " + pos);
		int posV2 = binarySearchV2(arr, t);
		System.out.println("(Loop)Target Found at " + posV2);
	}
}
