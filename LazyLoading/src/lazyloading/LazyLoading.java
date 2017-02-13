
package lazyloading;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author Yunch
 */
public class LazyLoading {


    public static void main(String[] args) throws FileNotFoundException, IOException {
        
        ArrayList<Integer> itemsWeight = new ArrayList<Integer>();
        BufferedReader br = new BufferedReader(new FileReader(new File("lazy_loading.txt")));
        PrintWriter pw = new PrintWriter(new File("output.txt"));
        int numDays = 0;
        int numItems = 0;
        int maxTrips = 0;
        int tripWeight = 0;
        int tripItems = 0;
        numDays = Integer.parseInt(br.readLine());
        
        try{
        for(int i = 0; i < numDays; i++){
            itemsWeight = new ArrayList<Integer>();
            maxTrips = 0;
            tripItems = 0;
            tripWeight = 0;
            numItems = Integer.parseInt(br.readLine());
            for(int j = 0; j < numItems; j++){
                itemsWeight.add(Integer.parseInt(br.readLine()));
            }
            Collections.sort(itemsWeight);
            
            int heavist;
            int j = numItems - 1;
            outloop:
            for(;j > 0; j++){
                j = itemsWeight.size() - 1;
                if(itemsWeight.get(j) >= 50){
                    itemsWeight.remove(j);
                    numItems--;                
                    maxTrips++;
                }else{
                    tripWeight = itemsWeight.get(j);
                    tripItems = 1;
                    heavist = tripWeight;
                    while(tripWeight < 50){
                        if(j-1 >= 0){
                            tripWeight = heavist * (++tripItems);
                            itemsWeight.remove(0);
                        }else{
                            //maxTrips++;
                            break outloop;
                        }
                    }
                    
                    maxTrips++;
                    
                    itemsWeight.remove(j-tripItems+1);
                    j = itemsWeight.size() - 1;
                    
                }
                
                
            }
            pw.println("Case #"+(i+1)+": "+maxTrips);
            
        }
        }catch(Exception e){
            
        }
        finally{
                pw.close();

        };
    }
    
}
