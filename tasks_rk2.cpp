#include "tasks_rk2.h"

pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el)
{
    int middle = sizeAr/2;
    if(sizeAr%2==1)
    {
        middle= middle+ 1;
    }
    static int countCall;
    static int index = middle;
    if(middle!=0 && el!=ar[middle-1])
    {
        if(el>ar[middle-1])
        {
              if((sizeAr-middle)%2==1){
                              index++;
                          }
            index+=middle/2;
            countCall++;
            binSearch(ar+middle,sizeAr-middle,el);
        }
        if(el<ar[middle-1])
        {
             if((middle-1)%2==0)
             {
                 index--;

             }
             index-=middle/2;
             countCall++;
             binSearch(ar,middle-1,el);
    }
    }
    if(ar[middle-1]==el)
    {
        countCall++;
        index--;
    }

    pair <int,int> t;
    t.first=index;
    t.second = countCall;
    return t;
}


 int Graph:: allsearch (int countNodes)
 {
     int tmp=countNodes;
     int allcount=0;
     int temp =1;
     while(tmp>0){
     temp*=tmp;
     allcount+=temp;
     tmp--;
     }
     return allcount;
 }

//int  Graph :: buildTreeBFS(int countNodes)
//{
//    head= new Node;
//    list<Node*>::iterator t;
//   int allnodes=


//}
