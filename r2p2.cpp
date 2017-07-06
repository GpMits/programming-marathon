// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  string a, b, brev;
  
  cin >> n;
  
  for(int i = 0; i<n; i++){
    cin >> a;
    cin >> b;
    
    brev = string ( b.rbegin(), b.rend() );
    brev = brev + brev;
    b = b+b;
    
    if(b.find(a) != string::npos || brev.find(a) != string::npos) cout << "S";
    else cout<< "N";
    
    if(i+1 != n) cout<< "\n";
  }
}