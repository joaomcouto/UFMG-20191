#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int MAX=5000;
int INTERVAL=50;
int IT=5;

string nome[5] = {"camerini", "camerini_sorted", "kruskal", "prim", "boruvka" };

ll get(string t){
  int i = t.size()-1;
  ll ret = 0;
  ret += (ll)(t[i--]-'0');
  ret += 10*((ll)(t[i--]-'0'));
  i--;
  ret += 100*((ll)(t[i--]-'0'));
  ret += 100*10*((ll)(t[i--]-'0'));
  return ret;
}

int main(int argc, char const *argv[]) {

  if( argc != 3 ){
    printf("Invalid arguments\n");
    return 0;
  }

  MAX = atoi(argv[1]);
  INTERVAL = atoi(argv[2]);

  string file;
  ifstream in;
  ofstream out;

  for( int i=0; i<5; i++ ){
    file = "";
    file += "time/";
    file += nome[i];
    file += ".txt";
    out.open(file);
    for( int j=INTERVAL; j<=MAX; j+=INTERVAL ){
      double soma=0;
      for( int k=1; k<=IT; k++ ){
        file = "";
        file += "results/";
        file += nome[i];
        file += "/num_";
        file += to_string(j);
        file += "/time";
        file += to_string(k);
        file += ".txt";
        in.open(file);
        string le;
        in >> le;
        soma += get(le);
        in.close();
      }
      soma /= IT;
      out << j << " " << soma << endl;
    }
    out.close();
  }

  return 0;
}
