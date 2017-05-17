/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package discoproj;

//import de.linguatools.disco.CorruptConfigFileException;
//import de.linguatools.disco.DISCO;
import de.linguatools.disco.ReturnDataBN;
import de.linguatools.disco.ReturnDataCol;
//import de.linguatools.disco.WrongWordspaceTypeException;
//import java.io.FileNotFoundException;
import java.io.IOException;


import de.linguatools.disco.DISCO;
public class Discoproj {
         public static void main() throws IOException{

        // first command line argument is path to the DISCO word space directory
        String discoDir = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/enwiki-20130403-word2vec-lm-mwl-lc-sim";
        // second argument is the input word
        String word = "football";

	/****************************************
	 * create instance of class DISCO.      *
	 * Do NOT load the word space into RAM. *
	 ****************************************/
        DISCO disco;
        try {
            disco = new DISCO();
        } catch (NullPointerException ex){
            System.out.println("Error creating DISCO instance: "+ex);
            return;
        }

        // retrieve the frequency of the input word
        int freq = disco.frequency(discoDir,word);
        // and print it to stdout
        System.out.println("Frequency of "+word+" is "+freq);

        // end if the word wasn't found in the index
        if(freq == 0) return;

        // retrieve the collocations for the input word
        ReturnDataCol[] collocationResult = disco.collocations(discoDir,word);
        // and print the first 20 to stdout
        System.out.println("Collocations:");
        for(int i = 1; i < collocationResult.length; i++){
            System.out.println("\t"+collocationResult[i].word+"\t"+
                    collocationResult[i].value);
	    if( i >= 20 ) break;
        }

        // retrieve the most similar words for the input word
        ReturnDataBN simResult;
        simResult = disco.similarWords(discoDir,word);
        // and print the first 5 of them to stdout
        System.out.println("Most similar words:");
        for(int i = 1; i < simResult.words.length; i++){
            System.out.println("\t"+simResult.words[i]+"\t"+simResult.values[i]);
	    if( i >= 5 ) break;
        }

        // compute second order similarity between the input word and its most
        // similar words
	System.out.println("Computing second order similarity between "+word+
			   " and all of its similar words...");
	long startTime = System.currentTimeMillis();
        for(int i = 1; i < simResult.words.length; i++){
            float s2 = disco.secondOrderSimilarity(discoDir,word, simResult.words[i]);
	}
	long endTime = System.currentTimeMillis();
	long elapsedTime = endTime - startTime;
	System.out.println("OK. Computation took "+elapsedTime+" ms.");
    }
}
