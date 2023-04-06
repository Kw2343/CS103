#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <sstream>

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
void insertClassList() ;
void contactFaculty();
void loginLogLook();
void student_login();
void updateClassList();
void deleteClassList();


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
        cout<<"6.Student Login"<<endl;
        cout<<"7.Exit"<<endl;
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
                        student_login();
                        break;        

                case 7:
                        cout<<"Thanks for using this program\n\n\n";
                        break;        

                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl; 
                        main();


        }      
}


void forgot() {

  int ch;

  system("cls");

  cout << "Forgotten ? We're here for help\n";

  cout << "1.Search your id by username" << endl;

  cout << "2.Search your id by password" << endl;

  cout << "3.Main menu" << endl;

  cout << "Enter your choice :";

  cin >> ch;

  switch (ch)

  {

  case 1:

  {

    int count = 0;

    string searchuser, su, sp;

    cout << "\nEnter your remembered username :";

    cin >> searchuser;

    ifstream searchu("records.txt");

    while (searchu >> su >> sp)

    {

      if (su == searchuser)

      {

        count = 1;
      }
    }

    searchu.close();

    if (count == 1)

    {

      cout << "\n\nHurray, account found\n";

      cout << "\nYour password is " << sp;

      cin.get();

      cin.get();

      system("cls");

      main();

    }

    else

    {

      cout << "\nSorry, Your userID is not found in our database\n";

      cout << "\nPlease kindly contact your system administrator for more "
              "details \n";

      cin.get();

      cin.get();

      main();
    }

    break;
  }

  case 2:

  {

    int count = 0;

    string searchpass, su2, sp2;

    cout << "\nEnter the remembered password :";

    cin >> searchpass;

    ifstream searchp("records.txt");

    while (searchp >> su2 >> sp2)

    {

      if (sp2 == searchpass)

      {

        count = 1;
      }
    }

    searchp.close();

    if (count == 1)

    {

      cout << "\nYour password is found in the database \n";

      cout << "\nYour Id is : " << su2;

      cin.get();

      cin.get();

      system("cls");

      main();

    }

    else

    {

      cout << "Sorry, We cannot found your password in our database \n";

      cout << "\nkindly contact your administrator for more information\n";

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

    cout << "Sorry, You entered wrong choice. Kindly try again" << endl;

    forgot();
  }
}

void registr()
{
    string ruserId, rpassword;
    system("cls");
    cout << "\t\t\t Enter the Username : ";
    cin >> ruserId;
    cout << "\t\t\t Enter the Password : ";
    cin >> rpassword;

    // Write to the file "records.txt"
    ofstream record("records.txt", ios::app);
    record << ruserId << ' ' << rpassword << endl;
    record.close(); // Close the file

    // Write to the log file "registrationlog.txt"
    ofstream log("registrationlog.txt", ios::app);
    log << "New registration: " << ruserId << endl;
    log.close(); // Close the file

    system("cls");
    cout << "\n\t\t\t Registration is successful! \n";
    main();
}

void student_login()
{
    int count = 0;
    int choice;
    string user, pass, u, p;

    system("cls");

    cout << "Please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("records.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << "\nHello " << user << "\nLOGIN SUCCESS\nWelcome to the main page.\n\n";
          char menu_choice;
    do {
        cout << "Welcome to the Student Portal. Please select from the following options" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "1. Display Class List" << endl;
        cout << "2. Display Student Reports" << endl;
        cout << "3.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> menu_choice;

        switch(menu_choice) {
            case '1':
                displayClassList();
                break;
            case '2':
                display();
                break;
                
            case 3:
                cout << "Returning to main menu..." << endl;
                break;
                
            default:
                cout << "" << endl;
                break;
        }
    } while (menu_choice != '3');
    }
    else
    {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
        cout << "1. Forgot password?\n2. Register as a new user\n3. Go back to main menu\nEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            forgot();
        }
        else if (choice == 2)
        {
            registr();
        }
        else if (choice == 3)
        {
            main();
        }
        else
        {
            cout << "Invalid choice\n";
            student_login();
        }
    }

   
}



void teacher_login()
{  
    int teacher_choice;
    string teacher_username = "teacher";
    string teacher_password = "teacher123";
    string username, password;
    int num_attempts = 0;

    do {
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
                        cout << "Returning to main menu...\n";
                        main();
                        break;
                        
                    default:
                        cout<<"\nInvalid choice! Please try again.\n";
                }

                if (teacher_choice != 4) {
                    cout << "\nPress Enter to continue...\n";
                    cin.get();
                }

                system("cls"); // Clear screen before displaying menu again

            }  while(teacher_choice != 4);
            
            break;
        }
        else
        {
            num_attempts++;
            if (num_attempts >= 3) {
                cout << "\nToo many login attempts.Please contact admin.\n";
                exit(0);
            } else {
                cout << "\n Teacher login failed. Incorrect username or password. " << 3 - num_attempts << " attempts remaining.\n";
            }
        }
    } while (num_attempts < 3);
}



