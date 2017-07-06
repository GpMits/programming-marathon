#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{   

    int pessoas;
    int num, numTeste = 1, i;
    cin >> pessoas;
    while(pessoas != 0){
        for (i=0; i<pessoas; i++){
            scanf("%d", &num); 
            if(num == i+1) {
                cout << "Teste " << numTeste << "\n";
                cout << num << "\n";
            }
        }
        numTeste++;
        cin >> pessoas;
        if (pessoas != 0) cout << "\n";
    }
    
    return 0;
}