#include <iostream>

using namespace std;

class MyString {
private:
    char *buf; // stocheaza sirul de lungime l (nu uitati sa alocati spatiu si pentru caracterul’/0’)
    int l;
public:
    MyString();

    MyString(char *);

    MyString(const MyString &);

    MyString &operator=(const MyString &);

    ~MyString();

    friend ostream &operator<<(ostream &, const MyString &);

    friend istream &operator>>(istream &, MyString &);

    char &operator[](int);

    int get_len();

    friend const MyString operator+(const MyString &, const MyString &); /* concateneaza 2 stringuri si salveaza rezultatul intr-un obiect nou de tip MyString pe care il returneaza*/
    MyString &operator+=(const MyString &); /*concateneaza 2 stringuri si salveaza rezultatul in primul operand a carui adresa o returneaza*/
    friend bool operator==(const MyString &, const MyString &); /*verifica daca cele 2 siruri sunt identice*/
    friend bool operator!=(const MyString &, const MyString &);/*verifica daca cele 2 siruri sunt diferite*/
    int lookFor(char); //cauta caracterul dat ca parametru in sir si returneaza numarul de aparitii
};
