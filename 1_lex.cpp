#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<fstream>
using namespace std;
int isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    int i, flag = 0;
    for(i = 0; i < 32; ++i)
    {
        if(strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
int main()
{
    char ch, buffer[15],b[30],op[]="+-*/=><",numer[]=".0123456789";
    ifstream fin("c.txt");
    int mark[1000]={0};
    int i,j=0,kc=0,ic=0,mc=0,nc=0,oc=0,aaa=0;
    vector<string> k;
    vector<char>id;
    vector<char>ma;
    vector<string>nu;
    if(!fin.is_open())
    {
        cout<<"Unable to open file!!";
        exit(0);
    }
    while(!fin.eof())
    {
           ch = fin.get();
           for(i = 0; i < 7; ++i)
           {
               if(ch == op[i])
               {
                    int aa=ch;
                    if(mark[aa]!=1)
                    {
                    ma.push_back(ch);
                    mark[aa]=1;
                    ++mc;
                    }
               }
            }
            if(ch>='0' || ch<='9' || ch=='.' ||ch == ' ' || ch == '\n' || ch == ';')
            {
                if(ch>='0' && ch<='9' )
                    b[aaa++]=ch;
                if((ch == ' ' || ch == '\n' || ch == ';') && (aaa != 0))
                {
                   b[aaa] = '\0';
                   aaa = 0;
                   char arr[30];
                   strcpy(arr,b);
                   nu.push_back(arr);
                   ++nc;
                }
           }
           if(isalnum(ch))
           {
               buffer[j++] = ch;
           }
           else if((ch == ' ' || ch == '\n') && (j != 0))
           {
                   buffer[j] = '\0';
                   j = 0;
                   if(isKeyword(buffer) == 1)
                   {
                       k.push_back(buffer);
                       ++kc;
                   }
                   else
                   {
                        if(buffer[0]>=97 && buffer[0]<=122) 
                        {
                            if(mark[buffer[0]-'a']!=1)
                            {
                                id.push_back(buffer[0]);
                                ++ic;
                                mark[buffer[0]-'a']=1;
                            }
                        }
                    }
            }

    }

    fin.close();
    cout << "Keywords found are as follows: \n";
    for(int i=0;i<kc;i++)
    {
        cout<<k[i]<<"\n";
    }
    cout << endl;
    cout << "Identifiers found are as follows: \n";
    for(int i=0;i<ic;i++)
    {
        cout<<id[i]<<"\n";
    }
    cout << endl;
    cout << "Operators found are: \n";
    for(int i=0;i<mc;i++)
    {
         cout<<ma[i]<<"\n";
    }
    cout << endl;
    printf("Numerical Constants found are: \n");
    for(int i=0;i<nc;i++)
    {
        cout<<nu[i]<<"\n";
    }
    cout << endl;
    return 0;
}