void insert()
{
    int id;
    float marks, per;
    string name, grade;
    system("cls");
    cout<<"\n\n\t\t\t*** Insert Record ***";
    cout<<"\n\n Enter Student ID : ";
    cin >> id;
    cout<<"\n\n Enter Student Name: ";
    cin >> name;
    cout<<"\n\n Enter Student Marks: ";
    cin >> marks;

    // Write to the file "student.txt"
    ofstream record("student.txt",ios::app);
    per = marks / 100 * 100;
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
    record << id << ' ' << name << ' ' << marks << ' ' << per << ' ' << grade << endl;
    record.close(); // Close the file

    system("cls");
    cout<<"\n\n *** Insert Record Successfully ***";
}

// Function to display all records
void display()
{
    system("cls");
    cout << "\n\n\t\t\t *** Display All Records ***\n";
    ifstream record("student.txt");
    if (!record) {
        cout << "Error: Cannot open file\n";
        return;
    }
    int id;
    string name;
    float marks, per;
    string grade;
    cout << "\n\n\t ID\t\t Name\t\t Marks\t\t Percentage\t\t Grade\n\n";
    while (record >> id >> name >> marks >> per >> grade) {
        cout << "\t" << id << "\t\t" << name << "\t\t" << marks << "\t\t" << per << "%" << "\t\t" << grade << "\n";
    }
    record.close();
}

