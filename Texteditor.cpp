#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void countwords(string filename);
void countletters(string filename);
void countlines(string filename);
void findword(string filename,string word);


int main()
{
 
}


//___________________________________________________________________________________

void countwords(string filename)
{

ifstream fileinput(filename); //opening text file

 int count=1; //will not count first word so initial value is 1

 char ch;
    if (!fileinput.is_open()) 
    {
  
        cout << "file not found";
    }
    else 
    {
        while(fileinput)
            {
                fileinput.get(ch);
                if(ch==' '||ch=='\n')
                count++;
            } 
 
 cout<<count<<" Words"<<"\n";
 fileinput.close(); //closing file
    }
}
//___________________________________________________________________________________

void countletters(string filename)
{



ifstream fileinput(filename); //opening text file

 int count=0; 

 char ch;
    if (!fileinput.is_open()) 
    {
  
        cout << "file not found";
    }
    else 
    {
        while(fileinput)
            {
            fileinput.get(ch);
            if(ch != 4)//4 is the ascii code of EOT (end of text)
            count++;
            } 
    }
 
 
 
 cout<<count-1<<" Characters"<<"\n";
 fileinput.close(); //closing file
}

//___________________________________________________________________________________

void countlines(string filename)
{


ifstream fileinput(filename); //opening text file

 int count=0; 

 char ch;
    if (!fileinput.is_open()) 
    {
  
        cout << "file not found";
    }
    else 
    {
        while(fileinput)
            {
            fileinput.get(ch);
            if(ch == 10)//10 is the ascii code of \n
            count++;
            } 
    }
 
 
 cout<<count+1<<" Lines"<<"\n";
 fileinput.close(); //closing file

}

//___________________________________________________________________________________

void findword(string filename,string word)
{

ifstream fileinput(filename); //opening text file

string str;
    if (!fileinput.is_open()) 
    {
  
        cout << "file not found";
    }
    else 
    {
        while(fileinput >> str)//taking every word and comparing with replaceStr
            { 
                if (str.find(word) != std::string::npos) 
                {
                    cout << "found!" << '\n';
                    break;
                } 
                else
                {
                    cout<<"not found"<<'\n';
                    break;
                }
            }
    }

 fileinput.close(); //closing file
 
}




//___________________________________________________________________________________
