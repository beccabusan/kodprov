#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int is_consonant(char t){
  if ((t == 'a') || (t == 'A') || (t == 'e') || (t == 'E') || (t == 'y') || (t == 'Y') || (t == 'i') || (t == 'I') || ( t== 'o') || (t =='O') || (t == '�') || (t == '�') || (t == '�') || (t == '�') || (t == '�') || (t == '�') ||  (t == 'u')  || (t == 'U')){
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

    if(!(isalpha(s[i]))){
      ++i;
      }
   else if (isalpha(s[i])){

      if(is_consonant(s[i]) == 0){
	t = s[i];
	++i;
	if ((s[i] == 'o' || s[i] == 'O') && (tolower(s[i+1]) == tolower(t)) ) {
	  newS[j] = t;
	  ++j;
	  i = i+1;
      	}
	else {
	  puts("Meningen f�ljer inte r�varspr�ket");
	  break;
	}

      }

      else if(is_consonant(s[i]) == 1) /* if (s[i] == 'a' || s[i] == 'A' || s[i] == 'E' || s[i] == 'e' || s[i] == 'y'|| s[i] == 'Y' || s[i] == '�' || s[i] == '�' || s[i] == '�' || s[i] == '�' || s[i] == '�' || s[i] == '�' || s[i] == 'u' || s[i] == 'U' || s[i] == 'o' || s[i] == 'O' || s[i] == 'i' || s[i] == 'I')*/ {
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

/*
- allokerar plats tv� g�nger!! not good!(borttaget i denna version)
- Fel i is_consonant, �ndrat nu till t == "a" ist�llet f�r t != "a". Kollar nu efter vokaler och returnerar 0 om det �r en vokal och 1 om det �r en konsonant.
- Ocks� fel p� rad 33 skall vara i++;  inte i=+2; eftersom for loopen adderar ett tilli. 
- �ven utkomenterad kod som var on�dig.
- Lade till  && (tolower(s[i+1]) == tolower(t)) f�r att g�ra programmet s�krare
*/
