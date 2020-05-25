
#include<bits/stdc++.h> 
using namespace std; 

int lcs_incr_order(int arr1[], int n, int arr2[], int m) 
{ 

	int table[m]; 
	for (int j=0; j<m; j++) 
		table[j] = 0; 

	for (int i=0; i<n; i++) 
	{ 

		int current = 0; 

	
		for (int j=0; j<m; j++) 
		{ 
 
			if (arr1[i] == arr2[j]) 
				if (current + 1 > table[j]) 
					table[j] = current + 1; 
			if (arr1[i] > arr2[j]) 
				if (table[j] > current) 
					current = table[j]; 
		} 
	} 


	int result = 0; 
	for (int i=0; i<m; i++) 
		if (table[i] > result) 
		result = table[i]; 

	return result; 
} 

int main() 
{ 
    int n = 1;
    int m = 1;

    cout << "Enter the value of n and m :";
    cin >> n >> m;
	int arr1[n] ;
	int arr2[m] ;

    for(int i =0;i<n;i++)
    cin >>arr1[i];

    for(int i=0 ; i<m;i++)
    cin >> arr2[i];

	cout << "Length of LCIS is "
		<< lcs_incr_order(arr1, n, arr2, m); 
	return (0); 
} 
