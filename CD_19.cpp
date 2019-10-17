#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

class academicStatus
//class that store GPA,CGPA,Status,Accumulated credit and MUET band. Have change function which change all variable(GPA,CGPA,Status,Accumulated credit and MUET band) at once.
{
private:
double gpa;
double cgpa;
string status;
int accumulatedCredit;
int muetBand;

public:
double getGpa();
double getCgpa();
string getStatus();
int getAccumulatedcredit();
int getMuetband();
void academics_set(string,string,string,string,string);
void displayData();
academicStatus();
~academicStatus();
};

double academicStatus::getGpa(){
	return gpa;
}

double academicStatus :: getCgpa(){
	return cgpa;
}

string academicStatus :: getStatus(){
	return status;
}

int academicStatus :: getAccumulatedcredit(){
	return accumulatedCredit;
}

int academicStatus :: getMuetband(){
	return muetBand;
}

academicStatus :: academicStatus(){
	//constructor function
	gpa=0;
	cgpa=0;
	status="";
	accumulatedCredit=0;
	muetBand=1;

}

void academicStatus :: academics_set(string studentGpa,string studentCgpa,string studentStatus,string studentAccumulatedcredit,string studentMuetband){
	//change or set all variable(GPA,CGPA,Status,Accumulated credit and MUET band) at once.
	gpa=stod(studentGpa);
	cgpa=stod(studentCgpa);
	status=studentStatus;
	accumulatedCredit=stoi(studentAccumulatedcredit);
	muetBand=stoi(studentMuetband);


}

academicStatus :: ~academicStatus(){
	//destructor function
	gpa=0;
	cgpa=0;
	status="";
	accumulatedCredit=0;
	muetBand=1;
}

void academicStatus :: displayData(){ // display fucntion for this academic status class
	cout<<"Gpa : "<<gpa<<endl;
	cout<<"Cgpa : " <<cgpa<<endl;
	cout<<"Status : "<<status<<endl;
	cout<<"Accumulated credit : "<<accumulatedCredit<<endl;
	cout<<"Muet band : "<<muetBand<<endl;
	cout<<endl<<endl;
}

class courselist
//class that store list of course,grade and course unit.Consist of change function which change all varible(course,grade and course unit) at once
{
private:
string *course,*grade,*cu;//cu is course unit.
int size_of_list=0;
public:



courselist(){
}
courselist(string Coursein[],string CUin[],string Gradein[],int size){
	course_set(Coursein, CUin, Gradein, size);
}

void course_set(string Coursein[],string CUin[],string Gradein[],int size)
{
	course = new string [size];
	grade = new string [size];
	cu = new string [size];
	size_of_list=size;
	for(int i=0; i<size; i++)
	{
		course[i]=Coursein[i];
		grade[i]=Gradein[i];
		cu[i]=CUin[i];
	}

}

float convertTonumber(string gradeOfcourse)//convert Alphabet to numeric //copy to courselist //add start here
{
	if (gradeOfcourse=="A"||gradeOfcourse=="a")
		return 4.00;
	else if(gradeOfcourse=="A-"||gradeOfcourse=="a-")
		return 3.67;
	else if (gradeOfcourse=="B+"||gradeOfcourse=="b+")
		return 3.33;
	else if (gradeOfcourse=="B"||gradeOfcourse=="b")
		return 3.00;
	else if(gradeOfcourse=="B-"||gradeOfcourse=="b-")
		return 2.67;
	else if(gradeOfcourse=="C+"||gradeOfcourse=="c+")
		return 2.33;
	else if(gradeOfcourse=="C"||gradeOfcourse=="c")
		return 2.00;
	else if (gradeOfcourse=="C-"||gradeOfcourse=="c-")
		return 1.67;
	else if(gradeOfcourse=="D+"||gradeOfcourse=="d+")
		return 1.33;
	else if (gradeOfcourse=="D"||gradeOfcourse=="d")
		return 1.00;
	else if (gradeOfcourse=="D-"||gradeOfcourse=="d-")
		return 0.67;
	else if(gradeOfcourse=="F"||gradeOfcourse=="f")
		return 0.00;
	else if(gradeOfcourse=="TL"||gradeOfcourse=="tl")
		return -2;
	else
		return -1;
}

double calculateGpa(){ //calculate gpa of the 6 courses

	int unit=0;
	double gpa=0;
	double processingGpa;

	for(int i=0; i<size_of_list; i++) {

		if(course[i]=="CPT111"||course[i]=="cpt111"||course[i]=="CST131"||course[i]=="cst131"||course[i]=="CPT113"||course[i]=="cpt113"||course[i]=="CMT221"||course[i]=="cmt221"||course[i]=="CMT222"||course[i]=="cmt222"||course[i]=="CAT200"||course[i]=="cat200") {
			processingGpa=convertTonumber(grade[i])*stoi(cu[i]);
			unit+=stoi(cu[i]);
			gpa+= processingGpa;

		}


	}

	gpa=gpa/unit;

	return gpa;
}



int getsizeoflist()
{
	return size_of_list;
}

string getcourse(int index_number)
{
	return course[index_number];
}

string getgrade(int index_number)
{
	return grade[index_number];
}

string getcourseunit(int index_number)
{
	return cu[index_number];
}

};

class profile : public academicStatus
{ //class that contain all student data(name,no.matric,gender,address,email and no. phone) and function that change the variable of all variable.
//class is derived from class academicStatus.
//class that composite with class Coursetable.
private:
string name;
string nomatric;
string gender;
string address;
string email;
string nophone;
courselist Coursetable;
friend void display_in_table(profile student);
friend void display_student_data(profile student);
public:
profile()
{
	name="empty";
	nomatric="0";
	gender="empty";
	address="empty";
	email="empty";
	nophone="empty";
}

profile(string Name, string Nomatric, string Gender, string Address, string Email, string NoPhone)
{
	change(Name,  Nomatric,  Gender,  Address,  Email,  NoPhone);
}
void change(string Name, string Nomatric, string Gender, string Address, string Email, string NoPhone) //function is used to add name,no. matric, gender, address, email and no. phone during data input via keyboard or files.
{
	name=Name;
	nomatric=Nomatric;
	gender=Gender;
	address=Address;
	email=Email;
	nophone=NoPhone;
}
void course_change(string Coursein[],string CUin[],string Gradein[],int size) //function that access to the function course_set in class courselist.
{
	Coursetable.course_set (Coursein, CUin, Gradein,  size);//function used to add in course, course unit and grade.
}

void changeNomatric(string Nomatric) //function that change only no. matric
{
	nomatric=Nomatric;
}

float callconvertTonumber(string validatingGrade){ //from main function call the function convertTonumber() from courselist
	return Coursetable.convertTonumber(validatingGrade);
}

double callcalculateGpa(){ //from main function call the function calculateGpa() from courselist

	return Coursetable.calculateGpa();
}

string getname()
{
	return name;
}
string getmatric()
{
	return nomatric;
}

string getgender()
{
	return gender;
}

string getaddress()
{
	return address;
}
string getemail()
{
	return email;
}
string getnophone()
{
	return nophone;
}

int getsizeoflist()
{
	return Coursetable.getsizeoflist();
}

string getcourse(int index_number)
{
	return Coursetable.getcourse(index_number);
}

string getgrade(int index_number)
{
	return Coursetable.getgrade(index_number);
}

string getcourseunit(int index_number)
{
	return Coursetable.getcourseunit(index_number);
}

};


