/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fightthezombie;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.NumberFormat;

/**
 *
 * @author Yunch
 */
public class FightTheZombie {

    static int ways = 0;
    
    public static int possibleWays(int goal, int numDice, int numSides){
        int sum = 0;
        if(numDice == 1){
            if(numSides >= goal){
                if(goal > 0)
                    return numSides - goal + 1;
                else
                    return numSides;
            }else{
                return 0;
            }
        }else{
            if(goal > numSides+1){
                for(int i = 1; i <= numSides; i++ ){
                    sum += possibleWays(goal-i, numDice-1, numSides);
                }  
            }else{
                sum = possibleWays(goal-1, numDice, numSides) 
                    - possibleWays(goal-numSides-1, numDice-1, numSides) 
                    + possibleWays(goal-1, numDice-1, numSides);
            }
            
            return sum;
        }
    }
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        int numZombies;
        int HP, relativeHP;
        int numSpells;
        int numDice;
        int diceSides;
        int ways;
        int totWays;
        double probability, maxProbability;
        String[] line;
        String[] spellLine;
        String[] spell;
        String damage;
        BufferedReader br = new BufferedReader(new FileReader(new File("fighting_the_zombie.txt")));
        PrintWriter pt = new PrintWriter(new File("output.txt"));
        NumberFormat formatter = new DecimalFormat("#0.000000"); 
        
        numZombies = Integer.parseInt(br.readLine());
        try{
            for(int i = 0; i < numZombies; i++){

                line = br.readLine().split(" ");
                HP = Integer.parseInt(line[0]);
                numSpells = Integer.parseInt(line[1]);
                maxProbability = 0;

                spellLine = br.readLine().split(" ");
                for(int j = 0; j < numSpells; j++){
                    probability = 0;
                    spell = spellLine[j].split("d");
                    numDice = Integer.parseInt(spell[0]);
                    damage = spell[1];
                    if(damage.indexOf("+") >= 0){
                        relativeHP = HP - Integer.parseInt(damage.split("\\+")[1]);
                        diceSides = Integer.parseInt(damage.split("\\+")[0]);
                    }else if(damage.indexOf("-") >= 0){
                        relativeHP = HP + Integer.parseInt(damage.split("-")[1]);
                        diceSides = Integer.parseInt(damage.split("-")[0]);
                    }else{
                        relativeHP = HP;
                        diceSides = Integer.parseInt(damage);
                    }

                    totWays = (int) Math.pow(diceSides, numDice);
                    if(diceSides*numDice < relativeHP)
                        probability  = 0;
                    else{
                        ways = possibleWays(relativeHP, numDice, diceSides);
                        probability = (double) ways / totWays;
                    }
                    if(probability > maxProbability){
                        maxProbability = probability;
                    }
                }

                pt.println("Case #"+(i+1)+": "+formatter.format(maxProbability));
            }
        }catch(Exception e){
        }finally{
            br.close();
            pt.close();
        }
        

        
        
    }
    
}
