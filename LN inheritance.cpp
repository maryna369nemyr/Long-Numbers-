#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include<math.h>

#include <cstring>


#include "List_Function.h"
using namespace std;

LN::LN()
{
    int i;
    for(i=0;i<NMax;++i)
        massive[i]=0;
    digit=1;frac=1;
    sign=1;
}
LN::LN(const LN& A)
{
    int i;
    for (i=0; i<NMax;i++)
    {
        massive[i]=A.massive[i];
    }
    digit=A.digit; frac=A.frac;
    sign=A.sign;


}

void LN::FDIGIT()
{
     int k=0;
     int i;
     for(i=0;i<NMax/2;i++)
     {
        if((massive[i]==0)) {k++; continue;}
        else break;
     }

       if((NMax/2)==k)  digit=1;
       else digit=NMax/2-k;
}
void LN::FFRAC()
{
     int k=0;
     int i;
     for(i=NMax-1;i>=NMax/2;i--)
     {
        if((massive[i]==0)) {k++; continue;}
        else break;
     }

       if((NMax/2)==k)  frac=1;
       else frac=NMax/2-k;
}
int LN::IN(char Mass[NMax], int work_len)
{
     int tem=StrIntoChar(Mass,&work_len);
     if (tem==0) {cout<<"END OF WORK. ( the word in string is too long)."<<endl;exit(0);}

    sign=1;
    int temp=work_len,j=0;
    int i, pp=0, countt=0,k1=0;
    bool p=false;
    if(Mass[0]=='-') {sign=0;--temp;j=1;}

    for (i=0; i<work_len; i++)
    {
        if(Mass[i]=='.') {p=true;pp=i; ++countt;}
    }
    if (countt>1) {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}
//если целое
if((!p)&&(work_len<NMax/2)){ for (i=0;i<temp;i++)
                            {

                            if(((Mass[work_len-1-i]-'0')<position)&&(Mass[work_len-1-i]-'0')>=0)
                            {massive[NMax/2-1-i]=Mass[work_len-1-i]-'0';}
                            else
                            {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}}
                       }
else {if((p)&&((work_len-pp-1)<NMax/2)&&(pp-1 < NMax/2))
    {
    k1=0;
    for (i=pp+1;i<work_len;i++)
    {
                            if(((Mass[i]-'0')<position)&&(Mass[i]-'0')>=0)
                            {massive[NMax/2+k1]=Mass[i]-'0';k1++;}
                            else
                            {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}
                        }

                     if(sign==1)   {for(i=0;i<pp;i++)
                        {
                            if(((Mass[pp-i-1]-'0')<position)&&(Mass[pp-i-1]-'0')>=0)
                            {massive[NMax/2-1-i]=Mass[pp-i-1]-'0';}
                            else
                            {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}
                        }
                        }
                        else
                        {
                             {for(i=0;i<pp-1;i++)
                        {
                            if(((Mass[pp-i-1]-'0')<position)&&(Mass[pp-i-1]-'0')>=0)
                            {massive[NMax/2-1-i]=Mass[pp-i-1]-'0';}
                            else
                            {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}
                        }
                        }
                        }
                        }
        else {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}}
        FDIGIT();
        FFRAC();
        return 1;
}
void LN::OUT()
{
     int i;
     for (i=NMax/2-digit;i<NMax/2+frac;i++)//вместо 0 нужно ставить к для красивого вывода
       {
        if(i==NMax/2) cout<<" | ";
        cout<<massive[i]<<",";}

        cout<<endl;
        cout<<"DIGIT="<<digit<<"     |         FRAC ="<<frac<<endl;
        if(sign) cout<<"SIGN   +"<<endl;
        else cout<<"SIGN   -"<<endl;
        cout<<"\n";
}
void LN::OUT_BIN(int len)
{
     int i;
     cout<<"(";
     for (i=NMax/2-1;i<NMax/2+len;i++)
       {
        if(i==NMax/2) cout<<" . ";
        cout<<massive[i]<<" ";}

        cout<<")2";cout<<endl;
        cout<<"DIGIT="<<digit<<"     |         FRAC ="<<frac<<endl;
        if(sign) cout<<"SIGN   +"<<endl;
        else cout<<"SIGN   -"<<endl;
        cout<<"\n";
}
int LN:: operator >=(const LN &a)
{
    if((sign==1)&&(a.sign==0)) return 1;
    if((sign ==0)&&(a.sign==1)) return 0;

    if(sign==1){if(digit>a.digit) return 1;
                if(digit<a.digit) return 0;

                }

    if(sign==0){if(digit>a.digit) return 0;
                if(digit<a.digit) return 1;
               }
    int max_frac =(frac>=a.frac)? frac:a.frac;
    if((digit==a.digit)&&(sign==1))
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 1;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 0;
           if(massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i]) continue;
        }
        for(i=0;i<max_frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 1;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 0;
           if(massive[NMax/2+i]==a.massive[NMax/2+i]) continue;
        }
        return 1;
    }
    else
     {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 0;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 1;
           if(massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i]) continue;
        }
        for(i=0;i<max_frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 0;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 1;
           if(massive[NMax/2+i]==a.massive[NMax/2+i]) continue;
        }
        return 1;
    }
}
int LN:: operator <=(const LN &a)
{
    if((sign==1)&&(a.sign==0)) return 0;
    if((sign ==0)&&(a.sign==1)) return 1;
    if(sign==1){if(digit>a.digit) return 0;
                if(digit<a.digit) return 1;
}
    if(sign==0){if(digit>a.digit) return 1;
                if(digit<a.digit) return 0;
}
    int max_frac =(frac>=a.frac)? frac:a.frac;
    if((digit==a.digit)&&(sign==1))
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 0;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 1;
           if(massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i]) continue;
        }
        for(i=0;i<max_frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 0;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 1;
           if(massive[NMax/2+i]==a.massive[NMax/2+i]) continue;
        }
        return 1;
    }
    else
     {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 1;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 0;
           if(massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i]) continue;
        }
        for(i=0;i<max_frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 1;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 0;
           if(massive[NMax/2+i]==a.massive[NMax/2+i]) continue;
        }
        return 1;
    }
}
int LN::operator <( const LN& a)
{
    if((sign==1)&&(a.sign==0)) return 0;
    if((sign ==0)&&(a.sign==1)) return 1;
    if(sign==1){if(digit>a.digit) return 0;
                if(digit<a.digit) return 1;
}
    if(sign==0){if(digit>a.digit) return 1;
                if(digit<a.digit) return 0;
}
    int max_frac =(frac>=a.frac)? frac:a.frac;
if((digit==a.digit)&&(sign==1))
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 0;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 1;
           if((massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i])&&((NMax-digit+i)!=NMax-1)) continue;
        }
        for(i=0;i<max_frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 0;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 1;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])&&((NMax/2+i)==NMax/2-1+frac)) return 0;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])&&((NMax/2+i)!=NMax/2-1+frac)) continue;
        }
        return 1;
    }
    else
     {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 1;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 0;
           if((massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i])&&((NMax-digit+i)!=NMax-1)) continue;
        }
        for(i=0;i<max_frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 1;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 0;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])&&((NMax/2+i)==NMax/2-1+frac)) return 0;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])&&((NMax/2+i)!=NMax/2-1+frac)) continue;
        }
        return 1;
    }
}
int LN::operator >( const LN& a)
{
    if((sign==1)&&(a.sign==0)) return 1;
    if((sign ==0)&&(a.sign==1)) return 0;
    if(sign==1){if(digit>a.digit) return 1;
                if(digit<a.digit) return 0;
}
    if(sign==0){if(digit>a.digit) return 0;
                if(digit<a.digit) return 1;
                }
                    int max_frac =(frac>=a.frac)? frac:a.frac;
if((digit==a.digit)&&(sign==1))
    {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 1;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 0;
           if((massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i])&&((NMax-digit+i)!=NMax-1)) continue;
        }
        for(i=0;i<max_frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 1;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 0;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])&&((NMax/2+i)==NMax/2-1+frac)) return 0;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])&&((NMax/2+i)!=NMax/2-1+frac)) continue;
        }
        return 1;
    }
    else
     {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 0;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 1;
           if((massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i])&&((NMax-digit+i)!=NMax-1)) continue;
        }
        for(i=0;i<max_frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 0;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 1;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])&&((NMax/2+i)==NMax/2-1+frac)) return 0;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])&&((NMax/2+i)!=NMax/2-1+frac)) continue;
        }
        return 1;
    }
}
int LN:: operator ==(const LN &a)
{
    if(sign!=a.sign) return 0;
    if(digit!=a.digit) return 0;
    if(frac!=a.frac) return 0;

     if(sign==1){   int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 0;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 0;
           if((massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i])&&((NMax-digit+i)!=NMax-1)) continue;
        }
        for(i=0;i<frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 0;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 0;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])) continue;
        }
        return 1;
    }
    else
     {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 0;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 0;
           if((massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i])&&((NMax-digit+i)!=NMax-1)) continue;
        }
        for(i=0;i<frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 0;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 0;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])) continue;
        }
        return 1;
    }
}

