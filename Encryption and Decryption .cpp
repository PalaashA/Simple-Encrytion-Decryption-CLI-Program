#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main()
{
    fstream file;
    char data[100],ch,ch1;
    int i,j=0,k;
    int password,varInput;

    //Program starts:
    cout<<"Welcome to the Program!"<<endl<<"Please input password"<<endl;
    cin>>password;
    if(password==1234)
    {
        cout<<"Welcome!"<<endl<<"Input your choice."<<endl;
        label1:
        cout<<"Enter:"<<endl<<"1 for Encryption"<<endl<<"2 for Decryption "<<endl<<"3 to view contents of the file OR"<<endl<<"Anything else to exit application!"<<endl;
        cin>>varInput;
        if(varInput==1)
        {
            //Encryption Block:
            cout<<"Welcome to Encryption block"<<endl;
            //Input data to File:
            file.open("sample.txt",ios::app);
            cout<<"Enter data to the File:"<<endl;
            cin.ignore(); //Ignore ENTER command in buffer
            cin.getline(data,100);

            //Encryption char+2 :

            for(i=0;i<strlen(data);i++)
           {
               data[i]=data[i]+2;
           }
           //cout<<data;

            file<<data;
            file.close();
            cout<<"Data has been successfully encrypted. Going back to main screen! \n"<<endl;
           goto label1;


        }
        else if(varInput==2)
        {
           //Decryption Block:
           cout<<"Welcome to DECRYPTION BLOCK"<<endl;
           //Opening the file and putting the cursor in the beginning:
           file.open("sample.txt",ios::in);
           //Reading data from the file:
           while(!file.eof())
           {
               file.getline(data,100);

           //Decrypting char-2:
           for(i=0;i<strlen(data);i++)
           {
               data[i]=data[i]-2;
           }
             cout<<data;
           }
           file<<data;

           file.close();
           cout<<" \n Data has been successfully decrypted. Going back to main screen! \n"<<endl;
           goto label1;



        }
        else if(varInput==3)
        {
            //To show contents of the file:
            file.open("sample.txt",ios::in);
            cout<<"Current data in the file::"<<endl;
            while(1)
                {
                    file.get(ch);
                    if(file.eof())
                    break;
                    cout<<ch;
                    j=j+1;
                }
            file.close();
            cout<<" \n Going back to main screen! \n"<<endl;
            goto label1;

        }
        else
        {
            cout<<"Thank You!";

        }
    }
    else
    {
        cout<<"Invalid password! Program will now terminate...";

    }
    return 0;
}
