#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Donator.h"

using namespace std;

static string GeneralID;

template <typename T>
Node<T>::Node() : data()
{
    this->nextNode = NULL;
}
template <typename T>
Node<T>::Node(T* data)
{
    this->data = data;
    this->nextNode = NULL;
}
template <typename T>
Node<T>::Node(T& data)
{
    this->data = &data;
    this->nextNode = NULL;
}
template <typename T>
Node<T>::~Node()
{
    delete data;
    delete nextNode;
    cout << "~Node\n";
}
template <typename T>
void Node<T>::setData(T* data)
{
    this->data = data;
}
template <typename T>
void Node<T>::setData(T& data)
{
    this->data = &data;
}
template <typename T>
void Node<T>::setNextNode(Node* nextNode)
{
    this->nextNode = nextNode;
}
template <typename T>
T* Node<T>::getData() const
{
    return data;
}
template <typename T>
Node<T>* Node<T>::getNextNode() const
{
    return nextNode;
}


template <typename T>
LinkedList<T>::LinkedList()
{
    Node<T>* dummy;
    head = dummy;
}
template <typename T>
void LinkedList<T>::add(Node<T> *newNode)
{
    Node<T> *cursor = head;
    
    for ( int pos = find(newNode->getData()); pos > 0; pos -- )
        cursor = cursor->getNextNode();
    

    newNode->setNextNode(cursor->getNextNode());
    cursor->setNextNode(newNode);
}
// template <typename T>
// void LinkedList<T>::add(Node<T> *newNode, int pos)
// {
//     Node<T> *cursor = &head;
    
//     while ( pos > 1 )
//     {
//         cursor = cursor->getNextNode();
//         pos --;
//     }
    
