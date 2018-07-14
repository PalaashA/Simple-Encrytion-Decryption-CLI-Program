#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<iomanip>


using namespace std;

int main()
{
    fstream file;
    char data[100],ch,ch1;
    char name[10];
    int i,j=0,k,key=0;
    int password,varInput;

    //Program starts:	
    cout<<"Welcome to the Program!"<<endl<<"Please input password:";
    cin>>password;

    if(password==1234)
    {
        cout<<"WELCOME!"<<endl<<"Input your choice."<<endl;
        label1:
        cout<<"Enter:"<<endl<<"1.Encryption"<<endl<<"2.Decryption "<<endl<<"3.View contents of the file, OR"<<endl<<"Press any other key to exit!"<<endl;
        cin>>varInput;

        if(varInput==1)
        {
        	if(!file)
        	{
        		cout<<"File can't be opened";

			}
			else{

            //Encryption Block:				
            cout<<"Welcome to Encryption Block"<<endl;
				
            //Input data to File:				
            cout<<"Enter name of file:";
            cin>>name;
             strcat(name,".txt");
            file.open(name,ios::out);
            cout<<"Enter data to the File:";
            cin.ignore(); //Ignore ENTER command in buffer
            cin.getline(data,100);
             cout<<"Enter the passkey:";
    		cin>>key;

            //Encryption char+key :
            for(i=0;i<strlen(data);i++)
           {
               data[i]=data[i]+key;
           }
           
	    file<<data;
            file.close();
            cout<<"Data has been successfully encrypted. Going back to main screen! \n"<<endl;

           goto label1;
		}

        }
        else if(varInput==2)
        {
        	if(!file)
        	{
        		cout<<"File can't be opened";

			}
			else{
				
           //Decryption Block:				
           cout<<"tWelcome to DECRYPTION BLOCK"<<endl;
				
           //Opening the file and putting the cursor in the beginning:				
           cin.ignore();
           cout<<"Enter name of file:";
            cin>>name;
             strcat(name,".txt");
           file.open(name,ios::out|ios::in);
				
           //Reading data from the file:
           while(!file.eof())
           {
            file.getline(data,100);
		   
            //Decrypting char-key:
                cout<<"Enter the passkey:";
	    		cin>>key;
            for(i=0;i<strlen(data);i++)
            {
                data[i]=data[i]-key;
            }
           }
				
           //Overwriting existing data:
           file.seekg(0,ios::beg);
           for(i=0;i<strlen(data);i++)
           {
               file<<data[i];
           }

           file.close();
           cout<<" \nData has been successfully decrypted. Going back to main screen! \n"<<endl;

           goto label1;
       }
        }
        else if(varInput==3)
        {
        	if(!file)
        	{
        		cout<<"File can't be opened";

			}
			else{
				
            //To show contents of the file:
            cout<<"Enter name of file:";
            cin>>name;
             strcat(name,".txt");
            file.open(name,ios::in);
            cout<<"Current data in the file:";
            while(1)
                {
                    file.get(ch);
                    if(file.eof())
                    break;
                    cout<<ch;

                }
            file.close();
            cout<<"Going back to main screen! \n"<<endl;

            goto label1;

        	}

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
