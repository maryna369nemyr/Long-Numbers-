#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include <string.h>
#include <cstring>


#include "List_Function.h"
using namespace std;

int LongNumber:: AllowedToMulti(LongNumber A, LongNumber B)
{
    if( ((A.digit+B.digit)<=NMax)||(((A.digit==1)&&(A.massive[NMax-1]==0))||((B.digit==1)&&(B.massive[NMax-1]==0))) )
        return 1;
    else return 0;
}
int LongNumber:: AllowedToPlus(LongNumber A, LongNumber B)
{
    if(A.sign==B.sign) {
                            if((A.digit+B.digit)<=NMax) return 1;
                            if(A.digit==NMax )
                               {
                                   LongNumber A1(A, NMax-B.digit, NMax-1);
                                   LongNumber s; s=A1+B;if (s.digit==B.digit) return 1; else return 0;}
                            if(B.digit==NMax )
                               {
                                   LongNumber B1(B, NMax-A.digit, NMax-1);
                                   LongNumber s; s=B1+A;if (s.digit==A.digit) return 1; else return 0;}
                            return 0;
                        }
     else return 1;

}
int LongNumber:: AllowedToSub(LongNumber A, LongNumber B)
{
    if(A.sign!=B.sign) {
                            if((A.digit+B.digit)<=NMax) return 1;
                            if(A.digit==NMax )
                               {
                                   LongNumber A1(A, NMax-B.digit, NMax-1);
                                   LongNumber s; s=A1+B;if (s.digit==B.digit) return 1; else return 0;}
                            if(B.digit==NMax )
                               {
                                   LongNumber B1(B, NMax-A.digit, NMax-1);
                                   LongNumber s; s=B1+A;if (s.digit==A.digit) return 1; else return 0;}
                            return 0;
                        }
     else return 1;

}
LongNumber::LongNumber(const LongNumber &a)
{
    int i;
    for (i=0; i<NMax;i++)
    {
        massive[i]=a.massive[i];
    }
    digit=a.digit;
    sign=a.sign;

}
LongNumber::LongNumber(LongNumber A, int a, int b)
{
    int i;
    for(i=0;i<NMax;++i)
        massive[i]=0;
    digit=1;
    sign=1;

    for(i=0;i<=b-a;i++)
    {
        massive[NMax-1-i] =A.massive [b-i];
    }
    FindDigit();
    sign=1;

}

LongNumber::LongNumber(int a)
{
    int pos=a;
    int k_pos=0;
    while(pos>0)
    {pos=pos/10;k_pos++;}

     int i;
     if(k_pos>NMax)

     {
         cout<<" CHECK THE NUMBER. TOO BIG NUMBER. YOU WILL GET ZERO\n"<<endl;
         for(i=0;i<NMax;++i) massive[i]=0;
         digit=1;sign=1;
     }
     else
        {      if(a<0) {sign=0;a=-a;}
                else sign=1;
            for(i=0;i<NMax;++i) massive[i]=0;
            digit=1;
            unsigned int temp=a;
            i=0;
              while(temp>0)
                {
                    massive[NMax-i-1]=temp%position;
                    temp=temp/position;
                    i++;
                }
            FindDigit();
        }
}
void LongNumber::FindDigit()
{

     int k=0;
     int i;
     for(i=0;i<NMax;i++)
     {
        if((massive[i]==0)) {k++; continue;}
        else break;
     }

       if(NMax==k) digit=1;
       else digit=NMax-k;


}
int LongNumber::  CountNumericInDigit()
{
    int pos=position;
    int k_pos=0;
    while(pos>0)
    {
        pos=pos/10;
        k_pos++;
    }
    return k_pos;
}

void LongNumber:: OutStartPosition()
{
    cout << "START! You work in "<<position<<" numerical system ."<< endl;
}
LongNumber::LongNumber()
{
    int i;
    for(i=0;i<NMax;++i)
        massive[i]=0;
    digit=1;
    sign=1;
}

