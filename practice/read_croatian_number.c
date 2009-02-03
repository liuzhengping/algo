/* Napisati program koji za zadani prirodni broj N manji od milijardu uz pomoc funkcije ciji je prototip:
void citaj(char *s, int x);
zapise izgovor broja x u s
U glavnom programu ucitati broj N (manji od 100000), zatim N prirodnih brojeva (manjih od milijardu). 
Program treba ispisati tablicu u sljedecem formatu: na prvih deset mjesta napisati broj pomocu znamenki (bez vodecih nuli, poravnat udesno), zatim jedan razmak, te potom izgovor koji ne sadrzi niti jedan razmaka.

Primjer:
Ulaz:
5
1023    13000
101614

952123001
  123456789

Izlaz:
     1023 tisucudvadesettri
    13000 trinaesttisuca
   101614 stojednatisucasestocetrnaest
952123001 devetstopedesetdvamilijunastodvadesettritisucejedan
123456789 stodvadesettrimilijunacetristopedesetsesttisucasedamstoosamdesetdevet
*/
#include <stdio.h>
#include <string.h>
#define MAX 100005
#define M 15
void do_tisucu(char *s, int x, int m) {
  /* dodaje na s procitani broj x < 1000 u muskom(1)/zenskom(0) rodu */
  char dm[][M] = {"", "jedan", "dva", "tri", "cetiri", "pet", "sest", "sedam",
              "osam", "devet"};
  char dz[][M] = {"", "jedna", "dvije", "tri", "cetiri", "pet", "sest", 
                     "sedam", "osam", "devet"};
  char dv[][M] = {"deset", "jedanaest", "dvanaest", "trinaest", "cetrnaest", 
               "petnaest", "sesnaest", "sedamnaest", "osamnaest", "devetnaest"};
  char sto[][M] = {"", "", "dvadeset", "trideset", "cetrdeset", "pedeset", 
                "sezdeset", "sedamdeset", "osamdeset", "devedeset"};
  char tis[][M] = {"", "sto", "dvijesto", "tristo", "cetristo", "petsto", 
                "sesto", "sedamsto", "osamsto", "devetsto"};
  
  strcat(s, tis[x/100]);
  x %= 100;
  if(x < 10) strcat(s, m ? dm[x] : dz[x]);
  else if(x < 20) strcat(s, dv[x-10]);
  else {
    strcat(s, sto[x/10]);
    strcat(s, m ? dm[x%10] : dz[x%10]);
  }
}
void citaj(char *s, int x) {
  s[0] = 0; /* "izbrisi" s */
  /*sredi milijune */
  int div = x/1000000;
  if(div) {
    if(div > 1) do_tisucu(s, div, 1);
    strcat(s, (div%10 == 1 && div != 11) ? "milijun" : "milijuna");
    x %= 1000000;
  }
  x %= 1000000;
  /* sredi tisuce */
  div = x/1000;
  if(div) {
    if(div ==  1) strcat(s, "tisucu");
    else {
      do_tisucu(s, div, 0);
      strcat(s, (div%10 >= 2 && div%10 <= 4 
                 && !(div >= 12 && div <= 14) ) ? "tisuce" : "tisuca");
    }
    x %= 1000;
  }
  /* sredi stotine */
  do_tisucu(s, x%1000, 1);
}
int main() {
  int n, i, niz[MAX];
  scanf("%d", &n);
  for(i = 0; i < n; ++i)
    scanf("%d", &niz[i]);
  for(i = 0; i < n; ++i) {
    char s[150];
    citaj(s, niz[i]);
    printf("%9d %s\n", niz[i], s);
  }
  return 0;
}
