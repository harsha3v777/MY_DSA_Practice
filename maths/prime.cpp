#include<iostream>
using namespace std;

//modulo arithmetics
//ans%((10^7)+9)  then total ans will be in the range of 0 to (10^7)+8
//100%3 range is in 0,1,2
//x%n - range[0,n-1]
//  properties
//(x+y)%n = x%n + y%n
//(x+y)%n = x%n - y%n
//(x*y)%n = x%n * y%n
// (((x%m)%m)%m) is same as x%m

string isPrime(int n){
    if(n<=1) return "non-prime";
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return "non-prime";
        }
    }
    return "prime";
}


void printPrimesUpto(int tn){
    cout<<"Primes numbers up to "<<tn<<" : ";
    for(int n=2;n<=tn;n++){
       bool isprime=true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            isprime=false;
            break;
        }
    }
    if(isprime){
        cout<<n<<" ";    
    }
  }
  cout<<endl;
}


int main(){
    int s=9;
    cout<<s<<" is "<<isPrime(s)<<endl;

    int l=50;
    printPrimesUpto(50);
}