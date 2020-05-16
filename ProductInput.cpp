namespace two
{

     void productInput(productData products[100])
     
     {


     int emp_loop = 0, endLoop_p = 1; 

     

     ofstream FileProduct;
     FileProduct.open("ProductInfo.csv", ios::app);
     
     while( emp_loop <= 99 && endLoop_p == 1 )
     {
     cout <<setw(87)<<"Please provide the following data about the products[emp_loop]"<<endl<<endl<<endl;
    
    //Input = Product's Name
    cout <<setw(52)<<"NAME       "
         <<setw(27)<<" ";
    getline(cin, products[emp_loop].name);
    getline(cin, products[emp_loop].name);
    cout <<endl<<endl<<endl;
    
    
    //Input = Product's ID
    cout <<setw(52)<<"ID         "
         <<setw(27)<<" ";
    cin >>products[emp_loop].id;
    cout <<endl<<endl<<endl;

    //Input = Product's Price
    cout <<setw(52)<<"Price        "
         <<setw(27)<<" ";
    cin >>products[emp_loop].price;
    cout <<endl<<endl<<endl;

    //Storing 'Product Data' into a file, named "ProductInfo"
    FileProduct <<products[emp_loop].id<<","
                 <<products[emp_loop].name<<","
                 <<products[emp_loop].price
                 <<endl;
    

    //Counter for the number of products[emp_loop] and loop
    emp_loop++;

    //Choice to 'Quit' or add more 'products'
    cout <<setw(68)<<"Choose and option"<<endl<<endl<<endl
         <<setw(64)<<"1. Continue"<<endl
         <<setw(60)<<"2. Quit"<<endl<<endl;
    cout <<setw(57)<<" "; 
    cin  >>endLoop_p;
    cout <<endl<<endl;


    }
    
    }

}    
