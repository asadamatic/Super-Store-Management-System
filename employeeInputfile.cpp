

namespace one
{

void employeeInput()
    {
    
    //Declaring a variable array of type  ' employeeData '
    //This will create a space for 10 employees
    employeeData employees[20];

    //Counter for the number of times, admin has logged into his account
    int adminCount  = 0, adminLoop = 0, jobChoice, endLoop = 1;

    //Declaring a variable  array of type 'adminData'
    adminData admin[2];

    //Array of string type to store the names of jobs, allowing the the ease of editing to the editor
    string jobs[2] = { "Cashier" , "Data Entry"};

    //File Handilng: Storing data of employees in a file
    ofstream FileEmployee;
    FileEmployee.open("employeeInfo.csv", ios::app);
    
    fstream Fileadmin;
    Fileadmin.open("admininfo.txt");
    
  

    Fileadmin >>admin[0].name;
    Fileadmin >>admin[0].password;  
    Fileadmin >>adminCount;
    Fileadmin.close();
    

    //'Loop 1' for admin, to enter employee's data starts here
    while( adminLoop <= 19 && endLoop == 1 )
    {    
        
    //If statment to determine whether the admin is logging in for the first  time    
    if( adminCount == 0 )
    {

    cout <<setw(90)<<"CHOOSE A USER NAME ANE PASSWORD TO MAKE YOUR ACCOUNT SECURE"<<endl<<endl<<endl
         <<setw(62)<<"USER NAME"<<endl<<endl<<endl;
    cout <<setw(57)<<" ";cin >>admin[0].name;
    cout <<endl<<endl;    
    cout <<setw(62)<<"PASSWORD"<<endl<<endl<<endl;
    cout <<setw(57)<<" ";cin >> admin[0].password;
    
    adminCount++;
    Fileadmin.open("admininfo.txt");
    Fileadmin <<admin[0].name<<endl;
    Fileadmin <<admin[0].password<<endl;
    Fileadmin <<adminCount;

    
    } 

    //'1.Else if', to take admin to the new portal after successful login
    else if( adminCount > 0 )
    {      

    enter_again:    
    cout <<setw(80)<<"Please provide your login credentials to proceed"<<endl<<endl<<endl;    
    cout <<setw(62)<<"USER NAME"<<endl<<endl<<endl;
    cout <<setw(57)<<" ";cin >>admin[1].name;
    cout <<endl<<endl; 
    cout <<setw(62)<<"PASSWORD"<<endl<<endl<<endl;
    cout <<setw(57)<<" ";cin >>admin[1].password;
    cout <<endl<<endl<<endl;
    
    //Nested if to allow the admin to login if the ogin credentials are correct
    if( admin[1].name == admin[0].name && admin[1].password == admin[0].password )
    {

    cout <<setw(73)<<"Choose a job for the new employee"<<endl<<endl
         <<setw(75)<<"( Press the corresponding number ) "<<endl<<endl<<endl
         <<setw(40)<<"1. "<<jobs[0]<<endl
         <<setw(40)<<"2. "<<jobs[1]<<endl<<endl;
    cout <<setw(57)<<" ";cin >>jobChoice;

  
    employees[adminLoop].job = jobs[jobChoice-1];     
    cout <<endl<<endl<<endl;
    
    cout <<setw(87)<<"Please provide the following information about your employee"<<endl<<endl<<endl;
    
    //Input = Employee's Name
    cout <<setw(52)<<"NAME       "
         <<setw(27)<<" ";
    getline(cin, employees[adminLoop].name);
    getline(cin, employees[adminLoop].name);
    
    
    //Input = Employee's ID
    cout <<setw(52)<<"ID         "
         <<setw(27)<<" ";
    cin >>employees[adminLoop].id;
    
    

    //Input = Employee's AGE
    cout <<setw(52)<<"AGE        "
         <<setw(27)<<" ";
    cin >>employees[adminLoop].age;
    

    //Input = Employee's CNIC
    cout <<setw(52)<<"CNIC       "
         <<setw(27)<<" ";
    cin >>employees[adminLoop].cnic;
    

    //Input = Employee's Base Salary
    cout <<setw(52)<<"BASE SALARY"
         <<setw(27)<<" ";
    cin >>employees[adminLoop].baseSalary; 
    

    //Input = Employee's Password
    cout <<setw(52)<<"PASSWORD   "
         <<setw(27)<<" ";
    getline(cin, employees[adminLoop].password); 
    getline(cin, employees[adminLoop].password); 
    
    //Storing 'Employee Data' into a file, named "employeeInfo"
    FileEmployee <<employees[adminLoop].name<<","
                 <<employees[adminLoop].id<<","
                 <<employees[adminLoop].age<<","
                 <<employees[adminLoop].cnic<<","
                 <<employees[adminLoop].job<<","
                 <<employees[adminLoop].baseSalary<<","
                 <<employees[adminLoop].password
                 <<endl;
    
    //Counter for Loop in the admin section                          
    adminLoop++;

    //Choice to 'Quit' or add more 'employees'
    cout <<setw(68)<<"Choose and option"<<endl<<endl<<endl
         <<setw(64)<<"1. Continue"<<endl
         <<setw(60)<<"2. Quit"<<endl<<endl;
    cout <<setw(57)<<" "; 
    cin  >>endLoop;
    cout <<endl<<endl;
  
  
   
    }
    else 
    {

    cout <<setw(80)<<"Your username or password is incorrect!"<<endl<<endl<<endl;

    goto enter_again;

    }    
 
    }
    //End of '1.Else if'


    }
    //'Loop 1', for admin to enter employee's data ends here
    }

	
}
