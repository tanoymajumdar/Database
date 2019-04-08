#include<iostream>
#include<string>
#include<algorithm>
#include "database.h"
bool Database::add_profile(string id, string n, string p)
{
    vector<Profile>::iterator prof_itr;
    for ( prof_itr=prof.begin(); prof_itr!=prof.end(); prof_itr++ )
    {
        if ( (*prof_itr).studentID == id )
        {
            (*prof_itr).name = n;
            (*prof_itr).phoneNumber = p;
            cout<< "Profile Updated"<<endl;
            return true;
        }
    }
    Profile pro;
    pro.studentID = id;
    pro.name = n;
    pro.phoneNumber = p;
    prof.push_back(pro);
    return true;
}

bool Database::add_grade(string id, string cid, double m)
{
    vector<Grade>::iterator grad_itr;
    vector<Profile>::iterator prof_itr;
    for ( prof_itr=prof.begin(); prof_itr!=prof.end(); prof_itr++ )
    {
        if ((*prof_itr).studentID == id )
        {
            for ( grad_itr=grad.begin(); grad_itr!=grad.end(); grad_itr++ )
            {
                if ( (*grad_itr).studentID == id && (*grad_itr).classID == cid )
                {
                    (*grad_itr).mark = m;
                    cout<<"Grade Updated"<<endl;
                    return true;
                }
            }
            Grade g;
            g.studentID = id;
            g.classID = cid;
            g.mark = m;
            grad.push_back(g);
            return true;
        }
    }
    cout<<"Student Not Exists"<<endl;
    return false;
}

bool Database::del_grade( string id, string cid)
{
    vector<Grade>::iterator grad_itr=grad.begin();
    vector<Profile>::iterator prof_itr;
    for ( prof_itr=prof.begin(); prof_itr!=prof.end(); prof_itr++ )
    {
        if ( (*grad_itr).studentID == id && (*grad_itr).classID == cid )
        {
            grad.erase(grad_itr);
            return true;
        }
    }
    cout<<"Record Not Exists"<<endl;
    return false;
}

bool Database::del_profile( string id )
{
    vector<Profile>::iterator prof_itr;
    vector<Grade>::iterator grad_itr;
    for ( prof_itr=prof.begin(); prof_itr!=prof.end(); prof_itr++ )
    {
        if ( (*prof_itr).studentID == id )
        {
            for ( grad_itr=grad.begin(); grad_itr!=grad.end(); grad_itr++ )
            {
                grad.erase(grad_itr);
            }
            prof.erase(prof_itr);
            return true;
        }
    }
    cout<<"Record Not Exists"<<endl;
    return false;
}


void Database::display_profiles()
{
    vector<Profile>::iterator prof_itr;
    sort ( prof.begin(), prof.end() );
    for ( prof_itr=prof.begin(); prof_itr!=prof.end(); prof_itr++ )
    {
        cout<<(*prof_itr).name<<" "<<(*prof_itr).studentID<< " "<<(*prof_itr).phoneNumber<<endl;
    }
}

bool operator< (const Grade &a, const Grade &b)
{
    return a.mark < b.mark;
}
bool operator<(const Profile &a, const Profile &b)
{
    return a.name < b.name;
}
void Database::display_grades( string cid )
{
 int max=0;
 int min=100;
 int sum=0;
 int avg=0;
 int count=0;
 string name;
 vector<Grade>::iterator grad_itr;
 sort(grad.begin(), grad.end());
 for ( grad_itr=grad.begin(); grad_itr!=grad.end(); grad_itr++ )
 {
     if ( (*grad_itr).classID == cid )
     {
         sum = sum +(*grad_itr).mark;
         count++;
         if ( (*grad_itr).mark > max )
         {
             max = (*grad_itr).mark;
         }
         if ( (*grad_itr).mark < min)
         {
             min = (*grad_itr).mark;
         }
         vector<Profile>::iterator prof_itr;
         for ( prof_itr=prof.begin(); prof_itr!=prof.end(); prof_itr++ )
         {
             if ( (*prof_itr).studentID == (*grad_itr).studentID )
             {
               name = (*prof_itr).name;  
             }
         }
         cout<< name <<" " << (*grad_itr).studentID  << " "<< (*grad_itr).mark <<endl;
     }
 }
 avg=sum/count;
 cout<< "Min" << " " << min << endl;
 cout<< "Max" << " " << max <<endl;
 cout<< "Average" << " " << avg << endl;
 
}





