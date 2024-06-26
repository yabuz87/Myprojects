#include <iostream>
#include<windows.h>
#include<fstream>
#include <ctime>
#include <chrono>
#include <cstdlib>
using namespace std;

string path ="PassportData";
struct personal_info{
    string fname,lname,mname,birh_info,pobox;
    string sex;
    struct adress{
    string kebele,pobox;
    string city;
    }address_data;
    string passport_page;
    string appointment_day;
    string application_code;
};
string command_system();
void service_system(string);
void file_saver(personal_info);
void search_file();
void view_data();
void edit_data();
int* verify_data(string);
void editor(personal_info,string,int);
void rename_delete();
void terminate_application();
void requirements();
int main()
{
    system("color 9F");


    command_system();

    return 0;
}
string command_system(){

    system("cls");

    string command;
    label_1:
    cout<<"\n\n\n\n\n-> Home Page";
    cout << "\n\n\t\t\t\t\t\t\t\tPASSPORT SERVICE SYSTEM" << endl;
    cout<<"\n\n\t\t\tUse the code next to the services description which is in the bracket (**) to get our service!\n";
    cout<<"\n\n\t\t\t\t\t\tFor better experience maximize the screen!\n\n";
    cout<<"\n\n\n\t\t\t->Start New Application (11)\t\t->Check data and Search applicant (22)\t\t->Edit personal info (33)";
    cout<<"\n\n\n\t\t\t->View Data (44)\t\t\t->Requirements (55)\t\t\t\t->Terminate application (66)";


    cout<<"\n\n\n\n\tEnter code here: ";
    cin>>command;

    if(command=="11" ){
        service_system(command);}
    else if(command=="22"){
        search_file();
    }
    else if(command=="44"){
        view_data();
    }
    else if(command=="33"){edit_data();}
    else if(command=="66"){terminate_application();}
    else if(command=="55"){
        requirements();
    }
    else {
            system("cls");
            cout<<"\n ~> You have Entered wrong code please try again";
            goto label_1;
    }

}
void service_system(string command){
    system("color 9F");
    system("cls");
    srand(time(0));
    personal_info get_info;

    cout<<"\t-> Application Page\n";
    cout<<"\n Fill the information below correclty";

    cout<<"\n\n\n\t\t\t\t\tFIRST NAME: ";
    cin>>get_info.fname;


    cout<<"\n\t\t\t\t\tLAST NAME: ";
    cin>>get_info.lname;


    cout<<"\n\t\t\t\t\tMIDDLE NAME: ";
    cin>>get_info.mname;


    cout<<"\n\t\t\t\t\tSEX (M/F): ";
    cin>>get_info.sex;

    cout<<"\n\t\t\t\t\tBirth Information\n";
    cout<<"\n\t\t\t\t\t\tFORMAT(Day/Month/Year): ";
    cin>>get_info.birh_info;

    cout<<"\n\t\t\t\t\tAdress Information\n";
    cout<<"\n\t\t\t\t\t\tCITY: ";
    cin>>get_info.address_data.city;
    cout<<"\n\t\t\t\t\t\tPOSTAL CODE Strictly use 4 digits(OPTIONAL): ";
    cin>>get_info.address_data.pobox;

    cout<<"\n\t\t\t\t\tPASSPORT PAGE NO(Strictly choose form 32 or 64): ";
    cin>>get_info.passport_page;


    for(int i=0;i<4;i++){
        int randnum = 1 + (rand () % 9);
        get_info.application_code += to_string(randnum);
    }
    cout<<"\n\t\tYou have finished entering the information needed. Know save you data\n"<<endl;
    cout<<"\n\n\tEnter 'S' or 's' to Save or(other keys to discard) Your data: ";
    cin>>command;
    if(command=="s" || command=="S"){
        {
        auto now = chrono::system_clock::now();
        time_t timestamp = chrono::system_clock::to_time_t(now);
        tm* localTime = localtime(&timestamp);
        get_info.appointment_day=(to_string(localTime->tm_mday)+"/"+to_string(localTime->tm_mon +5)+"/"+to_string(localTime->tm_year + 1900));}
        cout<<"\n\tYou have successfully applied and Your Application code is : [ "<<get_info.application_code<<" ]"
        <<"\n\t\t\tDO NOT FORGET THIS CODE!(If you forget you must go to view data page to get see it again)";
        file_saver(get_info);
        }
    cout<<"\n\n\tEnter 'r' or 'R' to return to home page and other keys to exit: ";
    cin>>command;
    if(command=="r" || command=="R")
        command_system();
    else
        exit(0);



}
void file_saver(personal_info get_info){
    ofstream file1("PassportData",ios::app);
    if(file1.is_open()){
        file1<<"-------------------------------------------------- Applicant INfO ----------------------------------------------------\n"
        <<"Full Name: "<<get_info.fname<<" "<<get_info.lname<<" "<<get_info.mname<<endl<<"Birth Info: "<<get_info.birh_info<<endl
        <<"SEX: "<<get_info.sex<<endl<<"City: "<<get_info.address_data.city<<endl<<"POBOX: "<<get_info.address_data.pobox<<
        endl<<"Passport Page: "<<get_info.passport_page<<endl<<"Application code: "<<get_info.application_code<<endl<<"Appointment Day: "
        <<get_info.appointment_day<<endl;
        file1.close();
    }
    else{cout<<"Failed to open file!";}

}

