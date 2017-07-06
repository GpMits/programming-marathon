#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Vertex {
	int i;
	int j;
};

int main() {
    int N, M, d;
    Vertex actual;
    bool error, end;
    int matrix[10][10];
    int markedVertexes[10][10];
    vector<Vertex> newVertexes;
    vector<Vertex> vertexes;
    cin >> N;
    cin >> M;

    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < M; j++) {
    		cin >> matrix[i][j];
    		if(matrix[i][j] == 3) {
    			actual.i = i;
    			actual.j = j;
    		}
    	}
    }
    for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) markedVertexes[i][j]=0;
	}
    //BFS
    markedVertexes[actual.i][actual.j] = 1;
    vertexes.push_back(actual);
    d = 1;
    end = false;
    while (!vertexes.empty() && !end) {
        actual = vertexes.back();
        vertexes.pop_back();
		Vertex newVx;
		if(actual.i + 1 < N && matrix[actual.i+1][actual.j] != 2 && markedVertexes[actual.i+1][actual.j] == 0) {
			if(matrix[actual.i+1][actual.j] == 0) {
				end = true;
			}
			newVx.i = actual.i + 1;
			newVx.j = actual.j;
			markedVertexes[actual.i+1][actual.j]=1;
			newVertexes.push_back(newVx);
		}
		if(actual.j + 1 < M && matrix[actual.i][actual.j+1] != 2 && markedVertexes[actual.i][actual.j+1] == 0) {
			if(matrix[actual.i][actual.j+1] == 0) {
				end = true;
			}
			newVx.i = actual.i;
			newVx.j = actual.j + 1;
			 markedVertexes[actual.i][actual.j+1] = 1;
			newVertexes.push_back(newVx);
		}
		if(actual.i - 1 >= 0 &&  matrix[actual.i-1][actual.j] != 2 && markedVertexes[actual.i-1][actual.j] == 0) {
			if(matrix[actual.i-1][actual.j] == 0) {
				end = true;
			}
			newVx.i = actual.i - 1;
			newVx.j = actual.j;
			markedVertexes[actual.i-1][actual.j]=1;
			newVertexes.push_back(newVx);
		}
		if(actual.j - 1 >= 0 && matrix[actual.i][actual.j-1] != 2 && markedVertexes[actual.i][actual.j-1] == 0) {
			if(matrix[actual.i][actual.j-1] == 0) {
				end = true;
			}
			newVx.i = actual.i;
			newVx.j = actual.j - 1;
			markedVertexes[actual.i][actual.j-1] = 1;
			newVertexes.push_back(newVx);
		}
		
		if(vertexes.empty() && !newVertexes.empty() && end == false){
			vertexes = newVertexes;
			newVertexes = vector<Vertex>();
			d++;
		}

	}
	cout<<d;
}