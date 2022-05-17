#include <QPair>
#include <list>
#include <iostream>
using namespace std;


template <typename T>
ostream& operator<< (ostream& ostr, const pair<int, T> t) {
     ostr << "(" << t.first << ", " << t.second << ")\n";
     return ostr;

}




template <class T>

class Filo{
private:
    T* ar;
    int size;
    int countData;
public:
    int getcountData()
    {
        return countData;
    }
    Filo()
    {
        ar=new T[256];
        size=256;
        countData=0;
    };
    Filo(int _size)
    {
        size=_size;
        ar=new T[size];
        countData=0;
    }
    ~Filo()
    {
     delete[] ar;
    }
    int push_back(T el)
    {
        if(countData+1==size)
        {
            return 0;
        }
        else
        {
         ar[countData++]=el;
         return 1;
        }


    }
    pair<int,T> pop_back()
    {
        pair<int,T> t;
        if(countData==0)
        {
            pair<int,int> t;
            t.first = 0;
            return t;
        }

       T el;
       el=ar[--countData];
       t.first=1;
       t.second=el;
       return t;
    }

};


template <class T>
class CheckBrackets : public Filo<char>
{
private:

public:
    CheckBrackets() : Filo<char>() {

    };
    ~CheckBrackets()=default;
    int checkBrackets(const char* strBrackets)
    {

        int i=0;
        while(strBrackets[i]!=NULL)
        {
          if(strBrackets[i]=='{' || strBrackets[i]=='[' || strBrackets[i]=='(' )
          {
              push_back(strBrackets[i]);
          }

          if(strBrackets[i]==']')
          {
              if(pop_back().second=='[')
              {

              }
              else
              {
                  return -1;
              }
          }
          if(strBrackets[i]==')')
          {
              if(pop_back().second=='(')
              {

              }
              else
              {
                  return -1;
              }
          }
          if(strBrackets[i]=='}')
          {
              if(pop_back().second=='{')
              {

              }
              else
              {
                  return -1;
              }
          }
          i++;
        }
        if(getcountData()!=0)
            return -1;
        return 0;
    }
};

pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el);


struct Node {
        Node();
        Node(int nameNode)
        {
            this->name = nameNode;
        }
        ~Node();

        Node* parent;
        list<Node*> listChilds;
        int name;
        static int countNodes;
    };

class Graph {
        private :
            Node* head;
            int allsearch (int countNodes);
//            list <Node*> Allnode;
            //здесь можно писать любые функции, которые могут понадобиться
        public :
            Graph();
            Graph(int countNodes);
            ~Graph();
            /*
                output		:	-1 - если функция не реализована
                            :	положительное число -- число узлов
                author		:
                date		:
            */
            int buildTreeBFS(int countNodes);
            /*
                output		:	-1 - если функция не реализована
                            :	положительное число -- число узлов
                author		:
                date		:
            */
            std::pair<bool, list<int>> searchDFS(int nameNode);
            std::pair<bool, list<int>> searchBFS(int nameNode);
    };





