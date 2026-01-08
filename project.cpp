#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

struct staff
{
    string staffType ;
    string name ;
    string age ;
    string gender ;
    string department ;
    string year ;
    string identity ;
};

struct patient
{
    string name ;
    string age ;
    string year ;
    string gender ;
    string identity ;
    string desease[100] ;
    string bloodPressure[100] ;
    string sugarLevel[100] ;
    string Time[100] ;
};

staff staffDoctor[1000] ;
staff staffNurse[1000] ;
patient patients[100000] ;

int patientCount = 0 ;
int nurseCount = 0 ;
int doctorCount = 0 ;

void makeDoctorIds(string) ;
void makeNurseIds(string) ;
void makePatientIds() ;
void stater() ;
void setcl(int, int) ;
void mainHeader() ;
void menuBox() ;
void invalidOption() ;
void IdIsinvalid() ;
void pressAnyKey() ;
void checkUpMenu() ;
void seeAllIdentities() ;
void showAllPatiantIds() ; 
void showAllDoctosIds() ;
void showAllNursesIds() ;
bool checksId(string ) ; 
string mainMenu() ;
string staffTypeMenu() ;

int main()
{
    system("cls") ;
    stater() ;
    getch() ;
    while(true)
    {
        string m = mainMenu();

        if (m == "1")
        {  
            string opt = staffTypeMenu();
            if (opt == "1")
            {
                makeDoctorIds("Doctor");
            }
            else if (opt == "2")
            {
                makeNurseIds("Nurse");
            }
            else if (opt == "3")
            {
                continue;
            }
            else
            {
                invalidOption();
            }
        }
        else if (m == "2")
        {
            mainHeader();
            setcl(1,0);
            cout << "                                                [   E N T E R     N E W     P A T I E N T   ]" <<endl <<endl ;
            setcl(6,0);
            makePatientIds();
        }
        else if (m == "3")
        {
            mainHeader();
            setcl(1,0);
            cout << "                                                [   R E T R I E V E     D A T A     B Y     I D   ]" <<endl <<endl ;
            setcl(6,0);

            string id ;
            cout << " Enter id : " ;
            cin >> id ;
            
            if (!checksId(id)) continue;

            int temp = -1;
            int index = -1;

            if (id[0] == 'D')
            {
                for(int i = 0 ; i < doctorCount ; i++ )
                {
                    if ( id == staffDoctor[i].identity )
                    {
                        temp = 1 ;
                        index = i ;
                        break ;
                    }
                }
                
                if( temp != -1 ) 
                {
                    setcl(5,0); cout << "                                    ===============================================================================================" << endl; setcl(6,0);
                    cout << "                                                        status     :  Doctor\n";
                    cout << "                                                        Name       :  " << staffDoctor[index].name << "\n";
                    cout << "                                                        Age        :  " << staffDoctor[index].age << "\n";
                    cout << "                                                        Gender     :  " << staffDoctor[index].gender << "\n";
                    cout << "                                                        Department :  " << staffDoctor[index].department << "\n";
                    setcl(5,0); cout << "                                    ===============================================================================================" << endl; setcl(6,0);
                    pressAnyKey();
                }
                else 
                {
                    setcl(4,0); cout << "       >>   This Id does not exists   << \n" ; setcl(6,0); getch();
                }
            }
            else if (id[0] == 'N')
            {
                for(int i = 0 ; i < nurseCount ; i++ )
                {
                    if ( id == staffNurse[i].identity )
                    {
                        temp = 1 ;
                        index = i ;
                        break ;
                    }
                }
                if( temp == -1 )
                {
                    setcl(4,0);
                    cout << "       >>   This Id does not exists   << \n" ;
                    setcl(6,0);
                    getch() ;
                }
                else 
                {
                    setcl(5,0); cout << "                                    ===============================================================================================" << endl; setcl(6,0);
                    cout << "                                                        status     :  Nurse\n";
                    cout << "                                                        Name       :  " << staffNurse[index].name << "\n";
                    cout << "                                                        Age        :  " << staffNurse[index].age << "\n";
                    cout << "                                                        Gender     :  " << staffNurse[index].gender << "\n";
                    cout << "                                                        Department :  " << staffNurse[index].department << "\n";
                    setcl(5,0); cout << "                                    ===============================================================================================" << endl; setcl(6,0);
                    pressAnyKey();
                }
            }
            else if (id[0] == 'P')
            {
                for(int i = 0 ; i < patientCount ; i++ )
                {
                    if ( id == patients[i].identity )
                    {
                        temp = 1 ;
                        index = i ;
                        break ;
                    }
                }
                if( temp == -1 )
                {
                    setcl(4,0);
                    cout << "       >>   This Id does not exists   << \n" ;
                    setcl(6,0);
                    getch() ;
                }
                else
                {
                    setcl(5,0); cout << "                                    ===============================================================================================" << endl; 
                    cout << "                                     status     :  " ;setcl(8,0);
                    cout << "Patient ";setcl(5,0); cout << " | ";
                    cout << "   Name   :  " ;setcl(8,0); 
                    cout << patients[index].name ;setcl(5,0); cout << " | ";
                    cout << "   Age    :  " ;setcl(8,0); 
                    cout << patients[index].age ;setcl(5,0); cout << " | ";
                    cout << "   Gender     :  " ;setcl(8,0);
                    cout << patients[index].gender << "\n" ;

                    setcl(5,0); cout << "                                    --------------------------------------- Medical History --------------------------------------\n"; setcl(6,0);
                    bool history = false;
                    for(int i=0; i<100; i++) {
                        if(patients[index].desease[i] != "") {
                            history = true;
                            cout << "                                    " << i+1 << "Time :" << patients[index].Time[i] << " Disease: " << patients[index].desease[i] 
                                 << " | BP: " << patients[index].bloodPressure[i] 
                                 << " | Sugar: " << patients[index].sugarLevel[i] << endl;
                        }
                    }
                    if(!history) cout << "                                                           No history found.\n";

                    setcl(5,0); cout << "                                    ===============================================================================================" << endl; setcl(6,0);
                    pressAnyKey();
                }
            }
        } 
        else if ( m == "4")
{
    mainHeader() ;
    setcl(3,0) ;
    checkUpMenu() ;
    setcl(6,0) ;
    string id ;
    cout << "                         -> Enter patient id : " ;
    setcl(4,0) ;
    cin >> id ;
    setcl(6,0) ;
    cout <<endl <<endl <<endl  ;

    if (id[0] == 'P') 
    {
        int index_ = -1 ;
        int temp_ = -1 ;
        
        if (!checksId(id))  continue; // Restart loop if ID is invalid

        for(int i = 0 ; i < patientCount ; i++ )
        {
            if ( id == patients[i].identity )
            {
                temp_ = 1 ;
                index_ = i ;
                break ;
            }
        }
        if( temp_ == -1 )
        {
            setcl(4,0);
            cout << "       >>   This Id does not exists   << \n" ;
            setcl(6,0);
            getch() ;
            continue; 
        }

        int checkUpCount = -1; 

        // Find the first empty slot
        for (int i = 0; i < 100; i++)
        {
            if (patients[index_].desease[i] == "") 
            {
                    checkUpCount = i;
                    break;
            }
        }


        if ( checkUpCount != -1) 
        {
            cout << "                      **********************************************************" <<endl ;
            cout <<  "                      Enter disease of patient              :  " ;
            cin >> patients[index_].desease[checkUpCount] ;
            cout <<  "                      Enter Blood Pressure of patient       :  " ;
            cin >> patients[index_].bloodPressure[checkUpCount] ;
            cout <<  "                      Enter sugar level of patient          :  " ;
            cin >> patients[index_].sugarLevel[checkUpCount] ;
            cout <<  "                      Enter day/date/year                   :  " ;
            cin >> patients[index_].Time[checkUpCount]  ;
            
            setcl(2,0);
            cout <<endl <<endl << "                         >> Checkup Added Successfully at " << patients[index_].Time[checkUpCount] << " << "  <<endl;
            setcl(6,0);
            getch();
        }
        else 
        {
            setcl(4,0);
            cout << "       >>   Patient History Full   << \n" ;
            setcl(6,0);
            getch();
        }
    }
    else
    {
        cout << "                        >>  This is not a valid patient Id   <<" ;
        getch();
    }
}
        else if ( m == "5")
        {
            seeAllIdentities() ;
        }
        else if ( m == "6")
        {
            mainHeader();
            setcl(2,0);
            cout <<endl <<endl <<endl <<endl<< "                                                     >>  Thanks for using this application.  <<\n\n";
            setcl(6,0);
            break ;
        }
        else
        {
            invalidOption();
        }
    }
}


