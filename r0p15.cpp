#include <iostream>
using namespace std;
 
int main()
{
   int a;
 
   while(cin >> a){
     for (int i = 0; i<a; i++){
         for(int j = 0; j<a; j++){
             if(i==j && i != a-(j+1) ) cout << "1";
             else if(i == a-(j+1)) cout << "2";
             else cout<<"3";
         }
         if(i+1!=a)cout << "\n";
     }
     if(!cin.eof()) cout << "\n";
   }
   return 0;
}