int LN:: operator !=(const LN &a)
{
    if(sign!=a.sign) return 1;
    if(digit!=a.digit) return 1;
    if(frac!=a.frac) return 1;

     if(sign==1){   int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 1;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 1;
           if((massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i])&&((NMax-digit+i)!=NMax-1)) continue;
        }
        for(i=0;i<frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 1;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 1;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])) continue;
        }
        return 0;
    }
    else
     {
        int i;
        for (i=0;i<digit;i++)
        {
           if(massive[NMax/2-digit+i]>a.massive[NMax/2-digit+i]) return 1;
           if(massive[NMax/2-digit+i]<a.massive[NMax/2-digit+i]) return 1;
           if((massive[NMax/2-digit+i]==a.massive[NMax/2-digit+i])&&((NMax-digit+i)!=NMax-1)) continue;
        }
        for(i=0;i<frac;i++)
        {
           if(massive[NMax/2+i]>a.massive[NMax/2+i]) return 1;
           if(massive[NMax/2+i]<a.massive[NMax/2+i]) return 1;
           if((massive[NMax/2+i]==a.massive[NMax/2+i])) continue;
        }
        return 0;
    }
}
void LN:: operator =(const LN&a)
{
    int i;
    for (i=0; i<NMax;i++)
    {
        massive[i]=a.massive[i];
    }
    digit=a.digit; frac=a.frac;
    sign=a.sign;
}