void makeDoctorIds(string type)
{
    mainHeader();
    setcl(1,0);
    cout << "                                                [   H I R E     D O C T O R   ]" <<endl <<endl ;
    setcl(6,0);

    staffDoctor[doctorCount].staffType = type ;
    cout << " Enter " << staffDoctor[doctorCount].staffType << " name            : " ;
    cin >> staffDoctor[doctorCount].name ;
    cout << " Enter " << staffDoctor[doctorCount].staffType << " age             : " ;
    cin >> staffDoctor[doctorCount].age ;
    cout << " Enter " << staffDoctor[doctorCount].staffType << " gender          : " ;
    cin >> staffDoctor[doctorCount].gender ;
    cout << " Enter " << staffDoctor[doctorCount].staffType << " department      : " ;
    cin >> staffDoctor[doctorCount].department ;

    while(true)
    {
        cout << " Enter " << staffDoctor[doctorCount].staffType << " hiring year     : " ;
        cin >> staffDoctor[doctorCount].year ;
        bool invalid = false; 
        for (int i = 0; i < staffDoctor[doctorCount].year.length() ; i++)
        {
            if (!(staffDoctor[doctorCount].year[i] >= '0' && staffDoctor[doctorCount].year[i] <= '9'))
            {
                invalid = true;
                break;
            }
        }
        if ( invalid )
        {
            setcl(4,0);
            cout << "          >>> invalid year  <<<  " << endl ;
            cout << "  *year  must be of 4 digit positive integer * " << endl ;
            setcl(6,0);
            getch() ;
            continue ;
        }
        int checkYear = stoi(staffDoctor[doctorCount].year) ;
        if( checkYear > 999 && checkYear < 10000)
        {
            break ;
        }
        setcl(4,0);
        cout << "     >>> invalid year  <<<  " << endl ;
        cout << "  *year  must be of 4 digits* " << endl ;
        setcl(6,0);
        getch() ;
    }

    string serialNumber = to_string(doctorCount) ;
    if ( doctorCount < 10 )
        serialNumber = "000" + serialNumber ;
    else if( doctorCount < 100 )
        serialNumber = "00" + serialNumber ;
    else
        serialNumber = "0" + serialNumber ;

    string checkAssigner = staffDoctor[doctorCount].year + serialNumber ;
    int num = stoi(checkAssigner) ;

    int num1 =  num / 10000000 ;
    int num2 = (num / 1000000) % 10 ;
    int num3 = (num / 100000) % 10 ;
    int num4 = (num / 10000) % 10 ;
    int num5 = (num / 1000) % 10 ;
    int num6 = (num / 100) % 10 ;
    int num7 = (num / 10) % 10 ;
    int num8 =  num  % 10 ;

    int sum = (num1*1) + (num2*2) + (num3*3) + (num4*4) + (num5*5) + (num6*6) + (num7*7) + (num8*8)  ;

    

    int Check = sum % 11 ;
    string check = to_string(Check) ;

    staffDoctor[doctorCount].identity = "D-" + staffDoctor[doctorCount].year + "-" + serialNumber + "-" + check ;

    setcl(2,0);
    cout << "\n   >> Doctor Added Successfully <<\n";
    setcl(6,0);
    cout << "   ID : " << staffDoctor[doctorCount].identity << "\n";
    getch() ;
    doctorCount ++ ;
}

