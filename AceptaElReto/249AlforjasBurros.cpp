#include <iostream>
#include <vector>
#include <algorithm>

void resolver(){
int burros = 0, sacos = 0, maxb = 0;
std::cin >> burros >> sacos;
std::vector<int> pesos(sacos);
    
for (int i=0; i < sacos; ++i) std::cin >> pesos[i];
sort(pesos.begin(), pesos.end());
int j = 1;
while (maxb < burros && j < sacos ){
    if(pesos[j] == pesos[j-1]){ ++maxb;
      j = j + 2;} 
    else ++j;
    }
std::cout << maxb << '\n';
}

int main(){
 int numCasos = 0; 
 std::cin >> numCasos;  
 for(int i = 0; i < numCasos; ++i) resolver();
 return 0;
}