/*This C++ project on Student Report Management System is an organized system used for collecting,
storing and organizing the data of students. The student information contains: student number
, name, department, address ,number of subjects, marks and grades
*/

//This project is developed using C++ Programming Language, classes, structures, arrays and different variables and strings.
#include <iostream>
#include <string>
# include<fstream>
#include <sstream>//we used it to covert string to integer
using namespace std;
int laststudent;
//the maxmum number of students that the program can deal with
const int  maxmum_namber_of_students = 200;

//class declaration
class Student {
public:

    string number;
    string name;
    string department;
    //address as structure containing (city, residential area, zip code)
    struct address
    {
        string city, residential_area, zip_code;
    };
    address address;
    int number_of_subjects;
    int marks[10];
    char grades;

    /*
    This feature enlists all the students’ record saved in file.
    The grade report is displayed in a tabular form with roll no.
    and name of the students, marks achieved in all subjects, and the grade and percentage obtained by them.
    */
    void Display_students_grade_report()
    {
        cout << " Student name : " << name << "\n";
        cout << " Student No. : " << number << "\n";
        cout << " student Marks : ";
        for (int i = 0; i < number_of_subjects; ++i)
        {
            cout << marks[i] << " , ";
        }
        cout << "\n";
        int sum = 0; float Percentage;
        //geting the sum of the marks
        for (int i = 0; i < number_of_subjects; ++i)
        {
            sum += marks[i];
        }
        cout << " Student total grade : " << sum;
        //geting the percentage .... we assum the all marks from 100
        Percentage = (float(sum) / (number_of_subjects * 100)) * 100;
        cout << " Student Percentage " << Percentage << endl;
        //cheak that the grads has been calculated or not 
        if ((grades == 'A') || (grades == 'B') || (grades == 'C') || (grades == 'D') || (grades == 'F'))
            //print it if i was calulated
            cout << "the grade is " << grades << endl;
    }

    /*
    this feature is used to edit the report card record of a particular student.
    For this, the name and roll no. of the student is sought. Upon successful modification,
    the program displays the message “Record Updated”.
    If no record of student is found in file, it displays the message “Record not found”
    */

    void Modify_students_report()
    {

        int x, option;
        //give the user the option to modify all information or a selected one
        cout << "choose your option" << endl;
        cout << "1-modify all items" << endl;
        cout << "2-modify selected item " << endl;
        cin >> option;
        switch (option)
        {
        case 1://case 1---> modify all items
        { cout << "enter the new roll no." << endl;
        cin >> number;  //take the new item 
        cout << "enter the new name" << endl;
        cin.ignore();
        getline(cin, name);//take the new item 
        cout << " enter the new department" << endl;
        cin.ignore();
        getline(cin, department);  //take the new item 
        cout << "to change the address  ";
        cout << "enter the new city" << endl;
        cin.ignore();
        getline(cin, address.city);//take the new item 
        cout << "enter new residential_area" << endl;
        cin.ignore();
        getline(cin, address.residential_area);//take the new item 
        cout << "enter new zip code" << endl;
        cin.ignore();
        getline(cin, address.zip_code);//take the new item 
        cout << "enter the new number of subject" << endl;
        cin >> number_of_subjects;//take the new item 
        for (int i = 0; i < number_of_subjects; i++)
        {
            cout << "enter the new mark of subject no." << i + 1 << endl;
            cin >> marks[i];
        }}
        break;
        case 2://case 1---> modify selected item
        {cout << "choose the number of item U want to modify :" << endl;
        cout << "1-roll no." << endl;
        cout << "2-name" << endl;
        cout << "3-department" << endl;
        cout << "4-address" << endl;
        cout << "5-number of subject" << endl;
        cout << "6-marks" << endl;
        //ask the user for this element
        cin >> x;
        switch (x)
        {
        case 1: cout << "enter the new roll no." << endl;
            cin >> number;
            break;
        case 2: cout << "enter the new name" << endl;
            cin.ignore();
            getline(cin, name);
            break;
        case 3: cout << " enter the new department" << endl;
            cin.ignore();
            getline(cin, department);
            break;
        case 4: cout << "to change the address  ";
            cout << "enter the new city" << endl;
            cin.ignore();
            getline(cin, address.city);
            cout << "enter new residential_area" << endl;
            cin.ignore();
            getline(cin, address.residential_area);
            cout << "enter new zip code" << endl;
            cin.ignore();
            getline(cin, address.zip_code);
            break;
        case 5: cout << "enter the new number of subject" << endl;
            cin >> number_of_subjects;
            break;
        case 6:
            for (int i = 0; i < number_of_subjects; i++) //let's take the marks the loop depends on the number of subjects
            {
                cout << "enter the new mark of subject no." << i + 1 << endl;
                cin >> marks[i];
            }
            break;

        }
        }
        cout << "Record Updated" << endl;
        }

    }