LN LN:: operator +(const LN& A)
{
   LN sum;
   LN a=A;
   LN b=(*this);
   if((sign ==0)&&(a.sign==1)){b.sign=1; sum= a-b;return sum;}
   if((a.sign==0)&&(sign==1)) {a.sign=1; sum=(*this)-a; return sum;}

   int max_digit = (digit >a.digit) ? digit:a.digit;
   int max_frac = (frac>a.frac)? frac:a.frac;
   if((max_digit+max_frac+1)>=NMax) {cout<<"<<END OF WORK +>>\n\n"; exit(0);}/////////////!!!!!!!
   int r = 0, i, temp;

   for (i = 0; i<max_frac; i++)
   {
    temp = massive[NMax/2-1-i+max_frac]+a.massive[NMax/2-1-i+max_frac]+r;
    r=temp/position;
    sum.massive[NMax/2-1-i+max_frac]=temp%position;
   }
   for (i = 0; i<max_digit; i++)
   {
    temp = massive[NMax/2-1-i]+a.massive[NMax/2-1-i]+r;
    r=temp/position;
    sum.massive[NMax/2-1-i]=temp%position;
   }
    sum.massive[NMax/2-1-max_digit] = r;

   if((sign ==1)&&(a.sign==1)) sum.sign=1;
   if ((sign ==0)&&(a.sign==0)) sum.sign=0;
   sum.FDIGIT();
   sum.FFRAC();
   return sum;
}
LN LN:: operator - (const LN &A)
{

    LN rizn; LN a=A; LN b=(*this);
    if((sign==1)&&(a.sign==0)) {a.sign=1; rizn=(*this)+a; rizn.sign=1; return rizn;}
    if((sign==0)&&(a.sign==1)) {b.sign=1; rizn=b+a; rizn.sign=0; return rizn;}

    int max_digit = (digit >a.digit) ? digit:a.digit;
    int max_frac = (frac >a.frac) ? frac:a.frac;
    int r = 0, i;
    if((sign==1)&&(a.sign==1))

    {if ((*this)>=a)

    {
        for(i=NMax/2-1+max_frac;i>=NMax/2-max_digit;i--)
    {
        r=massive[i] - a.massive[i]-r;
        rizn.massive[i]=(r<0)?(r+position):(r);
        r=(r<0)?1:0;
    }
    if (r==1) {rizn.massive[NMax/2-max_digit]=rizn.massive[NMax/2-max_digit]-1;}
    rizn.FDIGIT(); rizn.FFRAC();rizn.sign=1;
    }
    if ((*this)<a)
    {
        for(i=NMax/2-1+max_frac;i>=NMax/2-max_digit;i--)
    {
        r= a.massive[i]- massive[i] -r;
        rizn.massive[i]=(r<0)?(r+position):(r);
        r=(r<0)?1:0;
    }
    if (r==1) {rizn.massive[NMax/2-max_digit]=rizn.massive[NMax/2-max_digit]-1;}
    rizn.FDIGIT(); rizn.FFRAC();rizn.sign=0;
    }
    }


    if((sign==0)&&(a.sign==0))
    {if ((*this)<a)
    {
        for(i=NMax/2-1+max_frac;i>=NMax/2-max_digit;i--)
    {
        r=massive[i] - a.massive[i]-r;
        rizn.massive[i]=(r<0)?(r+position):(r);
        r=(r<0)?1:0;
    }
    if (r==1) {rizn.massive[NMax/2-max_digit]=rizn.massive[NMax/2-max_digit]-1;}
    rizn.FDIGIT(); rizn.FFRAC();rizn.sign=0;
    }
    if ((*this)>=a)
    {
        for(i=NMax/2-1+max_frac;i>=NMax/2-max_digit;i--)
    {
        r= a.massive[i]- massive[i] -r;
        rizn.massive[i]=(r<0)?(r+position):(r);
        r=(r<0)?1:0;
    }
    if (r==1) {rizn.massive[NMax/2-max_digit]=rizn.massive[NMax/2-max_digit]-1;}
    rizn.FDIGIT(); rizn.FFRAC();rizn.sign=1;
    }
    }
    //else {cout<<"IT IS IMPOSSIBLE TO DO THE OPERATION (NEGATIVE NUMBER).YOU WILL GET NUMBER 0"<<endl;}
    return rizn;

}

