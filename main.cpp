#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;

void write2file(int semester[],string course[],int courseunit[],string agrade[],float grade[],float GPA[],float CGPA[],string CommentGPA[],string CommentCGPA[],string nomatric,string name,int i);
void gettext(string& nomatric,string& name,int nocourse[],int totalunit[],int semester[],string course[],int courseunit[],string agrade[],float grade[],float GPA[],float CGPA[],string line,int& i,int noline);
bool checksame(const string course[],const string C,const int i);
bool checkforalpha(const string X);
bool checkfordigit(const string X);
bool checkcourse(const string X);
bool arrangementofsem(const int semester[],const int i);
float AGtoG(string AG);
string comment(const double GPA);

int main()
{
    string filename;
    cout<<"Please key in your filename: ";
    getline(cin,filename);
    if (filename.find(".txt"))                              //Check whether have .txt at the back.
        filename.insert(filename.length(),".txt");
    ifstream readfile("error.dat");
    if (!readfile)
        cout<<"Your File is not found!";
    else
    {
        string nomatric="No matric no.";
        string name="No name";
        int  semester[60]={};
        string course[60]={};
        int courseunit[60]={};
        string agrade[60]={};
        float grade[60]={};
        float GPA[10]={};
        string CommentGPA[10];
        int totalunit[10]={};
        int nocourse[10]={};
        float CGPA[10]={};
        string CommentCGPA[10];
        float TotalUnitCGPA[10]={};
        string line;
        int i=0;
        int noline=1;
        while(!readfile.eof()) //Get line until end of file
        {
            getline(readfile,line);
            gettext(nomatric,name,nocourse,totalunit,semester,course,courseunit,agrade,grade,GPA,CGPA,line,i,noline);
            noline++;
        }
        readfile.close();
        for(int j=0;j<=(semester[i-1]-1);j++) //calculate GPA and CGPA for each semester.
        {
            if (totalunit[j]==0) //if not taking course and  because the dividend cannot be zero.
                {
                    GPA[j]=0;
                    if(j!=0) //check if first semester.
                        CGPA[j]=CGPA[j-1];  //since there is no course in this semester then the CGPA is the same as last semester.
                    else
                        CGPA[j]=0;  //first semester no course means zero CGPA.
                 }
            else
            {
                CGPA[9]+=GPA[j];    //adding sum of  grade*course unit for each semester
                TotalUnitCGPA[9]+=totalunit[j]; //adding total course unit for each semester
                GPA[j]=round((GPA[j]/totalunit[j])*100)/100; //round off the answer from the division of sum of  grade*course unit/total course unit to 2 decimal place
                CGPA[j]=round((CGPA[9]/TotalUnitCGPA[9])*100)/100;  //round off the answer from the division of sum of  grade*course unit/total course unit to 2 decimal place
            }
            CommentGPA[j]=comment(GPA[j]);  //Give comment for each semester
            CommentCGPA[j]=comment(CGPA[j]); //Give comment for each semester
        }
        cout<<"Calculating finished"<<endl;
        write2file(semester,course,courseunit,agrade,grade,GPA,CGPA,CommentGPA,CommentCGPA,nomatric,name,i);
        system("Pause");
    }
}

