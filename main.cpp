#include <iostream>
#include "tasks_rk2.h"
using namespace std;
void task_5()
{
    CheckBrackets<char> c;
    cout<< c.checkBrackets("(()[]{}{()}{[[[]]]}(")<<endl;
}
void task_4()
{
    pair<int,string> t;
    t.first = 10;
    t.second= "qwerty";
    cout<<t;
}
void task_2()
{
    pair <int,int> t;
    int ar[10]={0,1,2,3,4,5,6,7,8,9};
    t = binSearch(ar,10,6);
    cout << t;



}
using namespace std;
int main(int argc, char *argv[])
{
    task_2();
    task_4();
    task_5();
    return 0;
}