void delete_record()
{
    int id;
    bool found = false;
    cout << "Enter the ID of the record to delete: ";
    cin >> id;
    ifstream record("student.txt");
    ofstream temp("temp.txt");
    if (!record) {
        cout << "Error: Cannot open file\n";
        return;
    }
    int current_id;
    string name;
    float marks, per;
    string grade;
    while (record >> current_id >> name >> marks >> per >> grade) {
        if (current_id != id) {
            temp << current_id << " " << name << " " << marks << " " << per << " " << grade << endl;
        } else {
            found = true;
        }
    }
    record.close();
    temp.close();
    if (found) {
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

//Parent menu & option declarations - Justyne 
void displayClassList() {
    cout << "Displaying class list for student: \n" << endl;
    cout << "Subject: English" << endl;
    cout << "Teacher: Mrs Florence MacDonald \n" << endl;
    cout << "Subject: Maths" << endl;
    cout << "Teacher: Mr George Hope \n" << endl;
    cout << "Subject: Social Studies" << endl;
    cout << "Teacher: Miss Jane McCain\n" << endl;
    cout << "Subject: Science" << endl;
    cout << "Teacher: Ms Joy Board \n" << endl;
    cout << "Subject: P.E. & Sports" << endl;
    cout << "Teacher: Mr Jordan Bulk \n" << endl;
}
void displayStudentReports() {
    
    cout << "Displaying current grades for student \n" << endl;
    cout << "Subject: English" << endl;
    cout << "Term 1: C- " << endl;
    cout << "Term 2: B+ " << endl;
    cout << "Term 3: A- "  << endl;
    cout << "Term 4: A+ \n" << endl;
    "\n";
    cout << "Subject: Maths" << endl;
    cout << "Term 1: F " << endl;
    cout << "Term 2: C+ " << endl;
    cout << "Term 3: B- "  << endl;
    cout << "Term 4: B+ " << endl;
    "\n";
    cout << "Subject: Social Studies" << endl;
    cout << "Term 1: B+- " << endl;
    cout << "Term 2: B+ " << endl;
    cout << "Term 3: A- "  << endl;
    cout << "Term 4: A \n" << endl;
    "\n";
    cout << "Subject: Science" << endl;
    cout << "Term 1: B- " << endl;
    cout << "Term 2: B+ " << endl;
    cout << "Term 3: A+ "  << endl;
    cout << "Term 4: A+ \n" << endl;
    "\n";
    cout << "Subject: P.E." << endl;
    cout << "Term 1: D " << endl;
    cout << "Term 2: D+ " << endl;
    cout << "Term 3: C- "  << endl;
    cout << "Term 4: C+ \n" << endl;
    "\n";

}
void facultyDirectory() {
    cout << "Faculty Contacts: " << endl;
    cout << "----------------" << endl;
    cout << "School landline: PH: 09 555 0813" << endl;
    cout << "Principle:  Terry Johns - PH: (ext. 712)" << endl;
    cout << "Vice-Principle:  George Glass - PH: (ext. 710)" << endl;  
    cout << "Administration & Reception: Heather McGowan PH: (ext. 705 )" << endl;
    cout << "Teacher Contacts: " << endl;
    cout << "----------------" << endl;
    cout << "English: Mrs Florence MacDonald - email: fmacdonald@school.ac.nz \n" << endl;
    cout << "Maths: Mr George Hope - email: ghope@school.ac.nz \n" << endl;
    cout << "Social Studies: Miss Jane McCain = email: jmccain@school.ac.nz\n" << endl;
    cout << "Science: Ms Joy Board - email: jboard@school.ac.nz \n" << endl;
    cout << "P.E. & Sports: Mr Jordan Bulk - email: jbulk@school.nz \n" << endl;
}
void parentMenu() {
    char choice;
    do {
        cout << "Welcome to the Parents and Caregivers Menu. Please select from the following options" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "1. Display Class List" << endl;
        cout << "2. Display Student Reports" << endl;
        cout << "3. Directory for teachers & faculty" << endl;
        cout << "Q. Exit App" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                displayClassList();
                break;
            case '2':
                displayStudentReports();
                break;
            case '3':
               facultyDirectory();
                break;
            case 'Q':
            case 'q':
                cout << " Thank you for using the School Information System!  Exiting now... \n" << endl;
                exit (0);
                break;
        }
    } while (choice != 'B' && choice != 'b');
}


void parent_login() // Parent Login by Kelvin
{
  int parent_choice;
  string parent_username = "parent";
  string parent_password = "parent123";
  string username, password;

  int login_attempts = 3; // set the number of login attempts to 3

  do {
    cout << "Enter Parent username: ";
    cin >> username;
    cout << "Enter Parent password: ";
    cin >> password;

    if (username == parent_username && password == parent_password) {
      cout << "\nLogin successful!\n";

      do {
        parentMenu();

      } while (parent_choice != 3);
      break;
    } else {
      login_attempts--; // decrement the number of login attempts
      if (login_attempts == 0) {
        cout << "\nLogin failed. You have exceeded the maximum number of login attempts. Please contact admin\n";
        main();
        break;
      } else {
        cout << "\nLogin failed. Incorrect username or password. " << login_attempts << " attempts remaining.\n";
      }
    }
  } while (login_attempts > 0);
}

void admin_login()

{

  int admin_choice;
  
  string logs;
  
  string admin_username = "admin";

  string admin_password = "admin123";

  string username, password;

  cout << "Enter admin username: ";

  cin >> username;

  cout << "Enter admin password: ";

  cin >> password;

  if (username == admin_username && password == admin_password)

  {

    cout << "\nAdmin login successful!\n";

    //added admin login log also 

    ofstream record("loginlog.txt", ios::app);

    record << username << endl;

    record.close(); 

    do

    {

      cout << "\nWelcome " << username
           << " to Student Record Management System\n\n";

      cout << "1. Add Class list\n";

      cout << "2. Delete class\n";

      cout << "3. Login logs\n";

      cout << "4. Exit\n";

      cout << "Enter your choice: ";

      cin >> admin_choice;

      switch (admin_choice)

      {

      case 1:

        insertClassList();

        break;

      case 2:
      // add code for update/delete class menu
        int update_choice;
        cout << "1. Delete Class List\n";
        cout << "2. Return to last menu";
        cout << "Enter your choice: ";
        cin >> update_choice;
     switch (update_choice)
      {
      case 1:
        deleteClassList();
        break;
      default:
        cout << "\nInvalid choice! Please try again.\n";
        break;
      
      case 2:
      break;
      
      }
      break;

        break;

      

      case 3:
//added in login log issue
        
        
        break;

      case 4:

        cout << "Goodbye!";
        main();
        return;
        break;

      default:

        cout << "\nInvalid choice! Please try again.\n";
      }

      if (admin_choice != 7) {

        cout << "\nPress Enter to continue...\n";

        cin.get();
      }

      system("cls");

      // Clear screen before displaying menu again

    } while (admin_choice != 7);

  } else

  {

    cout << "\nAdmin login failed. Incorrect username or password.\n";

    main();
  }
}


void insertClassList()
{
    string teacher_name, subject, timetable;
    system("cls");
    cout<<"\n\n\t\t\t*** Insert class list ***";
    cout<<"\n\n Enter Teacher's name: ";
    cin >> teacher_name;
    cout<<"\n\n Enter Subject: ";
    cin >> subject;
    cout<<"\n\n Enter Time: ";
    cin >> timetable;
   

    // Write to the file "class.txt"
    ofstream record("class.txt",ios::app);
    
   
    record << teacher_name << ' ' << subject  << ' ' << timetable << endl;
    record.close(); // Close the file

    // Display class list
    displayClassList();

    system("pause");
    system("cls");

}

void deleteClassList() {
    string teacher_name;
    bool found = false;

    cout << "Enter the name of the teacher to delete: ";
    cin >> teacher_name;

    ifstream infile("class.txt");
    ofstream outfile("temp.txt");
    if (!infile) {
        cout << "Error: Cannot open file for reading.\n";
        return;
    }
    string tname, subject, timetable;
    while (infile >> tname >> subject >> timetable) {
        if (tname != teacher_name) {
            outfile << tname << " " << subject << " " << timetable << endl;
        } else {
            found = true;
        }
    }

    infile.close();
    outfile.close();

    if (found) {
        remove("class.txt");
        rename("temp.txt", "class.txt");
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

