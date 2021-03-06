#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    protected:
        int age;
        string name;
    public:
        virtual void getdata()=0;
        virtual void putdata()=0;
};

class Professor: public Person{
    static int ID;
    int publications;
    int cur_id;
    public:
        Professor(){
            cur_id = ID++;
        }
        void getdata(){
            cin >> name >> age >> publications;
        }
        void putdata(){
            cout << name <<' '<< age <<' '<< publications <<' '<< cur_id << '\n';
        }
};

int Professor::ID = 1;

class Student: public Person{
    static int ID;
    int marks[6];
    int cur_id;
    int sum(){
        int result=0;
        for(int i =0; i<6; i++){
            result+=marks[i];
        }
        return result;
    }
    public:
        Student(){
            cur_id=ID++;
        }
        void getdata(){
            cin >> name >> age;
            for(int i=0; i<6; i++){
                cin >> marks[i];
            }
        }
        void putdata(){
            cout << name <<' '<< age <<' '<< sum() <<' '<< cur_id << '\n';
        }
};

int Student::ID=1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
