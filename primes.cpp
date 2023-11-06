#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n){
    if(n<2) return false;
    int sqrtn = std::sqrt(n)+1;
    for(int i = 2; i < sqrtn; i++){
        if((n % i) == 0){
            return false;
        } 
    }
    return true;
}


int main(){
    std::vector<int> primes;
    for(int i = 0; i < 10000; i+=1){
        if(isPrime(i)) primes.push_back(i);
    }
    for(unsigned int i = 0; i < primes.size(); i++){
        std::cout << primes[i] << ", ";
    }
    std::cout << std::endl;
}