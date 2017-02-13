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
public class Best {
    short[] move;
    short score;
    boolean moved = false;
    
    public Best()
    {
        move = new short[2];
        score = 0;
    }
    
    public void setMove(short i, short j)
    {
        moved = true;
        move[0] = i;
        move[1] = j;
    }
    
}
