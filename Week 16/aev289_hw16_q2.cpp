#include <iostream>
#include <vector>

using namespace std;
template <class T>
class Queue{
    vector <T> data;
    int start=0;
public:
    void enqueue(T newItem){data.push_back(newItem);}
    T dequeue(){//pop
        if(isEmpty())
        {
            return NULL;
        }
        else{
            T temp=data[start];
            start++;
            if(isEmpty())
            {
                clear();
            }
            return temp;
        }
    }
    T top() const{
        if(isEmpty())
            return NULL;
        else
            return data[start];}
    bool isEmpty()const{
            return data.size()==start;}
    int size()const{return data.size()-start;}
    void clear(){
        start=0;
        data.clear();}
    
};
#include <iostream>

int main(){
   
    return 0;
}
