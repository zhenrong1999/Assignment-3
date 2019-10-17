#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class ad
{
private:
  string *course,*grade;
  int *nomatric,*cu;
  int ma;
public:
  ad(){}
  ad(int matric[],string Coursein[],int CUin[],string Gradein[],int size)
  {
    nomatric = new int [size];
    course = new string [size];
    grade = new string [size];
    cu = new int [size];
    for(int i=0;i<size;i++)
    {
      nomatric[i]=matric[i];
      course[i]=Coursein[i];
      grade[i]=Gradein[i];
      cu[i]=CUin[i];
    }
  }

    void change (int matric,string Coursein[],int CUin[],string Gradein[],int size)
    {
      ma = matric;
      course = new string [size];
      grade = new string [size];
      cu = new int [size];
      for(int i=0;i<size;i++)
      {
        course[i]=Coursein[i];
        grade[i]=Gradein[i];
        cu[i]=CUin[i];
      }
  }
};

void readline(string line,string course[],string grade[],int cu[],int &i,ad stu[],int &nostu,int nomatric[]);
int main ()
{
ifstream readf("file3.txt"); //read file function
    if (!readf)
        cout<<"Fail to read file";
    else
        {
                string line;
                string course[100],grade[100];
                int nomatric[100],cu[100];
                int i=0;
                ad stu[10];
                int nostu=0;
                while(!readf.eof()) //start reading
                {
                getline(readf,line);
                readline(line,course,grade,cu,i,stu,nostu,nomatric);
                i++;
                }
                cout<<" sucess..."<<endl; //read finished
        }
}

void readline(string line,string course[],string grade[],int cu[],int &i,ad stu[],int &nostu,int nomatric[])
{
  int x;
    stringstream readl; //let the string like cout and cin
    readl.str(line); //set line as the read
    readl>>x;
    if (x!=nomatric[i-1])
    {
      stu[nostu].change(nomatric[i-1],course,cu,grade,i);
      nostu++;
      i=0;
    }
    nomatric[i]=x;
    readl>>course[i]>>cu[i]>>grade[i];
    cout<<nomatric[i]<<course[i]<<cu[i]<<grade[i]<<endl;
}
