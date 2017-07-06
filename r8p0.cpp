#include <iostream>
#include <string.h>
using namespace std;

int main() {
	long long letras[256];
	memset (letras,0,256*sizeof(long long));
	string s;
	long long resp = 0;
	cin >> s;
	for (long i=0; i<s.size(); i++){
		letras[s[i]]++;
	}
	for (long i=0; i<256; i++){
		resp=resp+(letras[i]*letras[i]);
	}
	
	cout<<resp;
	//Fazer força bruta dá timeout, tive que contar a ocorrencia de cada letra e fazer assim
	return 0;
}