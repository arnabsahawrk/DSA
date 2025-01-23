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

class compare // priority queue work with class
{
public:
    bool operator()(Student left, Student right) // operator mandatory to use
    {
        return left.marks == right.marks ? left.roll > right.roll : left.marks < right.marks;
    }
};

int main()
{
    priority_queue<Student, vector<Student>, compare> pq;

    string name;
    int roll, marks;
    while (cin >> name >> roll >> marks)
    {
        Student obj(name, roll, marks);
        pq.push(obj);
    }

    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}