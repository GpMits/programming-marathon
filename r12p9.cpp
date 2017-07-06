#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testes;
	int aux;
	vector<int> seq;
	int n, trocas=0;
	
	cin >> testes;
	
	for(int teste=0; teste<testes; teste++){
		cin >> n;
		seq.reserve(n);
		
		for(int i=0; i<n; i++){
			cin >> aux;
			seq[i] = aux-1;
		}
		
		for(int i=0; i<n; i++){
			if(seq[i] != i){
				swap(seq[i], seq[seq[i]]);
				i=0;
				trocas++;
			}
		}
		
		cout<<trocas;
		if(teste+1<testes)cout<<endl;
		trocas=0;
	}
	return 0;
}

//Só sair trocando cada elemento pra posicao que ele deveria estar