#include <stdio.h>
#include <string.h>
// DIFFRENCE BETWEEN TYPEDEF
typedef int realnum;
int main(){
    // DECLARATION
    struct pokemon{
        // ATTRIBUTES
        char name[50];
        int hp;
        realnum speed; //TYPE DEF JUST CHANGE THE NAME OF THE DTATA TYPE
        int attack;
        char tier;
    }charizard;  //ONE WAY TO DECLARE  
    struct pokemon pikachu; //SECOND WAY TO DECLARE OBJECT
    // pikachu.name[]="PICKACHU"; // AFTER DECLARING A STRING WE CANNOT GIVE ITS VALUE DIRECTLY THE ONLY WAY IS BY USING "strcpy(str,"string")"
    strcpy(pikachu.name,"PICKACHU");
    printf("%s\n",pikachu.name);  
    // ASSIGN VALUE TO ATTRIBUTES OF DIFFRENT OBJECTS  
    pikachu.attack=99;
    pikachu.hp=80;
    pikachu.speed=101;
    pikachu.tier='A';
    // TAKING INPUT
    scanf("%d",&charizard.attack);
    scanf("%s",charizard.name);
    printf("%s\n",charizard.name);
    charizard.hp=113;
    charizard.speed=90;
    charizard.tier='B';
    // PRINTING OBJECTS ATTRIBUTES VALUE
    printf("%d\n",charizard.attack);    

    typedef struct book
    {
        char name[50];
        realnum quantity;
        int price;
    }book_name ; // JUST GIVEN NAME TO MY STRUCT DECLARED AS NAME 
    struct book maths;
    book_name physics={"Physics",20,80000};
    printf("%s",physics.name);
return 0;
}