void makeNurseIds(string type)
{
    mainHeader();
    setcl(1,0);
    cout << "                                                [   H I R E     N U R S E   ]\n\n";
    setcl(6,0);

    staffNurse[nurseCount].staffType = type ;
    cout << " Enter " << staffNurse[nurseCount].staffType << " name            : " ;
    cin >> staffNurse[nurseCount].name ;
    cout << " Enter " << staffNurse[nurseCount].staffType << " age             : " ;
    cin >> staffNurse[nurseCount].age ;
    cout << " Enter " << staffNurse[nurseCount].staffType << " gender          : " ;
    cin >> staffNurse[nurseCount].gender ;
    cout << " Enter " << staffNurse[nurseCount].staffType << " department      : " ;
    cin >> staffNurse[nurseCount].department ;

    while(true)
    {
        cout << " Enter " << staffNurse[nurseCount].staffType << " hiring year     : " ;
        cin >> staffNurse[nurseCount].year ;
        bool invalid = false; 
        for (int i = 0; i < staffNurse[nurseCount].year.length() ; i++)
        {
            if (!(staffNurse[nurseCount].year[i] >= '0' && staffNurse[nurseCount].year[i] <= '9'))
            {
                invalid = true;
                break;
            }
        }
        if ( invalid )
        {
            setcl(4,0);
            cout << "          >>> invalid year  <<<  " << endl ;
            cout << "  *year  must be of 4 digit positive integer * " << endl ;
            setcl(6,0);
            getch() ;
            continue;
        }
        int checkYear = stoi(staffNurse[nurseCount].year) ;
        if( checkYear > 999 && checkYear < 10000)
        {
            break ;
        }
        setcl(4,0);
        cout << "     >>> invalid year  <<<  " << endl ;
        cout << "  *year  must be of 4 digits* " << endl ;
        setcl(6,0);
        getch() ;
    }

    string serialNumber = to_string(nurseCount) ;
    if ( nurseCount < 10 )
        serialNumber = "000" + serialNumber ;
    else if( nurseCount < 100 )
        serialNumber = "00" + serialNumber ;
    else
        serialNumber = "0" + serialNumber ;

    string checkAssigner = staffNurse[nurseCount].year + serialNumber ;
    int num = stoi(checkAssigner) ;

    int num1 =  num / 10000000 ;
    int num2 = (num / 1000000) % 10 ;
    int num3 = (num / 100000) % 10 ;
    int num4 = (num / 10000) % 10 ;
    int num5 = (num / 1000) % 10 ;
    int num6 = (num / 100) % 10 ;
    int num7 = (num / 10) % 10 ;
    int num8 =  num  % 10 ;

    int sum = (num1*1) + (num2*2) + (num3*3) + (num4*4) + (num5*5) + (num6*6) + (num7*7) + (num8*8)  ;

    

    int Check = sum % 11 ;
    string check = to_string(Check) ;

    staffNurse[nurseCount].identity = "N-" + staffNurse[nurseCount].year + "-" + serialNumber + "-" + check ;

    setcl(2,0);
    cout << "\n   >> Nurse Added Successfully <<\n";
    setcl(6,0);
    cout << "   ID : " << staffNurse[nurseCount].identity << "\n";
    getch() ;
    nurseCount ++ ;
}

