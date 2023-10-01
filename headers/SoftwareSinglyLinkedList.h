#pragma once
#include <iostream>
#include "NodeSoftware.h"

using namespace std;

class SoftwareSinglyLinkedList
{
private:
    int longList;
    NodeSoftware* next;
public:
    SoftwareSinglyLinkedList();
    SoftwareSinglyLinkedList(NodeSoftware*);
    ~SoftwareSinglyLinkedList();
    int getLongList();
    NodeSoftware* getFirst();
    virtual bool isEmpty();
    virtual NodeSoftware* searchNode(string name);
    virtual void setFirst(NodeSoftware*);
    virtual void insert(NodeSoftware*); //insertLast
    virtual void deleteNode(string name);
    //virtual NodeUser* moverAlFinal();
    //virtual NodeUser* moverAnterior(NodeUser*);
    //virtual void insertFirst(NodeUser*);
    //virtual void eliminarInicio();
    //virtual void eliminarFinal();
    //virtual void insertarSiguiente(NodoSimple*,int);
    //virtual void eliminarSiguiente(int);
};