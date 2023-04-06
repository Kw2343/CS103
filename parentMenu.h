//Parent Menu - Justyne Stoddard 270217652


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