void makePatientIds()
{
    
    cout << " Enter patient name   : " ;
    cin >> patients[patientCount].name ;
    cout << " Enter patient age    : " ;
    cin >> patients[patientCount].age ;
    cout << " Enter patient gender : " ;
    cin >> patients[patientCount].gender ;

    while(true)
    {
        cout << " Enter patient year   : " ;
        cin >> patients[patientCount].year ;
        bool invalid = false; 
        for (int i = 0; i < patients[patientCount].year.length() ; i++)
        {
            if (!(patients[patientCount].year[i] >= '0' && patients[patientCount].year[i] <= '9'))
            {
                invalid = true;
                break;
            }
        }
        if ( invalid )
        {
            setcl(4,0);
            cout << "          >>> invalid year  <<<  " << endl ;
            cout << "  *year  must be of 4 digit positive integer * " << endl ;
            setcl(6,0);
            getch() ;
            continue;
        }
        int checkYear = stoi(patients[patientCount].year) ;
        if( checkYear > 999 && checkYear < 10000)
        {
            break ;
        }
        setcl(4,0);
        cout << "         >>> invalid year  <<<  " << endl ;
        cout << "  *year  must be of 4 digits positive integer * " << endl ;
        setcl(6,0);
        getch() ;
    }

    string serialNumber = to_string(patientCount) ;
    if ( patientCount < 10    ) 
            serialNumber = "00000" + serialNumber ;
    else if( patientCount < 100   ) 
            serialNumber = "0000" + serialNumber ;
    else if( patientCount < 1000  ) 
            serialNumber = "000" + serialNumber ;
    else if( patientCount < 10000 )
            serialNumber = "00" + serialNumber ;
    else    
            serialNumber = "0" + serialNumber ;

    string checkAssigner = patients[patientCount].year + serialNumber ;
    int num = stoi(checkAssigner) ;

    int num1  =  num / 1000000000 ;
    int num2  = (num / 100000000) % 10 ;
    int num3  = (num / 10000000) % 10 ;
    int num4  = (num / 1000000) % 10 ;
    int num5  = (num / 100000) % 10 ;
    int num6  = (num / 10000) % 10 ;
    int num7  = (num / 1000) % 10 ;
    int num8  = (num / 100) % 10 ;
    int num9  = (num / 10) % 10 ;
    int num10 =  num  % 10 ;

    int sum = (num1*1) + (num2*2) + (num3*3) + (num4*4) + (num5*5) + (num6*6) + (num7*7) + (num8*8) + (num9*9) + (num10*10) ;

    int Check = sum % 11 ;
    string check = to_string(Check) ;

    patients[patientCount].identity = "P-" + patients[patientCount].year + "-" + serialNumber + "-" + check ;

    setcl(2,0);
    cout <<endl << endl << "   >> Patient Added Successfully << " <<endl <<endl;
    setcl(6,0);
    cout << "   ID : " << patients[patientCount].identity <<endl <<endl;
    getch() ;
    patientCount ++ ;
}
void stater()
{
   cout <<endl <<endl<<endl <<endl<<endl <<endl<<endl <<endl<<endl <<endl <<"                                         Hospital Management System " <<endl ;   
}
string mainMenu()
{
    mainHeader();
    setcl(1,0);
    cout << "                                                     [   M   A   I   N       M    E    N   U   ]" <<endl  <<endl;
    setcl(6,0);
    cout << "                                                 [C H O O S E    O N E    O F   T H E   F O L L O W I N G]" <<endl <<endl;
    menuBox();

    setcl(5,0);
    cout << "                                                       ---------------------------" <<endl;
    cout << "                                                       >>   Choose option : ";
    setcl(4,0);
    string opt;
    cin >> opt;
    setcl(6,0);
    return opt;
}
void checkUpMenu()
{
    setcl(4,0);
    cout << "                                                 [C H O O S E    O N E    O F   T H E   F O L L O W I N G]" <<endl <<endl;
    setcl(6,0);

}
string staffTypeMenu()
{
    mainHeader();
    setcl(1,0);
    cout << "                                                        [   H I R E     N E W     S T A F F   ]" <<endl <<endl ;
    setcl(6,0);
    cout << "                                                 [C H O O S E    O N E    O F   T H E   F O L L O W I N G]" <<endl <<endl ;
    cout << "                                                         ----------------------------------------" <<endl;
    cout << "                                                         | ************************************ |" <<endl;
    cout << "                                                         | *  1-> Doctor                      * |" <<endl;
    cout << "                                                         | *  2-> Nurse                       * |" <<endl;
    cout << "                                                         | *  3-> Back                        * |" <<endl;
    cout << "                                                         | ************************************ |" <<endl;
    cout << "                                                         ----------------------------------------" <<endl <<endl;
    setcl(5,0);
    cout << "                                                 ---------------------------" <<endl ;
    cout << "                                                 >>   Choose option : ";
    setcl(4,0);
    string opt;
    cin >> opt;
    setcl(6,0);
    return opt;
}
void mainHeader()
{
    system("cls");
    setcl(8,0);
    cout << endl <<endl ;
    cout << "                                         _______________________________________________________________________________" <<endl ;
    cout << "                                         ###############################################################################" <<endl ;
    setcl(5,0);
    cout << "                                                    H O S P I T A L   M A N A G E M E N T   S Y S T E M" <<endl ;
    setcl(8,0);
    cout << "                                         _______________________________________________________________________________"  <<endl ;
    cout << "                                         ###############################################################################" <<endl <<endl ;
    setcl(6,0);
}
void menuBox()
{
    setcl(6,0);
    cout << "                                                         -----------------------------------------" <<endl ;
    cout << "                                                         | ************************************* |" <<endl;
    cout << "                                                         | *  1-> Hire new staff member        * |" <<endl;
    cout << "                                                         | *  2-> Enter new patient            * |" <<endl;
    cout << "                                                         | *  3-> Retrieve data by ID          * |" <<endl;
    cout << "                                                         | *  4-> Add Checkup                  * |" <<endl;
    cout << "                                                         | *  5-> See All Existing Identities  * |" <<endl;
    cout << "                                                         | *  6-> Exit                         * |" <<endl;
    cout << "                                                         | ************************************* |" <<endl;
    cout << "                                                         -----------------------------------------" <<endl <<endl;
}
void invalidOption()
{
    mainHeader();
    setcl(4,0);
    cout << endl <<endl ;
    cout << "                                                       --------------------------------------------" <<endl;
    cout << "                                                       | **************************************** |" <<endl;
    cout << "                                                       | *   I N C O R R E C T   O P T I O N    * |" <<endl;
    cout << "                                                       | **************************************** |" <<endl;
    cout << "                                                       --------------------------------------------" <<endl <<endl;
    setcl(6,0);
    cout << "                                                [ P R E S S    A N Y    K E Y    T O     C O N T I N U E . . . ]";
    getch();
}
void IdIsinvalid()
{
    setcl(4,0);
    cout << "\n    >>   invalid id   <<\n";
    setcl(6,0);
    getch();
}
void pressAnyKey()
{
    setcl(6,0);
    cout <<endl <<endl<< "                                               [ P R E S S    A N Y    K E Y    T O     C O N T I N U E . . . ]";
    getch();
}
void setcl(int text, int background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (background << 4));
}
bool checksId(string id)
{

    if (id.length() < 13)
            {
                IdIsinvalid();
                return false; 
            }
            if ( id[0] != 'P' && id[0] != 'D' && id[0] != 'N' )
            {
                IdIsinvalid();
                return false;
            }
            if ( id[1] != '-' )
            {
                IdIsinvalid();
                return false;
            }
            if (id.length() < 7)
            {
                IdIsinvalid();
                return false;
            }

            string str = "" ;
            for ( int i = 5 ; i >= 2 ; i-- )
            {
                str = id[i] + str ;
            }

            int yearCheck = stoi(str) ;

            if ( yearCheck < 1000 || yearCheck > 9999)
            {
                IdIsinvalid();
                return false;
            }

            if ( id[6] != '-' )
            {
                IdIsinvalid();
                return false;
            }

            string serialStr = "" ;
            string checkStr  = "" ;

            bool invalid = false;

            if (id[0] == 'D' || id[0] == 'N')
            {
                if (id.length() != 13 && id.length() != 14)
                {
                    IdIsinvalid();
                    return false;
                }

                for (int i = 7; i <= 10; i++)
                {
                    if (!(id[i] >= '0' && id[i] <= '9'))
                    {
                        invalid = true;
                        break;
                    }
                    serialStr += id[i];
                }
                if (invalid)
                {
                    IdIsinvalid();
                    return false;
                }

                if (id[11] != '-')
                {
                    IdIsinvalid();
                    return false;
                }

                checkStr = id.substr(12);
                if (!(checkStr.length() == 1 || checkStr.length() == 2))
                {
                    IdIsinvalid();
                    return false;
                }
            }
            else if (id[0] == 'P')
            {
                if (id.length() != 15 && id.length() != 16)
                {
                    IdIsinvalid();
                    return false;
                }

                for (int i = 7; i <= 12; i++)
                {
                    if (!(id[i] >= '0' && id[i] <= '9'))
                    {
                        invalid = true;
                        break;
                    }
                    serialStr += id[i];
                }
                if (invalid)
                {
                    IdIsinvalid();
                    return false;
                }

                if (id[13] != '-')
                {
                    cout << "      >>  Invalid format   <<" << endl ;
                    IdIsinvalid();
                    return false;
                }

                checkStr = id.substr(14);
                if (!(checkStr.length() == 1 || checkStr.length() == 2))
                {
                    cout << "      >>  Invalid format   <<" << endl ;
                    IdIsinvalid();
                    return false;
                }
            }

            for (int i = 0; i < checkStr.length(); i++)
            {
                if (!(checkStr[i] >= '0' && checkStr[i] <= '9'))
                {
                    IdIsinvalid();
                    invalid = true;
                    break;
                }
            }
            if (invalid) return false;

            int serialNumberCheck = stoi(serialStr) ;
            int takeCheck = stoi(checkStr) ;

            if (takeCheck < 0 || takeCheck > 10)
            {
                cout << "           >>  Invalid Check  <<" ;
                IdIsinvalid();
                return false;
            }

            int sum = 0;

            if (id[0] == 'D' || id[0] == 'N')
            {
                int num = yearCheck * 10000 + serialNumberCheck;

                int num1 =  num / 10000000 ;
                int num2 = (num / 1000000) % 10 ;
                int num3 = (num / 100000) % 10 ;
                int num4 = (num / 10000) % 10 ;
                int num5 = (num / 1000) % 10 ;
                int num6 = (num / 100) % 10 ;
                int num7 = (num / 10) % 10 ;
                int num8 =  num  % 10 ;

                sum = (num1*1) + (num2*2) + (num3*3) + (num4*4) + (num5*5) + (num6*6) + (num7*7) + (num8*8)  ;
            }
            else if (id[0] == 'P')
            {
                int num = yearCheck * 1000000 + serialNumberCheck;

                int num1  =  num / 1000000000 ;
                int num2  = (num / 100000000) % 10 ;
                int num3  = (num / 10000000) % 10 ;
                int num4  = (num / 1000000) % 10 ;
                int num5  = (num / 100000) % 10 ;
                int num6  = (num / 10000) % 10 ;
                int num7  = (num / 1000) % 10 ;
                int num8  = (num / 100) % 10 ;
                int num9  = (num / 10) % 10 ;
                int num10 =  num  % 10 ;

                sum = (num1*1) + (num2*2) + (num3*3) + (num4*4) + (num5*5) + (num6*6) + (num7*7) + (num8*8) + (num9*9) + (num10*10) ;
            }

            int expectedCheck = sum % 11;

            if (expectedCheck != takeCheck)
            {
                setcl(4,0);
                cout <<endl << "      >>  Valid Format but <<"  <<endl ;
                cout <<endl << "       >>   Invalid check <<"  <<endl ;
                cout <<endl << "       >>    invalid id   <<" <<endl ;
                setcl(6,0);
                getch();
                return false;
            }

            setcl(2,0);
            cout <<endl  << "             >> valid id  <<" <<endl ;
            setcl(6,0);

            return true;
}
void seeAllIdentities()
{
    mainHeader();
    setcl(1, 0);
    cout << "                                        [   V I E W     A L L    I D E N T I T I E S   ]  " <<endl ;
    setcl(6, 0);
    string passward;
    cout << "                        Enter password : ";
    setcl(4, 0);
    cin >> passward;
    if (passward == "123456789")
    {
        while (true)
        {
            system("cls");
            mainHeader();
            setcl(1, 0);
            cout << "                                        [   V I E W     A L L    I D E N T I T I E S   ]  " << endl << endl;
            cout << "                                        [   C H O O S E   W H O  Y O U   W A N T   T O   S E E    ]  " << endl << endl;;
            setcl(6, 0);
            cout << "                                                         ----------------------------------------" << endl;
            cout << "                                                         | ************************************ |" << endl;
            cout << "                                                         | *  1-> TO SEE DOCTOR IDENTITIES      * |" << endl;
            cout << "                                                         | *  2-> TO SEE NURSES IDENTIES      * |" << endl;
            cout << "                                                         | *  3-> TO SEE PATIENT IDENTIES     * |" << endl;
            cout << "                                                         | *  4-> GO TO MAIN MENU             * |" << endl;
            cout << "                                                         | ************************************ |" << endl;
            cout << "                                                         ----------------------------------------" << endl << endl;
            setcl(5, 0);
            cout << "                                          >>   Enter  here : ";
            setcl(4, 0);
            string opt;
            cin >> opt;
            setcl(5, 0);
            
            if (opt == "1")
            {
                showAllDoctosIds();
            }
            else if (opt == "2")
            {
                showAllNursesIds();
            }
            else if (opt == "3")
            {
                showAllPatiantIds();
            }
            else if (opt == "4")
            {
                break;
            }
            else
            {
                invalidOption();
            }
        }
    }
    else {
        cout << endl << endl << endl << endl;
        setcl(4, 0);
        cout << "                                          >>   INCORRECT      PASSWORD   <<   ";
        setcl(6, 0);
        getch();
    }
}

