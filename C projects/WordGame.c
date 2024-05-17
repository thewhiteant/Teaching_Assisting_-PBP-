#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){

    int len;
    //Getting Inputs
    printf("Enter Length of the word: ");
    scanf("%d",&len);    


    //First Player

    char word[100];

    printf("word: ");
    scanf("%s",word);
    printf("\n");

    

    //Clear The Screen (External Libaray stdlib)
    system("cls");

    
    
 
    char hidden_word[100]; 

    
    hidden_word[0] = word[0];
    
    // A****

    int i;    
    for(i=1;i<len;i++){
        hidden_word[i] = '*';
    }

    hidden_word[len] = '\0';
    
        


    char guess_word[100];
    
    int hint_count = len/3;



    while(1){
        printf("==> %s \n", hidden_word);
        printf("Guess (Hint $) [Left: %d] : ",hint_count);
        scanf("%s",guess_word);

         
        if(strcmp(guess_word,"$") == 0){

            if(hint_count>0){
                hint_count--;
            while(1){
                int indx = rand() % len;

                if(hidden_word[indx] == '*'){
                    hidden_word[indx] = word[indx];

                    break;
                    
                  
                }
            }

            }else{
                printf("Oppps No Hints.\n");
            }


            continue;
                    
        }




        if(strcmp(guess_word,word) == 0) {
            printf("Aloooha!! You Win..\n");
            break;
        }else{
            printf("E E E Wrong Try!!!\n");
        }
        
       


    }

    





    
    





    return 0;
}