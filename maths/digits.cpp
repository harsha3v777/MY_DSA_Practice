#include<iostream>
#include<math.h>
using namespace std;

void printDigits(int n){
    int count=0;
    int sum=0;
    while(n!=0){ //o(log10(n))
        int digit=n%10;
        cout<<digit<<endl;
        n=n/10;
        count++;
        sum+=digit;
    }
    cout<<"count : "<<count<<endl;
    cout<<"sum of digits : "<<sum<<endl;

}

void isArmstrong(int n){
    int cubes=0;
    int copyn=n;
    while(n!=0){
        int temp=n%10;
        cubes+=temp*temp*temp;
        n=n/10;
    }
    if(cubes==copyn){
        cout<<"it is an armStrong number";
    }else{
        cout<<"it is not an armStrong number";
    }
    cout<<endl;
}

void gcd(int a,int b){
    int gcd=1;
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0){
            gcd=i;
        }
    }
    cout<<"gcd : "<<gcd<<endl;
}

void euclidsgcd(int a,int b){
    while(a>0 && b>0){
      if(a>b){
         a=a%b;
      }else{
         b=b%a;
     }
   }
   if(a==0){
    cout<<"gcd : "<<b<<endl;
   }else{
    cout<<"gcd : "<<a<<endl;
   }
}

int gcdrec(int a,int b){
    if(b==0) return a;

    return gcdrec(b,a%b);
}

//lcm - a*b=lcm(a,b)*gcd(a,b)
void lcm(int a ,int b){
    int lcm=(a*b)/gcdrec(a,b);
    cout<<"lcm : "<<lcm<<endl;
}

int main(){
    int n=2721;
    printDigits(n);
    cout<<"count : "<<(int)(log10(n)+1)<<endl;  //gives count of numbers

    isArmstrong(153);

    gcd(24,30);
    euclidsgcd(39,63);
    cout<<"gcd recursion : "<<gcdrec(40,24)<<endl;
    lcm(15,10);
    return 0;
}