//template class
template <class type>
int binarysearch(int begin,int end, type arr[],type search) //binary search is a search method used to search an object from an arry and give the index_number number of the object in the arry.
{
	int half;       // store the middle point of the beginning point and end point of the array
	bool finding=false;
	do
	{

		half=floor((end-begin)/2)+begin; //calculate the middle point.
		if(arr[half]==search)
		{
			finding=true;
			return half;
		}
		else if(search>arr[half])
		{
			begin=++half;
		}
		else if(search<arr[half])
		{
			end=half-1;
		}

		if(begin>=end)
		{
			finding=true;
		}
	} while(!finding);      //loop until find the searching item.
	return -1;
}

//user defined function

int menu_selector(int min_menu_no,int max_menu_no)
{
	int menu_selected;
	do
	{
		try
		{
			cin>>menu_selected;
		}
		catch(...)
		{
			cout<<"Your can't an alphabet."<<endl;
			cin.clear(); cin.ignore();
		}
		if(menu_selected<min_menu_no||menu_selected>max_menu_no)
		{
			cout<<"You can't input number less than "<<min_menu_no <<" and more than "<<max_menu_no<<endl;
			cin.clear(); cin.ignore();}
	} while(menu_selected<min_menu_no||menu_selected>max_menu_no);

	return menu_selected;
}

string stringintoupper(string input)    //convert string lowercase letter to uppercase letter
{
	stringstream input_as_stream;
	input_as_stream.str(input);
	char temp;
	string templower;
	string output="";
	int size_input=input.length();
	for (int i=0; i<size_input; i++)
	{
		input_as_stream>>temp;
		templower=toupper(temp);
		output.insert(output.length(),templower);
	}
	return output;
}

bool validation(profile student) //validate whether the respective student is qualified or not qualified
{
	if(student.getCgpa()>=2) //validate whether student's cgpa >2
		if(student.getAccumulatedcredit()>=60) //validate whether student's accumulated credit >60
			if(stringintoupper(student.getStatus())=="ACTIVE") //validate whether student's status is active
				if(student.getMuetband()>=4) //validate whether student's muet band >=4
					if(student.callcalculateGpa()>=2) //validate whether student's gpa >2
					{
						int no_of_required_course=0;    //store the number of valided required course.
						for(int i=0; i<student.getsizeoflist(); i++)
						{

							if(stringintoupper(student.getcourse(i))=="CPT111")       //check the student have the course CPT111
							{
								if(student.callconvertTonumber(student.getgrade(i))>=2)     //convert to number and check the student pass the course or not
								{no_of_required_course++;}
								else
								{return false;}
							}
							else if(stringintoupper(student.getcourse(i))=="CPT113")  //check the student have the course CPT113
							{
								if(student.callconvertTonumber(student.getgrade(i))>=2)//convert to number and check the student pass the course or not
								{no_of_required_course++;}
								else
								{return false;}
							}
							else if(stringintoupper(student.getcourse(i))=="CST131")  //check the student have the course CST131
							{
								if(student.callconvertTonumber(student.getgrade(i))>=2)//convert to number and check the student pass the course or not
								{no_of_required_course++;}
								else
								{return false;}
							}
							else if(stringintoupper(student.getcourse(i))=="CMT221")  //check the student have the course CMT221
							{
								if(student.callconvertTonumber(student.getgrade(i))>=2)//convert to number and check the student pass the course or not
								{no_of_required_course++;}
								else
								{return false;}
							}
							else if(stringintoupper(student.getcourse(i))=="CMT222")  //check the student have the course CMT222
							{
								if(student.callconvertTonumber(student.getgrade(i))>=2)//convert to number and check the student pass the course or not
								{no_of_required_course++;}
								else
								{return false;}
							}
							else if(stringintoupper(student.getcourse(i))=="CAT200")  //check the student have the course CAT200
							{
								if(student.callconvertTonumber(student.getgrade(i))>=2)//convert to number and check the student pass the course or not
								{no_of_required_course++;}
								else
								{return false;}
							}
							else if(stringintoupper(student.getcourse(i))=="CAT300")  //check the student have the course CAT300
							{
								if(student.callconvertTonumber(student.getgrade(i))==-2)//convert to number and check the student get the course.
								{no_of_required_course++;}
								else
								{return false;}
							}
						}
						if(no_of_required_course==7)
						{return true;} // if all requirement are true, return true
					}

	return false; // if 1 of the validation false, return false
}

void display_in_table_header()
{
	cout<<left<<'|'<<setw(11)<<"No. Matric"<<'|'<<setw(25)<<"Name"<<'|'<<setw(8)<<"Gender"<<'|'<<setw(10)<<"Status"<<'|'<<setw(6)<<"CGPA"<<'|'<<endl; cout<<left<<'|'<<setw(11)<<"No. Matric"<<'|'<<setw(25)<<"Name"<<'|'<<setw(10)<<"Status"<<'|'<<setw(6)<<"CGPA"<<'|'<<endl;
}
void display_in_table(profile student)//display the information of group of student in table form.
{
	cout<<left<<'|'<<setw(11)<<student.nomatric<<'|'<<setw(25)<<student.name<<'|'<<setw(8)<<student.gender<<'|'<<setw(10)<<student.getStatus()<<'|'<<setw(6)<<student.getCgpa()<<'|'<<endl;
}
void display_student_data(profile student) // display all the information of respective student
{
	cout<<left<<setw(3)<<"1. "<<setw(20)<<"Name: "<< student.name<<endl;
	cout<<left<<setw(3)<<"2. "<<setw(20)<<"No. matric: "<< student.nomatric<<endl;
	cout<<left<<setw(3)<<"3. "<<setw(20)<<"Gender: "<< student.gender<<endl;
	cout<<left<<setw(3)<<"4. "<<setw(20)<<"Address: "<< student.address<<endl;
	cout<<left<<setw(3)<<"5. "<<setw(20)<<"Email: "<< student.email<<endl;
	cout<<left<<setw(3)<<"6. "<<setw(20)<<"No. phone: "<< student.nophone<<endl;
	cout<<left<<setw(3)<<"7. "<<setw(20)<<"GPA: "<< student.getGpa()<<endl;
	cout<<left<<setw(3)<<"8. "<<setw(20)<<"CGPA: "<< student.getCgpa()<<endl;
	cout<<left<<setw(3)<<"9. "<<setw(20)<<"Status: "<< student.getStatus()<<endl;
	cout<<left<<setw(3)<<"10. "<<setw(20)<<"Accumulated Credit: "<< student.getAccumulatedcredit()<<endl;
	cout<<left<<setw(3)<<"11. "<<setw(20)<<"Muet band: "<< student.getMuetband()<<endl;
	cout<<left<<setw(3)<<"12. "<<"Course list"<<endl;
	cout<<internal<<"|"<<setw(4)<<"No."<<"|"<<setw(7)<<"Course"<<"|"<<setw(12)<<"Course Unit"<<"|"<<setw(6)<<"Grade"<<"|"<<endl;
	for(int j=0; j< student.getsizeoflist(); j++)
	{
		cout<<internal<<"|"<<setw(2)<<j+1<<". "<<"|"<<setw(7)<< student.getcourse(j)<<"|"<<setw(12)<< student.getcourseunit(j)<<"|"<<setw(6)<< student.getgrade(j)<<"|"<<endl;
	}
}


