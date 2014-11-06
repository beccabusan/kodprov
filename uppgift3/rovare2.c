#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int is_consonant(char t){
  if ((t == 'a') || (t == 'A') || (t == 'e') || (t == 'E') || (t == 'y') || (t == 'Y') || (t == 'i') || (t == 'I') || ( t== 'o') || (t =='O') || (t == 'å') || (t == 'Å') || (t == 'ä') || (t == 'Ä') || (t == 'ö') || (t == 'Ö') ||  (t == 'u')  || (t == 'U')){
    return 1;
  }
  else 
    return 0;
}

char* rovarsprak_to_str(char *s){
  int j = 0;
  char t;
  char *newS = malloc(sizeof(*s));
  int lengthOfS;
  lengthOfS = strlen(s);
  for(int i = 0; i < lengthOfS; i++){

    if (!(isalpha(s[i]))){
      ++i;
    }
    else if (isalpha(s[i])){

      if (is_consonant(s[i]) == 0){
	t = s[i];
	++i;
	if (s[i] == 'o' || s[i] == 'O') {
	  newS[j] = t;
	  ++j;
	  i = i+1;
      	}
	else {
	  puts("Meningen följer inte rövarspråket");
	  break;
	}

      }

      else if(is_consonant(s[i]) == 1) /* if (s[i] == 'a' || s[i] == 'A' || s[i] == 'E' || s[i] == 'e' || s[i] == 'y'|| s[i] == 'Y' || s[i] == 'å' || s[i] == 'Å' || s[i] == 'ä' || s[i] == 'Ä' || s[i] == 'ö' || s[i] == 'Ö' || s[i] == 'u' || s[i] == 'U' || s[i] == 'o' || s[i] == 'O' || s[i] == 'i' || s[i] == 'I')*/ {
	newS[j] = s[i];
	++j;
      }
    }
  }      
  return newS;
}



int main (int argc, char *argv[]){
  if (argc < 2){
    puts("Usage: ./rovare mening");
    return 0;
  }
  char *s;
  s = rovarsprak_to_str(argv[1]);
  printf("%s\n", s);
  free (s);
  return 0;
}

//allokerar plats två gånger!! not good!
