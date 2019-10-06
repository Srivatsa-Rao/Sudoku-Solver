#include<stdio.h>
#include<time.h>
#include<iostream>
#define unassigned 0
#define N 9
bool Findunassignedloc(int grid[N][N],int &row,int &col);
bool Issafe(int grid[N][N],int row,int col,int num);
bool Solvesudoku(int grid[N][N])
{
    int row,col;
    if(!Findunassignedloc(grid,row,col))
    {
        return true;
    }

    for(int num=1; num<=9; num++)
    {
        if(Issafe(grid,row,col,num))
        {
            grid[row][col]=num;
            if(Solvesudoku(grid))
            {
                return true;
            }
            grid[row][col]=unassigned;


        }
    }
    return false;
}

bool Findunassignedloc(int grid[N][N],int &row,int &col)
{
    for(row=0; row<N; row++)
    {
        for(col=0; col<N; col++)
        {
            if(grid[row][col]==unassigned)
            {
                return true;
            }
        }
    }
    return false;


}
bool Usedinrow(int grid[N][N],int row,int num)
{
    for(int col=0; col<N; col++)
    {
        if(grid[row][col]==num)
        {
            return true;
        }
    }
    return false;

}
bool Usedincol(int grid[N][N],int col,int num)
{
    for(int row=0; row<N; row++)
    {
        if(grid[row][col]==num)
        {
            return true;
        }
    }
    return false;

}
bool Usedinbox(int grid[N][N],int boxStartRow,int boxStartCol,int num)
{
    for(int row=0; row<3; row++)
    {
        for(int col=0; col<3; col++)
        {
            if(grid[row+boxStartRow][col+boxStartCol]==num)
                return true;
        }
    }
    return false;


}
bool Issafe(int grid[N][N],int row,int col,int num)
{
    return (!Usedinrow(grid,row,num)&&!Usedincol(grid,col,num)&&!Usedinbox(grid,row-row%3,col-col%3,num));

}
void printgrid(int grid[N][N])
{

    for(int row=0; row<N; row++)
    {
        for(int col=0; col<N; col++)
        {
            printf("%2d",grid[row][col]);

        }
        printf("\n");
    }
}
int main()
{
    int grid[N][N];
    printf("Enter the sudoku puzzle\n");
    for(int row=0; row<N; row++)
    {
        for(int col=0; col<N; col++)
        {
            printf("%d row,%d col\n",row+1,col+1);
            scanf("%d",&grid[row][col]);

        }

    }
    std::cout<<std::endl;
    std::cout<<"Your solution";
     std::cout<<std::endl;

    clock_t startTime=clock();

        if(Solvesudoku(grid)==true)
            printgrid(grid);
        else
            printf("No solution exists");
    clock_t endTime=clock();
    clock_t time=(endTime-startTime);
    long double timeinsec=time/(long double)CLOCKS_PER_SEC;
    std::cout<<std::endl<<"Time required to process  :"<<timeinsec<<"seconds\n";
        return 0;
    }
