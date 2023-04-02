#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;
int i=0;
// Define Student struct outside of main() function
struct Student
{
    int id;
    float marks, per;
    string name, grade;
} s[25];

void login();
void registr();
void forgot();
void teacher_login();
void parent_login();
void admin_login();
void insert();
void display();
void delete_record();


int count = 0;

int main(){
        int choice;
        cout<<"***********************************************************************\n\n\n";
        cout<<"                      Welcome to School Information System                \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        cout<<"1.Register"<<endl;
        cout<<"2.Forgot Password or Username"<<endl;
        cout<<"3.Teacher Login"<<endl;
        cout<<"4.Parent Login"<<endl;
        cout<<"5.Admin Login"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        registr();
                        break;
                case 2:
                        forgot();
                        break;
                case 3:
                        teacher_login();
                        break;
                case 4:
                        parent_login();
                        break;
                case 5:
                        admin_login();
                        break;

                case 6:
                        cout<<"Thanks for using this program\n\n\n";
                        break;        

                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl; 
                        main();


        }      
}

void parent_login() 
{
    int choice;
    string parent_username = "parent";
    string parent_password = "parent123";
    string username, password;

    cout << "Enter Parent username: ";
    cin >> username;

    cout << "Enter Parent password: ";
    cin >> password;

    if (username == parent_username && password == parent_password)
    {
        cout << "\nParent login successful!\n" ;
            //Inserted by JS
         }
    }

void admin_login()
{
    string admin_username = "admin";
    string admin_password = "admin123";
    string username, password;
    
    cout << "Enter admin username: " ;
    cin >> username;

    cout << "Enter admin password: ";
    cin >> password;

    if (username == admin_username && password == admin_password)
    {
        cout << "\nAdmin login successful!\n";
        // Add your admin features here
    }
    else
    {
        cout << "\nAdmin login failed. Incorrect username or password.\n";
        return;
    }
}


void teacher_login()
{  
    int teacher_choice;
    string teacher_username = "teacher";
    string teacher_password = "teacher123";
    string username, password;

    cout << "Enter Teacher username: ";
    cin >> username;

    cout << "Enter Teacher password: ";
    cin >> password;

    if (username == teacher_username && password == teacher_password)
    {
        cout << "\nAdmin login successful!\n";
        // Add admin features here
        cin.get();
        cin.get();

        system("cls"); // Clear screen before displaying menu

        do
        {
            cout<<"\nWelcome "<< username<<" to Student Record Management System\n\n";
            cout<<"1. Add Record\n";
            cout<<"2. Display Records\n";
            cout<<"3. Delete Record\n";
            cout<<"4. Exit\n";
            cout<<"Enter your choice: ";
            cin>>teacher_choice;

            switch(teacher_choice)
            {
                case 1:
                    insert();
                    break;
                case 2:
                    cin.ignore();// Clear input buffer
                    display();
                    cin.get();
                    cin.get();
                    break;
                case 3:
                    delete_record();
                    break;
                case 4:
                    cout << "Goodbye!" ;
                    break;
                default:
                    cout<<"\nInvalid choice! Please try again.\n";
            }

            if (teacher_choice != 6) {
                cout << "\nPress Enter to continue...\n";
                cin.get();
            }

            system("cls"); // Clear screen before displaying menu again

        }  while(teacher_choice != 6);
               
    }
    else
    {
        cout << "\nAdmin login failed. Incorrect username or password.\n";
        main();
    }
}

void login()
{
       
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;
        
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello "<<user<<"\nLOGIN SUCESS\nWelcome to the main page.\n\n";
                cin.get();
                cin.get();
                main();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }
}
void registr()
{
        
        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        main();
        
        
}

void forgot()
{
        int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;
                        
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;
                        
                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                main();
                        }
                
                        break;
                }
                
                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }
        
}