//     newNode->setNextNode(cursor->getNextNode());
//     cursor->setNextNode(newNode);
// }
template <typename T>
const int LinkedList<T>::find(T *target) const
{
    int res = 0;
    Donator cmprb;
    cmprb.setDonation(target->getDonation());
    cmprb.setName(target->getName());
    cmprb.setNum(target->getNum());

    const Node<T> *cursor = head;
    while ( cursor->getNextNode() )
    {
        cursor = cursor->getNextNode();
        if ( cmprb.compareForSort(cursor->getData()) > 0 )
            return res;
        
        res ++;
    }
    return res; // 있어야 할 자리index return
}
template <typename T>
void LinkedList<T>::sort(Node<T> *target, int currentPOS)
{
    Node<T> *cursor = head;
    while ( currentPOS > 1 )
    {
        cursor = cursor->getNextNode();
        currentPOS --;
    }
    cursor->setNextNode(cursor->getNextNode()->getNextNode());
    int truePOS = find(target->getData()); 
    
    add(target);
}
template <typename T>
void LinkedList<T>::SaveinFile(int argc, char* argv[]) const
{
    ofstream fout;
    fout.open(argv[1], ios::out);
 
    const Node<T>* cursor = head;
    if( !head->getNextNode() )
    {
        cout<<"List is NULL";
    } 
    else
    {
        Donator *temp;
        while ( cursor->getNextNode() ) 
        {    
            cursor = cursor->getNextNode();
            temp = cursor->getData();
            if ( temp->distinguish() == -1 )
            {
                fout << "학생 ";
                fout << temp->getId() << " ";
                fout << temp->getName() << " ";
                fout << temp->getDept() << " ";
                fout << temp->getNum() << " ";
                fout << temp->getDonation() << "\n";
            }
            else if ( temp->distinguish() == 0 )
            {
                fout << "교직원 ";
                fout << temp->getId() << " ";
                fout << temp->getName() << " ";
                fout << temp->getDept() << " ";
                fout << temp->getDeptno() << " ";
                fout << temp->getNum() << " ";
                fout << temp->getDonation() << "\n";
            }
            else if ( temp->distinguish() == 1 )
            {
                fout << "일반 ";
                fout << temp->getId() << " ";
                fout << temp->getName() << " ";
                fout << temp->getNum() << " ";
                fout << temp->getDonation() << "\n";
            }
        }
    }
 
    fout.close(); 
}
template <typename T>
void LinkedList<T>::AddDonatorwithsort()
{
    string Enter;
    cout << "신규 기탁자 정보를 입력하세요 : ";
    cin.ignore();
    getline(cin, Enter);

    stringstream ss;
    ss.str(Enter);
    ss >> Enter;

    bool flag = 0;
    if ( Enter.compare("학생") == 0 )
    {
        Student *temp = new Student();
        
        if ( !temp->setDatas(*this, ss) )
        {
            cout << "!!! 동일한 기탁자가 존재하여 신규 등록 불가 !!!\n";
            delete temp;
        }
        else
        {    
            cout << "<신규> ";
            temp->print();
            Node<T> *newNode = new Node<T>(temp);
            add(newNode);
        }
    }
    else if ( Enter.compare("교직원") == 0 )
    {
        Employee *temp = new Employee();
        
        if ( !temp->setDatas(*this, ss) )
        {
            cout << "!!! 동일한 기탁자가 존재하여 신규 등록 불가 !!!\n";
            delete temp;
        }
        else
        {    
            cout << "<신규> ";
            temp->print();
            Node<T> *newNode = new Node<T>(temp);
            add(newNode);
        }
    }
    else if ( Enter.compare("일반") == 0 )
    {
        General *temp = new General();
        string data;
        
        temp->setId(temp->nextKey(GeneralID));
        ss >> data;
        temp->setName(data);
        ss >> data;
        if ( Find(data) > -1 )
        {
            cout << "!!! 동일한 기탁자가 존재하여 신규 등록 불가 !!!\n";
            delete temp;
        }
        else
        {
            temp->setNum(data);
            ss >> data;
            temp->setDonation(stoi(data));
            cout << "<신규> ";
            temp->print();
            Node<T> *newNode = new Node<T>(temp);
            add(newNode);
        }
    }
}
template <typename T>
void LinkedList<T>::Readwithsort(string line)
{
    stringstream ss;
    ss.str(line);
    ss >> line;

    if ( line.compare("학생") == 0 )
    {
        Student *temp = new Student();
        
        temp->setDatas(*this, ss);
        Node<T> *newNode = new Node<T>(temp);
        add(newNode);
    }
    else if ( line.compare("교직원") == 0 )
    {
        Employee *temp = new Employee();
        
        temp->setDatas(*this, ss);
        Node<T> *newNode = new Node<T>(temp);
        add(newNode);
    }
    else if ( line.compare("일반") == 0 )
    {
        General *temp = new General();
        
        temp->setDatas(*this, ss);
        Node<T> *newNode = new Node<T>(temp);
        add(newNode);
    }
}
template <typename T>
void LinkedList<T>::Alter()
{
    string target; 
    cout << "변경을 원하는 사번이나 학번 또는 전화번호(XXX-XXXX-XXXX)를 입력하세요 : ";
    cin >> target;
    int pos = Find(target);

    if ( pos < 0 )
        cout << "사번이나 학번, 전화번호가 일치하지 않습니다\n";
    
    else
    {
        Node<T> *cursor = head;  
        int ammount;
        cout << "추가 기탁액을 입력하세요 : ";
        cin >> ammount;
        for ( int i = 0; i < pos; i ++ )
            cursor = cursor->getNextNode();

        cursor->getData()->setDonation(cursor->getData()->getDonation() + ammount);
        cout << "<변경>"; cursor->getData()->print();
        sort(cursor, pos);
    }
}
template <typename T>
void LinkedList<T>::Delete()
{
    string target;
    cout << "삭제를 원하는 사번이나 학번 또는 전화번호(XXX-XXXX-XXXX)를 입력하세요 : ";
    cin >> target;
    int pos = Find(target);

    if ( pos < 0 )
        cout << "사번이나 학번, 전화번호가 일치하지 않습니다\n";
    
    else
    {
        Node<T> *cursor = head;  
        for ( int i = 0; i < pos-1; i ++ )
            cursor = cursor->getNextNode();

        cout << "<삭제> ";
        cursor->getNextNode()->getData()->print();

        Node<T> *temp = cursor->getNextNode()->getNextNode();
        cursor->getNextNode()->setNextNode(NULL);
        delete cursor->getNextNode();
        cursor->setNextNode(temp);
    }
}
template <typename T>
const int LinkedList<T>::Find(string target) const
{
    int res = 0;

    const Node<T> *cursor = head;
    while ( cursor->getNextNode() )
    {
        res ++;
        cursor = cursor->getNextNode();
        if ( cursor->getData()->isEqual(target) )
            return res;
        
    } 
    return -1; // 일치하는 데이터 index return
}
template <typename T>
Node<T>* LinkedList<T>::get1st() const
{
    if( !head->getNextNode() ) 
    {
        cout<<"List is NULL";
        return 0;
    }
    else
        return head->getNextNode();
}
template <typename T>
void LinkedList<T>::printAll() const
{
    const Node<T>* cursor;
    if( !head->getNextNode() )
    {
        cout<<"List is NULL";
    } 
    else
    {
        cursor = head->getNextNode();
        cursor->getData()->print();
        while( cursor->getNextNode() )
        {
            cursor = cursor->getNextNode();
            cursor->getData()->print();
        }
    }
}


