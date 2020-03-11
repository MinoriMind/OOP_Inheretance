#include <iostream>
#include <string>
using namespace std;


enum GENDER
{
    U, M, F
};


enum SUIT
{
    DRESSED, UNDRESSED, SUITED
};


class UndressedHuman
{
    string fio;
    int age;
    GENDER gender;
public:
    UndressedHuman(string fio, int age, GENDER gender)
    {
        this->fio = fio;
        this->age = age;
        this->gender = gender;
    }

    void SetFio(string Name)
    {
        fio = Name;
    }

    string GetFio()
    {
        return fio;
    };
};


class DressedHuman : public UndressedHuman
{
    SUIT suit;
public:
    string cool;
    DressedHuman(string fio , int age, GENDER gender, string cool, SUIT suit) :
    UndressedHuman (fio, age, gender)
    {
        this->cool = cool;
        this->suit = suit;
    }
    void SetSuit(SUIT suit)
    {
        this->suit = suit;
    }
    SUIT GetSuit()
    {
        return suit;
    }
};


class Boy : public UndressedHuman
{
    int parentNum;
public:
    Boy (string fio , int age, GENDER gender, string cool, SUIT suit) :
    UndressedHuman (fio, age, gender)
    {
        this->parentNum = 2;
    }

    int GetParentNum()
    {
        return parentNum;
    }
};


class DoctorHuman : public UndressedHuman
{
    int healed;
    SUIT suit;
public:
    DoctorHuman(string fio , int age, GENDER gender, SUIT suit, int healed) :
    UndressedHuman (fio, age, gender)
    {
        this->suit = suit;
        this->healed = healed;
    }

    void SetHealedNum(int healed)
    {
        this->healed = healed;
    }

    int GetHealedNum()
    {
        return healed;
    }
};




class CoolDoctor: public DoctorHuman
{
    int cured;
public:
    CoolDoctor(string fio , int age, GENDER gender, SUIT suit, int healed, int cured) :
    DoctorHuman (fio, age, gender, suit, healed+1)
    {
        this->cured = cured;
    }

    void SetCuredNum(int cured)
    {
        this->cured = cured;
    }

    int GetCuredNum()
    {
        return cured;
    }
};


int main()
{
    string Name = "Pipe";
    int age = 5;
    GENDER gender = M;
    SUIT suit = DRESSED;
    string cool = "Cool thing";
    UndressedHuman humoon(Name, age, gender);
    cout << "Undressed human FIO: " << humoon.GetFio() << endl;
    humoon.SetFio("dos");
    cout << "New undressed human FIO: " << humoon.GetFio() << endl;
    DressedHuman dressed(Name, age, gender, cool, suit);
    dressed.SetSuit(suit);
    cout << cool << endl;
    cout << "Suit number: " << dressed.GetSuit() << endl;

    int healed = 0;
    int cured = 0;
    CoolDoctor mistercool(Name, age, gender, suit, healed, cured);
    mistercool.SetHealedNum(10);
    mistercool.SetCuredNum(228);
    cout << "Healed by cool doc: " << mistercool.GetHealedNum() << endl;
    cout << "Cured by cool doc: " << mistercool.GetCuredNum() << endl;
    return 0;
}