void LongNumber::Output()
{
     int k=0;
     int i;
     for(i=0;i<NMax;i++)
     {
        if((massive[i]==0)) {k++; continue;}
        else break;
     }
    if((*this)==0) --k;
    for (i=k;i<NMax;i++)//вместо 0 нужно ставить к для красивого вывода
        cout<<massive[i]<<",";
        cout<<endl;
        cout<<"DIGIT="<<digit<<endl;
        if(sign) cout<<"SIGN   +"<<endl;
        else cout<<"SIGN   -"<<endl;
        cout<<"\n";
}
int StrIntoChar(char Mass[NMax], int* work_len)
{
    string number;
    cout<<"Enter the LongNumber:"<<endl;
    cin>>number;
    int k;
    LongNumber a;
    k=a.CountNumericInDigit();

    if(k>1){if(number.size()>NMax*(k-1)) { cout<<"MISTAKE. NUMBER IS BIGGER THEN IT IS ALLOWED."<<endl;return 0;}
           else {strcpy(Mass,number.c_str());//NMax* количество цифр в разряде
                *work_len=strlen(Mass);return 1;}
            }
    else {if(number.size()>NMax) { cout<<"MISTAKE. NUMBER IS BIGGER THEN IT IS ALLOWED."<<endl;return 0;}
                else {strcpy(Mass,number.c_str());//NMax* количество цифр в разряде
                      *work_len=strlen(Mass);return 1;}
               }

}
int LongNumber::InputFromTwoToTen(char Mass[NMax], int work_len)
{

                 sign=1;
                 int temp=work_len;
                 int i,j=0;
                 if(Mass[0]=='-') {sign=0;j=1;--temp;}
                 for (i=0;i<temp;i++)
                    {


                            if(((Mass[work_len-1-i]-'0')<position)&&(Mass[work_len-1-i]-'0')>=0)
                             {massive[NMax-1-i]=Mass[work_len-1-i]-'0';}
                              else
                             {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}



                    }
                  FindDigit();  //если система исчисления больше 10, то эта функция работает как для 10.
                 return 1;
}
int LongNumber::InputMultipleTen(char Mass[NMax], int work_len)
{
    InputFromTwoToTen(Mass, work_len);
    if(position==10) return 1;
    int power=0,razryad=0, k=0,schetchik=0, temp=0;
    int a[NMax];
    int j,i;
    int helpp=k;int q; if(sign==0) q=1; else q=0;
    int razryad_10=digit;
    int k_pos= CountNumericInDigit();

        for(i=0;i<razryad_10;i++)
        {
           for (j=helpp;j<razryad_10;j++)
            {
                temp=temp+ (Mass[work_len-1-j]-'0')* powf(10,power);
                k++;schetchik++;
                    if((temp*10<position)&&(k<work_len-q))
                    {
                        if ((schetchik==k_pos-1)&&((Mass[work_len-1-j]-'0')==0))
                              {
                                schetchik=0;
                                helpp=k;
                                power=0;
                                razryad++;
                                a[razryad-1]=temp;
                                temp=0;
                                break;
                              }
                        else   { power++;  continue;  }
                    }
                    else
                      {
                        schetchik=0;
                        helpp=k;
                        power=0;
                        razryad++;
                        a[razryad-1]=temp;
                        temp=0;
                        break;
                     }
            }
        }

        LongNumber zero;
        (*this)=zero;
        if(q) sign=0;
        for (i=0; i<razryad;i++)
        massive[NMax-1-i]=a[i];
        FindDigit();
    return 1;
}