bool checkfordigit(const string X)      //function to check for the content that contain all digit
{
	char str[X.length()];
	for (unsigned int j =0; j<X.length(); j++) //change the string into array of char because isdigit accept char.
		str[j]=X[j];
	for (unsigned int i =0; i<X.length(); i++) //check one by one.
	{
		if (!isdigit(str[i])) //check for digit
			return false;
	}
	return true;
}

bool emailcheck(const string X) //check for the contain that contain symbol '@'. Because email must have this '@' symbol
{
	for (unsigned int i =0; i<X.length(); i++) //check one by one.
	{
		if (X[i]=='@') //check for symbol'@'
			return true;
	}
	return false;
}

void get_array_of_no_matric(string arr[],int studentCount,profile student[]) //get a copy array of no. matric from the student class
{
	sort(student, student + studentCount,[](profile a, profile b) -> bool {         //sort the no matric according to the ascending order.
		return a.getmatric() < b.getmatric();
	} );
	for(int i=0; i<studentCount; i++)
		arr[i]=student[i].getmatric();
}

/*		//not used in the program.
   void get_array_of_name(string arr[],int studentCount,profile student[]) //get a copy array of name from the student class
   {
        sort(student, student + studentCount,[](profile a, profile b) -> bool {
                return a.getname() < b.getname();
        } );
        for(int i=0; i<studentCount; i++)
                arr[i]=student[i].getname();
   } */


void keyIn_by_SY(int &studentCount,profile student[],int const max_student) // user define function that perform key in method
{
	string studentGpa;
	string studentCgpa;
	string studentStatus;
	string studentAccumulatedcredit;
	string studentMuetband;
	char choice;
	string Name,gender,address,email,nophone;
	string nomatric;
	bool checking=false;
	int no_of_course;
	//loop for the key in data of the student
	do {
		cout<<"Key in name of the student: "<<endl; //tell user to type in the name of the student
		cin.clear(); cin.ignore();
		getline(cin,Name); //get the name for the student
		cout<<"Key in matric number of the student: "<<endl; //tell user to type in the no. matric of the student
		cin>>nomatric;  //get the no. matric for the student
		//verify the no. matric key in is verified to the format of it which is six integer
		if(nomatric.find_first_not_of("1234567890")!=string::npos || nomatric.length()!=6) {

			cout<<"Please key in only integer and proper data. The student's data is not recorded in here."<<endl<<endl<<endl;//display error message to the user to key in only integer
			continue;
		}

		cout<<"Key in gender of the student(male/female): "<<endl;
		cin>>gender;

		if(gender!="male" && gender != "female" && gender!="MALE" && gender!="FEMALE") { //verify whether key in the correct data or not

			cout<<"Please key in only male or female. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		cout<<"Key in address of the student: "<<endl;
		cin.clear(); cin.ignore();
		getline(cin,address);

		cout<<"Key in email of the student: "<<endl;
		cin>>email;

		if(emailcheck(email)==false) { // verify the email by checking whther there is @ inside the variable

			cout<<"Please key in only peoper data. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		cout<<"Key in phone number of the student: "<<endl; // verify isit integer
		cin>>nophone;

		if(checkfordigit(nophone)==false) {

			cout<<"Please key in only peoper data. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		student[studentCount].change(Name,nomatric,gender,address, email,nophone);//set these variable using the change() function
		system("cls");
		cout<<"Key in student's gpa."<<endl;
		cin>>studentGpa;

//verify gpa is number or not
		if(studentGpa.find_first_not_of("1234567890.")!=string::npos || stod(studentGpa)>4.0) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}

		cout<<"Key in student's cgpa."<<endl;
		cin>>studentCgpa;

//verify cgpa is number or not
		if(studentCgpa.find_first_not_of("1234567890.")!=string::npos || stod(studentCgpa)>4.0) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}

		cout<<"Key in student's status."<<endl;
		cout<<"1. Active"<<endl;
		cout<<"2. P1"<<endl;
		cout<<"3. P2"<<endl;
		cout<<"4. FO"<<endl;
		cin>>choice;
		switch (choice)
		{
		case '1':      studentStatus="Active"; break;
		case '2':      studentStatus="P1";     break;
		case '3':      studentStatus="P2";     break;
		case '4':      studentStatus="FO";     break;
		default:
			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			cin.clear(); cin.ignore( numeric_limits<int>::max(),'\n'); //discard all the input from cin.
			continue;
		}


		cout<<"Key in student's accumulated credit."<<endl;
		cin>>studentAccumulatedcredit;

//verify accumulated credit hour is number or not
		if(studentAccumulatedcredit.find_first_not_of("1234567890.")!=string::npos) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}

		cout<<"Key in student's muet band."<<endl;
		cin>>studentMuetband;

//verify muet band is number or not
		if(studentMuetband.find_first_not_of("1234567890")!=string::npos || stoi(studentMuetband)>6) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}

		student[studentCount].academics_set(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband);//set these variable using academics_set function
		system("cls");

		cout<<"Key in the number of course. (default: 7)"<<endl;
		cout<<"*Reminder : for course CAT300, the grade section key in TL"<<endl<<endl;
		do
		{
			try
			{
				cin>>no_of_course;
			}
			catch(...)
			{
				cout<<"Your can't an alphabet."<<endl;
			}
			if(no_of_course<0)
			{
				cout<<"You can't input number less than or equal to 0"<<endl;
			}
		} while(no_of_course<0);
		string *course= new string[no_of_course];
		string *cu= new string[no_of_course];
		string *grade= new string[no_of_course];
		int input;
		for(int i=0; i<no_of_course; i++)
		{
			cout<<i+1<<". Course Code: ";
			cin>>course[i];
			while(course[i].length()!=6)
			{
				cout<<"Please try again.\n";
				cout<<i+1<<". Course Code: ";
				cin>>course[i];
			}
			cout<<i+1<<". Course Unit: ";
			cin>>input;
			while(!(input>0))
			{
				cout<<"Please try again with positive integer.\n";
				cout<<i+1<<". Course Unit: ";
				cin.clear(); cin.ignore();
				cin>>input;
			}
			cu[i]=to_string(input);
			cout<<i+1<<". Grade: ";
			cin>>grade[i];
			while(student[i].callconvertTonumber(grade[i])==-1)
			{
				cout<<"Please try again with valid grade.\n";
				cout<<i+1<<". Grade: ";
				cin>>grade[i];
			}
		}
		student[studentCount].course_change(course,cu,grade,no_of_course);// set these variables using course_change function
		cout<<"Do you wish to continue key in another student's data?"<<endl<<endl; //ask the user to key in new student profile or no
		cout<<"1. Yes"<<endl;
		cout<<"2. No"<<endl<<endl<<endl<<endl;

		cout<<"*Maximum "<<max_student<<" students' data only"<<endl;
		cin>>choice;

		if(choice=='1') {
			checking=true;
		}

		else  {
			cin.clear(); cin.ignore(numeric_limits<int>::max(),'\n'); //discard all the cin input due to characters like letters.
		}
		studentCount++;
	} while(checking==true && studentCount<max_student);

	for(int j=0; j<studentCount; j++)
		display_student_data(student[j]);

	cout<<endl<<"Above is the data you had just key in."<<endl<<endl;
	system("pause");
}

