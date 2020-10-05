#include <bits/stdc++.h> 
using namespace std; 
// ss[i][j] stores true if given sum is possible when we loop through 0 to i
bool** ss; 

void display(const vector<int>& v) 
{ 
	for (int i = 0; i < v.size(); ++i) 
		printf("%d ", v[i]); 
	printf("\n"); 
} 

// declaring a recursive function to print all subsets. vector sub stores current subset
void Subsets(int arr[], int i, int sum, vector<int>& sub) 
{ 
	
	if (i == 0 && sum != 0 && ss[0][sum]) 
	{ 
		sub.push_back(arr[i]); 
		display(sub); 
		return; 
	} 

	// if sum equals 0 
	if (i == 0 && sum == 0) 
	{ 
		display(sub); 
		return; 
	} 

	 
	if (ss[i-1][sum]) 
	{ 
		// new vector v stores path 
		vector<int> v = sub; 
		Subsets(arr, i-1, sum, v); 
	} 


	if (sum >= arr[i] && ss[i-1][sum-arr[i]]) 
	{ 
		sub.push_back(arr[i]); 
		Subsets(arr, i-1, sum-arr[i], sub); 
	} 
} 

void print(int arr[], int n, int sum) 
{ 
	if (n == 0 || sum < 0) 
	return; 


	ss = new bool*[n]; 
	for (int i=0; i<n; ++i) 
	{ 
		ss[i] = new bool[sum + 1]; 
		ss[i][0] = true; 
	} 

	if (arr[0] <= sum) 
	ss[0][arr[0]] = true; 

	for (int i = 1; i < n; ++i) 
		for (int j = 0; j < sum + 1; ++j) 
			ss[i][j] = (arr[i] <= j) ? ss[i-1][j] || 
									ss[i-1][j-arr[i]] 
									: ss[i - 1][j]; 
	if (ss[n-1][sum] == false) 
	{ 
		printf("No subsets are present which equals to given sum %d\n", sum); 
		return; 
	} 

	 
	vector<int> sub; 
	Subsets(arr, n-1, sum, sub); 
} 

// driver code 
int main() 
{ 
	int arr[] = {2, 7, 8, 11, 13}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int sum = 30; 
	print(arr, n, sum); 
	return 0; 
} 
