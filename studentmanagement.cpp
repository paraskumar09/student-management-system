//PARAS KUMAR
//210010140019
//BTech(IT)

#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>
#include<iomanip>
#include<conio.h>
using namespace std;
int n = 0;
class Student
{
public:
    int roll;
    string name;
    int score;
};

Student st[100];
void add()
{
    if (n >= 100)
    {
        cout << "reach max" << endl;
        return;
    }

   cout<<setw(50)<<".........................\n"
       <<setw(50)<<". Enter student details .\n"
       <<setw(51)<<".........................\n\n"; 

    cout << "Enter the roll no : ";
    cin >> st[n].roll;
    cout << "Enter the name : ";
    cin >> st[n].name;
    cout << "Enter the score : ";
    cin >> st[n].score;
    n++;
    system("cls");
}

void show()
{
    for (int i = 0; i < n; i++)
    {
        system("color a");
        cout <<"\nRoll NO= "<<st[i].roll << endl;
        cout <<"Name= "<<st[i].name << endl;
        cout <<"score= "<<st[i].score<<endl<< endl;
    }
    cout << "\n\n press any key to exit" << endl;
    getch();
    system("cls");
}

void loadToFile()
{

    cout<<"data uploading to file";
    for(int i=0;i<8;i++)
    {
        Sleep(100);
        cout<<".";
    }

    
        cout<<"\n\nData uploaded enter any key to continue\n";
        getch();
        system("cls");
    ofstream file("studentdata.txt");
    if (file.is_open())
    {
        file << n << endl;
        for (int i = 0; i < n; i++)
        {
            file << st[i].roll << endl;
            file << st[i].name << endl;
            file << st[i].score<<endl;
        }
        file.close();
    }
    else
    {
        cout << "cant able to open file" << endl;
    }
}

void loadFrmFile()
{

    ifstream file("studentdata.txt");
    file >> n;
    for (int i = 0; i < n; i++)
    {
        file >> st[i].roll;
        file >> st[i].name;
        file >> st[i].score;
    }
    file.close();
}

int main()
{
    char c;
    loadFrmFile();
    do
    {
        system("color c");
        cout<<"\t\t\t..........................\n"
            <<"\t\t\t. Made by Paras kumar    . \n\t\t\t. Roll No : 210010140019 . \n\t\t\t. Btech(It)              . \n"
            <<"\t\t\t..........................\n\n\n";
        cout << "No of students= "<<n<<endl;
        cout << "\n";
        cout << " --Menu--" << endl;
        cout << "\t1. Add new student" << endl
             << "\t2. Show all student" << endl
             << "\t3. Load all student to file\n"
             << "\t4. Load all student from file\n"
             << "\t5. exit.... \n\n";
        cin >> c;
        switch (c)
        {
        case '1':
           system("cls");
            add();
            break;
        case '2':
            show();
            break;
        case '3':
            system("cls");
            loadToFile();
            break;
        case '4':
            system("cls");
             cout<<"Loading data from file";
            for(int i=0;i<8;i++)
            {
                Sleep(100);
                cout<<".";
            }
        
        
            cout<<"\n\nData loaded enter any key to continue\n";
            getch();
            system("cls");
            loadFrmFile();
            break;
        case '5':
            exit(0);
        default:
            break;
        }
    } while (1);

    return 0;
}