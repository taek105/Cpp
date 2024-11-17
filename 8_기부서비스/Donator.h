#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class Node
{
private:
    T* data;
    Node* nextNode;

public:
    Node();
    Node(T*);
    Node(T&);
    ~Node();
    void setData(T*);
    void setData(T&);
    void setNextNode(Node*);
    T* getData() const;
    Node<T>* getNextNode() const;

};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    void add(Node<T>*);
    // void add(Node<T>*, int pos);
    const int find(T* target) const; //리스트에서 정렬기준(기부액->이름->전화번호) 타겟이 있을 자리 파악 list[0] = head
    void sort(Node<T>*, int);

public:
    LinkedList();
    void SaveinFile(int argc, char* argv[]) const;
    void AddDonatorwithsort();
    void Readwithsort(string);
    void Alter();
    void Delete();
    const int Find(string target) const; //리스트에서 KEY(ID->전화번호)로 타겟의 위치 파악 list[0] = head
    Node<T>* get1st() const;
    void printAll() const;

};

class Donator
{
private:
    string name;
    string num;
    int donation;

public:
    Donator();
    Donator(string, string, int);
    virtual const bool setDatas(const LinkedList<Donator>&, stringstream&);
    virtual void setId(string);
    void setName(string);
    void setNum(string);
    void setDonation(int);
    virtual string getId() const;
    string getName() const;
    string getNum() const;
    virtual string getDept() const;
    virtual int getDeptno() const;
    int getDonation() const;
    string nextKey(string&) const;
    const bool isEqual(string) const;
    const int compareForSort(const Donator*) const;
    virtual void print() const;
    virtual const int distinguish() const;
    const bool operator <(const Donator*) const;
    const bool operator <=(const Donator*) const;
    const bool operator >(const Donator*) const;
    const bool operator >=(const Donator*) const;

};

class Student : public Donator
{
private:
    string stuid;
    string dept;
    
public:
    Student();
    Student(string, string, int, string, string);
    void setId(string);
    const bool setDatas(const LinkedList<Donator>&, stringstream&);
    string getId() const;
    string getDept() const;
    void print() const;
    const int distinguish() const;

};

class Employee : public Donator
{
private:
    string empid;
    string dept;
    int deptno;
    
public:
    Employee();
    Employee(string, string, int, string, string, int); 
    void setId(string);
    const bool setDatas(const LinkedList<Donator>&, stringstream&);
    string getId() const;
    string getDept() const;
    int getDeptno() const;
    void print() const;
    const int distinguish() const;

};

class General : public Donator
{
private:
    string genid;

public:
    General();
    General(string, string, int, string);
    void setId(string);
    const bool setDatas(const LinkedList<Donator>&, stringstream&);
    string getId() const;
    void print() const;
    const int distinguish() const;

};

class Manager
{
private:
    LinkedList<Donator> list;
    void Command(LinkedList<Donator>&, int argc, char* argv[]);

public:
    Manager();
    void Run(int argc, char* argv[]);
    
};