void update_data(const int studentCount,profile student[]) //update the data of respective student
{
	string studentGpa;
	string studentCgpa;
	string studentStatus;
	string studentAccumulatedcredit;
	string studentMuetband;
	string Name,gender,address,email,nophone;
	string nomatric;
	string nomatricarry[studentCount];
	int index_number;
	cout<<"Update Menu"<<endl;
	do
	{
		cout<<"Key in the no. matric of the student (-1 to return)"<<endl;
		cin>>nomatric;
		if(nomatric=="-1")
		{return;}
		if(nomatric.find_first_of("1234567890")!=string::npos && nomatric.length()==6) //verify the matric number key in by user is integer and valid or not
		{
			get_array_of_no_matric(nomatricarry,studentCount,student);      //make a copy of no matric array.
			index_number=binarysearch(0,studentCount,nomatricarry,nomatric); //call the binary search to get the index number of the student object array.
			if(index_number==-1) // if the matric number does not match 1 of the student
			{
				cout<<"Student not found in the database."<<endl;
			}
			else // if matric number match 1 of the student
			{
				cout<<"Student Found"<<endl;
				break;
			}
		}
		else // if the matric number key in by user is invalid
		{
			cout<<"Please try again"<<endl;
		}
	} while(true);
	//loop for the update the data of the student
	int no_menu;
	bool updating=true;
	do {
		system("pause");
		system("cls");
		display_student_data(student[index_number]); // display the student's information
		cout<<endl;
		cout<<"To change the student data key in the number in front of each line. For updating courses, please key in 12."<<endl;
		cout<<"Key in -1 to back to home."<<endl;
		cout<<"Attention! Number matric of student cannot be changed."<<endl;
		cin>>no_menu;

		switch(no_menu)
		{
		case -1:
			updating=false;
			break;
		case 1:
			cout<<"Name of the student: "<<endl; //tell user to type in the name of the student
			cin.clear(); cin.ignore();
			getline(cin,Name); //get the name for the student
			if(nomatric.find_first_not_of("1234567890")!=string::npos || nomatric.length()!=6) {

				cout<<"Please key in only integer and proper data. The student's data is not recorded in here."<<endl<<endl<<endl;//display error message to the user to key in only integer
				continue;
			}
			student[index_number].change(Name,student[index_number].getmatric(),student[index_number].getgender(),student[index_number].getaddress(), student[index_number].getemail(),student[index_number].getnophone());
			break;

		case 3:
			cout<<"Gender of the student(male/female): "<<endl;
			cin>>gender;

			if(gender!="male" && gender != "female" && gender!="MALE"&& gender!="FEMALE") { //verify gender key in by user if male or female only

				cout<<"Please key in only male or female. The student's data is not recorded in here."<<endl<<endl<<endl;
				continue;
			}
			//setting these variable
			student[index_number].change(student[index_number].getname(),student[index_number].getmatric(),gender,student[index_number].getaddress(), student[index_number].getemail(),student[index_number].getnophone());
			break;

		case 4:
			cout<<"Address of the student: "<<endl;
			cin.clear(); cin.ignore();
			getline(cin,address);
			student[index_number].change(student[index_number].getname(),student[index_number].getmatric(),student[index_number].getgender(),address, student[index_number].getemail(),student[index_number].getnophone());
			break;

		case 5:
			cout<<"Email of the student: "<<endl;
			cin>>email;

			if(emailcheck(email)==false) { //verify email by checking whether got @ inside or not

				cout<<"Please key in only peoper data. The student's data is not recorded in here."<<endl<<endl<<endl;
				continue;
			}
			student[index_number].change(student[index_number].getname(),student[index_number].getmatric(),student[index_number].getgender(),student[index_number].getaddress(),email,student[index_number].getnophone());
			break;

		case 6:
			cout<<"Phone number of the student: "<<endl;
			cin>>nophone;

			if(checkfordigit(nophone)==false) { //verify phone number

				cout<<"Please key in only peoper data. The student's data is not recorded in here."<<endl<<endl<<endl;
				continue;
			}
			//setting these variable using change() function
			student[index_number].change(student[index_number].getname(),student[index_number].getmatric(),student[index_number].getgender(),student[index_number].getaddress(), student[index_number].getemail(),nophone);

			break;

		case 7:
			cout<<"Key in student's gpa."<<endl;
			cin>>studentGpa;


			if(studentGpa.find_first_not_of("1234567890.")!=string::npos || stod(studentGpa)>4.0) { //verify gpa key in by user is integer and valid data

				cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
				continue;
			}
			//setting these variable using academics_set() function
			student[index_number].academics_set(studentGpa,to_string(student[index_number].getCgpa()),student[index_number].getStatus(),to_string(student[index_number].getAccumulatedcredit()),to_string(student[index_number].getMuetband()));

			break;

		case 8:
			cout<<"Key in student's cgpa."<<endl;
			cin>>studentCgpa;

//verify cgpa key in by user is integer and valid data
			if(studentCgpa.find_first_not_of("1234567890.")!=string::npos || stod(studentCgpa)>4.0) {

				cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
				continue;
			}
			//setting these variable using academics_set function
			student[index_number].academics_set(to_string(student[index_number].getGpa()),studentCgpa,student[index_number].getStatus(),to_string(student[index_number].getAccumulatedcredit()),to_string(student[index_number].getMuetband()));

			break;

		case 9:
			char choice;
			cout<<"Key in student's status."<<endl;
			cout<<"1. Active"<<endl;
			cout<<"2. P1"<<endl;
			cout<<"3. P2"<<endl;
			cout<<"4. FO"<<endl;
			cin>>choice;
			switch (choice)
			{
			case '1':      studentStatus="Active"; break;
			case '2':      studentStatus="P1";     break;
			case '3':      studentStatus="P2";     break;
			case '4':      studentStatus="FO";     break;
			default:
				cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
				cin.clear(); cin.ignore( numeric_limits<int>::max(),'\n'); //discard all the input from cin.
				continue;
			}
			//setting these variable using academics_set function
			student[index_number].academics_set(to_string(student[index_number].getGpa()),to_string(student[index_number].getCgpa()),studentStatus,to_string(student[index_number].getAccumulatedcredit()),to_string(student[index_number].getMuetband()));

			break;

		case 10:
			cout<<"Key in student's accumulated credit."<<endl;
			cin>>studentAccumulatedcredit;

//verify accumulated credit key in by user is integer and valid data
			if(studentAccumulatedcredit.find_first_not_of("1234567890")!=string::npos) {

				cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
				continue;
			}
			//setting these variable using academics_set function
			student[index_number].academics_set(to_string(student[index_number].getGpa()),to_string(student[index_number].getCgpa()),student[index_number].getStatus(),studentAccumulatedcredit,to_string(student[index_number].getMuetband()));

			break;

		case 11:
			cout<<"Key in student's muet band."<<endl;
			cin>>studentMuetband;


			if(studentMuetband.find_first_not_of("1234567890")!=string::npos || stoi(studentMuetband)>6) { //verify muet band key in by user is integer and valid data

				cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
				continue;
			}
			//setting these variable using academics_set function
			student[index_number].academics_set(to_string(student[index_number].getGpa()),to_string(student[index_number].getCgpa()),student[index_number].getStatus(),to_string(student[index_number].getAccumulatedcredit()),studentMuetband);
			break;

		case 12:
			int no_of_course=student[index_number].getsizeoflist();
			string *course= new string[no_of_course];
			string *cu= new string[no_of_course];
			string *grade= new string[no_of_course];
			int linenumber;
			do
			{
				system("cls");
				cout<<left<<setw(3)<<"1. "<<setw(20)<<"Name: "<<student[index_number].getname()<<endl;
				cout<<left<<setw(3)<<"2. "<<setw(20)<<"No. matric: "<<student[index_number].getmatric()<<endl;
				cout<<left<<setw(3)<<"12. "<<"Course list"<<endl;
				cout<<internal<<"|"<<setw(4)<<"No."<<"|"<<setw(7)<<"Course"<<"|"<<setw(12)<<"Course Unit"<<"|"<<setw(6)<<"Grade"<<"|"<<endl;

				for(int j=0; j<student[index_number].getsizeoflist(); j++)
				{
					cout<<internal<<"|"<<setw(2)<<j+1<<". "<<"|"<<setw(7)<<student[index_number].getcourse(j)<<"|"<<setw(12)<<student[index_number].getcourseunit(j)<<"|"<<setw(6)<<student[index_number].getgrade(j)<<"|"<<endl;
					course[j]=student[index_number].getcourse(j);
					cu[j]=student[index_number].getcourseunit(j);
					grade[j]=student[index_number].getgrade(j);
				}

				cout<<"Key in the number in front of the line to be changed. (to exit key in -1. to add/delete new course key in 0 )"<<endl;
				do
				{
					try
					{
						cin>>no_menu;
					}
					catch(...)
					{
						cout<<"Your can't an alphabet."<<endl;
					}
					if(no_menu<-1||no_menu>student[index_number].getsizeoflist())
					{
						cout<<"You can't input number less than -1 and more than"<<student[index_number].getsizeoflist()<<endl;
					}
				} while(no_menu<-1||no_menu>student[index_number].getsizeoflist());

				if (no_menu==-1)
				{break;}

				if (no_menu==0)
				{
					cout<<"Pick one from the list\n";
					cout<<"1. Add course.\n2. Delete course.\n3. Back\n";
					do
					{
						try
						{
							cin>>no_menu;
						}
						catch(...)
						{
							cout<<"Your can't an alphabet."<<endl;
						}
						if(no_menu<0||no_menu>3)
						{
							cout<<"You can't input number less than 1 and more than 3"<<endl;
						}
					} while(no_menu<0||no_menu>3);

					string *temp_course;
					string *temp_cu;
					string *temp_grade;
					int input;
					temp_course  = course;
					temp_cu      = cu;
					temp_grade   = grade;

					switch(no_menu)
					{
					case 1:
						no_of_course++;
						delete []course;
						course = new string[no_of_course];
						delete []cu;
						cu = new string[no_of_course];
						delete []grade;
						grade = new string[no_of_course];

						for(int i=0; i<(no_of_course-1); i++)
						{
							course[i]  =    temp_course[i];
							cu[i]      =    temp_cu[i];
							grade[i]   =    temp_grade[i];
						}
						delete []temp_course;
						delete []temp_cu;
						delete []temp_grade;

						cout<<no_of_course<<". Course Code: ";
						cin>>course[no_of_course-1];
						while(course[no_of_course-1].length()!=6)
						{
							cout<<"Please try again.\n";
							cout<<no_of_course<<". Course Code: ";
							cin>>course[no_of_course-1];
						}
						cout<<no_of_course<<". Course Unit: ";
						cin>>input;
						while(!(input>0))
						{
							cout<<"Please try again with positive integer.\n";
							cout<<no_of_course<<". Course Unit: ";
							cin.clear(); cin.ignore();
							cin>>input;
						}
						cu[no_of_course-1]=to_string(input);
						cout<<no_of_course<<". Grade: ";
						cin>>grade[no_of_course-1];
						while(student[index_number].callconvertTonumber(grade[no_of_course-1])==-1)
						{
							cout<<"Please try again with valid grade.\n";
							cout<<no_of_course<<". Grade: ";
							cin>>grade[no_of_course-1];
						}
						student[index_number].course_change(course,cu,grade,no_of_course);
						break;

					case 2:
						cout<<"Key in the number in front of the line to be deleted. (To back, key in 0.  )"<<endl;
						no_menu=menu_selector(0,student[index_number].getsizeoflist());
						if(no_menu==0)
						{break;}
						else
						{
							delete []course;
							course = new string[no_of_course-1];
							delete []cu;
							cu = new string[no_of_course-1];
							delete []grade;
							grade = new string[no_of_course-1];
							bool found=false;
							for(int i=0; i<no_of_course; i++)
							{
								if(found==true)
								{
									course[i-1]  =    temp_course[i];
									cu[i-1]                  =    temp_cu[i];
									grade[i-1]       =    temp_grade[i];
								}
								else if(i==(no_menu-1))
								{
									found=true;
								}
								else
								{
									course[i]  =    temp_course[i];
									cu[i]            =    temp_cu[i];
									grade[i]         =    temp_grade[i];
								}
							}
							no_of_course--;
							delete []temp_course;
							delete []temp_cu;
							delete []temp_grade;
							student[index_number].course_change(course,cu,grade,no_of_course);
						}
						break;

					case 3:
						break;
					}
					continue;
				}

				linenumber=--no_menu;
				cout<<internal<<"|1."<<setw(7)<<"Course"<<"|2."<<setw(12)<<"Course Unit"<<"|3."<<setw(6)<<"Grade"<<"|"<<endl;
				cout<<internal<<"|1."<<setw(7)<<student[index_number].getcourse(linenumber)<<"|2."<<setw(12)<<student[index_number].getcourseunit(linenumber)<<"|3."<<setw(6)<<student[index_number].getgrade(linenumber)<<"|"<<endl;
				cout<<"Key in the number of column to change.(to exit key in 0)"<<endl;
				do
				{
					try
					{
						cin>>no_menu;
					}
					catch(...)
					{
						cout<<"Your can't an alphabet."<<endl;
					}
					if(no_menu<0||no_menu>3)
					{
						cout<<"You can't input number less than 0 and more than 3"<<endl;
					}
				} while(no_menu<0||no_menu>3);

				switch(no_menu)
				{
				case 1:
					cout<<linenumber+1<<". Course Code: ";
					cin>>course[linenumber];
					while(course[linenumber].length()!=6)
					{
						cout<<"Please try again.\n";
						cout<<linenumber+1<<". Course Code: ";
						cin>>course[linenumber];
					}
					break;
				case 2:
					int input;
					cout<<linenumber+1<<". Course Unit: ";
					cin>>input;
					while(!(input>0))
					{
						cout<<"Please try again with positive integer.\n";
						cout<<linenumber+1<<". Course Unit: ";
						cin.clear(); cin.ignore();
						cin>>input;
					}
					cu[linenumber]=to_string(input);
					break;
				case 3:
					cout<<linenumber+1<<". Grade: ";
					cin>>grade[linenumber];
					while(student[index_number].callconvertTonumber(grade[linenumber])==-1)
					{
						cout<<"Please try again with valid grade.\n";
						cout<<linenumber+1<<". Grade: ";
						cin>>grade[linenumber];
					}
					break;
				default:
					continue;
				}
				student[index_number].course_change(course,cu,grade,no_of_course);
			} while(true);
		}
	} while(updating);

	system("cls");
	display_student_data(student[index_number]);

	cout<<endl<<"Above is the data you had just key in."<<endl<<endl;
	system("pause");
}

