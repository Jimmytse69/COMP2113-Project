#include <iostream>
#include <vector>
using namespace std;

struct map_info {
	int row, column;									//define the size of row and column

	int player_row = 15, player_column = 15;						//for testing only, define a player located in (15,15)
	int player_coordinate[2] 
	= { player_row , player_column };

	vector<char> map;									//print out map of Dim of row*column
	vector<bool> dot;									//to indicate dot eaten or not (1 = exists, 0 = eaten)
};


void render_map(map_info &info)
{
	for (int i = 0; i < info.row; ++i) {							//for testing only, initatize dot map
		for (int j = 0; j < info.column; ++j) {
			info.dot.push_back(1);
		}
	}


	for (int i = 0; i < info.row; ++i) {							//rendering the map row by row
		for (int j = 0; j < info.column; ++j) {
			if (j == 0 || j == info.column - 1) {
				info.map.push_back('|');					//vertical wall
			}
			else if (i == 0 || i == info.row - 1) {
				info.map.push_back('-');					//horizontal wall
			}
			else if (i == info.player_coordinate[0] 
					&& j == info.player_coordinate[1]) {
				info.map.push_back('<');					//'<' is player location
			}
			else if (info.dot[i * j + j] == 1) {
				info.map.push_back('.');					//dot, contribute to 20 point each
			}
			else {
				info.map.push_back(' ');					//black space
			}
																		
		}
	}

}

void print_map(map_info &info)
{
	for (int i = 0; i < info.row; i++) {							//print map
		for (int j = 0; j < info.column; j++) {
			cout << info.map[ (i * info.column) + j ];
		}
		cout << endl;
	}
	
}

int main()
{
	map_info info;
	info.row = 30; info.column = 30;							//set a size of map
	
	render_map(info);
	print_map(info);

}
