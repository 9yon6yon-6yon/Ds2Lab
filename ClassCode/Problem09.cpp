#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct person
{
    string name;
    int age;
    int height;
};

bool compare (person a, person b)
{
    if(a.height==b.height) a.age>b.age;
    else a.height>b.height;
}

int main()
{
    int number;
    cin>>number; ///user input | number of people

    struct person people[number]; ///declare an array of structure

    for(int i=0; i<number; i++) ///taking the inputs of individual person
    {
        cin.ignore();
        getline(cin,people[i].name);
        //cin>>people[i].name;
        cin>>people[i].age;
        cin>>people[i].height;
    }

    /// bubble sort, insertion sort, selection sort
    sort(people,people+(number),compare);

    for(int i=0; i<number; i++) /// Print the structure
    {
        cout<<people[i].name<<" ";
        cout<<people[i].age<< " ";
        cout<<people[i].height;
        cout<<endl;
    }

    return 0;
}
