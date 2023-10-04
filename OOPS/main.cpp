#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int a;
        A(int a = 0): a(a){}
        void fun(char e){cout<<"fun from A"<<endl;}
        int fun(int e){cout<<"int fun from A"<<endl; return 69;}
};
class B{
    public:
    int b;
        B(int b = 0): b(b){}
        int fun(int e){cout<<"fun from B"<<endl; return 69;}
};
class AB: virtual public A, virtual public B{
    public:
    int ab;
        AB(int ab = 0): ab(ab){}
        // void fun(){cout<<"fun from AB"<<endl;}
};

int main(){
    A *obj = new A;
    return 0;
}
