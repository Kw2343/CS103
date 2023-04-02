//Parent Menu - Justyne Stoddard 270217652

#include <iostream>
using namespace std;

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
    cout << "Term 3: A- "  << endl;
    cout << "Term 4: A+ " << endl;
    cout << "Teacher comments: Trevor has shown great improvement in his English studies this year - Mrs MacDonald" << endl;
}

void facultyDirectory() {
    cout << "School landline: PH: 09 555 0813" << endl;
    cout << "Principle:  Terry Johns - PH: (ext. 712)" << endl;
    cout << "Vice-Principle:  George Glass - PH: (ext. 710)" << endl;  
    cout << "Administration & Reception: Heather McGowan PH: (ext. 705 )" << endl;

}

void parentMenu() {
    char choice;

    do {
        cout << "Welcome to the Parents and Caregivers Menu. Please select from the following options" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "1. Display Class List" << endl;
        cout << "2. Display Student Reports" << endl;
        cout << "3. Directory for teachers & faculty" << endl;
        cout << "B. Back" << endl;
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
            case 'B':
            case 'b':
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 'B' && choice != 'b');
}