LongNumber LN:: TurnIntoLongNumberWithFrac()
{
    int i;LongNumber a;
    for (i=0; i<=frac+digit;i++ )
    {
        a. massive[NMax-1-i]=massive[NMax/2-1+frac-i];
    }
    a.FindDigit();
    a.sign = sign;
    return a;
}
LongNumber LN:: TurnIntoLongNumber()
{

    int i;LongNumber a;
    if ((massive[NMax/2-1] ==0 )&& digit==1) return a;

    for (i=0; i<digit;i++ )
    {
        a. massive[NMax-1-i]=massive[NMax/2-1-i];
    }
    a.FindDigit();
    a.sign = sign;
    return a;
}
LN LN:: operator *(const LN& C)
{
      LongNumber a, b, dob;
      LN DOB, A=C;
      a=A.TurnIntoLongNumberWithFrac();
      b=TurnIntoLongNumberWithFrac();
      dob=a*b;
      int i,j;
      for(i=0; i<frac+A.frac;i++)
            DOB.massive[NMax/2+i] = dob.massive[NMax-frac-A.frac+i];

      int k=0;
      for(j=i+1; j<=dob.digit; j++)
            {DOB.massive[NMax/2-1-k]=dob.massive[NMax-j]; k++;}
    DOB.FDIGIT();
    DOB.FFRAC();
    return DOB;
}
LN LN:: operator *(int b)
{
      LongNumber a, dob;
      LN DOB;
      a=TurnIntoLongNumberWithFrac();

      dob=a*b;
      int i,j;
      for(i=0; i<frac;i++)
            DOB.massive[NMax/2+i] = dob.massive[NMax-frac+i];

      int k=0;
      for(j=i+1; j<=dob.digit; j++)
            {DOB.massive[NMax/2-1-k]=dob.massive[NMax-j]; k++;}
    DOB.FDIGIT();
    DOB.FFRAC();
    return DOB;
}
LN LN:: operator /(int64_t b)
 {
     int a= (b>=0)?b:(-b);
     int perenos=0, vuras,i,j=0;
     LN DIV, HELP, ZERO;

    for (i=NMax/2-digit; i< NMax/2; i++)
          {
                vuras=(massive[i]  + perenos*position)/a;
                HELP.massive[NMax/2-1]=vuras;
                DIV= DIV+HELP.MOVE_DIGIT(digit-1-j); ++j;
                perenos =(massive[i]  + perenos*position)-vuras*a;
          }
    HELP=ZERO;j=0;
    for (i=NMax/2; i< NMax; i++)
        {
                vuras=(massive[i]  + perenos*position)/a;
                DIV. massive[NMax/2+j]= vuras; ++j;
                perenos =(massive[i]  + perenos*position)-vuras*a;
        }

     DIV.FDIGIT();
     DIV.FFRAC();
      if(((sign==1)&&(b>=0))||((sign==0)&&(b<=0))) DIV.sign=1;
      if(((sign==0)&&(b>0))||((sign==1)&&(b<0))) DIV.sign=0;
     return DIV;
 }
 LN LN:: operator /( LongNumber q)
 {   if(q==0){cout<< "DIV ZERO LongNumber. END Of WORK.\n\n";exit(0);}
    LN ZERO;
     if((*this)==ZERO) { LN ZERO;return ZERO;}
     LongNumber q1= (q>=0)?q:(q*(-1)); LN a=q1.FromLongNumberToLN();
     LN b=(*this);


     LongNumber zero , temp , helpp , step;
     LN PERENOS,DIV, HELP, STEP, TEMP;

      int i,k,j=0;

      for(i=NMax/2-digit;i<NMax/2;i++)
          {
               step.FromIntToLongNumber(b.massive[i]);
               STEP=step.FromLongNumberToLN();
               HELP=STEP+ PERENOS*position;
               k=0;
               while(HELP>ZERO)
                {
                   if(HELP>=a)
                  { HELP=HELP-a;
                   k++;
                  }
                   else break;
                }
                temp.FromIntToLongNumber(k);
                TEMP=temp.FromLongNumberToLN();
                DIV=DIV+TEMP.MOVE_DIGIT(digit-1-j);
                j++;
                PERENOS=HELP;
          }
          j=0;TEMP=ZERO;
     for(i=NMax/2;i<NMax;i++)
          {
            step.FromIntToLongNumber(b.massive[i]);
                STEP=step.FromLongNumberToLN();
                HELP=STEP+ PERENOS*position;
                k=0;
                while(HELP>ZERO)
                 {
                   if(HELP>=a)
                  { HELP=HELP-a;
                   k++;
                  }
                   else break;
                }
                temp.FromIntToLongNumber(k);
                TEMP=TEMP.MOVE_DIGIT(j)+temp.FromLongNumberToLN();
                j++;TEMP.OUT();
                PERENOS=HELP;
                if((PERENOS==ZERO)&&(i>=NMax/2+frac)) break;
                else continue;
          }
        for(i=0;i<NMax/2;i++)
        {
            DIV.massive[NMax/2+i]= TEMP.massive[NMax/2-TEMP.digit+i];
        }
      DIV.FFRAC();
      DIV.FDIGIT();
      if(((sign==1)&&(q>=0))||((sign==0)&&(q<=0))) DIV.sign=1;
      if(((sign==0)&&(q>0))||((sign==1)&&(q<0))) DIV.sign=0;
     return DIV;
 }
 LN LN:: MOVE_DIGIT(int len)//влево
 {
        if (len>NMax/2- digit){cout<<"Check the move digit! Mistake. END OF WORK\n\n"; exit(0);}

    LN B;
    int pos_start;
    pos_start=NMax/2-digit - len;
     int i,j=0;
     for(i=pos_start;i<pos_start+digit;i++)
     {
         B.massive[i]=massive[NMax/2-digit+j];
         j++;

     }
     B.FDIGIT();
     B.FFRAC();
     return B;
}
 LN LN:: MOVE_FRAC(int len)//вправо
 {
        if (len>NMax/2- frac){cout<<"Check the move frac ! Mistake. END OF WORK\n\n"; exit(0);}

    LN B;
    int pos_start;
    pos_start=NMax/2 + len;
     int i,j=0;
     for(i=pos_start;i<pos_start+frac;i++)
     {
         B.massive[i]=massive[NMax/2+j];
         j++;

     }
     B.FDIGIT();
     B.FFRAC();
     return B;
}

