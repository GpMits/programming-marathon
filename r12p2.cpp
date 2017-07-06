#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//vector<vector<int> > pilhas;
	vector<int> altPilhas;
	int n, p; // num caixas, num pilhas
	int np, cx; //tamanho pilha
	int pilhaAlvo, posCaixa;
	int x=0, y=0;
	
	cin >> n >> p;
	
	while(n!=0){
		altPilhas.clear();
		altPilhas.reserve(p);
		for (int i=0; i<p; i++){
			cin >> np;
			altPilhas[i] = np;
			for (int j=0; j<np; j++){
				cin >> cx;
				if(cx == 1) {
					posCaixa = j;
					pilhaAlvo = i;
				}
			}
		}
		/*for (int i=0; i<p; i++){
			cout << altPilhas[i] << " ";
		}
		cout<<endl << pilhaAlvo << " " << posCaixa;*/
		
		for(int i=pilhaAlvo-1; i>=0; i--){
			if (altPilhas[i]-1<posCaixa) break;
			x += altPilhas[i] - posCaixa;
		}
		
		for(int i=pilhaAlvo+1; i<p; i++){
			if (altPilhas[i]-1<posCaixa) break;
			y += altPilhas[i] - posCaixa;
		}
		cout<<min(x,y) + altPilhas[pilhaAlvo] - 1 - posCaixa ;
		
		cin >> n >> p;
		x=0;
		y=0;
		if(n!=0) cout<<endl;
	}
	return 0;
}