void search_file(){
   system("cls");
    label:ifstream getdat("PassportData",ios::in);
    cout<<" -> Check Data and Search Page\n";
    string input;
    cout<<"\n\t\tEnter code use 'r' and 'R' to return to home page: ";
    cin>>input;
    if(input=="r" || input=="R")
        command_system();
   int* verification=new int[2];
   verification=verify_data(input);
    string text;

        if(verification[0]==0){
              //cout<<extract<<endl;
                    system("cls");
                    cout<<"\n\t\t\Applicant founded successfully\n\n";
                    if(getdat.is_open()){
                    getdat.seekg(0,ios::beg);
                    cout<<"--------------------------------- Applicant INfO ---------------------------------\n";
                    for(int j=0;j<verification[1];j++){
                        getline(getdat,text);
                        if(j==verification[1]-8){
                            for(int t=0 ;t<8;t++){
                            getline(getdat,text);
                            cout<<"\t"<<text<<endl;}}
                    }
                    getdat.close();
                    }
                    else{cout<<"Error file not oppened!";}}


        else{
            system("cls");
            getdat.close();
            cout<<"\n\t\t\Their is no applicant with this code!(Give correct code)\n";
            goto label;
            }




   // else{cout<<"Error file not oppened!";}
    cout<<"\n\n\n\n\tEnter 'r' or 'R' to return to home page and other keys to exit: ";
    cin>>input;
    if(input=="r" || input =="R")
        command_system();
    else
        exit(0);

}
void view_data(){
    system("cls");
    cout<<"\n-> View Data Page\n\n\n";
    int no=0;
    label:ifstream getdat("PassportData",ios::in);
    if(getdat.is_open()){
        string text;
        while(!getdat.eof()){
            getline(getdat,text);
            cout<<"\t"<<text<<endl;}getdat.close();}
    else{cout<<"Failed to open file";}
    string input;
    cout<<"\n\n\n\n\tEnter 'r' or 'R' to return to home page and other keys to exit: ";
    cin>>input;
    if(input=="r" || input =="R")
        command_system();
    else
        exit(0);
}
void edit_data(){
    system("cls");
    label:
    personal_info get_info;
    cout<<"\n\n-> Edit Data Page\n\n\n";
    string input,code;
    cout<<"\n\n\t\t\tUse the code next to the Info description which is in the bracket (**) Edit Your Data!\n";
    cout<<"\n\n\n\t\t\t->Name (11)\t\t\t\t->Sex(22)\t\t\t->Birth Information(33)\n\n\n\t\n\n\n\t\t\t->Page Number(44)"
    <<"\t\t\t->Appointment Date(55)\t\t->Address Info[ City(66) & for POBOX(77)]";
    cout<<"\n\n\t\tWhich information do you want to edit(or use r' and 'R' to return to home page: ): ";
    cin>>input;
    cout<<"\n\t\tEnter Application code: ";
    cin>>code;
    int* verification=new int[2];
    verification=verify_data(code);
    if(input=="r" || input=="R")
        command_system();
    else if((input=="11" ||input=="22"||input=="33"||input=="44"||input=="55"||input=="66")&& verification[0]==0){
            string text;
            system("cls");
            if(input=="11"){
                cout<<"\n Fill the information below correclty To edit you name";
                cout<<"\n\n\t\t\tFIRST NAME("<<verification[1]<<"): ";
                cin>>get_info.fname;
                cout<<"\n\t\t\tLAST NAME: ";
                cin>>get_info.lname;
                cout<<"\n\t\t\tMIDDLE NAME: ";
                cin>>get_info.mname;
            }
            else if(input=="22"){
                cout<<"\n Fill the information below correclty To edit you sex";
                cout<<"\n\t\t\t\t\tSEX (M/F): ";
                cin>>get_info.sex;}
            else if(input=="33"){
                cout<<"\n Fill the information below correclty To edit you Birth Information";
                cout<<"\n\t\t\t\t\tBirth Information\n";
                cout<<"\n\t\t\t\t\t\tFORMAT(Day/Month/Year): ";
                cin>>get_info.birh_info;}
            else if(input=="44"){
                cout<<"\n Fill the information below correclty To edit you Passport book Page number";
                cout<<"\n\t\t\t\t\tPASSPORT PAGE NO(Strictly choose form 32 or 64): ";
                cin>>get_info.passport_page;}
            else if(input=="55"){

                auto now = chrono::system_clock::now();
                time_t timestamp = chrono::system_clock::to_time_t(now);
                tm* localTime = localtime(&timestamp);
                get_info.appointment_day=(to_string(localTime->tm_mday)+"/"+to_string(localTime->tm_mon +5)+"/"+to_string(localTime->tm_year + 1900));
                get_info.appointment_day=(to_string(localTime->tm_mday)+"/"+to_string(localTime->tm_mon +5)+"/"+to_string(localTime->tm_year + 1900));}
            else if(input=="66"){
                cout<<"\n\t\t\t\t\tAdress Information\n";
                cout<<"\n\t\t\t\t\t\tCITY: ";
                cin>>get_info.address_data.city;}
            else {
                cout<<"\n\t\t\t\t\tAdress Information\n";
                cout<<"\n\t\t\t\t\t\tPOSTAL CODE Strictly use 4 digits(OPTIONAL): ";
                cin>>get_info.address_data.pobox;}
            editor(get_info,input,verification[1]);}

    else{
        system("cls");
        cout<<"\n\t\t\You have entered either either Application code or wrong service code to edit you data!(Give correct codes)\n";
        goto label;
    }



}
int*  verify_data(string input){
    fstream getdat("PassportData",ios::in);
    int i=0;
    int* verfication= new int[2];
    int is_not_found=1;
  if(getdat.is_open()){
        string text,extract;
        while(!getdat.eof()){

            if((i+1)%9==0){
              extract = text.substr(text.length() - 4);
              //cout<<extract<<endl;
              if(extract==input){
                    is_not_found=0;
                    verfication[0]=is_not_found;
                    verfication[1]=i;
                    break;}}
            getline(getdat,text);
            i++;
            if(extract!=input && getdat.eof()){
                  verfication[0]=is_not_found;
                  verfication[1]=i;
            }
        }

        getdat.close();
        return verfication;
  }
    else{cout<<"Error file not oppened!";}

}
void editor(personal_info get_info,string code,int i){
    ifstream getdat("PassportData",ios::in);
    int j=0;
    string text;
    ofstream newsave("PassportDataNew");
    if(getdat.is_open()&& newsave.is_open()){
    if(code=="11"){

        while(!getdat.eof()){
        getline(getdat,text);
            if(j==(i-7)){
        newsave<<"Full Name: "<<get_info.fname<<" "<<get_info.lname<<" "<<get_info.mname<<endl;}
        else{
            newsave<<text<<endl;
        }j++;}}
    else if(code=="22"){

        while(!getdat.eof()){
        getline(getdat,text);
            if(j==(i-5)){
        newsave<<"SEX: "<<get_info.sex<<endl;}
        else{
            newsave<<text<<endl;
        }j++;}}
    else if(code=="33"){

        while(!getdat.eof()){
        getline(getdat,text);
            if(j==(i-6)){
        newsave<<"Birth Info: "<<get_info.birh_info<<endl;}
        else{
            newsave<<text<<endl;
        }j++;}}
    else if(code=="44"){

        while(!getdat.eof()){
        getline(getdat,text);
            if(j==(i-2)){
        newsave<<"Passport Page: "<<get_info.passport_page<<endl;}
        else{
            newsave<<text<<endl;
        }j++;}}
    else if(code=="55"){

        while(!getdat.eof()){
        getline(getdat,text);
            if(j==(i)){
        newsave<<"Appointment Day: "<<get_info.appointment_day<<endl;}
        else{
            newsave<<text<<endl;
        }j++;}}
    else if(code=="66"){

        while(!getdat.eof()){
        getline(getdat,text);
            if(j==(i-4)){
        newsave<<"City: "<<get_info.address_data.city<<endl;}
        else{
            newsave<<text<<endl;
        }j++;}}
    else{
        while(!getdat.eof()){
        getline(getdat,text);
            if(j==(i-4)){
        newsave<<"POBOX: "<<get_info.address_data.pobox<<endl;}
        else{
            newsave<<text<<endl;
        }j++;}}
    getdat.close();
    newsave.close();

    cout<<"\n\n\t\tYou have successfully edited your information!!!\n\t\tTo see the updated information go to Check data and search info page from the home page";

}



    else
        cout<<"\nFailed to Open the file!";

    rename_delete();


    string input;
    cout<<"\n\n\n\n\tEnter 'r' or 'R' to return to home page and other keys to exit: ";
    cin>>input;
    if(input=="r" || input =="R")
        command_system();
    else
        exit(0);


}
void terminate_application(){
    system("cls");
    label:cout<<"\n\n-> Terminate Data Page\n\n\n";
    string code;
    cout<<"\n\t\tEnter Application code: ";
    cin>>code;

    int* verification=new int[2];
    verification=verify_data(code);
    int j=0,i=verification[1];
    if(verification[0]==0){
        ifstream getdat("PassportData",ios::in);
        ofstream newsave("PassportDataNew");
        int j=0;
        string text;
        if(getdat.is_open()&& newsave.is_open()){

            while(!getdat.eof()){
            getline(getdat,text);
                if((j==(i-8))||(j==(i-7))||(j==(i-6))||(j==(i-5))||(j==(i-4))||(j==(i-3))||(j==(i-2))||(j==(i-1))||(j==(i))){
                    continue;}
            else{
                newsave<<text<<endl;
            }j++;}
            getdat.close();
            newsave.close();
            rename_delete();
            cout<<"\n\n\t\tYou have successfully deleted Your Application You can check by going to view data page";
            }
            else{cout<<"\nFailed to open file!";}
    }
    else{
            system("cls");

            cout<<"\n\t\t\Their is no applicant with this code!(Give correct code)\n";
            goto label;}
    string input;
    cout<<"\n\n\n\n\tEnter 'r' or 'R' to return to home page and other keys to exit: ";
    cin>>input;
    if(input=="r" || input =="R")
        command_system();
    else
        exit(0);


}
void rename_delete(){
    string path_1="PassportData";
    string newname  = "PassportData";
    string oldname = "PassportDataNew";
    remove(path_1.c_str());
    rename(oldname.c_str(),newname.c_str());

}
void requirements(){
       system("cls");
        cout << "\n\n\t\t\t\t\t\t\t\tPASSPORT APPLICATION REQUIREMENTS" << endl;
        cout<<"\n\n\n\t->Personal Information\n\n\n\t\t-FIRST NAME\n\n\n\t\t-LAST NAME\n\n\n\t\t-"<<
        "MIDDLE NAME\n\n\n\t\t-SEX INFO\n\n\n\t\t-BIRTH INFO\n\n\n\t\t\t-DAY/MONTH/YEAR\n\n\n\t\t-Address Info\n\n\n\t\t\t-CITY\n\n\n\t\t\t"
        <<"-POSTAL CODE\n\n\n\t->Every Applicant Should pay 2000ETB via Bank Acount\n\n\n\t\tAccount No: 10000340078";
        string input;
        cout<<"\n\n\n\n\tEnter 'r' or 'R' to return to home page and other keys to exit: ";
        cin>>input;
        if(input=="r" || input =="R")
            command_system();
        else
            exit(0);
}



