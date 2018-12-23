#define LANG_COUNT 4
#define MAX_ROT 32
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <math.h>
using namespace std;

string lang[LANG_COUNT] = {"abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ","абвгдеёжзийклмнопрстуфхцчшщъыьэюя","АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"};

char doShift(int selectedLang, int position, int offset)
{
    int newPosition = position+offset;
    int tmp;
    if(offset > 0)
    {
        if(newPosition>lang[selectedLang].size() - 1)
        {
            tmp = floor(newPosition/lang[selectedLang].size());
            newPosition-=lang[selectedLang].size()*tmp;
        }
    }
    else
    {
        if (newPosition < 0)
        {
            tmp = ceil((newPosition * (-1)) / lang[selectedLang].size());
            newPosition = (lang[selectedLang].size() - 1) + (newPosition+ lang[selectedLang].size() * tmp);
        }   
    }
    char newChar = lang[selectedLang][newPosition];
    return newChar;
}

void encodeMessage()
{
    cout<<"Enter your message to encode:\n";
    string input;
    getline(cin,input);
    cout<<"You have encoded message: "+input+"\nResult:\n";
    for(int k = 1;k<=MAX_ROT;k++)
    {
        string output;
        for(int i = 0;i<input.size();i++)
        {
           char currentChar = input[i];
            for(int j = 0;j<LANG_COUNT;j++)
            {
                int langPosition = lang[j].find(currentChar);
                if((langPosition <= lang[j].size()) && (langPosition>= 0))
                {
                    output+=doShift(j,langPosition,k);
                    break;
                }
                if(j == LANG_COUNT-1) output+=currentChar;
            }
        }
        cout<<"ROT"<<k<<"\t"<<output<<endl;
    }
    
}

void decodeMessage()
{
    cout<<"Enter your message to decode:\n";
    string input;
    getline(cin,input);
    cout<<"You have decoded message: "+input+"\nResult:\n";
    for(int k = 1;k<=MAX_ROT;k++)
    {
        string output;
        for(int i = 0;i<input.size();i++)
        {
           char currentChar = input[i];
            for(int j = 0;j<LANG_COUNT;j++)
            {
                int langPosition = lang[j].find(currentChar);
                if((langPosition <= lang[j].size()) && (langPosition>= 0))
                {
                    output+=doShift(j,langPosition,-k);
                    break;
                }
                if(j == LANG_COUNT-1) output+=currentChar;
            }
        }
        cout<<"ROT"<<k<<"\t"<<output<<endl;
    }
}

int main()
{
    bool isRunning = true;
    int action;
    while(isRunning)
    {
        clrscr();
        cout<<"What do you want?\n1 - encode\n2 - decode\n3 - quit\nYour decision: ";
        scanf("%i",&action);
        getch();
        switch(action)
        {
          case 1:
            encodeMessage();
            break;
          case 2:
            decodeMessage();
            break;
          case 3:
            cout<<"Goodbuy!";
            isRunning = false;
            break;
          default:
            cout<<"You have made a mistake, try again!";
            break;
        }
        cout<<"\nPress any button";
        getch();
    }
}

