#pragma once
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;


typedef struct{
   int row;
   int column;
}position;


class path_finder{
    
    public:
        //Variables
        position Cell;
        vector<vector<int>> my_map;
        bool search_complete;
        
        
        
        //Methods 
        path_finder();
        void loadMap(vector<vector<int>> map);
        void printRawMap();
        
        int getUp(position cell);
        int getDown(position cell);
        int getLeft(position cell);
        int getRight(position cell);
        
        position manipulate_map();
        void update_map();
    
    
};