#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;
const int MIN = 1000;

int get(){
  int ret = rand()%(MAX-MIN);
  return ret+MIN;
}

int main(int argc, char const *argv[]) {

  if( argc != 3 ){
    printf("Invalid arguments\n");
    return 0;
  }

  ios_base::sync_with_stdio(false);

  int n = atoi(argv[1]);
  int num = atoi(argv[2]);

  srand(time(0));

  string file = "";
  ofstream out;

  for( int k=0; k<num; k++ ){
    file = "";
    file += "file/array";
    file += to_string(k+1);
    file += ".txt";
    out.open(file);

    out << n << endl;

    for( int i=0; i<n; i++ ){
      out << get() << " ";
    }
    out << endl;

    out.close();
  }

  return 0;
}
