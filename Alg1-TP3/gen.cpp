#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]); 
	int m = atoi(argv[2]);

	vector<int> v1, v2;
	for (int i = 0; i < n-1; i++) {
		v1.push_back(i);
		v2.push_back(i+1);
		
	}
	for (int i=0; i < n - 2; i++){
		v1.push_back(i);
		v2.push_back(i+2);
	}

	printf("%d %d\n", n, (2*n)-3);
	printf("%d %d\n", n, n-1);
	for (int i = 0; i < 2*n-3; i++)
		printf("%d %d\n", v1[i], v2[i]);

	return 0;
}