void LongNumber::operator=(const LongNumber& a)
{
    int i;
    for (i=0; i<NMax;i++)
    {
        massive[i]=a.massive[i];
    }
    digit=a.digit;
    sign=a.sign;
}
LongNumber LongNumber:: operator +(const LongNumber& A)
{

   LongNumber sum;
   LongNumber a=A;
   LongNumber b=(*this);
   if(!AllowedToPlus((*this), a)) {cout<<" YOU CAN'T DO THE OPERATION + .";} // END OF WORK.\n\n"; exit(0);}
   if((sign ==0)&&(a.sign==1)){b.sign=1; sum= a-b;return sum;}
   if((a.sign==0)&&(sign==1)) {a.sign=1; sum=(*this)-a; return sum;}

   int max_digit = (digit >a.digit) ? digit:a.digit;
  // if((max_digit+1)>=NMax) {cout<<"<<END OF WORK +>>\n\n"; exit(0);}//////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   int r = 0;
   int i;
   int temp;
   for (i = 0; i<max_digit; i++)
   {
    temp = massive[NMax-1-i]+a.massive[NMax-1-i]+r;
    r=temp/position;
    sum.massive[NMax-1-i]=temp%position;
   }
   sum.massive[NMax-1-max_digit] = r;
   int plusOneDigit=((r > 0) ? 1 : 0);
   sum.digit =max_digit+plusOneDigit;
   if((sign ==1)&&(a.sign==1)) sum.sign=1;
   if ((sign ==0)&&(a.sign==0)) sum.sign=0;
   return sum;
}
LongNumber LongNumber:: operator - (const LongNumber &A)
{
    LongNumber rizn;
    LongNumber a=A;
    LongNumber b=(*this);
    if(!AllowedToSub((*this), a)) {cout<<" YOU CAN'T DO THE OPERATION  -";} //END OF WORK.\n\n"; exit(0);}
    if((sign==1)&&(a.sign==0)) {a.sign=1; rizn=(*this)+a; rizn.sign=1; return rizn;}
    if((sign==0)&&(a.sign==1)) {b.sign=1; rizn=b+a; rizn.sign=0; return rizn;}

    int max_digit = (digit >a.digit) ? digit:a.digit;
    int r = 0;
    int i;
    if((sign==1)&&(a.sign==1))
    {if ((*this)>=a)
    {for(i=0;i<max_digit;i++)
    {
        r=massive[NMax-1-i] - a.massive[NMax-1-i]-r;
        rizn.massive[NMax-1-i]=(r<0)?(r+position):(r);
        r=(r<0)?1:0;
    }
    if (r==1) {rizn.massive[NMax-1-max_digit]=rizn.massive[NMax-1-max_digit]-1;}
    rizn.FindDigit(); rizn.sign=1;
    }
    if ((*this)<a)
    {for(i=0;i<max_digit;i++)
    {
        r=a.massive[NMax-1-i] - massive[NMax-1-i]-r;
        rizn.massive[NMax-1-i]=(r<0)?(r+position):(r);
        r=(r<0)?1:0;
    }
    if (r==1) {rizn.massive[NMax-1-max_digit]=rizn.massive[NMax-1-max_digit]-1;}
    rizn.FindDigit();rizn.sign=0;
    }
    }


    if((sign==0)&&(a.sign==0))
    {if ((*this)<a)
    {for(i=0;i<max_digit;i++)
    {
        r=massive[NMax-1-i] - a.massive[NMax-1-i]-r;
        rizn.massive[NMax-1-i]=(r<0)?(r+position):(r);
        r=(r<0)?1:0;
    }
    if (r==1) {rizn.massive[NMax-1-max_digit]=rizn.massive[NMax-1-max_digit]-1;}
    rizn.FindDigit(); rizn.sign=0;
    }
    if ((*this)>=a)
    {for(i=0;i<max_digit;i++)
    {
        r=a.massive[NMax-1-i] - massive[NMax-1-i]-r;
        rizn.massive[NMax-1-i]=(r<0)?(r+position):(r);
        r=(r<0)?1:0;
    }
    if (r==1) {rizn.massive[NMax-1-max_digit]=rizn.massive[NMax-1-max_digit]-1;}
    rizn.FindDigit();rizn.sign=1;
    }
    }
    //else {cout<<"IT IS IMPOSSIBLE TO DO THE OPERATION (NEGATIVE NUMBER).YOU WILL GET NUMBER 0"<<endl;}
    return rizn;

}
int LongNumber:: operator >=(const LongNumber &a)
{
    if((sign==1)&&(a.sign==0)) return 1;
    if((sign ==0)&&(a.sign==1)) return 0;
    if(sign==1){if(digit>a.digit) return 1;
                if(digit<a.digit) return 0;}
    if(sign==0){if(digit>a.digit) return 0;
                if(digit<a.digit) return 1;}
    if((digit==a.digit)&&(sign==1))
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax-digit+i]>a.massive[NMax-digit+i]) return 1;
           if(massive[NMax-digit+i]<a.massive[NMax-digit+i]) return 0;
           if(massive[NMax-digit+i]==a.massive[NMax-digit+i]) continue;
        }
        return 1;
    }
    else
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax-digit+i]>a.massive[NMax-digit+i]) return 0;
           if(massive[NMax-digit+i]<a.massive[NMax-digit+i]) return 1;
           if(massive[NMax-digit+i]==a.massive[NMax-digit+i]) continue;
        }
        return 1;
    }
}
int LongNumber:: operator <=(const LongNumber &a)
{
    if((sign==1)&&(a.sign==0)) return 0;
    if((sign ==0)&&(a.sign==1)) return 1;
    if(sign==1){if(digit>a.digit) return 0;
                if(digit<a.digit) return 1;}
    if(sign==0){if(digit>a.digit) return 1;
                if(digit<a.digit) return 0;}
    if((digit==a.digit) &&(sign==1))
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax-digit+i]>a.massive[NMax-digit+i]) return 0;
           if(massive[NMax-digit+i]<a.massive[NMax-digit+i]) return 1;
           if(massive[NMax-digit+i]==a.massive[NMax-digit+i]) continue;
        }
        return 1;
    }
    else
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax-digit+i]>a.massive[NMax-digit+i]) return 1;
           if(massive[NMax-digit+i]<a.massive[NMax-digit+i]) return 0;
           if(massive[NMax-digit+i]==a.massive[NMax-digit+i]) continue;
        }
        return 1;
    }
}
void LongNumber:: operator +=(const LongNumber &a)
{
  (*this) = ((*this)+a);
}
void LongNumber:: operator -=(const LongNumber &a)
{
  (*this) = ((*this)-a);
}
void LongNumber:: Input(char Mass[NMax], int work_len)
{
    int temp=StrIntoChar(Mass,&work_len);
    if (temp==0) {cout<<"END OF WORK. ( the word in string is too long)."<<endl;exit(0);}

    int n=3;
    if ((position <=10)&&(position >=0)) n=1;
    if ((position >10)&&(position%10==0) )n=2;
    switch(n)
    {case 1:
      InputFromTwoToTen(Mass, work_len);
      break;
     case 2:
        InputMultipleTen(Mass, work_len);
        break;
     default:
            cout<<"You have wrong NUMBER SYSTEM.(Check in the class).   END OF WORK"<<endl;
            exit(0);
    }
}
LongNumber LongNumber:: operator * (const LongNumber& a)
{
    int t=AllowedToMulti((*this),a);
    if(t==0) {cout<<">>It is not enough memory to multiplication<<\n>>END OF WORK<<";exit(0);}

  int i,j;
  int vuras,r;
  LongNumber temp;
  LongNumber zero;
  LongNumber dobutok;



  int max_digit=((*this)>=a)?(digit):(a.digit);
  int min_digit=((*this)<=a)?(digit):(a.digit);
  LongNumber max_arr, min_arr;
  if(min_digit==digit) {min_arr=(*this); max_arr=a;}
  else {min_arr=a; max_arr=(*this);}

  for(i=0;i<min_digit;i++)
  {
      temp=zero;
      r=0;
      vuras=0;
      for(j=0;j<max_digit;j++)
      {
        vuras=max_arr.massive[NMax-1-j]*min_arr.massive[NMax-i-1] +r;
        temp.massive[NMax-j-1]=vuras%position;
        r=vuras/position;
      }
      temp.massive[NMax-1-max_digit]=r;
      int helpp=((r>0)?1:0);
      temp.digit=max_digit+helpp;
      temp=temp.Move(i);
      dobutok+=temp;

  }
 dobutok.FindDigit();
     if(((sign==1)&&(a.sign==1))||((sign==0)&&(a.sign==0))) dobutok.sign=1;
      if(((sign==0)&&(a.sign==1))||((sign==1)&&(a.sign==0))) dobutok.sign=0;
  return dobutok;
}


