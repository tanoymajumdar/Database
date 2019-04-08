#ifndef DATABASE_H
#define DATABASE_H

#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef struct profile_t
{
    string studentID;
    string name;
    string phoneNumber; 
}Profile;
typedef struct grade_t
{
    string studentID;
    string classID;
    double mark;
}Grade;
class Database
{
    private:
    vector<Profile> prof;
    vector<Grade> grad;
    
    public:
    bool add_profile(string id, string name, string phone);
    bool del_profile(string id);
    bool add_grade(string id, string class_id, double grade);
    bool del_grade(string id, string class_id);
    
    //Display data
    void display_profiles();
    void display_grades(string class_id);
};
#endif