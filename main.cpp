/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "path_finder.h"


vector<vector<int>>map {{2,0,1,1,1,0,0,0,0,0,0},
                        {0,0,1,0,0,0,0,0,0,0,0},
                        {0,0,1,1,1,1,1,1,1,0,0},
                        {0,0,0,0,0,0,0,0,1,0,0},
                        {0,0,1,1,1,0,0,0,1,0,0}, 
                        {0,0,1,0,0,0,0,0,0,0,3}};

int main()
{
    path_finder my_path;
    my_path.loadMap(map);
    
    /*while(! my_path.search_complete){
       
    }*/
    
    for(int i = 0 ; i < 15; i++){
       my_path.update_map();  
    }
    
    my_path.printRawMap();
    my_path.print2dMap();

    return 0;
}
