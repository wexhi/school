/*
    类模板：以Vector题目为例。
*/
#include <iostream>
using namespace std;
 
template <class T>
class Vector{
private:
    T *p;
    int capability;
    int length;
public:
    Vector()
    {
        capability=0;
        length=0;
        p=NULL;
    }
    Vector(Vector &v)
    {
        capability=v.capability;
        length=v.length;
        p=new T[capability];
        for(int i=0;i<length;i++)
            p[i]=v.p[i];
    }
    ~Vector()
    {
        delete []p;
    }
    int add(T value)
    {
        if(length<capability){
            p[length]=value;
        }else{
            capability+=4;
            T *q=new T[capability]; 
            for(int i=0;i<length;i++)
                q[i]=p[i];
            if(p!=NULL)
                delete []p;
            p=q;
            p[length]=value;
        }
        length++;
        return length-1;
    }
    int get_size()
    {
        return length;
    }
    T operator [](int index)
    {
        return p[index];
    }
    void remove(int index)
    {
        if(index<0 || index>=length)
            return ;
        for(int i=index;i<length-1;i++)
            p[i]=p[i+1];
        length--;
    }
};
 
int main()
{
    Vector<int> vint;
    int n,m;
    cin >> n >> m;
    for ( int i=0; i<n; i++ ) {
        //    add() can inflate the vector automatically
        vint.add(i);    
    }
    //    get_size() returns the number of elements stored in the vector
    cout << vint.get_size() << endl;
    cout << vint[m] << endl;
    //    remove() removes the element at the index which begins from zero
    vint.remove(m);
    cout << vint.add(-1) << endl;
    cout << vint[m] << endl;
    Vector<int> vv = vint;
    cout << vv[vv.get_size()-1] << endl;
    vv.add(m);
    cout << vint.get_size() << endl;
    system("pause");
    return 0;
}