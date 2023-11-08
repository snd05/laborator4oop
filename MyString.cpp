#include "MyString.h"
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

MyString::MyString(char *string) {
    this->buf = string;
    this->l = strlen(string) + 1;
}

MyString::MyString(const MyString &string) {
    this->l=string.l;
    if(buf!=NULL){
        buf=new char[l];
        for(int i=0;i<string.l;i++)
            buf[i]=string.buf[i];
    }
    else
        buf=NULL;
}

MyString &MyString::operator=(const MyString &string) {
    l=string.l;
    for(int i=0;i<l;i++)
        buf[i]=string.buf[i];
    return *this;
}

ostream &operator<<(ostream &out, const MyString &string){
    out<<"Numarul de elemente:"<<string.l<<"\n";
    out<<"Sirul: ";
    if(string.buf!=NULL)
        for(int i=0;i<string.l;i++)
            out<<string.buf[i];
    return out;
}

istream &operator>>(istream &in,  MyString &string){
    cout<<"Sirul:"<<"\n";
    if(string.buf!=NULL)
        delete[] string.buf;
    string.buf=new char[100];
    in>>string.buf;
    string.l=strlen(string.buf)+1;
    return in;
}

char &MyString::operator[](int i) {
    assert(i>=0 && i< this->l);
    return this->buf[i];
}

int MyString::get_len() {
    int len;
    len=this->l;
    return len;
}

const MyString operator+( const MyString &a, const  MyString &b){
    int dim1=a.l, dim2=b.l;
    int dim_fin=dim1+dim2-1;
    char c[dim_fin];
    if(a.buf!=NULL)
        strcpy(c,a.buf);
    if(b.buf!=NULL)
        strcpy(c,b.buf);


    MyString result(c);

    return result;
}