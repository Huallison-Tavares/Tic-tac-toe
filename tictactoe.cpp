#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TicTacToe{
    
    private:
        char player1;
        char player2;
        char screen[3][3];
        
        void display(){
            std::string display = " ";
            for (int i=0;i<3;i++){
                for(int c=0;c<3;c++){
                    display += screen[i][c];
                    if (c != 2){
                        display += " * ";
                    }
                }
                if (i != 2){
                    display += "\n**********\n ";
                }
            }
            
            cout << display << endl;
        }
        
        void selectLocation(int player){
            int row, column;
            bool select = false;
            while (!select){
                cout << "Player 0" << player << ":"<< endl << "Onde Deseja jogar ? (Linha Coluna)\n";
                cin >> row >> column;
                --row;
                --column;
                if(screen[row][column]){
                    cout << "Local já escolhido, esconha outro." << endl;
                }else{
                    select = true;
                }
            }
            if (player == 2){
                screen[row][column] = player2;
            }else{
                screen[row][column] = player1;
            }
        }
        
        bool draw(){
            bool draw = true;
            for (int i=0;i<3;i++){
                for(int c=0;c<3;c++){
                    if (!screen[i][c]){
                        draw = false;
                    }
                }
            }
        
            return draw;
        }
        
        bool checkWinner(){
            char vencedor = 'C';
            
            for(int i=0;i<3;i++){
                if (screen[i][0] == screen[i][1] && screen[i][1] == screen[i][2] && screen[i][0]){
                    vencedor = screen[i][0];
                }else if(screen[0][i] == screen[1][i] && screen[1][i] == screen[2][i] && screen[0][i]){
                    vencedor = screen[0][i];
                }
            }
            
            if (screen[0][0] == screen[1][1] && screen[1][1] == screen[2][2] && screen[0][0]){
                vencedor = screen[0][0];
            }else if(screen[0][2] == screen[1][1] && screen[1][1] == screen[2][0] && screen[0][2]){
                vencedor = screen[1][1];
            }

            
            if (vencedor != 'C'){
                cout << "O vencedor é o " << vencedor << " !!!";
                return true;
            }else if (draw()){
                cout << "O jogo deu empate !";
                return true;
            }
            return false;
        }
    
    
    public:
        void selectSymbol(){
            cout << "Player 01:" << endl << "Deseja escolher X ou O ?\n";
            cin >> player1;
            if (player1 == 'O'){
                player2 = 'X';
            }else{
                player2 = 'O';
            }
            
            cout << player1 << " " << player2 << endl;
        }
        
        void game(){
            auto vencedor = false;
            int player = 1;
            while(!vencedor){
                display();
                selectLocation(player);
                vencedor = checkWinner();
                
                player++;
                if(player > 2){
                    player = 1;
                }
            }

        }
};

int main()
{
    TicTacToe game;
    game.selectSymbol();
    game.game();

    return 0;
}