int DoubleIntoChar(double q,char Mass[NMax], int* work_len)
  {
    //cout << "Double value: "<<q<<endl;

    std::ostringstream ost;
    ost << q;
//cout << "As string: " << ost.str() << endl;

    string number=ost.str();
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

int LN::IN_D(double q,char Mass[NMax], int work_len)
{
     int tem=DoubleIntoChar(q,Mass,&work_len);
     if (tem==0) {cout<<"END OF WORK. ( the word in string is too long)."<<endl;exit(0);}

    sign=1;
    int temp=work_len,j=0;
    int i, pp=0, countt=0,k1=0;
    bool p=false;
    if(Mass[0]=='-') {sign=0;--temp;j=1;}

    for (i=0; i<work_len; i++)
    {
        if(Mass[i]=='.') {p=true;pp=i; ++countt;}
    }
    if (countt>1) {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}
//если целое
if((!p)&&(work_len<NMax/2)){ for (i=0;i<temp;i++)
                            {

                            if(((Mass[work_len-1-i]-'0')<position)&&(Mass[work_len-1-i]-'0')>=0)
                            {massive[NMax/2-1-i]=Mass[work_len-1-i]-'0';}
                            else
                            {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}}
                       }
else {if((p)&&((work_len-pp-1)<NMax/2)&&(pp-1 < NMax/2))
    {
    k1=0;
    for (i=pp+1;i<work_len;i++)
    {
                            if(((Mass[i]-'0')<position)&&(Mass[i]-'0')>=0)
                            {massive[NMax/2+k1]=Mass[i]-'0';k1++;}
                            else
                            {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}
                        }

                     if(sign==1)   {for(i=0;i<pp;i++)
                        {
                            if(((Mass[pp-i-1]-'0')<position)&&(Mass[pp-i-1]-'0')>=0)
                            {massive[NMax/2-1-i]=Mass[pp-i-1]-'0';}
                            else
                            {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}
                        }
                        }
                        else
                        {
                             {for(i=0;i<pp-1;i++)
                        {
                            if(((Mass[pp-i-1]-'0')<position)&&(Mass[pp-i-1]-'0')>=0)
                            {massive[NMax/2-1-i]=Mass[pp-i-1]-'0';}
                            else
                            {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}
                        }
                        }
                        }
                        }
        else {cout<<">>>>>>>>>>>>>MISTAKE. END OF WORK.<<<<<<<<<<<<"<<endl;exit(0);}}
        FDIGIT();
        FFRAC();
        return 1;
}



