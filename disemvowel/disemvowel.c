#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "disemvowel.h"

char* vowels= "aeiou"; //Characters that will count as vowels
int nVowels=5;
int countNonVowels(char*);
int isVowel(char);
                            //Re-arranging the order so that most common vowels are first would provide a slight boost in performance

char* disemvowel(char* str) {
  char* shortened;
  int n = countNonVowels(str) + 1; // We need one extra space for the string terminating /0
  int i,j = 0;
  char c;

  shortened=calloc(n,sizeof(char));
  while( (c=str[i++]) ){
	if(isVowel(c)){j++;}
        else {
           shortened[i-j]=str[i];
        }
  }
  return (char*) "";
}

int countNonVowels(char *str){ //PCD:  Added to determine allocation length
  int i,j=0;
  char c;

  while( (c=str[i++]) ){
	if(isVowel(c)){j++;}
  }
  return(i-j);

}

int isVowel(char c){
  char v;
  int i = 0;
  while( (v=vowels[i++]) ){if(c==v){printf("matched!\n");break;}}    //iterate through the contents of the string of vowels and break out of the loop if there is a match
  i--; //Returns i to the index of the last assignment
  printf("i is %d, nVowels is %d",i,nVowels);
  return(i!=nVowels);                      //If the break-point occurs
}

int main(int argc, char* argv[]){
   printf(isVowel('u')?"yes\n":"no\n");
}