//read file1
void readfile1(profile student[],int &studentCount,const int max_student)
{
	ifstream readf("file1.txt"); //read file function
	stringstream readl; //let the string like cout and cin
	if (!readf)
		cout<<"Fail to read file";
	else
	{
		string line;
		string Name,a,gender,address,email,nophone;
		int nomatric;

		while(!readf.eof()) //start reading
		{
			if(studentCount<=max_student)
			{
				getline(readf,line);
				readl.clear(); //clear the contain in the read1 stringstream
				readl.str(line); //set line as the string read by read1
				readl>>Name>>a;
				while(!checkfordigit(a)) //read text until numbers.
				{
					Name.insert(Name.length()," "+a); //add the string a after the original string name
					readl>>a;
				}
				nomatric=stoi(a);
				readl>>gender>>address>>email;
				while(!emailcheck(email))
				{
					address.insert(address.length()," "+email); //add the string email after the original string address
					readl>>email;
				}
				readl>>nophone;
				cout<<Name<<" " <<nomatric<<" " <<gender<<" "<<address<<" "<<email<< " "<<nophone<<endl;
				student[studentCount].change(Name,a,gender,address, email,nophone);
				cout<<student[studentCount].getname()<<" "<<student[studentCount].getmatric()<<" "<<student[studentCount].getgender()<<" "<<student[studentCount].getaddress()<<" "<<student[studentCount].getemail()<<" "<<student[studentCount].getnophone()<<endl;
				studentCount++;
			}
			else
			{
				cout<<"Acheive max number of student.Please change the max number of student to higher value"<<endl;
				cout<<"Below are the student not key in into the database."<<endl;
				getline(readf,line);
				while(!readf.eof())
				{
					cout<<line<<endl;
				}
				break;
			}
		}
		cout<<"file 1 is loaded..."<<endl; //read finished
		system("pause");
	}
}

