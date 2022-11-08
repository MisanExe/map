
#include "path_finder.h"
#include <cstdlib>

//path_finder constructor
path_finder::path_finder(){
    Cell.row = 0;
    Cell.column = 0;
}

//print 2d view map
void path_finder::print2dMap(){
    for(int i = 0; i<my_map.size(); i++){
        for(int j =0; j<my_map[i].size(); j++){
            
            if(my_map[i][j] == 2){
                cout<<"📍";
            }else if(my_map[i][j] == 0){
                cout<<"    ";
            }else if(my_map[i][j] == 1){
                cout<<"  🏡  ";
            }else if(my_map[i][j] == 8){
                cout<<" . ";
            }else if(my_map[i][j] == 3){
                cout<<"🛑";
            }
        }
        
        cout<<"\n";
    }
}

//load map
void path_finder::loadMap(vector<vector<int>> map){
    my_map.resize(map.size() );
    for(int i = 0; i<map.size(); i++){
        for(int j =0; j<map[i].size(); j++){
             my_map[i].push_back(map[i][j]);
             
             if(my_map[i][j] == 2){
                 //start
                 Start.row = i;
                 Start.column = j;
                 Cell.row = i;
                 Cell.column = j;
             }else if(my_map[i][j] == 3){
                 Stop.row = i;
                 Stop.column = j;
             }
        }
    }
    
    cout<<"Loaded map Elements : "<<my_map.size()*my_map[0].size()<<"|| Starts at--> Row : "<<Cell.row<<" || Column : "<<Cell.column<<endl;
}

//print raw map
void path_finder::printRawMap(){
    for(auto i : my_map){
        for(auto j : i){
            cout<<j;
        }
        cout<<"\n";
    }
}

/////////////////////get cell positions

//get up
int path_finder::getUp(position cell){
    if(cell.row - 1 < 0){
        return -1;
    }else{
        cout<<"up : "<<my_map[cell.row-1][cell.column]<<"\n";
        return my_map[cell.row-1][cell.column];
    }
}

//get down
int path_finder::getDown(position cell){
    if(cell.row+1 > (my_map.size() -1) ){
        return -1;
    }else{
        cout<<"down : "<<my_map[cell.row+1][cell.column]<<"\n";
        return my_map[cell.row+1][cell.column];
    }
}

//getRight
int path_finder::getRight(position cell){
   if(cell.column+1 > (my_map[0].size()-1) ){
        return -1;
    }else{
        cout<<"right : "<<my_map[cell.row][cell.column+1]<<"\n";
        return my_map[cell.row][cell.column+1];
    }  
}

//getLeft
int path_finder::getLeft(position cell){
   if(cell.column-1 < 0 ){
        return -1;
    }else{
        cout<<"Left : "<<my_map[cell.row][cell.column-1]<<"\n";
        return my_map[cell.row][cell.column-1];
    } 
}


///////////////////////////////nav functions 
int path_finder::getG_value(position node_pos){
    int i = (abs(Cell.row - node_pos.row) + abs(Cell.column - node_pos.column));
     cout<<"g_value :"<<i<<endl;
    return i;
}

int path_finder::getH_value(position node_pos){
    int i = (abs(Stop.row - node_pos.row) + abs(Stop.column - node_pos.column));
    cout<<"H_value :"<<i<<endl;
    return i ;
}

int path_finder::getF_value(position node_pos){
    int i = (getG_value(node_pos) + getH_value(node_pos));
     cout<<"f_value :"<<i<<endl;
    return i ;
}

//////////////////////////////////screw with the map

position path_finder::calculate_nav(position cell){
    nav up;
    nav down;
    nav left;
    nav right;
    
    up.valid = false;
    down.valid = false;
    left.valid = false;
    right.valid = false;
    
    
    //up 
    up.nav_cell.row = cell.row -1;
    up.nav_cell.column = cell.column;
    //down
    down.nav_cell.row = cell.row+1;
    down.nav_cell.column = cell.column;
    //left 
    left.nav_cell.row = cell.row;
    left.nav_cell.column = cell.column-1;
    //right
    right.nav_cell.row = cell.row;
    right.nav_cell.column = cell.column+1;
    
    
    
    
    if(getUp(cell) == 0){
        up.valid = true;
    }
    if(getDown(cell) == 0){
        down.valid = true;
    }
    if(getLeft(cell) == 0){
        left.valid = true;
    }
    if(getRight(cell) == 0){
        right.valid = true;
    }
    
    //claculate NAV UP
    if(up.valid){
        up.g_value = getG_value(up.nav_cell);
        up.h_value = getH_value(up.nav_cell);
        up.f_value = getF_value(up.nav_cell);
    }
    
    //claculate NAV DOWN
    if(down.valid){
        down.g_value = getG_value(down.nav_cell);
        down.h_value = getH_value(down.nav_cell);
        down.f_value = getF_value(down.nav_cell);
    }
    
    //claculate NAV LEFT
    if(left.valid){
        left.g_value = getG_value(left.nav_cell);
        left.h_value = getH_value(left.nav_cell);
        left.f_value = getF_value(left.nav_cell);
    }
    
    //claculate NAV RIGHT
    if(right.valid){
        right.g_value = getG_value(right.nav_cell);
        right.h_value = getH_value(right.nav_cell);
        right.f_value = getF_value(right.nav_cell);
    }
    
    //find the max
    nav max;
    if(up.valid){
        max.nav_cell.row = up.nav_cell.row;
        max.nav_cell.column = up.nav_cell.column;
    }
    else if(right.f_value < max.f_value && right.valid){
        max.nav_cell.row = right.nav_cell.row;
        max.nav_cell.column = right.nav_cell.column;
    }else if(left.f_value < max.f_value && left.valid){
        max.nav_cell.row = left.nav_cell.row;
        max.nav_cell.column = left.nav_cell.column;
    }else if(down.f_value < max.f_value && down.valid){
        max.nav_cell.row = down.nav_cell.row;
        max.nav_cell.column = down.nav_cell.column;
    }
    
    /*if(up.valid && (up.f_value < right.f_value && up.f_value < left.f_value && up.f_value < down.f_value)){
        max.nav_cell.row = up.nav_cell.row;
        max.nav_cell.column = up.nav_cell.column;
        
    }else if (right.valid && (right.f_value < up.f_value && right.f_value < left.f_value && right.f_value < down.f_value)){
        max.nav_cell.row = right.nav_cell.row;
        max.nav_cell.column = right.nav_cell.column;
        
    }else if (left.valid && (left.f_value < right.f_value && left.f_value < up.f_value && left.f_value < down.f_value)){
        max.nav_cell.row = left.nav_cell.row;
        max.nav_cell.column = left.nav_cell.column;
        
    }else if (down.valid && (down.f_value < right.f_value && down.f_value < left.f_value && down.f_value < up.f_value)){
        max.nav_cell.row = down.nav_cell.row;
        max.nav_cell.column = down.nav_cell.column;
    }*/
    

    cout<<"next cell : Row "<<max.nav_cell.row<<" Column : "<<max.nav_cell.column<<endl;
    return max.nav_cell;
}



void path_finder::update_map(){
    Cell = calculate_nav(Cell);
    my_map[Cell.row][Cell.column] = 8;
}