void write2file(int semester[],string course[],int courseunit[],string agrade[],float grade[],float GPA[],float CGPA[],string CommentGPA[],string CommentCGPA[],string nomatric,string name,int i)
{
    ofstream writefile ("result.txt",ios::trunc);
    writefile<<left;
    cout<<left;
    writefile<<setw(20)<< "Student's Name"<<": "<<name<<endl; //showing name and matric number
    cout<<endl<<setw(20)<< "Student's Name"<<": "<<name<<endl;
    writefile<<setw(20)<<"Matric Nunber "<<": "<< nomatric<<endl;
    cout<<setw(20)<<"Matric Nunber "<<": "<< nomatric<<endl;
    writefile<<right<<showpoint;
    cout<<right<<showpoint;
    writefile.precision(3); //fix to 2 decimal place.
    cout.precision(3);
    writefile<<"| Semester |"<<' '<<"| Course |"<<' '<<"|Course Unit|"<<' '<<"|Grade|"<<' '<<"|Grade|"<<endl; //showing the table of grades.
    cout<<"| Semester |"<<' '<<"| Course |"<<' '<<"|Course Unit|"<<' '<<"|Grade|"<<' '<<"|Grade|"<<endl;
    int z=1;
    for (int j=0;j<i;j++)
        {
            if(semester[j]==z)
            {
                writefile<<'|'<<right<<setw(6)<<semester[j]<<setw(7)<<"| |"<<setw(7)<<course[j]<<setw(4)<<"| |"<<setw(6)<<courseunit[j]<<setw(8)<<"| |"<<setw(3)<<agrade[j]<<setw(5)<<"| |"<<setw(5)<<grade[j]<<'|'<<endl;
                cout<<'|'<<right<<setw(6)<<semester[j]<<setw(7)<<"| |"<<setw(7)<<course[j]<<setw(4)<<"| |"<<setw(6)<<courseunit[j]<<setw(8)<<"| |"<<setw(3)<<agrade[j]<<setw(5)<<"| |"<<setw(5)<<grade[j]<<'|'<<endl;
            }
            if (semester[j+1]!=z)   //look ahead for next semester for next line.If it is then print out the GPA and CGPA.
                {
                    writefile<<endl<<"GPA for Semester "<< z <<setw(13)<<"  : "<<GPA[z-1]<<endl;
                    cout<<endl<<"GPA for Semester "<< z <<setw(13)<<"  : "<<GPA[z-1]<<endl;
                    writefile<<"Comment GPA for Semester "<< z <<setw(5)<<"  : "<< CommentGPA[z-1]<<endl;
                    cout<<"Comment GPA for Semester "<< z <<setw(5)<<"  : "<< CommentGPA[z-1]<<endl;
                    writefile<<"CGPA for Semester "<< z <<setw(12)<<"  : "<<CGPA[z-1]<<endl;
                    cout<<"CGPA for Semester "<< z <<setw(12)<<"  : "<<CGPA[z-1]<<endl;
                    writefile<<"Comment CGPA for Semester "<< z <<"  : "<< CommentCGPA[z-1]<<endl<<endl;
                    cout<<"Comment CGPA for Semester "<< z <<"  : "<< CommentCGPA[z-1]<<endl<<endl;
                    z++;
                    if(semester[j]!=(z-1)) //for skipping semester to include back this line.
                        j--;
                    if(!((j+1)>=(i-1))) //if not end of array
                    {
                    writefile<<"| Semester |"<<' '<<"| Course |"<<' '<<"|Course Unit|"<<' '<<"|Grade|"<<' '<<"|Grade|"<<endl;
                    cout<<"| Semester |"<<' '<<"| Course |"<<' '<<"|Course Unit|"<<' '<<"|Grade|"<<' '<<"|Grade|"<<endl;
                    }
                }
            }
}

