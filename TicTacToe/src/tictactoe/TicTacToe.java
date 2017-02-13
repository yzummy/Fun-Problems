/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tictactoe;

/**
 *
 * @author Yunch
 */
public class TicTacToe {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        char[][] init = new char[3][3];
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                init[i][j] = ' ';

        
        Board board = new Board(init, false);
        board.start();
        
    }
    
}