LongNumber LongNumber:: Move( int len)//влево
{
    if (len>NMax- digit) {cout<<"Check the move ! Mistake. END OF WORK\n\n"; exit(0);}
    LongNumber B;
    int pos_start;
    pos_start=NMax-digit - len;
     int i,j=0;
     for(i=pos_start;i<pos_start+digit;i++)
     {
         B.massive[i]=massive[NMax-digit+j];
         j++;

     }
     B.digit = digit+len;
     return B;
}

LongNumber LongNumber:: Karatsuba(LongNumber A, LongNumber B)
{
    int t=AllowedToMulti(A,B);
    if(t==0) {cout<<">>It is not enough memory to multiplication<<\n>>END OF WORK<<";exit(0);}

    LongNumber result;

    if ((A.digit==1)||(B.digit==1))
        {
          if(B.digit==1)
          result=A*B.massive[NMax-1];
          else result=B*A.massive[NMax-1];

          return result;
       }
    int shiftt;
    shiftt=(A.digit+B.digit)/4;
    if(shiftt>A.digit) shiftt=A.digit/2;
    if(shiftt>B.digit) shiftt=B.digit/2;



    LongNumber b(A,NMax-shiftt,NMax-1);//cout<<"~ "<<")b="; b.Output();cout<<endl;
    LongNumber a (A,NMax-A.digit,NMax-shiftt-1);//cout<<" ~"<<")a="; a.Output();cout<<endl;

    LongNumber d(B,NMax-shiftt,NMax-1);// cout<<"~ "<<")d="; d.Output();cout<<endl;
    LongNumber c(B,NMax-B.digit,NMax-shiftt-1);//cout<<"~ "<<")c="; c.Output();cout<<endl;



     LongNumber ac=Karatsuba(a,c);
     LongNumber bd=Karatsuba(b,d);
     LongNumber ad_bc = Karatsuba((a+b),(c+d)) - ac - bd;

    ac=ac.Move(shiftt+shiftt);
    ad_bc=ad_bc.Move(shiftt);

    result=ac+ad_bc+bd;
}


 LongNumber LongNumber:: operator /(int A)
 {
     int a= (A>=0)?A:(-A);
    int perenos=0;
    int vuras;
    LongNumber div;

    LongNumber helpp;

    int i;
    for (i=0; i< digit; i++)
          {
                vuras=(massive[NMax-digit+i]  + perenos*position)/a;
                helpp.massive[NMax-1]=vuras;
                div=div+helpp.Move(digit-1-i);
                perenos =(massive[NMax-digit+i]  + perenos*position)-vuras*a;
          }

     div.FindDigit();
      if(((sign==1)&&(A>=0))||((sign==0)&&(A<=0))) div.sign=1;
      if(((sign==0)&&(A>0))||((sign==1)&&(A<0))) div.sign=0;
     return div;
 }

LongNumber LongNumber:: operator *(int A)
{
       int a= (A>=0)?A:(-A);
        int pos=a;
    int k_pos=0;
    while(pos>0)
    {
        pos=pos/10;
        k_pos++;
    }
    k_pos;

    if( ((digit+k_pos)<=NMax)||(((digit==1)&&(massive[NMax-1]==0))||(a==0)) );

    else  {cout<<">>It is not enough memory to multiplication<<\n>>END OF WORK<<";exit(0);}
  int j,i;
  int vuras=0,r=0;
  LongNumber temp;
  LongNumber dobutok;

      for(j=0;j<digit;j++)
      {
        vuras=massive[NMax-1-j]*a +r;
        temp.massive[NMax-j-1]=vuras%position;
        r=vuras/position;
      }
      int helpp;
      if (r<position) {temp.massive[NMax-1-digit]=r; helpp=((r>0)?1:0);  temp.digit=digit+helpp;}
      else
      {for(i=0;r>0;i++)
       {
           temp.massive[NMax-digit-1-i]=r%position;
           r=r/position;
       }

           temp.digit=digit+i;
      }
      dobutok=temp;
      dobutok.FindDigit();
      if(((sign==1)&&(A>=0))||((sign==0)&&(A<=0))) dobutok.sign=1;
      if(((sign==0)&&(A>0))||((sign==1)&&(A<0))) dobutok.sign=0;

  return dobutok;}

