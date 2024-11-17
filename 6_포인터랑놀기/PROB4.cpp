#include <iostream>
#include <string>

using namespace std;

class Set
{
private:
    int capacity;
    int cnt;
    int *data;
    void resize();

public:
    Set();
    Set(const Set& s1);
    ~Set();
    void addData(int);
    const int getCapacity();
    const int getCnt();
    int* getData();
    void duplicateDelete();
    const Set operator |(const Set& s1) const;
    const Set operator &(const Set& s1) const;
    const Set& operator =(const Set& s1);
    Set hi(Set s1);
};
istream& operator >>(istream& inputstream, Set& s1);
ostream& operator <<(ostream& outputstream, Set& s1);

Set Set::hi(Set s1)
{
    cout << "hi";
    return s1;
}

void Set::resize()
{
    if ( cnt == capacity )
    {
        capacity *= 2;
        int *temp = new int[capacity]; 
        for ( int i = 0; i < cnt; i ++ )
        {
            *(temp+i) = *(data+i);
        }
        delete []data; 
        data = temp;
    }
}

Set::Set()
{
    capacity = 10;
    cnt = 0;
    data = new int[capacity];
}

Set::Set(const Set& s1)
{  
    // this->capacity = s1.capacity;
    // this->cnt = s1.cnt;
    // for ( int i = 0; i < cnt; i ++ )
    //     data[i] = s1.data[i];

    cout << "check";
}

Set::~Set()
{
    delete []data;
}

void Set::addData(int enter)
{   
    resize();

    data[cnt++] = enter;
}

const int Set::getCapacity()
{
    return capacity;
}

const int Set::getCnt()
{
    return cnt;
}

int* Set::getData()
{
    return data;
}

void Set::duplicateDelete()
{      
    for ( int i = 0; i < cnt; i ++ )
    {   
        for ( int j = i+1; j < cnt; j ++ )
        {   
            if ( data[i] == data[j] )
            {        
                cout << data[i] << " is deleted as duplicated element\n";
                data[i] = 0;
            }
        }
    }
    for ( int i = 0; i < cnt; i ++ )
    {
        if ( data[i] == 0 )
        {
            for ( int j = 0; i+j+1 < cnt; j ++ )
                data[i+j] = data[i+j+1];
            
            data[cnt-1]= 0;
            cnt --;
            i --;
        }
    }
}

const Set Set::operator |(const Set& s1) const
{
    Set res;

    for ( int i = 0; i < cnt; i ++ )
        res.addData(data[i]);

    for ( int i = 0; i < s1.cnt; i ++ )
        res.addData(s1.data[i]);

    res.duplicateDelete();

    return res;
}

const Set Set::operator &(const Set& s1) const
{
    Set res;
    
    for ( int i = 0; i < cnt; i ++ )
    {
        for ( int j = 0; j < s1.cnt; j ++ )
        {
            if ( *(data+i) == *(s1.data+j) ) 
                res.addData(*(data+i));
        }
    }

    return res;
}

const Set& Set::operator =(const Set& s1)
{
    this->capacity = s1.capacity;
    this->cnt = s1.cnt;
    for ( int i = 0; i < cnt; i ++ )
       data[i] = s1.data[i];

    return *this;
}

istream& operator >>(istream& inputstream, Set& s1)
{  
    int ent;
    inputstream >> ent;
    while ( ent > 0 )
    {   
        s1.addData(ent);
        inputstream >> ent;
    }
    s1.duplicateDelete();

    return inputstream;
}

ostream& operator <<(ostream& outputstream, Set& s1)
{
    int *data = s1.getData();
    for ( int i = 0; i < s1.getCnt(); i ++ )
        outputstream << *(data+i) << " ";
    outputstream << endl;

    return outputstream;
}

int main()
{

    Set s1, s2, resultSet ;
    cout << "Input 2 sets of integers(Each set should end with a negative value)." << endl ; 
    cin >> s1 >> s2;
    
    resultSet = s1 | s2;
    cout << "Union is " << resultSet ; // 합집합
    resultSet = s1 & s2 ;
    cout << "Intersection is " << resultSet ; // 교집합

    // s1.hi(s2);

}