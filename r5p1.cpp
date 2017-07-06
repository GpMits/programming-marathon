#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int numV, numA, a, b,p, actual;
    bool error;
    int matrix[700][700];
    vector<int> markedVertexes;
    vector<int> vertexes;
    cin >> numV;
    while(numV != 0) {
    	markedVertexes.assign(numV,0);
    	
        cin >> numA;
        for (int i = 0; i < numA; i++) {
            cin >> a;
            a--;
            cin >> b;
            b--;
            cin >> p;
            if (p==1) {
                matrix[a][b] = 1;
                } else {
                matrix[a][b] = 1;
                matrix[b][a] = 1;
            }
        }
        
        //BFS
        error = false;
        for (int i = 0; i < numV; i++) {
        	markedVertexes.assign(numV,0);
            markedVertexes[i]=1;
            vertexes.clear();
            vertexes.push_back(i);
            while (!vertexes.empty()) {
                actual = vertexes.back();
                vertexes.pop_back();
                for (int m = 0; m < numV; m++) {
                    if (matrix[actual][m] == 1 && markedVertexes[m]== 0) {
                        markedVertexes[m] = 1;
                        vertexes.push_back(m);
                    }
                }
            }
            
            if ( find(markedVertexes.begin(), markedVertexes.end(), 0) != markedVertexes.end() ) {
                error = true;
                break;
            }
        }
        
        if (error) {
            cout << "0";
            } else {
            cout << "1";
        }
        
        for(int i=0; i<numV; i++){
        	for(int j=0; j<numV; j++) matrix[i][j] = 0;
        }
        
        cin >> numV;
        if(numV != 0) {
            cout << endl;
        }
    }
    return 0;
}