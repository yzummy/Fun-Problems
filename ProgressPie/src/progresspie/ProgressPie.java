/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package progresspie;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author Yunch
 */
public class ProgressPie {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        
        BufferedReader br = new BufferedReader(new FileReader(new File("progresspie.in")));
        String line;
        int num = 0;
        String[] data;
        int progress = 0;
        int x = 0, y = 0;
        double slope = 0;
        

            num = Integer.parseInt(br.readLine());
 
        
        for(int i = 1; i <= num; i++){
            
            line = br.readLine();
            data = line.split(" ");
            progress = Integer.parseInt(data[0]);
            x = Integer.parseInt(data[1]) - 50;
            y = Integer.parseInt(data[2]) - 50;
            
            
            
            if( (x*x+y*y) > 2500 || progress == 0){
                System.out.println("Case #" + i + ": white");
            }else if(progress == 50){
                if(x>=0)
                    System.out.println("Case #" + i + ": black");
                else
                    System.out.println("Case #" + i + ": white");
            }else if(progress < 50){


                if(x < 0)
                    System.out.println("Case #" + i + ": white");
                else{
                    if(progress == 25 && y == 0)
                        System.out.println("Case #" + i + ": black");
                    else{
                         slope = 1 / Math.tan((double)progress / 100 * 2 * Math.PI);
                        if(y >= x * slope)
                            System.out.println("Case #" + i + ": black");
                        else
                            System.out.println("Case #" + i + ": white");                   
                    }
                }
            }else if(progress > 50){
                if(x >= 0)
                    System.out.println("Case #" + i + ": black");
                else{
                    if(progress == 75 && y == 0)
                        System.out.println("Case #" + i + ": black");
                    else{
                        slope = 1 / Math.tan((double)progress / 100 * Math.PI);
                        if(y > x * slope)
                            System.out.println("Case #" + i + ": white");
                        else
                            System.out.println("Case #" + i + ": black");

                    }
                }
            }
            
        }
        
        
    }
    
}
