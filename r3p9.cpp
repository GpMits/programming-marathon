#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int n,k;
	int x,y,d;
	int maxD = 0, maxX, maxY;
	bool noAns = false;
	
	cin >> n >> k;
	
	int matrix[n][n];
	int hints[k][3];
	
	for(int i=0; i<n; i++){
	  for(int j=0; j<n; j++) matrix[i][j] = 0;
	}
	
	for(int i=0; i<k; i++){
	  cin >> x >> y >> d;
	  matrix[y][x] = -1;
	  hints[i][0] = x;
	  hints[i][1] = y;
	  hints[i][2] = d;
	}

	for(int i=0; i<n; i++){
	  for(int j=0; j<n; j++) {
	    if(matrix[i][j] != -1){
	      for(int z=0; z<k; z++){
            if(abs(hints[z][0]-j)+abs(hints[z][1]-i) == hints[z][2]) matrix[i][j] =  matrix[i][j] + 1;
	      }
	    }
	  }
	}
	
	for(int i=0; i<n; i++){
	  for(int j=0; j<n; j++) {
	    if(matrix[i][j] >= maxD){
	    	maxD = matrix[i][j];
	    	maxX = j;
	    	maxY = i;
	    }
	  }
	}
	
	for(int i=0; i<n; i++){
	  for(int j=0; j<n; j++) {
	    if(matrix[i][j] == maxD && (maxX != j || maxY != i)) noAns = true;
	  }
	}
	
	if(noAns) cout << "-1 -1";
	else cout << maxX << " " << maxY;
	return 0;
}