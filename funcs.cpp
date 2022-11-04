#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <cfloat>
#include "funcs.h"

char shiftChar(char c, int rshift){
    char temp = tolower(c);
    int raw = ((int)temp - 97 + rshift);
    raw += 26;
    raw =  raw % 26;
    raw += 97;
    temp = (char)raw;

    if((int)c >= 65 && (int)c <= 90){ 
        temp = toupper(temp);
        return temp;
    }

    if((int)c >= 97 && (int)c <= 122){ 
        return temp;
    }
    else{ 
        return c;
    }
}


std::string encryptCaesar(std::string plaintext, int rshift){
  std::string d = "";
  
 for (int i = 0 ; i < plaintext.length(); i++){
   char newc = plaintext[i];
   if (isalpha(newc)){
     newc = shiftChar(newc, rshift);
   }
   
   d = d + newc;
    
    
     }
 return d;
  
}

std::string decryptCaesar(std::string ciphertext, int rshift){   
    return encryptCaesar(ciphertext, 0-rshift);
}


double dist(std::vector<double> engFreq, std::vector<double> wordFreq)
{
    double d = 0.0;
    for(int i = 0; i < 26; i++)
    {
        d += (engFreq[i] - wordFreq[i])*(engFreq[i] - wordFreq[i]);
    }
    d = sqrt(d);
    return d;
}

int letterIndex(char c)
{
    int lowerLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int upperLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    for(int j = 0; j < 26; j++)
    {
        if(isupper(c))
        {
            if(c == upperLetters[j])
            {
                return j;
            }

        }

        else
        {
            if(c == lowerLetters[j])
            {
                return j;
            }
        }
    }
    return 26; 
}

int phraseLetters(std::string s)
{
    int num = 0;

    for(int j=0; j<s.length(); j++)
    {
        if(isalpha(s[j])) 
        {
            num++;
        }
    }
    return num;
}

std::string solve(std::string encrypted_string)
{
    std::string shifted_string[26];
    std::vector<double> englishFrequencies = {0.082, 0.015, 0.027, 0.047, 0.13, 0.022, 0.02, 0.062, 0.069, 0.0016, 
                                                0.0081, 0.04, 0.027, 0.067, 0.078, 0.019, 0.0011, 0.059, 0.062, 
                                                0.096, 0.027, 0.0097, 0.024, 0.0015, 0.02, 0.0078};
    std::vector<double> letterFrequencies = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
                                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    int numLetters = phraseLetters(encrypted_string);
    int index = 0;
    double min = DBL_MAX;
    double mins[26];
    int currIndex = 0;
    int minIndex = 0;

    for(int i=0; i<26; i++)
    {
        for(int j=0; j<encrypted_string.length(); j++)
        {
            if(isalpha(encrypted_string[j])) 
            {
                index = letterIndex(encrypted_string[j]);
                letterFrequencies[index] += 1.0;
            }
        }

        for(int k=0; k<26; k++)
        {
            letterFrequencies[k] = letterFrequencies[k] / numLetters;
        }

        if(dist(englishFrequencies, letterFrequencies) < min)
        {
            min = dist(englishFrequencies, letterFrequencies);
            mins[currIndex] = min;
            shifted_string[currIndex] = encrypted_string;
            currIndex++;
        }
         encrypted_string = encryptCaesar(encrypted_string, 1);
    }

    for(int p = 0; p < 26; p++)
    {
        if(min == mins[p])
        {
            minIndex = p;
        }
    }

    return shifted_string[minIndex];
    return "";
}