LongNumber LongNumber :: Tooma3(LongNumber A, LongNumber B)
{
    int t=AllowedToMulti(A,B);
    if(t==0) {cout<<">>It is not enough memory to multiplication<<\n>>END OF WORK<<";exit(0);}

 LongNumber result;

 if((A.digit<=2)||(B.digit<=2))
 {   if(A.digit<=2)
        result=B*(A.massive[NMax-1]+A.massive[NMax-2]*position);
        else result=A*(B.massive[NMax-1]+B.massive[NMax-2]*position);
       return result;
 }

 int shiftt=((A.digit)>(B. digit))?((A.digit)/3):((B. digit)/3);
 if(shiftt==0) shiftt=1;


 LongNumber a3(A,NMax-A.digit,NMax-2*shiftt-1);     // the biggest
 LongNumber a2(A,NMax -2*shiftt ,NMax -shiftt-1);
 LongNumber a1(A, NMax-shiftt , NMax-1);

 LongNumber b3(B,NMax-B.digit,NMax-1-2*shiftt);    // the biggest
 LongNumber b2(B,NMax -2*shiftt,NMax -shiftt-1);
 LongNumber b1(B, NMax-shiftt,NMax-1);


 LongNumber W4=Tooma3(a3,b3);// W(t)=A(t)*B(t)   W(бесконечности) A=t^2shiftt*a3+t^shiftt*a2+a1
 LongNumber W1=Tooma3((a1+a2+a3),(b1+b2+b3) );//W(1)
 LongNumber W2=Tooma3 ((a3*4+a2*2+a1),(b3*4+b2*2+b1));//W(2)
 LongNumber W3=Tooma3 ((a3*9+a2*3+a1),(b3*9+b2*3+b1));//W(3)
 LongNumber W0=Tooma3(a1,b1);//W(0)
 //W(t)=w4*t^4+w3*t^3+w2*t^2+w1*t+w0

 LongNumber w0=W0;
 LongNumber w4=W4;
 LongNumber w1=W1*3+(W3-W0)/3-((W2-W0)*3)/2-W4*3-(W0+W4)*3;
 LongNumber w2=W2*2+W0+W4*11-(W3+W1*5)/2;
 LongNumber w3=(W3+W1*3-W2*3-W0-W4*36)/6;

 result=w0+w1.Move(shiftt)+w2.Move(2*shiftt)+w3.Move(3*shiftt)+w4.Move(4*shiftt);
}
LongNumber LongNumber:: Pow( LongNumber n)
{
    if((n.digit==1)&&(n.massive[NMax-1]==0)) {LongNumber ONE(1); return ONE;}
    if((n.digit==1)&&(n.massive[NMax-1]==1)) return (*this);
    if((n.digit==1)&&(n.massive[NMax-1]==2))
    {
      if(AllowedToMulti((*this),(*this)))  return ((*this)*(*this));
      else {cout<<">>It is not enough memory to multiplication<<\n>>END OF WORK<<";exit(0);}
    }
    LongNumber n2 = n%2;
    LongNumber a;
    if((n2.digit==1)&&(n2.massive[NMax-1]==0))
    {
      a=Pow(n/2);
      if(AllowedToMulti(a,a)) return (a*a);
      else {cout<<">>It is not enough memory to multiplication<<\n>>END OF WORK<<";exit(0);}
    }
    if((n2.digit==1)&&(n2.massive[NMax-1]==1))
    {
      a=Pow(n/2);
      if((AllowedToMulti(a,a))&&(AllowedToMulti(a*a,(*this)))) return (a*a*(*this));
      else {cout<<">>It is not enough memory to multiplication<<\n>>END OF WORK<<";exit(0);}
    }
}

