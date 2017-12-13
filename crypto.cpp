#include<bits/stdc++.h>
using namespace std;
bool writeToFile(string c)
{
    ofstream Cipherfile;
    Cipherfile.open("cipherfilez.txt",ios::app);
    Cipherfile<<c;
    Cipherfile.close();
}
void showChoices()
{
	cout << "\n\t\t\tMENU" << endl;
	cout << "1: Caesar cipher  " << endl;
	cout << "2: Rail fence cipher   " << endl;
	cout << "3: Monoalphabetic cipher " << endl;
	cout << "4: Playfair " << endl;
	cout << "5: Exit " << endl;
	cout << "Enter your choice :";
}
caesarCypher()
{

    string s;
    int i;
    cout<<"Enter the plaintext you want to encrypt:  ";
   // cin>>s;
   cin.ignore();
    getline(cin,s);
   // cout<<"hell0";
    string en="";
   cout<<"Encrypted text :";
    for(i=0;i<s.length();i++)
    {
        //cout<<"hell";
        char c=(s[i]-65+3)%26+65;
        printf("%c",c);
        en+=c;
        //writeToFile(c);
        //cout<<s[i]+3;
    }

    writeToFile("By caesar "+en+"\n");
    cout<<endl;
    showChoices();
    return 0;

}
railFenceTechnique()
{
    string s;
    int i;
    string fh="";
    string sh="";
    cout<<"Enter the plaintext you want to encrypt:  ";
    cin.ignore();

    getline(cin,s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);

   cout<<"Encrypted text :";
   for(i=0;i<s.length();i+=2)
   {
        fh=fh+s[i];
        sh=sh+s[i+1];
   }
   string en=fh+sh;
   cout<<en;
   writeToFile("By railroad  "+en+"\n");
   showChoices();
}

monoAlphabetic()
{
    string s;
    int i,index;
    cout<<"Enter the plaintext you want to encrypt:  ";
    cin.ignore();
    getline(cin,s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string enc="";
    char key[26]={'z','v','x','c','b','m','n','a','d','s','f','h','g','k','l','j','w','q','r','y','u','t','o','p','i','e'};
    cout<<"Encrypted text :";
    for(i=0;i<s.length();i++)
    {
        if(isspace(s[i]))
        {
            enc[i]=' ';
        }
        else
        {index=int(s[i]-97);
        enc[i]=key[index];

        }cout<<enc[i];

    }
        writeToFile("By Monoalphabetic "+enc+"\n");
        showChoices();
}



int main()
{
    showChoices();

    while(1)
    {
        int choice;
        cin>>choice;

        switch (choice)
        {
            case 1: caesarCypher();
                    break;
            case 2: railFenceTechnique();
                    break;
            case 3: monoAlphabetic();
                    break;

            case 4:
                    break;

            case 5: exit(0);

        }
    }



}
