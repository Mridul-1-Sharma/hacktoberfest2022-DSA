#include <bits/stdc++.h>
using namespace std;

// Returns true if there is Pythagorean triplet in array
bool checkTriplet(int arr[], int n)
{
	// initializing unordered map with key and value as
	// integers
	unordered_map<int, int> umap;
	
	// Increase the count of array elements in unordered map
	for (int i = 0; i < n; i++)
		umap[arr[i]] = umap[arr[i]] + 1;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// calculating the squares of two elements as
			// integer and float
			int p = sqrt(arr[i] * arr[i] + arr[j] * arr[j]);
			float q
				= sqrt(arr[i] * arr[i] + arr[j] * arr[j]);
			
			// Condition is true if the value is same in
			// integer and float and also the value is
			// present in unordered map
			if (p == q && umap[p] != 0)
				return true;
		}
	}
	
	// If we reach here, no triplet found
	return false;
}


int main()
{
	int arr[] = { 3, 2, 4, 6, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	if (checkTriplet(arr, n))
		cout << "Yes";
	else
		cout << "No";
}