void showAllPatiantIds()
{
    system("cls");
    mainHeader();
    setcl(1, 0);
    cout << "                                            [   P A T I E N T     L I S T   ]  " << endl << endl;
    
    setcl(7, 0);
    cout << "               _______________________________________________________________________________" << endl;
    setcl(5, 0);
    cout << "                                   IDENTITIES                       NAMES   " << endl;
    setcl(7, 0);
    cout << "               _______________________________________________________________________________" << endl;
    setcl(9, 0);
    
    if (patientCount == 0) {
        cout << "\n                                   NO RECORDS FOUND" << endl;
    }

    for (int i = 0; i < patientCount; i++)
    {
        if (patients[i].identity != "")
            cout << "                                   " << patients[i].identity << "  |  " << patients[i].name << endl;
    }
    
    setcl(7, 0);
    cout << endl << "               _______________________________________________________________________________" << endl;
    setcl(6,0);
    cout << "\n                                   Press any key to return...";
    getch();
}

void showAllDoctosIds()
{
    system("cls");
    mainHeader();
    setcl(1, 0);
    cout << "                                             [   D O C T O R     L I S T   ]  \n\n";

    setcl(7, 0);
    cout << "               _______________________________________________________________________________" << endl;
    setcl(5, 0);
    cout << "                                   IDENTITIES                       NAMES   " << endl;
    setcl(7, 0);
    cout << "               _______________________________________________________________________________" << endl;
    setcl(9, 0);

    if (doctorCount == 0) {
        cout << "\n                                   NO RECORDS FOUND" << endl;
    }
    for (int i = 0; i < doctorCount; i++)
    {
        if (staffDoctor[i].identity != "")
            cout << "                                   " << staffDoctor[i].identity << "  |  " << staffDoctor[i].name << endl;
    }

    setcl(7, 0);
    cout << endl << "               _______________________________________________________________________________" << endl;
    setcl(6, 0);
    cout <<endl <<"                                  Press any key to return...";
    getch();

}

void showAllNursesIds()
{
    system("cls");
    mainHeader();
    setcl(1, 0);
    cout << "                                              [   N U R S E     L I S T   ]  " <<endl;

    setcl(7, 0);
    cout << "               _______________________________________________________________________________" << endl;
    setcl(5, 0);
    cout << "                                   IDENTITIES                       NAMES   " << endl;
    setcl(7, 0);
    cout << "               _______________________________________________________________________________" << endl;
    setcl(9, 0);

    if (nurseCount == 0) {
        cout <<endl << "                                   NO RECORDS FOUND" << endl;
    }
    for (int i = 0; i < nurseCount; i++)
    {
        if (staffNurse[i].identity != "")
            cout << "                                   " << staffNurse[i].identity << "  |  " << staffNurse[i].name << endl;
    }

    setcl(7, 0);
    cout << endl << "               _______________________________________________________________________________" << endl;
    setcl(6, 0);
    cout << "\n                                   Press any key to return...";
    getch();

}