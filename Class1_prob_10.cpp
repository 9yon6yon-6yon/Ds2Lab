#include <bits/stdc++.h>

using namespace std;

struct person
{
    string name_s;
    int id_s;
    int salary_s;
};
bool mycomp_dsc(person a, person b)
{
    if (a.salary_s == b.salary_s)
        return a.id_s > b.id_s;

    else
        return a.salary_s > b.salary_s;
}
bool mycomp_asc(person a, person b)
{
    if (a.salary_s == b.salary_s)
        return a.id_s < b.id_s;

    else
        return a.salary_s < b.salary_s;
}
int main()
{
    int n;
    cout << "Enter number of inputs" << endl;
    cin >> n;
    struct person people[n];

    string name[n];
    int id[n];
    int slary[n];
    cout << "Enter names " << endl;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {

        getline(cin, name[i]);
        people[i].name_s = name[i];
    }
    cout << "Enter id  " << endl;

    for (int i = 0; i < n; i++)
    {

        cin >> id[i];
        people[i].id_s = id[i];
    }
    cout << "Enter salary" << endl;

    for (int i = 0; i < n; i++)
    {

        cin >> slary[i];
        people[i].salary_s = slary[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Name " << name[i] << "\tId " << id[i] << "\tSalary" << slary[i] << endl;
    // }
    cout << "Printing using structure descending order" << endl;

    sort(people, people + n, mycomp_dsc);

    for (int i = 0; i < n; i++)
    {
        cout << people[i].name_s << "\t";
        cout << people[i].id_s << "\t";
        cout << people[i].salary_s << "\t";
        cout << " " << endl;
    }
      cout << "Printing using structure ascending order" << endl;
     sort(people, people + n, mycomp_asc);

    for (int i = 0; i < n; i++)
    {
        cout << people[i].name_s << "\t";
        cout << people[i].id_s << "\t";
        cout << people[i].salary_s << "\t";
        cout << " " << endl;
    }

    return 0;
}