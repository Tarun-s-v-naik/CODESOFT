#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main()
{
    int opr,ch;
    float num1,num2,res;
    cout<<"!SIMPLE CALCULATOR!"<<endl;
    for(;;)
    {
        cout<<"ENTER TWO NUMBERS"<<endl;
        cin>>num1>>num2;
        cout<<"1.ADDITION(+)\t2.SUBTRACTION(-)\t3.MULTIPLICATION(*)\t4.DIVISION(/)"<<endl;
        cout<<"ENTER YOUR CHOICE:";
        cin>>opr;
        switch(opr)
        {
            case 1:
                res=num1+num2;
                break;
            case 2:
                res=num1-num2;
                break;
            case 3:
                res=num1*num2;
                break;
            case 4:
                if(num2==0)
                {
                    cout<<"NUMBER IS DIVIDED BY ZERO"<<endl;
                    res=0;
                    break;
                }
                else
                {
                    res=num1/num2;
                    break;
                }
        }
        cout<<"RESULT="<<res<<endl;
        cout<<"DO YOU WANT TO CONTINUE(press 1 to continue and 0 to stop)"<<endl;
        cin>>ch;
        if(ch==1)
        {
            continue;
        }
        else
        {
            exit(0);
        }
    }
    
    return 0;
}