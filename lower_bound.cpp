#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    int N=0, Q=0, helper=0;
    std::vector<int>v;
    
    std::cin >> N;
    
    for(int i = 0; i < N; i++){
        std::cin >> helper;
        v.push_back(helper);
    }
    
    std::cin >> Q;
    std::vector<int>::iterator low;
    for(int i = 0; i < Q; i++){
        std::cin >> helper;
        low=std::lower_bound (v.begin(), v.end(), helper);
        if(v[low - v.begin()] == helper){
            std::cout << "Yes " << (low- v.begin())+1 << '\n';
        }else{
            std::cout << "No " << (low- v.begin())+1 << '\n';
        }
    }
      
    return 0;
}