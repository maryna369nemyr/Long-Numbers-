#ifndef LIST_FUNCTION_H_INCLUDED
#define LIST_FUNCTION_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include<math.h>
#define NMax 300
#define Newton 20
#include<time.h>
class LN;
class LongNumber
{
   private:
       int massive[NMax];
       int digit;
       const int position =10;
       int sign;
   public:
       friend class LN;
    LongNumber();//+
    LongNumber(LongNumber A, int a, int b);//+-
    LongNumber(const LongNumber &A);//+
    LongNumber( int a);//+

    void Output();//+
    int InputFromTwoToTen(char Mass[NMax], int work_len);//+
    int InputMultipleTen(char Mass[NMax], int work_len);//+

    void operator =(const LongNumber& a);//+
    LongNumber operator +(const LongNumber &a);// +
    LongNumber operator - (const LongNumber &a);// +
    LongNumber operator %(const LongNumber& a );//+
    LongNumber operator /(const LongNumber& a );//+
    LongNumber operator * (const LongNumber& a);// +
    LongNumber Pow( LongNumber n);//+

    int operator >=(const LongNumber &a);//+
    int operator >(const LongNumber &a);//+
    int operator <(const LongNumber &a);//+
    int operator <=(const LongNumber &a);//+
    void operator +=(const LongNumber &a);//+
    void operator -= (const LongNumber &a);//+
    int  operator !=(const LongNumber& a);//+
    int operator ==(const LongNumber &a);//+


    LongNumber operator/(int a);//+
    LongNumber operator *(int a);//+
    LongNumber operator %(int a );//+



    LongNumber NSD (const LongNumber &A, const LongNumber& B);
    int  operator ==( int a);//+
    int  operator !=( int a);//+
    int  operator >=( int a);//+
    int  operator <=( int a);//+
    int  operator >( int a);//+
    int  operator <(int a);//+




    void Input(char Mass[NMax], int work_len);
    void OutStartPosition();
    int CountNumericInDigit();
    LongNumber Move( int len);
    LongNumber Karatsuba(LongNumber A, LongNumber B);//-
    LongNumber Tooma3(LongNumber A, LongNumber B);//-
    void FindDigit();
    int AllowedToMulti(LongNumber A, LongNumber B);
    void FromIntToLongNumber( int a);//+
   // LongNumber PowAndMod( LongNumber n, LongNumber p);//неправильно работает
    void Lehmann();
    int Jacobi( LongNumber A, LongNumber B);
    void Solovay_Strassen();
    int J(LongNumber a, LongNumber b);
  //  void  PowTwo(LongNumber M, LongNumber B);
    int Rabin_Miller();
    int AllowedToPlus(LongNumber A, LongNumber B);
    int AllowedToSub(LongNumber A, LongNumber B);
    LongNumber PowMod(LongNumber n, LongNumber p);
    LN Bin(int *len);
    void  FromBinToLongNumber (const LN& BIN,int len );
    LN  FromLongNumberToLN ( );
    LN TheInverseOfTheNewton();


};


class LN
{
    private:

        int frac;
        int massive[NMax];
        int digit;
        const int position =10;
        int sign;

    public:
        friend class LongNumber;
    LN();
    LN(const LN &A);

    void FDIGIT();
    void FFRAC();
    int IN(char Mass[NMax], int work_len);
    void OUT();

    int operator >=(const LN &a);//+
    int operator >(const LN &a);//+
    int operator <(const LN &a);//+
    int operator <=(const LN &a);//++
    int operator !=(const LN& a);//+
    int operator ==(const LN &a);//+
    void operator =(const LN& a);
    LN operator +(const LN& A);// + and are not checking if it is allowed to do the operation
    LN operator -(const LN& A);//+ and are not checking if it is allowed to do the operation
    LN operator *(const LN& A);
    LongNumber TurnIntoLongNumberWithFrac();
    LongNumber TurnIntoLongNumber();

     LN operator *(int b);
     LN operator /(int64_t b);
     LN MOVE_DIGIT(int len);//left
     LN  MOVE_FRAC(int len);//right
      void OUT_BIN(int len);
      int IN_D(double q,char Mass[NMax], int work_len);
       LN  operator /( LongNumber q);



};
int DoubleIntoChar(double a,char Mass[NMax], int* work_len);
int StrIntoChar(char Mass[NMax], int* work_len);



#endif // LIST_FUNCTION_H_INCLUDED
