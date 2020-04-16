#include <iostream>
#include <dirent.h>
#include <fstream>
#include "L_T_hybrid.h"
#include "DLL.h"
#include <sstream>


using namespace std;
void file_name(DLL<string> *a){
	string filename;
	ostringstream ss;
    struct dirent *de;
    DIR *dir = opendir("/Semester 3 project/CV");
    filename="E:/Semester 3 project/CV/";
    if(!dir)
    {
        cout<<"opendir() failed! Does it exist?\n";
        return;
    }
	
  	int count=0;
        while(de = readdir(dir))
     {
     	ss.str("");
     	ss.clear();
     	ss<<filename<<de->d_name;
          count++;
     	if(count<=2){
     		continue;
		}
		fstream fi;
		fi.open(ss.str().c_str(),ios::in);
		string n=ss.str().c_str();
		a->addtotail(n);
			 if (fi){
			 }
			 else{
			 	cout<<"Could not open the file\n";
			 }
		fi.close();
	 }

    closedir(dir);

}
void read_cv(string a,DLL_pro *obj){
	fstream file;
	stringstream ss,para,heading;
	ss<<a;
	file.open(ss.str().c_str(),ios::in);
	ss.str("");
	ss.clear();
	string capital;
	int check=0,prev=0;
	do
	{
		file>>capital;
		if(capital.length()<=3)
		{
			para<<capital<<" ";
			check=0;
			prev=0;
			continue;
		}
		for(int i=0;i<capital.length();i++)
		{	
			if(capital[i]>'9'||capital[i]<'0')
			{
				if((capital[i]>'Z'&&capital[i]<'a')||capital[i]<'A'||capital[i]>'z')
				{
					 continue;
				}
			}
			if(isupper(capital[i]))
			{
				check=1;
				continue;
			}
			else
			{
				para<<capital<<" ";
				check=0;
				break;
			}		
		}
		
		if((prev==0 && check==1)||file.eof()){
			obj->add(heading.str(),para.str());
			heading.str("");
			heading.clear();
			para.str("");
			para.clear();
			
		}
		if(check==1)
		{
			heading<<capital<<" ";
			prev=check;
			continue;
		}
		
		prev=check;
	}while(!file.eof());
	file.close();
}
class Intake
{
    string degree_s,mexperience,experience,college_s,decision,field_s,extra_s,abbriviation_s,Abbriviation_s;
    string nil = "nil",NIL = "NIL",yes = "Y", no = "N";
    int skill_num,percentage_req;

    public:
    int requirement=5;
	list EXQ;
    list ACQ;
    list WORK_E;

    

    int input()
    {
        cout<<"\t\t\t\t\t\t\t\t\t\tAPPLICANT TRACKING SYSTEM\n\n\n";
        cout<<"\tENTER YOUR REQUIREMENTS BELOW : \n";
        cout<<"\t\t\t\t\tIf You Want To Leave Any Requirement Null Write NIL In The Subject\n\n";
        
        cout<<"Academic Adequacy : ";
        getline(cin , degree_s);
        if((degree_s.compare(nil)) == 0|| (degree_s.compare(NIL)) == 0)
        {
            requirement--;
        }
        else
        {
            ACQ.Insert(degree_s);
            cout<<"\nAbbreviation Of Above Academic Adequacy If Any : ";
            getline(cin , abbriviation_s);
            if(abbriviation_s.compare(nil) != 0 ||abbriviation_s.compare(NIL) != 0)
            {
                ACQ.Insert(abbriviation_s);
            }
        }
        

        cout<<"\nAny Specific Collegiate : ";
        getline(cin , college_s);
        if(college_s.compare(nil) == 0||college_s.compare(NIL) == 0)
        {
            requirement--;
        }
        else
        {
            ACQ.Insert(college_s);
            cout<<"\nabbreviation of Above Institute If any : ";
            getline(cin , Abbriviation_s);
            if(Abbriviation_s.compare(nil) != 0||Abbriviation_s.compare(NIL) != 0)
            {
                 ACQ.Insert(Abbriviation_s);
            }
        }


        cout<<"\nAny Specific Field : ";
        getline(cin , field_s);
        if(field_s.compare(nil) == 0|| field_s.compare(NIL)== 0)
        {
           requirement--;
        }
        else
        {
            WORK_E.Insert(field_s);
        }

        cout<<"\nMinimum Experience Required In Numbers : ";
        getline(cin , experience);
        if(experience.compare(nil) == 0|| experience.compare(NIL) == 0)
        {
            requirement--;
        }
        else
        {
            WORK_E.Insert(experience);
        }
   
        cout<<"\nMaximum Experience Required In Numbers : ";
        getline(cin , mexperience);
        if(mexperience.compare(nil) == 0|| mexperience.compare(NIL) == 0)
        {
            requirement--;
        }
        else
        {
            WORK_E.Insert(mexperience);
        }

        cout<<"\nDo You Want To Add More Keywords To Search(Y/N) : ";
        getline(cin , decision);
        if(decision.compare(yes)!= 0 && decision.compare(no))
        {
            cout<<"\n\t\tEITHER PRESS CAPITAL Y OR CAPITAN N TO MAKE A DECISION : ";
            getline(cin,decision);
        }
            if(decision.compare(yes) == 0)
            {
                while(extra_s.compare(no) != 0)
                {
                    cout<<"\nTo Stop Press N";
                    cout<<"\nEnter Keyword : ";
                    getline(cin , extra_s);
                    EXQ.Insert(extra_s);
                    requirement++;
                }
                requirement = requirement - 1; 
            }
            
     cout<<"\nENTER PERCENTAGE REQUIRED FOR SELECTION : " ;
	 cin>>percentage_req; 
	 return percentage_req;     
    }
};

int main()
{
	DLL<string> a;
	file_name(&a);
	int b=a.count();
	system("CLS"); 
    Intake in;
    float per=in.input();
    float req=in.requirement;
    float find;
    float percentage;
	DLL_pro object_hyb;
	for(int i=0;i<b;i++){
		system("CLS");	
		read_cv(a.get(i),&object_hyb);
		object_hyb.print();
		find=object_hyb.searching(in.ACQ,in.WORK_E,in.EXQ);
		percentage=(find/req)*100;
		cout<<"\n\nrequired : "<<req<<endl;
		cout<<"found : "<<find<<endl;
		cout<<"percentage required : "<<per<<endl;
		cout<<"percentage found : "<<percentage<<endl;
		if(percentage>=per){
			object_hyb.~DLL_pro();
			read_cv(a.get(i),&object_hyb);
			object_hyb.printfil(i);
		}
		getchar();
		object_hyb.~DLL_pro();
	}
}
