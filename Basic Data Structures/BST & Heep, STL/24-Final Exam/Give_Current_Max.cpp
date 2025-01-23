#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;

    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->marks = marks;
        this->roll = roll;
    }
};

class compare
{
public:
    bool operator()(Student left, Student right)
    {
        return left.marks == right.marks ? left.roll > right.roll : left.marks < right.marks;
    }
};

int main()
{
    int t, roll, marks;
    string name;
    cin >> t;
    priority_queue<Student, vector<Student>, compare> pq;

    while (t--)
    {
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }

    cin >> t;

    while (t--)
    {
        cin >> roll;

        if (roll == 0)
        {
            cin >> name >> roll >> marks;
            Student obj(name, roll, marks);
            pq.push(obj);
            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        }
        else if (roll == 1)
        {
            if (pq.empty())
                cout << "Empty" << endl;
            else
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        }
        else
        {
            if (pq.empty())
                cout << "Empty" << endl;
            else
            {
                pq.pop();

                if (pq.empty())
                    cout << "Empty" << endl;
                else
                    cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
            }
        }
    }

    return 0;
}