//read file2
void readfile2(profile student[],int &studentCount,const int max_student)
{
	string studentGpa;
	string studentCgpa;
	string studentStatus;
	string studentAccumulatedcredit;
	string studentMuetband;
	string studentMatricnumber;
	string line;
	int i=0;
	ifstream infile;
	infile.open("file2.txt");
	stringstream read2;     //let the string like cout and cin

	while(!infile.eof()) {
		read2.clear();  //clear the contain in the read1 stringstream
		getline(infile,line);
		read2.str(line); //set line as the string read by read1
		read2>>studentMatricnumber>>studentGpa>>studentCgpa>>studentStatus>>studentAccumulatedcredit>>studentMuetband;

		if(studentMatricnumber.find_first_not_of("1234567890")!=string::npos || studentMatricnumber.length()!=6) { // verify matric number isit length of 6 and number
			cout<<"There is an error in matric number section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		if(studentGpa.find_first_not_of("1234567890.")!=string::npos || stod(studentGpa)>4) { //verify gpa isit integer and valid
			cout<<"There is an error in gpa section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}


		if(studentCgpa.find_first_not_of("1234567890.")!=string::npos || stod(studentCgpa)>4) { //verify cgpa isit integer and valid
			cout<<"There is an error in cgpa section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		if(studentAccumulatedcredit.find_first_not_of("1234567890.")!=string::npos ) { //verify accumulated credit isit integer and valid
			cout<<"There is an error in accumulated credit section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		if(studentMuetband.find_first_not_of("1234567890.")!=string::npos || stoi(studentMuetband)<1 || stoi(studentMuetband)>6 ) { //verify muet band isit integer and valid
			cout<<"There is an error in muet band section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		if(studentMatricnumber==student[i].getmatric())
		{
			cout<<student[i].getmatric()<<" ";
			student[i].academics_set(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband); //set these variable
			student[i].displayData(); // display
		}

		else
		{
			cout<<"Dislocation occur at "<<studentMatricnumber<<endl;
			int j=i+1;
			bool success = false;
			for(int k=0; k<studentCount; k++)
			{
				if(studentMatricnumber==student[j].getmatric())
				{
					student[j].academics_set(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband);
					student[j].displayData();
					success=true;
					break;
				}
				j++;
				if(j>=studentCount)
				{j=0;}
			}
			if(success==false)
			{
				cout<<"student Not Found in the database.Adding new one."<<endl;
				cout<<"No matric of new student is "<<studentMatricnumber;
				student[studentCount].changeNomatric(studentMatricnumber);
				student[studentCount++].academics_set(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband);
				student[studentCount-1].displayData();
			}
		}
		i++;
	}
	cout<<"File 2 is loaded..."<<endl;
	system("pause");
}

//read file3
void readfile3(profile student[],int &studentCount,const int max_student)
{
	ifstream readf("file3.txt"); //read file function
	if (!readf)
		cout<<"Fail to read file";
	else
	{
		string line;
		string course[100],grade[100];
		string nomatric[100],cu[100];
		int size=0;
		int nostudent=0;
		string x;
		stringstream readl; //let the string like cout and cin
		bool success=false;
		while(!(readf.eof()&&success)) //start reading
		{
			success = false;
			getline(readf,line);
			readl.clear();
			readl.str(line); //set line as the read
			readl>>x;
			if(x==nomatric[size-1]||size==0)
			{
				nomatric[size]=x;
				readl>>course[size]>>cu[size]>>grade[size];
				cout<<nomatric[size]<<course[size]<<cu[size]<<grade[size]<<endl;
				size++;
			}
			if ((x!=nomatric[size-1]&&size>0)||readf.eof())
			{
				if(nomatric[size-1]==student[nostudent].getmatric())
				{
					student[nostudent].course_change(course,cu,grade,size);
					nostudent++;
					size=0;
				}
				else
				{
					cout<<"Dislocation occur at "<<nomatric[size-1]<<endl;
					int j=nostudent+1;

					for(int k=0; k<studentCount; k++)
					{
						if(nomatric[size-1]==student[j].getmatric())
						{
							cout<<"student Found in the database.Adding course."<<endl;
							student[j].course_change(course,cu,grade,size);
							size=0;
							success=true;
							break;
						}
						j++;
						if(j>=studentCount)
						{j=0;}
					}
					if(success==false)
					{
						cout<<"student Not Found in the database.Adding new one."<<endl;
						cout<<"No matric of new student is "<<nomatric[size-1];
						student[studentCount].changeNomatric(nomatric[size-1]);
						student[studentCount++].course_change(course,cu,grade,size);
						size=0;
						success=true;
					}
				}
				if(!readf.eof())
				{
					nomatric[size]=x;
					readl>>course[size]>>cu[size]>>grade[size];
					cout<<nomatric[size]<<course[size]<<cu[size]<<grade[size]<<endl;
					size++;
				}
			}
		}

		cout<<" File 3 is loaded..."<<endl; //read finished
		system("pause");
	}
}

//filtering by 5 aspect, gpa>2, cgpa>2, status, accumulated credit>60, muet band>4
void filtering_by_SY(profile student[],int studentCount){

	string choice3;
	string choice4;

	system("cls");

	cout<<"Displaying students' information by filtering : "<<endl;
	cout<<"1. Gpa more than or equal to 2.0"<<endl;
	cout<<"2. Cgpa more than or equal to 2.0 "<<endl;
	cout<<"3. Status "<<endl;
	cout<<"4. Accumulated credit more than or equal to 60 credit hours"<<endl;
	cout<<"5. Muet band 4 or higher"<<endl;
	cin>>choice3;

	if(choice3=="1") { //display data of student with overall gpa>=2

		system("cls");

		for(int i=0; i<studentCount; i++) {

			if(student[i].getGpa()>=2.0) {
				student[i].displayData();
			}
		}

	}

	else if( choice3=="2") { //display data of student with cgpa>=2

		system("cls");

		for(int i=0; i<studentCount; i++) {

			if(student[i].getCgpa() >=2.0) {
				student[i].displayData();
			}
		}

	}

	else if(choice3=="3") { //filter by status

		system("cls");

		cout<<"1. Active"<<endl;
		cout<<"2. P1"<<endl;
		cout<<"3. P2"<<endl;
		cout<<"4. FO"<<endl;
		cin>>choice4;


		if(choice4=="1") { //display data of student with active status

			system("cls");

			for(int i=0; i<studentCount; i++) {

				if(student[i].getStatus()=="active") {
					student[i].displayData();
				}
			}
		}

		else if(choice4=="2") { //display data of student with P1 status

			system("cls");

			for(int i=0; i<studentCount; i++) {

				if(student[i].getStatus()=="P1") {
					student[i].displayData();
				}
			}
		}

		else if(choice4=="3") {  //display data of student with P2 status

			system("cls");

			for(int i=0; i<studentCount; i++) {

				if(student[i].getStatus()=="P2") {
					student[i].displayData();
				}
			}
		}

		else if(choice4=="4") {  //display data of student with FO status

			system("cls");

			for(int i=0; i<studentCount; i++) {

				if(student[i].getStatus()=="FO") {
					student[i].displayData();
				}
			}
		}

		else{ //if the user key in wrong dinput, tell user
			system("cls");

			cout<<"Incorrect input, please try again next time ( key in only 1 / 2 / 3 /4) "<<endl;
		}

	}

	else if(choice3=="4") {  //display data of student with accumulated credit more than or equal 60

		system("cls");

		for(int i=0; i<studentCount; i++) {

			if(student[i].getAccumulatedcredit()>=60) {
				student[i].displayData();
			}
		}
	}

	else if(choice3=="5") {  //display data of student with muet band higher than band 3

		system("cls");

		for(int i=0; i<studentCount; i++) {

			if(student[i].getMuetband()>=4) {
				student[i].displayData();
			}
		}
	}
}

//function that generate overall report
void generate_report(profile student[],int studentCount){
	int no_menu_1;
	int no_menu_2;
	do
	{
		system("cls");
		cout<<"Generate Report Menu"<<endl;
		cout<<"Choose one of the following."<<endl;
		cout<<"1. List of qualified student"<<endl;
		cout<<"2. List of not qualified student"<<endl;
		cout<<"3. Back"<<endl;
		cin>>no_menu_1;
		if(no_menu_1==3)
			return;
		if(no_menu_1==1||no_menu_1==2)
		{
			cout<<"Choose one of the following."<<endl;
			cout<<"1. All Gender"<<endl;
			cout<<"2. Male"<<endl;
			cout<<"3. Female"<<endl;
			cin>>no_menu_2;
		}
	} while(no_menu_2<1&&no_menu_2>3);

	if(no_menu_1==1&&no_menu_2==1)
	{
//All Qualified student
		cout<<"Qualified student : "<<endl<<endl;
		display_in_table_header();
		for(int i=0; i<studentCount; i++) {
			if(validation(student[i])) {
				display_in_table(student[i]);
			}
		}
	}

	else if(no_menu_1==2&&no_menu_2==1) {
		cout<<"Not qualified student : "<<endl<<endl;
		display_in_table_header();
//All Not Qualified student
		for(int i=0; i<studentCount; i++) {
			if(!validation(student[i])) {
				display_in_table(student[i]);
			}
		}
	}

	else if(no_menu_1==1&&no_menu_2==2) {
		cout<<"Qualified male student : "<<endl<<endl;
		display_in_table_header();
//All  Qualified Male student
		for(int i=0; i<studentCount; i++) {
			if(validation(student[i]) && student[i].getgender()=="male") {
				display_in_table(student[i]);
			}
		}
	}
	else if(no_menu_1==2&&no_menu_2==2) {
		cout<<"Not qualified male student : "<<endl<<endl;
		display_in_table_header();
//All Not qualified male student
		for(int i=0; i<studentCount; i++) {
			if(!validation(student[i]) && student[i].getgender()=="male") {
				display_in_table(student[i]);
			}
		}
	}
	else if(no_menu_1==1&&no_menu_2==3) {
		cout<<"Qualified female student : "<<endl<<endl;
		display_in_table_header();
//All  Qualified Female student
		for(int i=0; i<studentCount; i++) {
			if(validation(student[i]) && student[i].getgender()=="female") {
				display_in_table(student[i]);
			}
		}
	}
	else if(no_menu_1==2&&no_menu_2==3) {
		cout<<"Not qualified female student : "<<endl<<endl;
		display_in_table_header();
//All Not Qualified female student
		for(int i=0; i<studentCount; i++) {
			if(!validation(student[i]) && student[i].getgender()=="female") {
				display_in_table(student[i]);
			}
		}
	}
	system("pause");
}

void filter_by_zr(int studentCount,profile student[])
{
	while(true) {
		system("cls");
		cout<<"Filter Menu\n";      //filter menu
		cout<<"1. Display All\n2. Search by matric no.\n3. Name for first alphabet  \n4. Gender \n5. Sorting\n6. Filter GPA,CGPA,Status,Accumulated credit and MUET\n7. Generate Report\n8. Back to main menu\n";
		int j; string nomatric;
		j=menu_selector(1,7);
		switch (j)
		{
		case 1:
			display_in_table_header();
			for(int k=0; k<studentCount; k++) //show all
			{display_in_table(student[k]);}
			break;

		case 2:
			cout<<"Key in the student's matric number."<<endl;//binarysearch
			cin>>nomatric;

			if(nomatric.find_first_of("1234567890")!=string::npos && nomatric.length()==6)
			{
				string nomatricarry[studentCount];
				get_array_of_no_matric(nomatricarry,studentCount,student);
				int index_number=binarysearch(0,studentCount,nomatricarry,nomatric);
				if(index_number==-1)
				{
					cout<<"Student not found in the database."<<endl;
				}
				else
				{
					cout<<"Student Found"<<endl;
					display_student_data(student[index_number]);
				}
			}
			else
			{
				cout<< "The no. matric cannot consist of alphabet"<<endl;
			}
			break;

		case 3:
			char str;
			cout<<"First Alphabet : \n";
			cin>>str;
			display_in_table_header();
			for(int k=0; k<studentCount; k++)
			{
				if(student[k].getname().at(0)==str) //search one by one for the first alphabet
				{display_in_table(student[k]);}
			}
			break;

		case 4:
			cout<< "1. Filter as Male \n"<<"2. Filter as Female \n";
			j=menu_selector(1,2);
			if (j==1)
			{
				display_in_table_header();
				for(int k=0; k<studentCount; k++)
					if(student[k].getgender()=="male") //search one by one for male
					{display_in_table(student[k]);}
			}
			else if(j==2) {
				display_in_table_header();
				for(int k=0; k<studentCount; k++)
					if(student[k].getgender()=="female")     //search one by one for female
					{display_in_table(student[k]);}
			}
			break;

		case 5:
			cout<<"1. By Name\n2.By No. Matric\n";
			j=menu_selector(1,2);
			if (j==1)
			{
				sort(student, student + studentCount,[](profile a, profile b) -> bool {
					return a.getname() < b.getname();
				} );
				display_in_table_header();                                                                                                //sorting the student according to the name of the student in ascending order
				for(int k=0; k<studentCount; k++)
				{display_in_table(student[k]);}
			}
			else if(j==2)
			{
				sort(student, student + studentCount,[](profile a, profile b) -> bool {
					return a.getmatric() < b.getmatric();
				} );
				display_in_table_header();                                                                                                        //sorting according to the no. matric in ascending order
				for(int k=0; k<studentCount; k++)
				{display_in_table(student[k]);}
			}
			break;
		case 6:
			filtering_by_SY(student,studentCount);
			break;
		case 7:
			generate_report(student,studentCount);
			break;
		case 8:
			return;
		}
	}
}


int main()
{
	system("color 02"); //Change command prompt font colour to green.
	int menu_no;    //for holding menu no for the switch.
	int studentCount=0; //Keep track of the total number of student read.
	int max_student=100;    //The maximum number of student can be read.
	profile * student; //dynamic array of object of profile
	student=new profile [max_student];
	while(true)     //start of looping. The loop will never stop until reach break.
	{
		system("cls");  //Clear the screen content of the command prompt.
		cout<<"Welcome to LetsGoIT, a program that help you verify the qualification of each 3rd year student !"<<endl<<endl;   //The menu option is print to the screen.
		cout<<"1. To key in your data, press 1.\n";
		cout<<"2. To insert data from files, press 2.\n";
		cout<<"3. To update data your data, press 3. \n";
		cout<<"4. For displaying information, filter menu and generating report, press 4.\n";
		cout<<"5. To change maximum number of students to be processed, press 5. (Current: "<<max_student<<")"<<endl;
		cout<<"6. Exit, press 6."<<endl;
		menu_no=menu_selector(1,6);     //the no menu choose by the user is stored.

		if(menu_no==1)
		{
			if(studentCount<max_student) //check the maximum number of student.
				keyIn_by_SY(studentCount, student,max_student); //key in for the student info manually
			else
			{
				cout<<"The database is full!!"<<endl;
				system("pause");
			}
		}

		else if(menu_no==2)
		{
			readfile1( student,studentCount,max_student);
			readfile2( student,studentCount,max_student);
			readfile3( student,studentCount,max_student);
			system("cls");
			for(int i=0; i<studentCount; i++)
			{
				display_student_data(student[i]);
			}
			system("pause");
		}
		else if(menu_no==3)
			update_data(studentCount, student);

		else if(menu_no==4)
		{
			filter_by_zr(studentCount, student);
		}
		else if(menu_no==5)
		{
			while(true)
			{
				cout<<"Enter the maximum student you want (Current: "<<max_student<<")"<<endl;
				menu_no = menu_selector (1, numeric_limits<int>::max());

				if(studentCount>=0&&studentCount<=menu_no)
				{
					profile *temperary= student;
					max_student=menu_no;
					student =new profile[max_student];
					for(int i=0; i<studentCount; i++)
					{
						student[i]=temperary[i];
					}
					delete []temperary;
					break;
				}
				else
				{
					cout<<"Maximum student you wanted is more than number of student stored"<<endl;
				}
			}
		}
		else if(menu_no==6)
			return 0; // exit the loop for the menu
		else
			continue;
	}
}
