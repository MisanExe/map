
#include "path_finder.h"

//path_finder constructor
path_finder::path_finder(){
    Cell.row = 0;
    Cell.column = 0;
}

//load map
void path_finder::loadMap(vector<vector<int>> map){
    my_map.resize(map.size() );
    for(int i = 0; i<map.size(); i++){
        for(int j =0; j<map[i].size(); j++){
             my_map[i].push_back(map[i][j]);
             
             if(my_map[i][j] == 2){
                 //start
                 Cell.row = i;
                 Cell.column = j;
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

//////////////////////////////////screw with the map

position path_finder::manipulate_map(){
    position my_cell;
    bool flag[5] = {false, false, false, false, false};
    
    my_cell.row = Cell.row;
    my_cell.column = Cell.column;
    
    

    
    return my_cell;
}


void path_finder::update_map(){
    Cell = manipulate_map();
    my_map[Cell.row][Cell.column] = 8;
    
    
}