void insert()
{
    int id;
    float marks, per;
    string name, grade;
    system("cls");
    cout<<"\n\n\t\t\t*** Insert Record ***";
    cout<<"\n\n Enter Student ID : ";
    cin >> s[i].id;
    cout<<"\n\n Enter Student Name: ";
    cin >> s[i].name;
    cout<<"\n\n Enter Student Marks: ";
    cin >> s[i].marks;

    // Write to the file "student.txt"
    ofstream record("student.txt",ios::app);
    record << s[i].id << ' ' << s[i].name << ' ' << s[i].marks << endl;
    record.close(); // Close the file

    system("cls");
    cout<<"\n\n *** Insert Record Successfully ***";

    s[i].per = s[i].marks / 100 * 100;
    if(s[i].per >= 85)
        s[i].grade = "A+";
    else if(s[i].per >=75)
        s[i].grade = "A";
    else if(s[i].per >=65)
        s[i].grade = "B+";
    else if(s[i].per >=55)
        s[i].grade = "B";
    else if(s[i].per >=50)
        s[i].grade = "C";
    else if(s[i].per >=45)
        s[i].grade = "D";
    else if(s[i].per >=33)
        s[i].grade = "E";
    else 
        s[i].grade = "F";
    i++;
}

void delete_record()
{
    system("cls");
    cout << "\n\n\t\t\t *** Delete Record ***";

    ifstream input_file("student.txt");
    if (!input_file) {
        cout << "\n\n Error: Cannot open file\n";
        return;
    }

    ofstream output_file("temp.txt");
    if (!output_file) {
        cout << "\n\n Error: Cannot create file\n";
        return;
    }

    int id, found = 0;
    cout << "\n\n Enter Student ID: ";
    cin >> id;

    while (!input_file.eof()) {
        int file_id;
        string name, grade;
        float marks;
        input_file >> file_id >> name >> marks;

        if (id == file_id) {
            found++;
            continue;
        }

        // calculate percentage and grade
        float per = (marks / 500) * 100;
        if (per >= 90)
            grade = "A+";
        else if (per >= 80)
            grade = "A";
        else if (per >= 70)
            grade = "B";
        else if (per >= 60)
            grade = "C";
        else if (per >= 50)
            grade = "D";
        else
            grade = "F";

        output_file << file_id << ' ' << name << ' ' << marks << ' ' << per << ' ' << grade << endl;
    }

    input_file.close();
    output_file.close();

    if (found == 0) {
        cout << "\n\n *** Student ID Not Found ***";
        remove("temp.txt");
    } else {
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "\n\n *** Delete Record Successfully ***";
    }
}

void display()
{
    system("cls");
    cout << "\n\n\t\t\t *** Display All Record ***\n";
    ifstream record("student.txt");
    if (!record) {
        cout << "Error: Cannot open file\n";
        return;
    }
    int id;
    string name;
    float marks;
    cout << "\n\n\t ID\t\t Name\t\t Marks\t\t Percentage\t\t Grade\n\n";
    while (record >> id >> name >> marks) {
        float per = marks / 100 * 100;
        string grade;
        if(per >= 85)
            grade = "A+";
        else if(per >=75)
            grade = "A";
        else if(per >=65)
            grade = "B+";
        else if(per >=55)
            grade = "B";
        else if(per >=50)
            grade = "C";
        else if(per >=45)
            grade = "D";
        else if(per >=33)
            grade = "E";
        else 
            grade = "F";
        cout << "\t" << id << "\t\t" << name << "\t\t" << marks << "\t\t" << per << "%" << "\t\t" << grade << "\n";
    }
    record.close();
   
}


void displayClassList() {

cout << "Displaying class list for student: Trevor McGee \n" << endl;
cout << "Subject: English" << endl;
cout << "Teacher: Mrs Florence MacDonald \n" << endl;
cout << "Subject: Maths" << endl;
cout << "Teacher: Mr George Hope \n" << endl;
cout << "Subject: Social Studies" << endl;
cout << "Teacher: Miss Jane McCain\n" << endl;
cout << "Subject: Science" << endl;
cout << "Teacher: Ms Joy Board \n" << endl;
cout << "Subject: P.E." << endl;
cout << "Teacher: Mr Jordan Bulk \n" << endl;
// code to display class list

}


void displayStudentReports() {

cout << "Displaying current grades for student: Trevor McGee \n" << endl;
cout << "Subject: English" << endl;
cout << "Term 1: C- " << endl;
cout << "Term 2: B+ " << endl;
cout << "Term 3: A- " << endl;
cout << "Term 4: A+ " << endl;
cout << "Teacher comments: Trevor has shown great improvement in his English studies this year - Mrs MacDonald" << endl;

}

void facultyDirectory() {
cout << "School landline: PH: 09 555 0813" << endl;
cout << "Principle: Terry Johns - PH: (ext. 712)" << endl;
cout << "Vice-Principle:  George Glass - PH: (ext. 710)" << endl; 
cout << "Administration & Reception: Heather McGowan PH: (ext. 705 )" << endl;
}
