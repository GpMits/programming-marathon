#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  int aux;
  //vector<int> votes;
  
  cin >> n;
  
  while(n!=0) {
    vector<int> votes (n,0); 
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        cin >> aux;
        votes[j] = votes[j] + aux;
      }
    }
  
    sort(votes.begin(), votes.begin() + n);
    cout<<votes[n-1];
    
    cin >> n;
    if(n!=0) cout << "\n";
  }
}