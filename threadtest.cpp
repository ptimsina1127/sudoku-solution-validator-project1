#include <iostream>
#include <thread>
using namespace std;

void test_func(int func_name, int x){
    for(int i = 0; i<x ;i++)
    {
        cout<<"from thread "<<func_name;
    }
}


int main (){
cout<<"test";
thread t1(test_func,1, 100);
thread t2(test_func,2, 100);

t1.join();
t2.join();

return 0;
}