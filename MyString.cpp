#include "MyString.h"
#include <iostream>
#include <string.h>

using namespace std;

MyString::MyString(char *string) {
    this->buf = string;
    this->l = strlen(string) + 1;
}

MyString::MyString(const MyString &string) {
    this->l=string.l;
    if(buf!=NULL){
        buf=new buf[l];
        for(int i=0;i<string.l;i++)
            buf[i]=string.buf[i];
    }
    else
        buff=NULL;
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
            out<<buf[i];
    return out;
}

istream &operator>>(istream &in, const MyString &string){
    cout<<"Sirul:"<<"\n";
    if(string.buf!=NULL)
        delete[] buf;
    string.buf=new char[100];
    in>>string.buf;
    string.l=strlen(string.buf)+1;
    return in;
}

char &MyString::operator[](int i) {
    assert(i>=0 && i< this->l);
    return this->buf[i];
}