/*LongNumber LongNumber:: PowAndMod( LongNumber n, LongNumber p)
{
   if((n.digit==1)&&(n.massive[NMax-1]==0)) {LongNumber ONE(1); return (ONE%p);}
    if((n.digit==1)&&(n.massive[NMax-1]==1)) return ((*this)%p);
    if((n.digit==1)&&(n.massive[NMax-1]==2)) return (((*this)*(*this))%p);


    LongNumber n2 = n%2;
    LongNumber a;
    if((n2.digit==1)&&(n2.massive[NMax-1]==0))
    {
      a=PowAndMod(n/2,p);
      return (((a%p)*(a%p)));
    }
    if((n2.digit==1)&&(n2.massive[NMax-1]==1))
    {
      a=PowAndMod(n/2,p);
      return (((a%p)*(a%p)*((*this)%p)));

    }
}*/
LongNumber LongNumber ::PowMod(LongNumber n, LongNumber p)
{  LongNumber i(1),one(1), a=(1);
   if(n==0) return one%p;
   for(i; i<=n;i=i+1)
   {
      if(a<p) a=(((*this)%p)*(a));
    else {a=(((*this)%p)*(a)); a=a%p;}
   }
   return a%p;
}

 LongNumber LongNumber:: operator /(const LongNumber & A)
 {

      LongNumber div,a=A,b=(*this); a.sign=1; b. sign=1;
       if(a==0) {cout<<" YOU TRY TO DIVIDE ON ZERO. END OF WORK.\n\n"; exit(0);}

      if(b<a) return div;

      LongNumber perenos, zero , temp , helpp , step;

      int i,k;

      for(i=0;i<digit;i++)
          {
               step.FromIntToLongNumber(b.massive[NMax-digit+i]);
               helpp=step+ perenos*position;
               k=0;
               while(helpp>zero)
                {
                   if(helpp>=a)
                  { helpp=helpp-a;
                   k++;
                  }
                   else break;
                }
                temp.FromIntToLongNumber(k);
                div=div+temp.Move(digit-i-1);
                perenos = helpp;
          }
     div.FindDigit();
      if(((sign==1)&&(A.sign==1))||((sign==0)&&(A.sign==0))) div.sign=1;
      if(((sign==0)&&(A.sign==1))||((sign==1)&&(A.sign==0))) div.sign=0;
     return div;
 }

int LongNumber:: operator <(const LongNumber &a)
{
     if((sign==1)&&(a.sign==0)) return 0;
    if((sign ==0)&&(a.sign==1)) return 1;
    if(sign==1){if(digit>a.digit) return 0;
                if(digit<a.digit) return 1;}
    if(sign==0){if(digit>a.digit) return 1;
                if(digit<a.digit) return 0;}
    if((digit==a.digit)&&(sign==1))
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax-digit+i]>a.massive[NMax-digit+i]) return 0;
           if(massive[NMax-digit+i]<a.massive[NMax-digit+i]) return 1;
           if((massive[NMax-digit+i]==a.massive[NMax-digit+i])&&((NMax-digit+i)==NMax-1)) return 0;
           if((massive[NMax-digit+i]==a.massive[NMax-digit+i])&&((NMax-digit+i)!=NMax-1)) continue;
        }
        return 1;
    }
    else      {  int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax-digit+i]>a.massive[NMax-digit+i]) return 1;
           if(massive[NMax-digit+i]<a.massive[NMax-digit+i]) return 0;
           if((massive[NMax-digit+i]==a.massive[NMax-digit+i])&&((NMax-digit+i)==NMax-1)) return 0;
           if((massive[NMax-digit+i]==a.massive[NMax-digit+i])&&((NMax-digit+i)!=NMax-1)) continue;
        }
        return 1;}
}
int LongNumber:: operator >(const LongNumber &a)
{
    if((sign==1)&&(a.sign==0)) return 1;
    if((sign ==0)&&(a.sign==1)) return 0;
    if(sign==1){if(digit>a.digit) return 1;
                if(digit<a.digit) return 0;}
    if(sign==0){if(digit>a.digit) return 0;
                if(digit<a.digit) return 1;}
    if((digit==a.digit)&&(sign==1))
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax-digit+i]>a.massive[NMax-digit+i]) return 1;
           if(massive[NMax-digit+i]<a.massive[NMax-digit+i]) return 0;
           if((massive[NMax-digit+i]==a.massive[NMax-digit+i])&&((NMax-digit+i)==NMax-1)) return 0;
           if(massive[NMax-digit+i]==a.massive[NMax-digit+i]) continue;
        }
        return 1;}
           else
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax-digit+i]>a.massive[NMax-digit+i]) return 0;
           if(massive[NMax-digit+i]<a.massive[NMax-digit+i]) return 1;
           if((massive[NMax-digit+i]==a.massive[NMax-digit+i])&&((NMax-digit+i)==NMax-1)) return 0;
           if(massive[NMax-digit+i]==a.massive[NMax-digit+i]) continue;
        }
        return 1;
    }
}

 void LongNumber:: FromIntToLongNumber( int a)
 {
     int pos=a;
     int k_pos=0;
     while(pos>0)
     {pos=pos/10;k_pos++;}

     int i;
     if(k_pos>NMax)

     {
         cout<<" CHECK THE NUMBER. TOO BIG NUMBER. YOU WILL GET ZERO\n"<<endl;
         for(i=0;i<NMax;++i) massive[i]=0;
         digit=1;sign=1;return;
     }
     LongNumber zero;
     (*this)=zero;
         if(a<0) {sign=0;a=-a;}
                else sign=1;
     i=0;
     int temp=a;
     while(temp>0)
     {
         massive[NMax-i-1]=temp%position;
         temp=temp/position;
         i++;
     }
     FindDigit();
 }

LongNumber LongNumber:: operator %( const LongNumber& a )
{
    LongNumber mod;
    mod=(*this)- ((*this)/a)*a;
    return mod;
}
LongNumber LongNumber:: operator %(int a )// not for -
{
    LongNumber mod;
    mod=(*this)- ((*this)/a)*a;
    return mod;
}

