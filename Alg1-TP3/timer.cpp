#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main() {
	/*if (argc < 4) {
		printf("Argumentos insuficientes\n");
		return 1;
	}*/
	
	//int beg = atoi(argv[1]);
	//int end = atoi(argv[2]);
	//int jump = atoi(argv[3]);
	for (int size = 5; size < 10000; size += 50) {

		//for (int i = 0; i < 10; i ++){

		char s[100];
		sprintf(s, "./gen.out %d %d > in.txt", size, (2*size)-3);
		system(s);

		auto start = std::chrono::high_resolution_clock::now();
		char s2[100];
		sprintf(s, "./tp3 tarefa2 in.txt");
		system(s);
		
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;

		int num_arestas = 2*(size);

		cout << size << "," << elapsed.count() << "\n";
	//}
	}
	return 0;
}
