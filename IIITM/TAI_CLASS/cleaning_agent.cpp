#include<bits/stdc++.h>
using namespace std;

const int N=9;
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,-1,1};

struct Agent {
    int x,y;
    int cleaned=0,steps=0,visited=0;
    set<pair<int,int>> visitedTiles;
    vector<vector<char>> movementGrid;

    Agent(int startX,int startY){
        x=startX; y=startY;
        movementGrid=vector<vector<char>> (N,vector<char>(N,'.'));
        movementGrid[x][y]='*';
    }

    void move(vector<vector<int>> &grid){
        int dir=rand()%8;
        int nx=x+dx[dir],ny=y+dy[dir];
        if(nx>=0 && nx<N && ny>=0 && ny<N){
            x=nx;y=ny;
            movementGrid[x][y]='*';
        }
    }

    void act(vector<vector<int>> &grid){
        steps++;
        visitedTiles.insert({x,y});
        if(grid[x][y]==1){
            cleaned++;
            grid[x][y]=0;
        }
    }

    void simulate(vector<vector<int>> &grid,int maxSteps){
        for(int i=0;i<maxSteps;i++){
            act(grid);
            move(grid);
        }
        visited=visitedTiles.size();
    }

    void printMovement(){
        cout<<"\nAgent Movement Map (path = '*'):\n";
        for(auto &row:movementGrid){
            for(auto &cell:row)cout<<cell<<' ';
            cout<<'\n';
        }
    }
};

vector<vector<int>> generateGrid(int p){
    vector<vector<int>> grid(N,vector<int>(N,0));
    int total=N*N;
    int dirtyCount=total*p/100;
    set<int> chosen;
    while(chosen.size()<dirtyCount){
        int cell=rand()%total;
        if(chosen.insert(cell).second){
            int x=cell/N, y=cell%N;
            grid[x][y]=1;
        }
    }
    return grid;
}

void printGrid(const vector<vector<int>> &grid){
    cout<<"Initial Grid (1=dirty, 0=clean):\n";
    for(auto &row:grid){
        for(auto &cell:row)cout<<cell<<' ';
        cout<<'\n';
    }
}

void run(int p){
    auto grid=generateGrid(p);
    printGrid(grid);
    Agent bot(0,0);
    bot.simulate(grid,100);
    bot.printMovement();
    cout<<"\np = "<<p<<"% => Cleaned: "<<bot.cleaned
        <<", Steps: "<<bot.steps
        <<", Unique Tiles Visited: "<<bot.visited<<"\n"
        <<", Performance: "<< ((float)bot.cleaned/(float)bot.steps)*100<<"%";
}

int main(){
    srand(time(0));
    for(int p:{5,10,20,40,70}){
        cout<<"\n==============================================\n";
        run(p);
    }
    return 0;
}
