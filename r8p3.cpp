#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<long long,int> fibs;

void genFibs(){
	long long i = 1, j = 2, aux;
	int index = 2;
	fibs[1] = 1;
	fibs[2] = 2;
	while(index <= 50){
		index++;
		aux = i;
		i = j;
		j = aux+j;
		fibs[j] = index;
	}
}

int main() {
	//std::ios_base::sync_with_stdio(false);
	genFibs();
	
	vector<long long> numbers;
	int nTests, nChars, cont, ind;
	long long num;
	char c;
	char uText[50]="";
	char cText[50]="";
	
	scanf("%d", &nTests);
	for(int n=0; n<nTests; n++){
		memset(uText, 0, sizeof uText);
		memset(uText, 0, sizeof cText);
		scanf(" %d", &nChars);
		for(int i=0; i<nChars; i++){
			scanf("%lld", &num);
			numbers.push_back(num);
		}
		cont = 0;
		ind = 0;
		gets(cText);
		gets(cText);
		reverse(numbers.begin(), numbers.end());
		while(cont < nChars){
			c = cText[ind];
			if((int)c >= 65 && (int)c<=90) {
				uText[fibs[numbers.back()]-1] = c;
				numbers.pop_back();
				cont++;
			}
			ind++;
		}
		cont=0;
		ind=0;
		while(cont<nChars){
			if(uText[ind] == 0){
				uText[ind] = ' ';
			}else{
				cont++;
			}
			ind++;
		}
		
		numbers.clear();
		printf("%s\n", uText);
	}
	return 0;
}