/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tictactoe;
import java.util.*;
/**
 *
 * @author Yunch
 */
public class Board {
    
    public static final char HUMAN = 'O';
    public static final char COMPUTER = 'X';
    public short whoWins; // Human wins -1, computer wins +1, tie 0
    public short score; // Human wins -1, computer wins +1, tie 0
    public boolean side = true; // Human move TRUE, computer move FALSE
    private char[][] b;
    
    
    public Board(boolean movesFirst){
        b = new char[3][3];
        side = movesFirst;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                b[i][j] = ' ';    
    };
    
    public Board(char[][] init, boolean movesFirst){
        b = new char[3][3];
        side = movesFirst;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                b[i][j] = init[i][j];            
    }
    
    public Best chooseMove(boolean side){
        boolean bestSide = side;
        Best bestMove = new Best();
        Best response;
        
        //if full, return directly
        if(isFull()){
            response = new Best();

            if(checkWin())
                response.score = whoWins;
            else
                response.score = 0;
            return response;
        }
        response = new Best();
        if(checkWin())
        {
            response.score = whoWins;
            return response;
        }
        // Give most pessimistic score
        if(bestSide)
            bestMove.score = 1;
        else
            bestMove.score = -1;
        
        // Try every move
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                if(b[i][j] == ' '){
                    b[i][j] = bestSide?HUMAN:COMPUTER;
                    print();
                    response = chooseMove(!bestSide);                                   //Possible problem
                     
                    b[i][j] = ' ';
                    if((side && response.score < bestMove.score)
                            ||(!side && response.score > bestMove.score)){
                        bestMove.setMove((short)i, (short)j);
                        bestMove.score = response.score;
                        print();
                    }
                }
            }
            
        
        return bestMove;
    }
    
    
    
    
    public void print(){
        System.out.println("\n");
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++){
                System.out.print(b[i][j] + "|");        
            }
            System.out.println();
        }
    }
    
    public boolean isFull()
    {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                 if(b[i][j]==' ')
                     return false;
        return true;
    }
    
    public boolean checkWin()
    {
        if(checkRow() || checkCol() || checkDiag())
            return true;
        return false;
    }    

    private boolean checkRow() {
        for(int i = 0;i < 3; i++){
            if(b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][2] != ' ')
            {
                if(b[i][2] == HUMAN)
                    whoWins = -1;
                else
                    whoWins = 1;
                return true;
            }          
        }
        return false;
    }

    private boolean checkDiag() {
        if((b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[1][1] != ' ')
                || (b[0][2] == b[1][1] && b[1][1] == b[2][0]) && b[1][1] != ' ')
        {
            if(b[1][1] == HUMAN)
                whoWins = -1;
            else
                whoWins = 1;
            return true;
        }  
        return false;
    }

    private boolean checkCol() {
        for(int i = 0;i < 3; i++){
            if(b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[2][i] != ' ')
            {
                if(b[2][i] == HUMAN)
                    whoWins = -1;
                else
                    whoWins = 1;
                return true;
            }          
        }
        return false;
    }

    public void start() {
        chooseMove(side);
    }
    
    
}
