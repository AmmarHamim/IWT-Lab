#include<bits/stdc++.h>
using namespace std;
struct Student
{
    int id;
    string name;
};
void display(Student* ptr)
{
    cout<<ptr->id<<endl;
    cout<<ptr->name<<endl;
}
int main()
{
    Student s;
    cin>>s.id;
    cin>>s.name;

    Student* ptr=&s;
    display(ptr);
    return 0;
}