int LongNumber:: operator ==(const LongNumber &a)
{
     if((sign==1)&&(a.sign==0)) return 0;
    if((sign ==0)&&(a.sign==1)) return 0;
    if(digit>a.digit) return 0;
    if(digit<a.digit) return 0;
    if(digit==a.digit)
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax-digit+i]>a.massive[NMax-digit+i]) return 0;
           if(massive[NMax-digit+i]<a.massive[NMax-digit+i]) return 0;
           if((massive[NMax-digit+i]==a.massive[NMax-digit+i])) continue;
        }
        return 1;
    }
}
int LongNumber:: operator !=(const  LongNumber& a)//!!!!
{
    if((sign==1)&&(a.sign==0)) return 1;
    if((sign ==0)&&(a.sign==1)) return 1;
    if(digit>a.digit) return 1;
    if(digit<a.digit) return 1;
    if((digit==a.digit))
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax-digit+i]>a.massive[NMax-digit+i])  return 1;
           if(massive[NMax-digit+i]<a.massive[NMax-digit+i])  return 1;
           if((massive[NMax-digit+i]==a.massive[NMax-digit+i]))  continue;
        }
        return 0;
    }

}
void LongNumber ::Lehmann()
{


    LongNumber ONE(1);
    if((*this) ==1) {cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl;return;}
    if(((*this) ==2)||((*this) ==3)||((*this) ==5)||((*this) ==7)) {cout<<" >>>>> IT IS  A PRIME NUMBER  <<<<\n"<<endl;return;}
    LongNumber TWO(2) ; if(NSD(TWO, (*this))!=1){ cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl;return;}
    int t=5, t1=t;
    int k=0;
    LongNumber A(2), NUM, DEGREE, STEP;
    DEGREE=(((*this)-ONE)/2);
    while(t>0)
    {
        //STEP=A.Pow(DEGREE);
        //NUM=STEP%(*this);
        NUM=A.PowMod(DEGREE, (*this));
        if((NUM == ONE)||(NUM == ((*this)-ONE) )) k++;
        A=A+ONE;
        t--;
    }
    if (k==t1) cout<<" >>>>> IT IS A PRIME NUMBER  <<<<\n"<<endl;
    else cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl;
}

LongNumber LongNumber:: NSD (const LongNumber &C, const LongNumber& D)
{
    LongNumber A=C;A.sign=1;
    LongNumber B=D;B.sign=1;
    LongNumber zero;

    while((A!= zero)&&(B!=zero))
    {
        if(A>B) A= A%B;
        else B=B%A;
    }
    return (A+B);
}
 int LongNumber:: J(LongNumber a, LongNumber b) //const&
{
 if (!(NSD(a,b)==1)) return 0;
 int r=1;
 if (a<0) {
            a=a*(-1);
            if(b%(4)==3) r=-r;
           }
do{
long t=0;
   while((a.massive[NMax-1]%2 ==0)&&(a!=0))
       { t++; a=a/2;}
 if (t%2 ==1) {
              LongNumber j=b%(8);
                if(j==3 || j==5)
                 r=-r;
              }
 if (a%(4)==3 && b%(4)==3) r=-r;
   LongNumber c;
   c=a; a=b%(c);b=c;
  }
  while (!(a==0));
    return r;
}

