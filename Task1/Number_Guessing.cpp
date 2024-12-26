#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int guess;
    srand(time(0));
    int Randnum=rand()%100+1;
    cout<<"!NUMBER GUESSING GAME!"<<endl;
    cout<<"Guess the random number between 1 to 100 gnerated by computer"<<endl;
    while(true)
    {
        cin>>guess;
      if(guess>Randnum)
        {
             cout<<"your guess is high="<<guess<<endl;
        }
        else if(guess<Randnum)
        {
            cout<<"your guess is low="<<guess<<endl;
        }
        else
        {
            cout<<"your guess is right...!"<<endl;
            cout<<"you win...!"<<endl;
            cout<<guess<<"="<<Randnum;
            exit(0);
        }
    }
    return 0;
}