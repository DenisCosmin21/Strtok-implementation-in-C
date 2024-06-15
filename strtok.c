#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

char *mystrtok(char *s, const char *delim)
{
  static char *p = NULL;
  if(s != NULL){
    p = s;
  }
  else{
    s = p;
  }
  int isset = 0, cnt = 0;
 char *i = NULL, *aux = NULL;
 int exista = 0;
 for(i = p;*i != '\0';i = i + 1){
   isset = 0;
    for(int j = 0;j < strlen(delim);j++){
      if(*i == delim[j]){
	*i = '\0';
	aux = i + 1;
	cnt = 1;
	do{
	  exista = 0;
	  for(int k = 0;k < strlen(delim);k++){
	    if(*aux == delim[k]){
	      exista = 1;
	      cnt++;
	      *aux = '\0';
	      aux = aux + 1;
	      break;
	    }
	  }
	}while(exista == 1);
	isset = 1;
	break;
      }
    }
      if(isset == 1){
	p = i + cnt;
	return s;
      }
  }
 if(*p!= '\0'){
   p = i;
   return s;
 }
  return NULL;
}

  
    
      
int main(void)
{
  char input[] = "Mama mea e super. Sarmale cu ghimbir.";
    char *word;
    char *ant;
    int num_sentences = 0, num_words = 0;
    for (char* sentence = mystrtok(input, "."); sentence != NULL; sentence = mystrtok(NULL, ".")) {
      printf("%p\n" ,(void*)&input);
        num_sentences += 1;
	printf("%s\n", sentence);
	printf("%s\n", input);
        for ( word = mystrtok(sentence, " "); word != NULL; word = mystrtok(NULL, " ")) {
	  printf("%p\n" ,(void*)&input);
	  printf("%s\n", sentence);
	  printf("%s\n", input);
            num_words += 1;
	    ant = word;
        }
	printf("%s", ant);
	sentence = ant  + 2;
    }
    printf("The input has %d sentences and %d words\n", num_sentences, num_words);
    return 0;
}
