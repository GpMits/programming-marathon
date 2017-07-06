// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int a, d, aux;
  vector<int> atk;
  vector<int> def;
  
  cin >> a;
  cin >> d;
  
  while(a!=0 && d!=0) {
  
    for (int i = 0; i < a; i++){
      cin >> aux;
      atk.push_back(aux);
    }
  
    for (int i = 0; i < d; i++){
      cin >> aux;
      def.push_back(aux);
    }
  
    sort(atk.begin(), atk.begin() + a);
    sort(def.begin(), def.begin() + d);
    
    if(d == 1) cout << "N";
    else if(atk[0] >= def[1]) cout << "N";
    else cout << "Y";
    
    cin >> a;
    cin >> d;
    atk.clear();
    def.clear();
    
    if(a!=0) cout << "\n";
  }
}