    /*
Calculate the total score based on marks obtained by student and percentage then get the grade of the student as follows:
Percentage < 50%   grade is F
Percentage >=50 and < 65%   grade is D
Percentage >=65 and < 75%   grade is C
Percentage >=75 and < 85%   grade is B
Percentage >=85 grade is A

    */

    void Calculate_the_total_score()
    {

        //Calculate the total score based on marks obtained by student and percentage 
        int sum = 0; float Percentage;
        for (int i = 0; i < number_of_subjects; ++i)//let's take culc the sum of  marks 
        {
            sum += marks[i];
        }

        Percentage = (float(sum) / (number_of_subjects * 100)) * 100;

        //get the grade of the student 

        if (Percentage < 50) {
            grades = 'F';
        }
        else if ((Percentage >= 50) && (Percentage < 65)) {

            grades = 'D';
        }
        else if ((Percentage >= 65) && (Percentage < 75)) {

            grades = 'C';
        }
        else if ((Percentage >= 75) && (Percentage < 85)) {

            grades = 'B';
        }

        else {

            grades = 'A';
        }
        cout << name << " : " << grades << endl;

    }

    // the search can be made through:
      //  i)	student number

    void Search_for_certain_studentnumber(string num)
    {

        if (num == number) {
            int show;//give the user the option to see detail of student ,he search for
            cout << "the num is found" << endl; cout << "press 1 to see details or press any number to continou : ";
            cin >> show; if (show == 1) {
                //details printing
                cout << "the num is " << number << endl;
                cout << "the name is " << name << endl;
                cout << "department is " << department << endl;
                cout << "the city is " << address.city << endl;
                cout << "the residential area is " << address.residential_area << endl;
                cout << "the zip code area is " << address.zip_code << endl;
                //let's take the marks the loop depends on the number of subjects
                for (int j = 0; j < number_of_subjects; j++)
                    cout << marks[j] << endl;
            }
            //cheak that the grads has been calculated or not 
            if ((grades == 'A') || (grades == 'B') || (grades == 'C') || (grades == 'D') || (grades == 'F'))
                //print it if i was culculated
                cout << "the grade is " << grades << endl;
        }

    }
    // the search can be made through:
  //  ii) by student name as the user required

    void Search_for_certain_studentname(string names)
    {

        if (names == name)
        {
            int show;
            cout << "the name is found" << endl; cout << "press 1 to see details or press any number to continou : ";
            cin >> show; if (show == 1) {
                cout << "the num is " << number << endl;
                cout << "the name is " << name << endl;
                cout << "department is " << department << endl;
                cout << "the city is " << address.city << endl;
                cout << "the residential area is " << address.residential_area << endl;
                cout << "the zip code area is " << address.zip_code << endl;
                //let's take the marks the loop depends on the number of subjects
                for (int j = 0; j < number_of_subjects; j++)
                    cout << marks[j] << endl;
                //cheak that the grads has been calculated or not 
                if ((grades == 'A') || (grades == 'B') || (grades == 'C') || (grades == 'D') || (grades == 'F'))
                    //print it if i was culculated
                    cout << "the grade is " << grades << endl;
            }
        }

    }

    void insert()
    {
        //insert the new student details to the student in end of objects list

        cout << "insert the new student details" << endl;
        cout << "name: ";
        cin.ignore();
        getline(cin, name);
        cout << "number: "; cin >> number;
        cout << "department: "; cin.ignore();
        getline(cin, department);
        cout << "city: "; cin.ignore();
        getline(cin, address.city);
        cout << "residential area: "; cin.ignore();
        getline(cin, address.residential_area);
        cout << "zip code: "; cin.ignore();
        getline(cin, address.zip_code);
        cout << "number of subjects: "; cin >> number_of_subjects;
        //let's take the marks the loop depends on the number of subjects  
        for (int j = 0; j < number_of_subjects; j++)
            cin >> marks[j];
        cout << "insert completed" << endl;
        //be ready to insert an other object
        laststudent++;

    }


};//the end of the class

