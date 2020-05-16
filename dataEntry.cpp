
namespace three
{
	
	void dataEntry( employeeData employees[20], int count_emp )
{
   
    
    //Array to store the data of products
    productData products[100];

    //Variables to take input from the employee, to verify the employee
    string emp_name, emp_pass;

    

    ifstream FileEmployee1;
    FileEmployee1.open("employeeInfo.csv");

    
    
    enter_again1:
    cout <<setw(80)<<"Please provide your login credentials to proceed"<<endl<<endl<<endl;    
    cout <<setw(62)<<"USER NAME"<<endl<<endl<<endl;
    cout <<setw(57)<<" ";cin >>emp_name;
    cout <<endl<<endl; 
    cout <<setw(62)<<"PASSWORD"<<endl<<endl<<endl;
    cout <<setw(57)<<" ";cin >>emp_pass;
    cout <<endl<<endl<<endl;

    


    for (int a = 0; a < count_emp; a++)
    {    
    
    //If statement, to verify the epmloyee
    if( emp_name == employees[a].name && emp_pass == employees[a].password )
    {
      

    //Nested if statement to verify that the employee is specific for 'Data Entry'
    if( employees[a].job == "Data Entry" )  
    {
      
      two::productInput(products);

      break;
    }  
    else 
    {
       cout <<setw(80)<<"You are not authorized to enter this section!"<<endl<<endl; 
       break;
    }
    //Nested if ends here

    }
    else
    {
        //Nested if, to check for the vaue of loop counter, 'a'
        if( a == count_emp-1 )
        {
        cout <<setw(80)<<"Your username or password is incorrect!"<<endl<<endl<<endl;
        goto enter_again1;
        }
        else
        {
            continue;
        }    
    }    
     
    }
}

}
