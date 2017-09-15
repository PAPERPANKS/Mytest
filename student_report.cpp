#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<iomanip.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>

class student
{
    char name[50];
    int r_no;
    int classs;
    float marks;
    char grade;
public:
    int modify1();
    void modification();
    void getdata();
    void display();
    void search();
    int getrno()
    {
        return r_no;
    }
};
student ob1[10],ob2,ob3[10],ob4;
void student::getdata()
{
    char ch;
    cin.get(ch);
    cout<<"\n\n\t\t\tEnter the roll number: ";
    cin>>r_no;
    cout<<"\n\t\t\tEnter name:";
    cin>>name;
    cout<<"\n\t\t\tEnter class:";
    cin>>classs;
    cout<<"\n\t\t\tEnter the marks:";
    cin>>marks;
    if(marks>=75)       grade='A';
    else if(marks>=60)  grade='B';
    else if(marks>=50)  grade='C';
    else if(marks>=40)  grade='D';
    else grade='F';
}
void student::display()
{
    cout<<" \nRoll no :"<<r_no;
    cout<<" \nName:"<<name ;
    cout<<"\nclass:"<<classs<<"\n"<<name<<"\t..has passed examz with  "<<marks<<"\t and grade:  "<<grade;
}

void student::modification()
{
    char clas[4];
    cout<<" rol no:"<<r_no<<"\n";
    cout<<"name: "<<name<<"\t class:"<<clas<<"\t marks"<<marks<<"\n";
    cout<<"\n enter new details";
    char nm[20]="  " , cl[4]="  ";
    float mks;
    cout<<"\n new name:(press . to retain old one) ";
    cin>>nm;
    cout<<"\n new class :(press . to retain old one) ";
    cin>>cl;
    cout<<"\n new marks:(press -1 to retain old one) ";
    cin>>mks;
    if(strcmp(nm,".")!=0)
        strcpy(name,nm);
    if (strcmp(cl,".")!=0)
        strcpy(clas,cl);
    if(mks!=-1)
    {
        marks=mks;
        if(marks>=90) grade='A+';
        else if(marks>=75)  grade='A';
        else if(marks>=60)  grade='B';
        else if(marks>=50)  grade='C';
        else if(marks>=40)  grade='D';
        else grade='F';

    }

}
int passwords()
{

    char p1,p2,p3,p4,p5,p6;
    gotoxy(30,10);
    cout<<"  ENTER THE PASSWORD"<<endl;
    cout<<" \t\t\t       ******************"<<endl;

    gotoxy(32,15);
    p1=getch();
    cout<<"*";
    p2=getch();
    cout<<"*";
    p3=getch();
    cout<<"*";
    p4=getch();
    cout<<"*";
    p5=getch();
    cout<<"*";
    p6=getch();
    cout<<"*";
    getch();
    gotoxy(32,15);
    if ((p1=='p'||p1=='P')&&(p2=='a'||p2=='A')&&(p3=='n'||p3=='N')&&(p4=='k'||p4=='K')&&(p5=='a'||p5=='A')&&(p6=='j'||p6=='J'))

        return 1;

    else
        return 0;
}