//declaration of objects of students
Student s1[maxmum_namber_of_students];


/*
The read function in this student report system has been used for this feature.
It basically shows the progress report of all the students added in file.
This function reads all information of the students, roll no., name, department, address and marks of all the students.
*/
//we conseder that all in formation on the same line 

void readfile()
{

    //reading file code
    string word;
    ifstream fin;
    fin.open("arraydata.txt");
    fin >> word; int i = 10; string ss;
    while (fin.good())//cheak if every thing in file is well
    {
        s1[i].number = word;
        //s1[i].number = atof(word);//transforming the string to integar
        fin >> word;//let's move to the next word
        s1[i].name = word;//save the frist name as string
        fin >> word;//let's move to the next word
        s1[i].name = s1[i].name + " " + word;//save full the name of student as string
        fin >> word;
        s1[i].department = word;//save the department as string
        fin >> word;//let's move to the next word
        s1[i].address.city = word;//save the name as string
        fin >> word;//let's move to the next word
        s1[i].address.residential_area = word;
        fin >> word;//let's move to the next word
        s1[i].address.zip_code = word;//save the name as string
        fin >> word;//let's move to the next word
        // convert a string into an integer
        ss = word;
        istringstream convert1(ss);
        convert1 >> s1[i].number_of_subjects;

        for (int j = 0; j <= s1[i].number_of_subjects; j++)//let's take the marks the loop depends on the number of subjects
        {
            fin >> word;
            // convert a string into an integer
            ss = word;
            istringstream convert2(ss);
            convert2 >> s1[i].marks[j];
        }
        i++;
    }
    cout << "all file has been read" << endl;

    //last student will save the place of after the last object
    laststudent = i;

}




int main()
{
    for (int i = 0; i < 10; i++)s1[laststudent].insert();
    //reading the text file
    readfile();

    // the body of the program
    int choice;
    while (true)
    {
        //The menu asked the user for an option

        cout << "press 1 to insert a student into the system" << endl;
        cout << "press 2 to search for a student via their id number or via their name" << endl;
        cout << "press 3 to edit student details again finding student must be done via their id number" << endl;
        cout << "press 4 to calculate the total score and get grade of the student" << endl;
        cout << "press 5 to print student information " << endl;
        cout << "enter your choice: ";
    a: cin >> choice; if (choice > 5) { cout << "Enter a num bettween 1-5 " << endl; goto a; }

        //using switch statement to choice  an option
        switch (choice)
        {
        case 5:
            for (int i = 0; i < laststudent; i++)
                s1[i].Display_students_grade_report();
            break;
        case 3:
        {int i;
        string n;
        cout << "enter the name of the student you want to modify his data" << endl;
        cin.ignore();
        getline(cin, n);
        for (i = 0; i < laststudent; i++)
        {
            if (n == s1[i].name)
                break;//if you found the name go to the next statment 
        }
        //if the program break the last loop ,it can go through this statment
        if (i < laststudent)
            s1[i].Modify_students_report();
        //if not that mean this record is not found on the database
        else cout << "record not found" << endl;
        break;

        }
        case 4:
            for (int i = 0; i < laststudent; i++)
                s1[i].Calculate_the_total_score();
            cout << "the grades is calculated" << endl;;

            break;
            int option;
        case 2:
            //choice  an option to search with 
            cout << "search for student by" << endl;
            cout << "1-> student number " << endl;
            cout << "2->  student name " << endl;
        b:  cin >> option; if (option > 2) { cout << "Enter 1 or 2 " << endl; goto b; }
            if (option == 1)
            {//search by number
                string num; cout << "number : "; cin >> num;
                for (int i = 0; i < laststudent; i++)
                    s1[i].Search_for_certain_studentnumber(num);
            }
            if (option == 2) {
                //search by name
                cout << "name: " << endl;
                string name;
                cin.ignore();
                getline(cin, name);
                for (int i = 0; i < laststudent; i++)
                    s1[i].Search_for_certain_studentname(name);
            }

            break;
        case 1:
            s1[laststudent].insert();
            break;
        }

    }
}