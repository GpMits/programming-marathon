#include <iostream>
using namespace std;

int main() {
	int n, m;
	int x, y, z;
	int numTeste = 1;
	int mat[100][100];
	int actualVs[100];
	int minValue = 9999, minI, minJ;
	bool end = false;
	
	cin >> n;
	for(int i=0; i<n; i++){
			actualVs[i] = 0;
			for(int j=0; j<n; j++){
				mat[i][j] = 0;
			}
		}
	while(n!=0){
		cout<<"Teste " << numTeste << endl;
		cin >> m;
		for (int i=0; i<m; i++){
			cin >> x >> y >> z;
			mat[x-1][y-1] = z;
			mat[y-1][x-1] = z;
		}
		
		//Prim
		actualVs[0] = 1;
		while(!end){
			for(int i=0; i<n; i++){
				if(actualVs[i] == 1){
					for(int j=0; j<n; j++){
						if(actualVs[j]==0 && mat[i][j] > 0 && mat[i][j]<minValue){
							minValue = mat[i][j];
							minI = i;
							minJ = j;
						} 
					}
				}
			}
			actualVs[minJ] = 1;
			mat[minI][minJ] = -1;
			minValue = 9999;
			end = true;
			for(int i=0; i<n; i++){
				if(actualVs[i] == 0) end = false;
			}
		}
		
		//Procura a ultima aresta pra formatacao da saida
		minI =0;
		minJ = 0;
		end = false;
		for(int i=n-1; i>=0; i--){
			for(int j=n-1; j>=0; j--){
				if(mat[i][j] == -1){
					minI = i;
					minJ = j;
					end = true;
					break;
				}
			}
			if (end) break;
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(mat[i][j] == -1) {
					if(i<=j) cout << i+1 << " " << j+1;
					else cout << j+1 << " " << i+1;
					if(minI != i || minJ !=j) cout<<endl;
				}
			}
		}
		end = false;
		numTeste++;
		cin >> n;
		if(n!=0) cout<<endl<<endl;
		for(int i=0; i<n; i++){
			actualVs[i] = 0;
			for(int j=0; j<n; j++){
				mat[i][j] = 0;
			}
		}
	}
	return 0;
}