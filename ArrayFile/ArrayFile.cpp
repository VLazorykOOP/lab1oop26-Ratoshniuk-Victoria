#include <iostream>
using namespace std;

const int MAX = 200;


void task1()
{
    int A[MAX];
    int N, i, nB = 0;

    cout << "Enter size of array N: ";
    cin >> N;

    for (i = 0; i < N; i++)
    {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    cout << "Array without positive elements:\n";

    for (i = 0; i < N; i++)
    {
        if (A[i] <= 0)
            cout << A[i] << "\t";
    }

    cout << endl;
}



void task2()
{
    int* A;
    int N, i;
    int minPos;
    bool found = false;
    int index = -1;

    cout << "Enter size of array N: ";
    cin >> N;

    A = new int[N];

    for (i = 0; i < N; i++)
    {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }


    for (i = 0; i < N; i++)
    {
        if (A[i] % 2 == 0)
        {
            index = i;
            break;
        }
    }


    if (index == -1)
    {
        cout << "No element divisible by 2 found\n";
        delete[] A;
        return;
    }


    for (i = index + 1; i < N; i++)
    {
        if (A[i] > 0)
        {
            if (!found || A[i] < minPos)
            {
                minPos = A[i];
                found = true;
            }
        }
    }

    if (found)
        cout << "Minimum positive element = " << minPos << endl;
    else
        cout << "No positive elements after first divisible by 2\n";

    delete[] A;
}

void task3()
{
    int A[MAX], B[MAX];
    int N;
    int i, j, k;
    int nB = 0;
    bool repeated;

    cout << "Enter size of array N: ";
    cin >> N;

    for (i = 0; i < N; i++)
    {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    for (i = 0; i < N; i++)
    {
        repeated = false;

        for (j = 0; j < N; j++)
        {
            if (i != j && A[i] == A[j])
                repeated = true;
        }

        if (repeated)
        {
            bool exist = false;

            for (k = 0; k < nB; k++)
                if (B[k] == A[i])
                    exist = true;

            if (!exist)
                B[nB++] = A[i];
        }
    }

    cout << "Repeated elements:\n";

    for (i = 0; i < nB; i++)
    {
        cout << B[i] << "\t";
        if ((i + 1) % 5 == 0)
            cout << endl;
    }

    cout << endl;
}



int main()
{  
    int choice;

    do {
        cout << "\nMENU\n";
        cout << "1 - Task 1\n";
        cout << "2 - Task 2\n";
        cout << "3 - Task 3\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: cout << "Exit program\n"; break;
        default: cout << "Wrong choice\n";
        }

    } while (choice != 0);

    return 0;
}           