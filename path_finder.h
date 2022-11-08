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

typedef struct{
    bool valid;
    int g_value;
    int h_value;
    int f_value;
    position nav_cell;
}nav;




class path_finder{
    
    public:
        //Variables
        position Start;
        position Stop;
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
        
        position calculate_nav(position cell);
        bool compare_nav(nav node1, nav node2);
        position manipulate_map();
        void update_map();
        void print2dMap();
        
        //nav value
        int getG_value(position node_pos);
        int getH_value(position node_pos);
        int getF_value(position node_pos);
    
    
};