void main()
{

    cout<<"\t\n\n";
    cout<<"\n\t\t HH     HH EEEEEEE LL      LL      OOOOOO  !! ";
    cout<<"\n\t\t HH     HH EE      LL      LL      OO  OO  !! ";
    cout<<"\n\t\t HHHHHHHHH EEEEE   LL      LL      OO  OO  !! ";
    cout<<"\n\t\t HH     HH EE      LL      LL      OO  OO  !! ";
    cout<<"\n\t\t HH     HH EEEEEEE LLLLLLL LLLLLLL OOOOOO  !! ";
    cout<<"\n\n\t\t\t\t\t\t\tjj";
    cout<<"\n\n\t\t PPPPP   aaaaa  nn      kk k  aaaaa     jj              ";
    cout<<"\n\t\t PP  PP    aaa  nnnnn   kkk     aaa     jj                ";
    cout<<"\n\t\t PPPPP   a  aa  nn  nn  kkk   a  aa  jj jj    ";
    cout<<"\n\t\t pp      aaaaa  nn  nn  kk k  aaaaa  jjjjj           ";
    cout<<"\n\n\n\tCOMPUTER   PROJECT  (******* STUDENT MANAGEMENT ******)";
    cout<<"\n\n\t\t\t\t       BY  :-";
    cout<<"\n\n\t\t\t*  PANKAJ KUMAR"<<"\t  XI ";
    cout<<"\n\n\t\t\t*  PANKAJ GAUTAM"<<"  XI ";

    cout<<"\nPress ENTER key to continue\n";
    getch();
    clrscr();
    cout<<"\n\n\t\t\t SHIV VANI MODEL SR. SEC. SCHOOL\n" ;
    cout<<"\t\t\t ****************************\n";
    cout<<"\n\n\t\t                STUDENT MANAGER\n";
    cout<<"\t\t                *************** \n";
    int passwords();
    if(!passwords())
    {
        for(int i=0; i<2; i++)
        {
            clrscr();
            cout<<"\nWRONG PASSWORD, TRY ONCE MORE\n";
            if(passwords())
            {
                goto last;
            }
            else
            {
                clrscr();
                cout<<"\n\n\t\t\t ALL ATTEMPTS FAILED.....";
                cout<<"\n\n\n\t\t\t HEY YOU ARE A THEIF.................. ";
                exit(0);
            }

        }
        cout<<"\t\t\t SORRY :-( ............. \n \t\t\tinactive";
    }
    else
    {   clrscr();
last:
        ;
        clrscr();
        cout<<"LOADING/////////////////////////////////\n";
        int rn,tr,n,p,i=0,record=0;
        long pos;
        char ans;
        do
        {
            clrscr();
            cout<<"\n\n\n\t\t\tMenu for displaying\entering data\n\n";
            cout<<"\t\t\t1.Enter the details\n\n";
            cout<<"\t\t\t2.Displaying the details\n\n";
            cout<<"\t\t\t3.searching details\n\n";
            cout<<"\t\t\t4.modification \n\n";

            cout<<"\t\t\t5.Deletion\n\n";
            cin>>tr;
            clrscr();
            switch(tr)
            {
            case 1: {
                cout<<"\n\t\t\t Enter the NOs of students to be added\n";
                cin>>n ;
                p=n;
                ofstream cpp("name.txt",ios::app);
                for( i=0; i<n; i++)
                {
                    ob1[i].getdata();
                    cpp.write((char*)&ob1[i],sizeof(ob1[i]));
                    record++;
                }
                cpp.close();
                clrscr();
                cout<<"\n\n\n Do you want to continue(y/n)";
                cin>>ans;
                break ;
            }
            case 2: {

                ifstream cpp("name.txt",ios::app);
                cpp.seekg(0);
                cout<<"\nHow many details u have entered???\n";
                cin>>p;
                {
                    for(i=0; i<p; i++)
                    {
                        cpp.read((char*)&ob1[i],sizeof(ob1[i]));
                        ob1[i].display();
                        cout<<"\n\n\n";
                    }
                }
                cout<<"\n\n\t\t\t\n Do you want to go back to main menu???(y/n)";
                cin>>ans;
                cpp.close();
                break;
            }
            case 3: {
                char found='n';
                ifstream cpp("name.txt",ios::in||ios::app);
                cout<<"\t\t\tEnter the roll no. to search \n";
                cin>>rn;
                cpp.seekg(0);
                while(!cpp.eof())
                {
                    pos=cpp.tellg();
                    cpp.read((char*)&ob2,sizeof(ob2));
                    if(ob2.getrno()==rn)
                    {
                        found='y';
                        ob2.display();
                        break;
                    }
                    else cpp.seekg(pos,ios::cur);
                }
                if(cpp.eof()) cout<<"crasheddddd";
                if(found=='n')
                    cout<<"\nRecord not found.....zzzzz\n";
                cout<<"\n\t\t\t\n\n Do you want to go back to main menu???(y/n)";
                cin>>ans;
                break;
            }
            case 4: {
                char found='f';
                ofstream cpp("name.txt",ios::out||ios::app);
                ifstream cp("name.txt",ios::in||ios::app);
                cout<<"\t\t\tEnter the roll no. to be modified \n";
                cin>>rn;
                while(!cpp.eof())
                {
                    pos=cp.tellg();
                    cp.read((char*)&ob2,sizeof(ob2));
                    if(ob2.getrno()==rn)
                    {
                        ob2.modification();
                        cp.seekg(pos);
                        cpp.write((char*)&ob2,sizeof(ob2));
                        found='t';
                        break;
                    }
                }
                if(found=='f')
                    cout<<"\nrecord not found\n";
                cpp.close();
                cp.close();
                ifstream cppp("name.txt",ios::in||ios::app);
                cppp.seekg(0);
                cout<<"\nWhich file you have modified(number)???\n";
                cin>>p;
                cout<<"\nNow the file contains\n";
                {
                    clrscr();
                    for(i=0; i<p; i++)
                    {
                        cppp.read((char*)&ob3[i],sizeof(ob3[i]));
                        ob3[i].display();
                    }
                }
                cout<<"\n\t\t\t\n Do you want to go back to main menu???(y/n)";
                cin>>ans;
                clrscr();
                cpp.close();
                break;
            }
            case 6: {
                char found='f',confirm='n';
                ifstream cpp("name.txt",ios::in||ios::app);
                ofstream cp("temp.txt",ios::out||ios::app);
                cout<<"\nEnter the roll No. of the student to be deleted....\n";
                cin>>rn;
                while(!cpp.eof())
                {
                    cpp.read((char*)&ob2,sizeof(ob2)) ;
                    if(ob2.getrno()==rn)
                    {
                        ob2.display();
                        found='t';
                        cout<<"\nAre you want to delete this record\n";
                        cin>>confirm;
                        if(confirm=='n')
                            cp.write((char*)&ob2,sizeof(ob2)) ;
                    }
                    else
                        cp.write((char*)&ob2,sizeof(ob2)) ;
                }
                if(found=='f')
                    cout<<"\nRecord not found!!!\n";
                cpp.close();
                cp.close();
                remove("name.txt");
                rename("temp.txt","stu.txt");
                cpp.open("name.txt",ios::in);
                cpp.seekg(0);
                cout<<"\nWhich file you have Deleted(number)???\n";
                cin>>p;
                cout<<"\nNow the file contains\n";
                for(int i=0; i<p; i++)
                {
                    cpp.read((char*)&ob3[i],sizeof(ob3[i]));
                    if(cpp.eof()) break;
                    ob4.display();

                }
                cpp.close();
                break;
            }
            case 5: {

            }
            }

        } while(ans=='Y'||ans=='y');
        getch();
    }
}
