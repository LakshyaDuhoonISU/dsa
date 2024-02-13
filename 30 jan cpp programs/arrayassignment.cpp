// 2d array(matrix) program
// 5 subjects 10 students(2d array) >40-pass else fail, print subject-wise results(pass and fail %age) and subject topper
// student wise- subject marks, total marks(out of 500) and %age
#include <iostream>
using namespace std;

void subjectWise(int result[5][10])
{
    for (int i = 0; i < 5; i++)
    {
        int topperIndex = 0;
        int pass = 0, fail = 0;
        for (int j = 0; j < 10; j++)
        {
            if (result[i][j] > 40)
            {
                pass++;
            }
            else
            {
                fail++;
            }
            if (result[i][j] > result[i][topperIndex])
            {
                topperIndex = j;
            }
        }
        cout << endl
             << "Passing Percentage for subject " << i + 1 << " : " << (pass * 10) << "%" << endl;
        cout << "Failing Percentage for subject " << i + 1 << " : " << (fail * 10) << "%" << endl;
        cout << "Topper of subject " << i + 1 << " (Student " << topperIndex + 1 << ") : " << result[i][topperIndex] << endl
             << endl;
    }
}

void studentWise(int result[5][10])
{
    for (int j = 0; j < 10; j++)
    {
        int total = 0;
        for (int i = 0; i < 5; i++)
        {
            cout << "Marks of subject " << i + 1 << " for Student " << j + 1 << " : " << result[i][j] << endl;
            total += result[i][j];
        }
        cout << endl
             << "Total marks (out of 500) for Student " << j + 1 << " : " << total << endl;
        cout << "Percentage for Student " << j + 1 << " : " << (total / 5) << "%" << endl
             << endl;
    }
}

int main()
{
    char ans='y';
    int result[5][10];
    while (ans=='y')
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter marks for subject: " << i + 1 << endl;
            for (int j = 0; j < 10; j++)
            {
                cout << "Enter marks for student: " << j + 1 << endl;
                cin >> result[i][j];
            }
        }
        cout << "\nSubject-wise Statistics:\n";
        subjectWise(result);
        cout << "\nStudent-wise Statistics:\n";
        studentWise(result);
        cout<<"Want to enter more marks?(y/n): ";
        cin>>ans;
    }
    return 0;
}