int LongNumber:: operator !=( int a)
{
    LongNumber A(a);
    if((*this)!=A) return 1;
    else return 0;
}
int LongNumber:: operator ==( int a)
{
    LongNumber A(a);
    if((*this)==A) return 1;
    else return 0;
}
int LongNumber:: operator >=( int a)
{
    LongNumber A(a);
    if((*this)>=A) return 1;
    else return 0;
}
int LongNumber:: operator <=( int a)
{
    LongNumber A(a);
    if((*this)<=A) return 1;
    else return 0;
}
int LongNumber:: operator >( int a)
{
    LongNumber A(a);
    if((*this)>A) return 1;
    else return 0;
}
int LongNumber:: operator <( int a)
{
    LongNumber A(a);
    if((*this)<A) return 1;
    else return 0;
}
 void LongNumber :: Solovay_Strassen()
{
    if((*this) ==1) {cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl;return;}
     if(((*this) ==2)||((*this) ==3)||((*this) ==5)||((*this) ==7)) {cout<<" >>>>> IT IS  A PRIME NUMBER  <<<<\n"<<endl;return;}
    LongNumber TWO(2);
    if(NSD(TWO, (*this))!=1){ cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl;return;}
    int t=5, t1=t;
    int k=0;int j;
    LongNumber  A(2),ONE(1) , NUM, DEGREE, STEP, JJ;
    DEGREE=(((*this)-ONE)/2);
    while(t>0)
    {
        //STEP=A.Pow(DEGREE);
        //NUM=STEP%(*this);
        NUM=A.PowMod(DEGREE, (*this));
        j=J(A, (*this)); if(j==-1) JJ=(*this)-ONE; else JJ.FromIntToLongNumber(j);
       // cout<<"NUM=";NUM. Output();
       // cout<<"j="<<j<<endl;
        if((NUM!=JJ)) {cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl;return;}
        else {k++;
        A=A+ONE;
        t--;}
    }
    if (k==t1) cout<<" >>>>> IT IS A PRIME NUMBER  <<<<\n"<<endl;
    else cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl;
}
int LongNumber :: Rabin_Miller()
{
    if((*this) ==1) {cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl;return 0;}
     if(((*this) ==2)||((*this) ==3)||((*this) ==5)||((*this) ==7)) {cout<<" >>>>> IT IS  A PRIME NUMBER  <<<<\n"<<endl;return 1;}
     LongNumber TWO(2) ; if(NSD(TWO, (*this))!=1){ cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl;return 0;}

     LongNumber ONE(1), M, B, NUM, A(2);
       M=(*this)-ONE;
       while(M%2==0)
       {
          M=M/2;
          B=B+ONE;
       }

int i=0, t=5, j=0, temp=0;

while(t>0)
{
    NUM=A.PowMod(M, (*this));
    if((NUM==ONE)||(NUM==(*this)-ONE)) { t--; A=A+1;continue;}
    i=0;
      for( j=1; B>j; j++)
     {
        NUM=(NUM*NUM) %(*this);
        if(NUM==ONE) { cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl; return 0;}
        if(NUM==(*this)-ONE) { i=1; break; }

     }
   if(!i) { cout<<" >>>>> IT IS !NOT! A PRIME NUMBER  <<<<\n"<<endl;return 0;}
   A=A+1;
   t--;
}
 cout<<" >>>>> IT IS  A PRIME NUMBER  <<<<\n"<<endl;return 1;
}
LN LongNumber:: Bin (int *len)
{
    LN BINARY; if((*this)==0) {(*len=1);return BINARY;}
    LongNumber helpp; int help[NMax/2]={};

    LongNumber a=(*this);
    int  j;    (*len)=0;
    if(a.digit>=NMax/2) {cout<<" Binary. You can't to save the number. Not enought memory. End of work.\n\n"; exit(0);}
    if(a<0) a=a*(-1);
    while(a>0)
    {
        if((*len)>NMax/2) {cout<<"PROBLEM. Binary will be bigger than it is allowed. END OF WORK.\n\n"; exit(0);}
        helpp = a%2; help[(*len)]=helpp.massive [ NMax-1];
        a=a/2;
        (*len)++;
    }
    for(j=0;j<(*len);j++)
    {
        BINARY.massive[NMax/2+j]= help[(*len)-1-j];
    }
    BINARY.FDIGIT();
    BINARY.FFRAC();
    BINARY.sign=sign;
    return BINARY;

}
void LongNumber:: FromBinToLongNumber (const LN& BIN, int len)
{
   LN B=BIN; LongNumber a;
   int k=0,i;
   for(i=0;i<len;i++) {k=k+B.massive[NMax/2 + i]*powf(2.0, len-1-i );}
   a.FromIntToLongNumber(k);a.sign=BIN.sign; (*this)=a;
}
LN LongNumber :: FromLongNumberToLN ( )
{
    LN A;
    if(digit>NMax/2) {cout<<" PROBLEM. YOU can't do LongNumber->LN. END OF WORK.\n\n"; exit(0);}
    int i;
    for(i=0;i<digit; i++)
    {
        A.massive[NMax/2-1-i]=massive[NMax-1-i];
    }
    A.sign=sign;
    A.FFRAC();
    A.FDIGIT();
    return A;
}
LN LongNumber:: TheInverseOfTheNewton()
{
    if((*this)==0) {cout<<" DIV ZERO. NEWTON. END OF WORK"<<endl;exit(0);}
    LN B = (*this).FromLongNumberToLN();
    char Mass[]="\0";
    int len;
    LN HALF; HALF.IN_D(0.5,Mass, len);
    LN ONE;ONE.IN_D(1.0,Mass,len);
    LN X0; X0.IN_D(1.5,Mass,len);
    int k=0;
    while(B>ONE)
    {
        if(B>=HALF){B=B/2;
        k++;}
        else break;
    }
    LN Xn=X0;LN Xn1;LN HELP;
    int n=0;        int j;
    while(n!=3)
    {

        HELP=Xn*2 - B*(Xn*Xn);
         Xn1=HELP;
         if(Xn1.frac>Newton){Xn1.frac=Newton;
                        for(j=0;j<NMax/2 - Xn1.frac;j++)
                        Xn1.massive[NMax/2 +Xn1.frac+j] = 0; Xn1.FFRAC();}
        Xn=Xn1;
        n++;
   }
    LongNumber r; LongNumber two(2); r=two.Pow(k); cout<<"r=";r.Output();
    Xn1=Xn1/r;
             if(Xn1.frac>Newton){Xn1.frac=Newton;
                        for(j=0;j<NMax/2 - Xn1.frac;j++)
                        Xn1.massive[NMax/2 +Xn1.frac+j] = 0;Xn1.FFRAC();}
    Xn1.sign= sign;
    Xn1.FFRAC();
    Xn1.FDIGIT();
    return Xn1;
}

