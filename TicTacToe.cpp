//Tic-Tac-Toe by Nicola Di Giorgio 10/2010

#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void CreateGrid();
void DrawBackGrid();
bool HasWinner();
void ControllerGame();

int grid[3][3];
bool goOn=false;
const int timeMill=1500;

int main(int argc, char *argv[])
{char cont;

do{
    system("cls");
    CreateGrid();        
    DrawBackGrid();
    ControllerGame();
    printf("Do you want play again? (y/n) ");
    cin >> cont;
    if (cont=='y') goOn=true;
}while (goOn);
    
    return EXIT_SUCCESS;
}


//FUNCTION
void CreateGrid(){
     for (int i=0; i<3;i++)
         for (int j=0; j<3;j++)
             grid[j][i]=0;   
     cout<< endl << "===============TRIS===================" <<endl << endl;
     cout << "The game is between player 1: 'O' and player 2: 'X'\n" << endl;
     
     }

//FUNCTION
void DrawBackGrid()
     {
     string emptyRow="  |---|---|---|\n";
     string rows[]={"1 | * | * | * |\n","2 | * | * | * |\n","3 | * | * | * |\n"};
     
     for (int i=0; i<3;i++)
         for (int j=0; j<3;j++)
             {if (grid[j][i]==1)
                 rows[i].replace(4+(j*4),1,"O");
              if (grid[j][i]==2)
                 rows[i].replace(4+(j*4),1,"X");
             }
     
     printf("    1   2   3  \n");
     for (int r=0; r<3; r++)
     {cout<<emptyRow <<rows[r];
     }
     cout<<emptyRow<< endl;     
}   


//FUNCTION
bool HasWinner()
{  bool winPlayer[]={false,false};
   bool exitBreak=false; //Check if you got a tris
   
     for (int i=0; i<3;i++)
           {if (grid[i][0]==grid[i][1] && grid[i][0]==grid[i][2] && grid[i][2]!=0)
                {winPlayer[grid[i][0]-1]=true; exitBreak=true; break; }          
           
            if (grid[0][i]==grid[1][i] && grid[0][i]==grid[2][i] && grid[2][i]!=0)
               {winPlayer[grid[0][i]-1]=true; exitBreak=true; break;}   
           }
     
     if (exitBreak!=true){                    
         if (grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2] && grid[2][2]!=0)
                winPlayer[grid[0][0]-1]=true;          
         if (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0] && grid[2][2]!=0)
                winPlayer[grid[0][2]-1]=true;                   
                          }
     //Check who has won, if any
     
     if (winPlayer[0]==true) {system("cls");
                              DrawBackGrid();
                              printf("\aPlayer 1 has won! ");
                              return true;
                             }
     else if (winPlayer[1]==true) {
                              system("cls");
                              DrawBackGrid();
                              printf("\aPlayer 2 has won! ");
                              return true;
                             }
     else return false;
}


//FUNCTION
void ControllerGame()
{    
     bool valid;
     int coordinate[2][2];     
     bool endGame=false;
     int cont=0;
     
 do{     
    for (int p=0;p<2;p++)
    {
    do{
     
     do{    
     printf("\nPlayer %d, it's your turn!. \nRow: ",p+1);
     cin >> (coordinate[p][0]);
     if (coordinate[p][0]>3 || coordinate[p][0]<1) {printf("Input not valid. \n");  
        valid=false; }
     else valid=true;
     }while (valid==false);
     
     do{
     cout << "Column: ";
     cin >> (coordinate[p][1]);
     if (coordinate[p][1]>3 || coordinate[p][1]<1) {printf("Input not valid. \n"); 
         valid=false; }
     else valid=true;
     }while (valid==false);    
         
     if (grid[coordinate[p][1]-1][coordinate[p][0]-1]!=0) {printf("\a\nThe square is not empty! Try again. \n"); 
     Sleep(timeMill); system("cls"); valid=false; DrawBackGrid(); 
     valid=false;}     
    }while (valid==false);         
    
    grid[coordinate[p][1]-1][coordinate[p][0]-1]=p+1;
     
     if (cont>1) if (HasWinner()==true)
                    {endGame=true;
                     break;}
    
    if (cont==4 && p==0 && endGame==false) {system("cls");
                  DrawBackGrid();
                  printf("The game ends with a draw!. ");
                  endGame=true;
                  break;    
                  }
                  
    system("cls");
    DrawBackGrid();
    }

    cont++; 
 }while(endGame==false);
    
}