Donator::Donator()
{
    this->donation = 0;
}
Donator::Donator(string name, string num, int d)
{
    this->name = name;
    this->num = num;
    this->donation = d;
}
const bool Donator::setDatas(const LinkedList<Donator>&, stringstream& ss)
{
    return 0;
}
void Donator::setName(string name)
{
    this->name = name;
}
void Donator::setNum(string num)
{
    this->num = num;
}
void Donator::setDonation(int donation)
{
    this->donation = donation;
}
void Donator::setId(string id)
{}
string Donator::getName() const
{
    return name;
}
string Donator::getNum() const
{
    return num;
}
string Donator::getDept() const
{
    return "\0";
}
int Donator::getDeptno() const
{
    return 0;
}
int Donator::getDonation() const
{
    return donation;
}
string Donator::getId() const
{
    return 0;
}
string Donator::nextKey(string& target) const
{
    int GeneralKeyValue = 5;

    if ( target[GeneralKeyValue] == '9' )
    {
        int i = 1;
        target[GeneralKeyValue] = '0';
        while ( target[GeneralKeyValue-i] == '9' )
        {
            target[GeneralKeyValue-i] = '0';
            i ++;
        }   
        target[GeneralKeyValue-i]++;
    }
    else
        target[GeneralKeyValue]++;

    return target;
}
const bool Donator::isEqual(string str) const
{
    bool res = 0;
    if ( getId().compare(str) == 0 )
        res = 1;
    
    else if ( getNum().compare(str) == 0 )
        res = 1;
    
    return res;
}
const int Donator::compareForSort(const Donator* cmprbtarget) const
{
    int res = 0;

    if ( this->getDonation() < cmprbtarget->getDonation() )
        res = -1;
    else if ( this->getDonation() > cmprbtarget->getDonation() )
        res = 1;
    
    if ( res == 0 )
    {
        if ( this->getName().compare(cmprbtarget->getName()) < 0 )
            res = 1;
        
        else if ( this->getName().compare(cmprbtarget->getName()) > 0 )
            res = -1;
    }

    if ( res == 0 )
    {
        if ( this->getNum().compare(cmprbtarget->getNum()) > 0 )
            res = 1;
        else if ( this->getNum().compare(cmprbtarget->getNum()) < 0 )
            res = -1;
    }

    return res;
}
void Donator::print() const
{}
const int Donator::distinguish() const
{
    return -3;
}
const bool Donator::operator <(const Donator* target) const
{
    bool res = 0;
    if ( this->getDonation() < target->getDonation() )
        res = 1;

    return res;
}
const bool Donator::operator <=(const Donator* target) const
{
    bool res = 0;
    if ( this->getDonation() <= target->getDonation() )
        res = 1;

    return res;
}
const bool Donator::operator >(const Donator* target) const
{
    bool res = 0;
    if ( this->getDonation() > target->getDonation() )
        res = 1;

    return res;
}
const bool Donator::operator >=(const Donator* target) const
{
    bool res = 0;
    if ( this->getDonation() >= target->getDonation() )
        res = 1;

    return res;
}


Student::Student():Donator()
{
}
Student::Student(string name, string num, int d, string stuid, string dept)
:Donator(name, num, d)
{
    this->stuid = stuid;
    this->dept = dept;
}
void Student::setId(string stuid)
{
    this->stuid = stuid;
}
const bool Student::setDatas(const LinkedList<Donator>& ls, stringstream& ss)
{
    bool flag = 0;
    string data;
    
    ss >> data;
    if ( ls.Find(data) > -1 )
        return flag;
    this->setId(data);
    ss >> data;
    this->setName(data);
    ss >> data;
    this->dept = (data);
    ss >> data;
    if ( ls.Find(data) > -1 )
        return flag;
    this->setNum(data);
    ss >> data;
    this->setDonation(stoi(data));

    flag = 1;
    return flag;
}
string Student::getId() const
{
    return stuid;
}
string Student::getDept() const
{
    return dept;
}
void Student::print() const
{
    cout << "[학생] " << getName() << "(학번:" << getId() << ", 학과:" 
    << dept << ") " << getNum() << " " << getDonation() << endl;
}
const int Student::distinguish() const
{
    return -1;
}


