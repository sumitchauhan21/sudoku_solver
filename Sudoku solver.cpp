#include<iostream>
using namespace std;
bool Is_Safe_In_3_by_3_Grid(int **Grid,int row,int column,int current_number)
 {
     int row_factor=row-(row%3);             
     int column_factor=column-(column%3);
     for(int i=0;i<3;i++)
     {
         for(int j=0;j<3;j++)
         {
             if(Grid[i+row_factor][j+column_factor]==current_number)
             {
                 return false;
             }
         }
     }
     return true;
 }
 bool Is_Safe_In_Column(int **Grid,int column,int current_number)
 {
     for(int i=0;i<9;i++)
     {
         if(Grid[i][column]==current_number)
         {
             return false;
         }
     }
     return true;
 }
 bool Is_Safe_In_Row(int **Grid,int row,int current_number)
 {
     for(int i=0;i<9;i++)
     {
         if(Grid[row][i]==current_number)
         {
             return false;
         }
     }
     return true;
 }
 bool Is_Current_Number_Safe(int **Grid,int row,int column,int current_number)
 {
     if(Is_Safe_In_Row(Grid,row,current_number) && Is_Safe_In_Column(Grid,column,current_number) && Is_Safe_In_3_by_3_Grid(Grid,row,column,current_number))
     {
         return true;
     }
     return false;
 }
 bool Find_Empty_Location(int **Grid,int &row,int &column)
 {
     for(int i=0;i<9;i++)
     {
         for(int j=0;j<9;j++)
         {
             if(Grid[i][j]==0)
             {
                 row=i;
                 column=j;
                 return true;
             }
         }
     }
     return false;
 }
bool Sudoku_Solver(int **Grid)
{
    int row,column;
    if(!Find_Empty_Location(Grid,row,column))
    {
        return true;
    }
    for(int i=1;i<=9;i++)
    {
        if(Is_Current_Number_Safe(Grid,row,column,i))
        {
            Grid[row][column]=i;
            if(Sudoku_Solver(Grid))
            {
                return true;
            }
            Grid[row][column]=0;
        }
    }
    return false;
}
int main()
 {
	//code
	char ch='y';
	while(ch=='y'||ch=='Y'){
		int **Grid=new int*[9];
		cout<<"Enter your 9X9 sudoku game here (NOTE: Please use number zero for blank square boxes)"<<endl;
	    for(int i=0;i<9;i++)
	    {
	        Grid[i]=new int[9];
	        for(int j=0;j<9;j++)
	        {
	            cin>>Grid[i][j];
	        }
	    }
	    int countzero=0;
	    bool greater_than_9 = false;
	    bool lesser_than_0 = false;
	    for(int i=0;i<9;i++)
	    {
	    	for(int j=0;j<9;j++)
	    	{
	    		if(Grid[i][j]==0)
	    		{
	    			countzero++;
				}
				if(Grid[i][j]>9)
				{
					greater_than_9 = true;
				}
				if(Grid[i][j]<0)
				{
					lesser_than_0 = true;
				}
			}
		}
		if(countzero>0 && lesser_than_0==false && greater_than_9==false && Sudoku_Solver(Grid))
		{    
		    cout<<endl;
			cout<<"-----------------------------------------SOLUTION-----------------------------------------"<<endl<<endl;
		    for(int i=0;i<9;i++)
	        {
	        	cout<<"                                 ";
	         for(int j=0;j<9;j++)
	          {
	             cout<<Grid[i][j]<<"  ";
	          }
	         cout<<endl;
	        }
	        cout<<"-----------------------------------------THANK YOU ---------------------------------------"<<endl<<endl;
		}
		else if(countzero==0)
		{
			cout<<"---------------Please make sure atleast one block is empty in your puzzle ----------------"<<endl<<endl;
		}
		else if(greater_than_9==true ||lesser_than_0 == true)
		{
			cout<<"-----------------------Please make sure numbers are in range of 0 to 9 -----------------------"<<endl<<endl;
		}
		else
		{
		    cout<<"--------------------------------Oops! Sudoku can't solved  --------------------------------"<<endl<<endl;
		}
		cout<<"Would you like to solve one more sudoku puzzle  enter (Y/N) ?";
		cout<<endl;
		cin>>ch;
		cout<<endl<<endl;
   }
	return 0;
}
