#include <iostream>
#include <stack>
#include <vector>


struct Island {
    int x;
    int y;
};

int count_island(std::vector<std::vector<int> > ocean){
    int counter = 0;
    for(int i = 0; i < ocean.size(); ++i){
        for(int j = 0; j < ocean[i].size(); ++j){
            if(ocean[i][j] == 1){
                ++counter;
                std::stack<Island> island;
                island.push({i, j});
                while(!island.empty()){
                    auto point = island.top();
                    island.pop();
                    ocean[point.x][point.y] = 0;
                    if(point.x > 0 && ocean[point.x - 1][point.y] == 1){
                        island.push({point.x - 1, point.y});
                    }
                    if(point.x < ocean.size() - 1 && ocean[point.x + 1][point.y] == 1){
                        island.push({point.x + 1, point.y});
                    }
                    if(point.y > 0 && ocean[point.x][point.y - 1] == 1){
                        island.push({point.x, point.y - 1});
                    }
                    if(point.x < ocean[i].size() - 1 && ocean[point.x][point.y + 1] == 1){
                        island.push({point.x, point.y + 1});
                    }
                }
            }
        }
    }
    return counter;
}

int main(){
    std::vector<std::vector<int> > ocean = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0}
    };
    std::cout << count_island(ocean) << std::endl;
    return 0;
}
