#include <bits/stdc++.h>
using namespace std;
const int N=20;
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,-1,1};

vector<vector<int>> generateGrid(int p,bool lowerHalfOnly){
    vector<vector<int>> g(N,vector<int>(N,0));
    int total=N*N;
    int dirtyCount=total*p/100;
    unordered_set<int> chosen;
    while((int)chosen.size()<dirtyCount){
        int cell;
        if(lowerHalfOnly){
            int row=rand()%(N/2)+N/2;
            int col=rand()%N;
            cell=row*N+col;
        } else cell=rand()%total;
        if(chosen.insert(cell).second){
            int x=cell/N,y=cell%N;
            g[x][y]=1;
        }
    }
    return g;
}

void printGrid(const vector<vector<int>>& g){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout<<g[i][j]<<' ';
        cout<<'\n';
    }
}

struct Agent{
    int x,y,steps=0,cleaned=0;
    set<pair<int,int>> visited;
    vector<vector<int>> knowledge;
    vector<vector<char>> movementGrid;
    Agent(int sx,int sy):x(sx),y(sy){
        knowledge.assign(N,vector<int>(N,-1));
        movementGrid.assign(N,vector<char>(N,'.'));
        movementGrid[x][y]='*';
        visited.insert({x,y});
    }

    void updateVision(const vector<vector<int>>& grid){
        for(int i=0;i<N;i++) for(int j=0;j<N;j++){
            if(abs(i-x)+abs(j-y)<=2) knowledge[i][j]=grid[i][j];
        }
    }

    void act(vector<vector<int>>& grid){
        steps++;
        if(grid[x][y]==1){
            cleaned++;
            grid[x][y]=0;
            knowledge[x][y]=0;
        }
    }

    pair<int,int> randomMove(){
            vector<int> dirs;
            for(int k=0;k<8;k++){
                int nx=x+dx[k], ny=y+dy[k];
                if(nx>=0 && nx<N && ny>=0 && ny<N) dirs.push_back(k);
            }
            if(dirs.empty()) return {x,y};
            int k=dirs[rand()%dirs.size()];
            return {x+dx[k],y+dy[k]};
    }

    pair<int,int> strategicMove(){
        
    }



    void simulate(vector<vector<int>> grid,bool strategic,int maxSteps){
        updateVision(grid);
        for(int i=0;i<maxSteps;i++){
            act(grid);
            pair<int,int> mv = strategic?strategicMove():randomMove();
            x=mv.first; y=mv.second;
            visited.insert({x,y});
            movementGrid[x][y]='*';
            updateVision(grid);
        }
    }
    void printMovement(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) cout<<movementGrid[i][j]<<' ';
            cout<<'\n';
        }
    }
};

void runCase(int p,bool lowerHalf){
    auto grid=generateGrid(p,lowerHalf);
    int initDirty=0;

    cout<<"Initial Grid (1=dirty):\n";
    printGrid(grid);
    cout<<"\n";

    auto gForRandom=grid;
    auto gForStrat=grid;

    Agent randBot(0,4), stratBot(0,4);

    randBot.simulate(gForRandom,false,100);
    stratBot.simulate(gForStrat,true,100);

    cout<<"Random Agent Movement:\n";
    randBot.printMovement();
    cout<<"Random Agent: P1="<<randBot.cleaned<<", Steps="<<randBot.steps<<", UniqueVisited="<<randBot.visited.size()
        <<", P2="<<fixed<<setprecision(2)<<(randBot.cleaned/randBot.steps)<<"%"
        <<", P3="<<fixed<<setprecision(2)<<(randBot.cleaned*100/randBot.steps)<<"%\n\n";


    cout<<"Strategic Agent Movement:\n";
    stratBot.printMovement();
    cout<<"Strategic Agent: P1="<<stratBot.cleaned<<", Steps="<<stratBot.steps<<", UniqueVisited="<<stratBot.visited.size()
        <<", P2="<<fixed<<setprecision(2)<<(stratBot.cleaned/stratBot.steps)<<"%"
        <<", P3="<<fixed<<setprecision(2)<<(stratBot.cleaned*100.0/stratBot.steps)<<"%\n\n";
}

int main(){
    srand(time(0));
    cout<<"CASE A: 20% dirt anywhere\n";
    runCase(20,false);
    cout<<"========================================\n";
    cout<<"CASE B: 20% dirt lower half only\n";
    runCase(20,true);
    return 0;
}
