#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

//Creating a data type to store all the information related to employee
struct employeeData
{

  string name, id, age, cnic, job, baseSalary, password;

};


//Creating a data type to store the login credentials of admin of the store
struct adminData
{

    string name, password;

};

//Creating a data type to store the information about a 'Product'
struct productData
{

   string id, name, price;

};

//Including Files
#include "employeeInputfile.cpp"
#include "ProductInput.cpp"
#include "dataEntry.cpp"

void creatingbill(employeeData [], productData [], int );

int main()
{ 
    using namespace one;
    using namespace two;
    using namespace three;
   
    //Variable to take input from the user, to guide him to the section he demands
    int choice;

    

    //Declaring a variable array of type  ' employeeData '
    //This will create a space for 10 employees
    employeeData employees[20];

    //Array to store the data of products
    productData products[100];
    
    
    ifstream FileEmployee1;
    FileEmployee1.open("employeeInfo.csv");
    
    int count_emp = 0;
    while( FileEmployee1.good())
    {
    getline(FileEmployee1, employees[count_emp].name, ',');
    getline(FileEmployee1, employees[count_emp].id, ',');
    getline(FileEmployee1, employees[count_emp].age, ',');
    getline(FileEmployee1, employees[count_emp].cnic, ',');
    getline(FileEmployee1, employees[count_emp].job, ',');
    getline(FileEmployee1, employees[count_emp].baseSalary, ',');
    getline(FileEmployee1, employees[count_emp].password);
    
    count_emp++;
    }
    
    while(choice != 4)
    {    
    choice_portal:    
    cout <<setw(90)<<"Select any service by presseing the related number"<<endl<<endl<<endl;
    cout <<setw(88)<<"1. Login as  admin to create employee's account"<<endl<<endl
         <<setw(54)<<"2. Data Entry"<<endl<<endl
         <<setw(51)<<"3. Cashier"<<endl<<endl
         <<setw(48)<<"4. Quit"<<endl<<endl;
    cout <<endl<<endl;
    cout <<setw(57)<<" ";cin >>choice;

    switch( choice  )
    {

    case 1:    
    
    employeeInput();

    break;

    case 2:

    dataEntry(employees, count_emp);

    break;

    case 3:
    
    creatingbill( employees, products, count_emp );

    break;
    
    case  4:
    break;
    default:

    cout <<"Choose from the given services only!"<<endl<<endl;
    
    }
    
}
return 0;
}

void creatingbill( employeeData employees[20], productData products[100], int count_emp )
{
    
    //Variable to take input from the user as 'Product id', and produce results based on that
    string product_id;

    //Variables to take input from the employee, to verify the employee
    string emp_name1, emp_pass1;
    
    int productLoop = 0, endLoop_p2 = 1, quantity = 0, count_p = 0;
    int totalBill = 0;
    //Taking input from the file
	ifstream FileProduct1;
    FileProduct1.open("ProductInfo.csv");
    
    //Creating 'write' mode for the fill 'bill.csv' to enter the bill credentials
    ofstream bill;
    bill.open("bill.csv", ios::app);
    
    while( FileProduct1.good() )
    {
    getline(FileProduct1, products[count_p].id, ',');
    getline(FileProduct1, products[count_p].name, ',');
    getline(FileProduct1, products[count_p].price);
    

         cout <<endl;
    
    count_p++;    
    }
    

    
    cout <<setw(80)<<"Please provide your login credentials to proceed"<<endl<<endl<<endl;    
    cout <<setw(62)<<"USER NAME"<<endl<<endl<<endl;
    cout <<setw(57)<<" ";cin >>emp_name1;
    cout <<endl<<endl; 
    cout <<setw(62)<<"PASSWORD"<<endl<<endl<<endl;
    cout <<setw(57)<<" ";cin >>emp_pass1;
    cout <<endl<<endl<<endl;

    

    int b;
    for ( b = 0; b < count_emp; b++)
    {    
    
    //If statement, to verify the epmloyee
    if( emp_name1 == employees[b].name && emp_pass1 == employees[b].password )
    {
      

    //Nested if statement to verify that the employee is specific for 'Data Entry'
    if( employees[b].job == "Cashier" )  
    {
         

        bill  <<"NEW Bill"<<endl;
    while ( productLoop <= 100 && endLoop_p2 == 1 )
    {    
         
         enter_again2:
         cout <<setw(65)<<"Enter the product id"<<endl<<endl<<endl;
         cout <<setw(57)<<"";
         cin >>product_id;

         cout <<setw(65)<<"Enter the product quantity"<<endl<<endl<<endl;
         cout <<setw(57)<<"";
         cin >>quantity;
         
    
    //Variable to run the loop depending upon the number of entries in the file 'ProductInfo.csv'
    int p_check;
    int productTotal =0;
    
    for( p_check = 0; p_check < count_p; p_check++)
    {   

    if( product_id == products[p_check].id )
    {  
        
       
    
        productTotal += stoi(products[p_check].price)*quantity;
        //Storing 'Product Data' into a file, named "bill"
        bill        <<products[p_check].id<<","
                    <<products[p_check].name<<","
                    <<quantity<<","
                    <<products[p_check].price<<","
                    <<productTotal
                    <<endl;
        totalBill += productTotal;
        productLoop++;
        break;

        }   

    }
        //If statement to print a message if the employee is not a cashier
    if ( p_check == count_p )
    {   

        cout <<setw(80)<<"The id you entered does not belong to any product!"<<endl<<endl;
        goto enter_again2;
        }
        

        //Choice to 'Quit' or add more 'products'
        cout <<setw(68)<<"Choose and option"<<endl<<endl<<endl
             <<setw(64)<<"1. Continue"<<endl
             <<setw(60)<<"2. Quit"<<endl<<endl;
        cout <<setw(57)<<" "; 
        cin  >>endLoop_p2;
        cout <<endl<<endl;

    }

    //Counter for the number of products[emp_loop] and loop
    
    break;
     
    }  
    else 
    {
       cout <<setw(80)<<"You are not authorized to enter this section!"<<endl<<endl;
    
       break;
    }
    //Nested if ends here

    }

      //Else if for the if 'verification' if statement
    else
    {
        //Nested if, to check for the vaue of loop counter, 'b'
    if( b == count_emp-1 )
    {
        cout <<setw(80)<<"Your username or password is incorrect!"<<endl<<endl<<endl;
       
    }  

    }    

    }

       bill <<"  "<<','
            <<"  "<<','
            <<"  "<<','
            <<"TOTAL"<<','
            <<totalBill<<endl
            <<endl;

}