Employee::Employee():Donator()
{
}
Employee::Employee(string name, string num, int d, string empid, string dept, int deptno)
:Donator(name, num, d)
{
    this->empid = empid;
    this->dept = dept;
    this->deptno = deptno;
}
void Employee::setId(string empid)
{
    this->empid = empid;
}
const bool Employee::setDatas(const LinkedList<Donator>& ls, stringstream& ss)
{
    bool flag = 0;
    string data;
    
    ss >> data;
    if ( ls.Find(data) > -1 )
        return flag;
    this->setId(data);
    ss >> data;
    this->setName(data);
    ss >> data;
    this->dept = (data);
    ss >> data;
    this->deptno = stoi(data);
    ss >> data;
    if ( ls.Find(data) > -1 )
        return flag;
    this->setNum(data);
    ss >> data;
    this->setDonation(stoi(data));

    flag = 1;
    return flag;
}
string Employee::getId() const
{
    return empid;
}
string Employee::getDept() const
{
    return dept;
}
int Employee::getDeptno() const
{
    return deptno;
}
void Employee::print() const
{
    cout << "[교직원] " << getName() << "(사번:" << getId()
    << ", 부서:" << dept << "(x" << deptno << ")" << ") "
    << getNum() << " " << getDonation() << endl;
}
const int Employee::distinguish() const
{
    return 0;
}


General::General():Donator()
{
}
General::General(string name, string num, int d, string genid)
:Donator(name, num, d)
{
    this->genid = genid;
}
void General::setId(string genid)
{
    this->genid = genid;
}
string General::getId() const
{
    return genid;
}
const bool General::setDatas(const LinkedList<Donator>& ls, stringstream& ss)
{
    bool flag = 0;
    string data;
    
    ss >> data;
    this->setId(data);
    GeneralID = data;
    ss >> data;
    this->setName(data);
    ss >> data;
    if ( ls.Find(data) > -1 )
        return flag;
    this->setNum(data);
    
    ss >> data;
    this->setDonation(stoi(data));

    flag = 1;
    return flag;
}
void General::print() const
{
    cout << "[일반] " << getName() << "(기탁자코드:" << getId()
    << ") " << getNum() << " " << getDonation() << endl;
}
const int General::distinguish() const
{
    return 1;
}


Manager::Manager()
{
    LinkedList<Donator> ls;
    list = ls;
}
void Manager::Run(int argc, char* argv[])
{
    LinkedList<Donator> donatorlist;
    ifstream ifstream(argv[1]);
    string line;
    while ( !ifstream.eof() )
    {
        getline(ifstream, line);
        donatorlist.Readwithsort(line);
    }
    // Node<Donator> *cursor = donatorlist.get1st();
    // Donator *d1 = cursor->getData();
    // Donator *d2 = cursor->getNextNode()->getData();

    cout << "*************** 발전기금 관리 프로그램 ***************\n--------- 기탁현황 ---------\n";
    donatorlist.printAll();
    Command(donatorlist, argc, argv);

    ifstream.close();
}
void Manager::Command(LinkedList<Donator>& donatorlist, int argc, char* argv[])
{
    int Command = 0;
    string Enter = "\0";
    cout << "[1] 전체 조회 / [2] 신규 기탁자 등록 / [3] 기탁정보 변경 "
    << "/ [4] 기탁자 삭제 / [5] 종료 : ";
    cin >> Command;
    while ( Command == 1 || Command == 2 || Command == 3 || Command == 4 )
    {
        switch (Command)
        {
            case 1:
                donatorlist.printAll();
                break;
            case 2:
                donatorlist.AddDonatorwithsort();
                break;
            case 3:
                donatorlist.Alter();
                break;
            case 4:
                donatorlist.Delete();
                break;
        }
        cout << "[1] 전체 조회 / [2] 신규 기탁자 등록 / [3] 기탁정보 변경 "
        << "/ [4] 기탁자 삭제 / [5] 종료 : ";
        cin >> Command;
    }
    cout << "변경 사항을 " << argv[1] << "에 저장하려면 W/w, " 
    << argv[1] << "을 이전 상태로 되돌리려면 C/c : ";
    cin >> Enter;

    if ( Enter.compare("W") == 0 || Enter.compare("w") == 0 )
    {
        donatorlist.SaveinFile(argc, argv);
        cout << ">>> 변경 사항을 저장하고 종료 <<<\n";
    }
    else if ( Enter.compare("C") == 0 || Enter.compare("c") == 0 )
        cout << ">>> 저장하지 않고 종료 <<<\n";
    else
    {
        cout << "잘못된 접근입니다.\n";
        cout << ">>> 저장하지 않고 종료 <<<\n";
    }
    
}