void gettext(string& nomatric,string& name,int nocourse[],int totalunit[],int semester[],string course[],int courseunit[],string agrade[],float grade[],float GPA[],float CGPA[],string line,int& i,int noline)
{
    stringstream ss;
    string S,C,CU,AG,extra;
    ss.str(line);
    ss>>S>>C>>CU>>AG>>extra;
    if(checkfordigit(S))    //checking first strings is digit or not.
       {
           semester[i]=stoi(S);//casting the semester to int.
           if(semester[i]>0)    //check is positive or not
           {
                if(S.length()==6) //checking it is matric number or not
                    if(checkforalpha(C))    //Checking it is name or not
                        {
                            ss.str(line);
                            ss.clear();
                            getline(ss,nomatric,' ');
                            getline(ss,name);
                            cout<< "no matric and name get!"<<endl;
                            return;
                        }
                if(semester[i]<=10)     //limit semester to 10
                    if(checkfordigit(CU)) //check is digit or not
                    {
                        courseunit[i]=stoi(CU); //casting the course unit into int
                        if (courseunit[i]>0)    //check is positive or not
                            if(arrangementofsem(semester,i))    //check for the arrangement where 1,...,1,2,...,2,...,3,... are valid.
                                if (AGtoG(AG)!=-1) //check for the format of alphabet grade.
                                    if(extra.length()==0) //check for extra char after alphabet grade.
                                        if(nocourse[semester[i]-1]<6)   //limit 6 course for each semester
                                            if(C.length()==6)   //check course length
                                                if(checkcourse(C)) //check course format (XXXYYY)where X is alphabet and Y is Number
                                                    if(!checksame(course,C,i))  //check for repeated course
                                                    {
                                                        course[i]=C;
                                                        agrade[i]=AG;
                                                        grade[i]=AGtoG(AG);
                                                        GPA[semester[i]-1]+=grade[i]*courseunit[i];
                                                        totalunit[semester[i]-1]+=courseunit[i];
                                                        nocourse[semester[i]-1]++;
                                                        i++;
                                                        cout<<"Valid line "<<left<<setw(3)<<noline<<": "<<line<<endl;
                                                        return ;
                                                    }
                    }
           }
       }
        if (S.length()==0&&C.length()==0) //for empty string the length of it is 0.
            return;     //skip empty line
    cout<<"Invalid line "<<left<<setw(3)<<noline<<": "<<line<<endl;
    return;
}

bool checksame(const string course[],const string C,const int i)
{
    for (int k=0;k<=i;k++)          //search through all array to find for the same course
               if(course[k]==C)
                   return true;
        return false;
}

bool checkcourse(const string X)    // to check for first three char is alphabet and last three char is digit.
{
    char str[X.length()];
    for(unsigned int i=0;i<X.length();i++)  //change the string into array of char because isaphla and isdigit accept char.
        str[i]=X[i];
    for(unsigned int i=0;i<X.length()/2;i++) //check from front and back of the str.
            if(!isalpha(str[i])||!isdigit(str[X.length()-1-i]))
                    return false;
    return  true;
}

bool checkforalpha(const string X)
{
    char str[X.length()];
    for (unsigned int j =0;j<X.length();j++)    //change the string into array of char because isaphla accept char.
        str[j]=X[j];
    for (unsigned int i =0;i<X.length();i++)   //check one by one.
        if (!isalpha(str[i]))   //check for alphabet
            return false;
    return true;
}

bool arrangementofsem(const int semester[],const int i)
{
    if(i==0)    //for first line.
        if(semester[i]>=1)
            return true;
    if(semester[i]>=semester[i-1]) //for second line and onward.
        return true;
    return false;
}

bool checkfordigit(const string X)
{
    char str[X.length()];
    for (unsigned int j =0;j<X.length();j++)    //change the string into array of char because isdigit accept char.
        str[j]=X[j];
    for (unsigned int i =0;i<X.length();i++)   //check one by one.
    {
        if (!isdigit(str[i]))   //check for digit
            return false;
    }
    return true;
}

float AGtoG(string AG)
{
    if (AG=="A")
        return 4.00;
    else if(AG=="A-")
        return 3.67;
    else if (AG=="B+")
        return 3.33;
    else if (AG=="B")
        return 3.00;
    else if(AG=="B-")
        return 2.67;
    else if(AG=="C+")
        return 2.33;
    else if(AG=="C")
        return 2.00;
    else if (AG=="C-")
        return 1.67;
    else if(AG=="D+")
        return 1.33;
    else if (AG=="D")
        return 1.00;
    else if (AG=="D-")
        return 0.67;
    else if(AG=="F")
        return 0.00;
    else
        return -1;
}

string comment(const double GPA)
{
    if (GPA<2.24)
        return "Work Harder";
    else if (GPA<2.75)
        return "Work Smart";
    else if (GPA<3.25)
        return "Good";
    else if (GPA<3.75)
        return "Very Good";
    else
        return "Excellent";
}
