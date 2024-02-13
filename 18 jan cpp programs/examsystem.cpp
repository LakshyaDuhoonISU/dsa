//exam system registration program
#include <iostream>
#include <limits>
using namespace std;

struct Exam
{
    int rollno;
    string name, subjects[5];
    float marks[5];
};

bool fail(float *ptr)
{
    return *ptr < 40;
}

int main()
{
    cout << "Welcome to Exam Enrollment System!" << endl;
    int n, c;
    bool present = false, exams = false, b;
    Exam arr[100];

    // Loop to check if roll number already exists
    for (int i = 0; i < 100; i++)
    {
        cout << "Enter roll no: ";
        cin >> n;

        if (arr[i].rollno == n)
        {
            cout << "Already registered!" << endl;
            present = true;
            break;
        }
        else
        {
            arr[i].rollno = n;
            cout << "Enter name: ";
            cin >> arr[i].name;
            break; // Remove the break statement to allow multiple registrations
        }
    }

    while (true)
    {
        cout << "1. Enroll For Exam" << endl
             << "2. Marks Entry" << endl
             << "3. Exit" << endl;
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "1. Regular Exam" << endl
                 << "2. Re Exam" << endl;
            int d;
            cin >> d;

            // Use a different loop variable for indexing
            switch (d)
            {
            case 1:
                // Enrollment for Regular Exam
                for (int i = 0; i < 5; i++)
                {
                    cout << "Enter subject name: ";
                    cin >> arr[n].subjects[i];
                }
                present = true;
                break;

            case 2:
                // Enrollment for Re Exam
                if (exams)
                {
                    cout << "Re Exam" << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        if (arr[n].marks[i] < 40)
                        {
                            cout << arr[n].subjects[i] << endl;
                        }
                    }
                }
                else
                {
                    cout << "Not given any exam yet" << endl;
                }
                break;

            default:
                cout << "Invalid option" << endl;
                break;
            }
            break;

        case 2:
            cout << "1. Regular Marks Entry" << endl
                 << "2. Re exam Marks Entry" << endl;
            int z;
            cin >> z;

            switch (z)
            {
            case 1:
                // Marks Entry for Regular Exam
                if (present)
                {
                    cout << "Regular Marks Entry" << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << "Enter marks of " << arr[n].subjects[i] << ": ";
                        cin >> arr[n].marks[i];

                        // Input validation for marks
                        while (cin.fail() || arr[n].marks[i] < 0 || arr[n].marks[i] > 100)
                        {
                            cout << "Invalid input. Please enter a valid mark between 0 and 100." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Enter marks of " << arr[n].subjects[i] << ": ";
                            cin >> arr[n].marks[i];
                        }
                    }
                    exams = true;
                    for (int i = 0; i < 5; i++)
                    {
                        b = fail(&arr[n].marks[i]);
                        if (b)
                        {
                            break;
                        }
                    }
                }
                break;

            case 2:
                // Marks Entry for Re Exam
                if (exams)
                {
                    if (b)
                    {
                        cout << "Re exam marks entry" << endl;
                        for (int i = 0; i < 5; i++)
                        {
                            if (arr[n].marks[i] < 40)
                            {
                                cout << arr[n].subjects[i] << ": ";
                                cin >> arr[n].marks[i];
                            }

                            // Input validation for marks
                            while (cin.fail() || arr[n].marks[i] < 0 || arr[n].marks[i] > 100)
                            {
                                cout << "Invalid input. Please enter a valid mark between 0 and 100." << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << arr[n].subjects[i] << ": ";
                                cin >> arr[n].marks[i];
                            }
                        }
                    }
                    else
                    {
                        cout << "No exams failed" << endl;
                    }
                }
                else
                {
                    cout << "Not given exam yet" << endl;
                }
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
            }
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
    return 0;
}