
	

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void restart(int a,int bombac[][a],char tablo[][a]){
	int i,j;
	for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            bombac[i][j] = 0;//deletes all bombs
        }
    }
	int bomba = (a * a) / 10;	
    for (i = 0; i < bomba; i++) {//replaces bombs
        int randomRow, randomCol;
        do {
            randomRow = rand() % a;
            randomCol = rand() % a;
        } while (tablo[randomRow][randomCol] == 'x' || (randomRow == 0 && randomCol == 0) || (randomRow == a - 1 && randomCol == a - 1));

        bombac[randomRow][randomCol] = 1;
        
}			
	printf("Bombs Are Replaced!\n");		
}
int main() {
   	while(1){
   		
    int a;
    printf("Please Enter the Dungeon Scale: ");
    scanf("%d", &a);
	
	
		 if (a <= 4) {
        printf("Please Enter Valid Range!(min.5x5)");      
    } 	
   
	else {	  
	printf("\n");
        char tablo[a][a];
        int iz[a][a]; //Marks the Path Taken
        int bombac[a][a];
        int i, j;
        int kRow = 0, kCol = 0; //Characters Location In Starting
		 
		
        srand(time(NULL));
        // oyun alaný
        for (i = 0; i < a; i++) {
            for (j = 0; j < a; j++) {
                tablo[i][j] = 'o';
                iz[i][j] = 0;
                bombac[i][j] = 0;//Center Bomb
                
            }
        }
        //Random Path Choosing
        int bomba = (a * a) / 10;
        for (i = 0; i < bomba; i++) {
            int randomRow, randomCol;
            do {
                randomRow = rand() % a;
                randomCol = rand() % a;
            } while (tablo[randomRow][randomCol] == 'x' || (randomRow == 0 && randomCol == 0) || (randomRow == a-1 && randomCol == a-1));//Control of not placing bombs at the beginning and end

            bombac[randomRow][randomCol] = 1;
        }
		int kalancan = bomba/2;
		printf("Your goal is to reach the bottom exit.\n");
		printf("You have %d lives, be careful!\n",kalancan);
        
        while (1) {
            for (i = 0; i < a; i++) {
                for (j = 0; j < a; j++) {
                    if (iz[i][j] || tablo[i][j] == 'K') {
                        printf("%c ", tablo[i][j]);
                    } else {
                        printf("o ");
                    }
                }
                printf("\n");
            }
            // exit control
            if (kRow == a - 1 && kCol == a - 1) {
                printf("Congratulations You Have Reached The Exit!\n");
                return 0;
            }
           
		    //movement code
            char hareket;
            printf("Move with WASD ('q' to exit, 'r' to re-deploy bombs):");
            scanf(" %c", &hareket);

            switch (hareket) {
                case 'w':
                    if (kRow > 0) {
                        kRow--;
                        iz[kRow][kCol] = 1;
                    }
                    break;
                case 'a':
                    if (kCol > 0) {
                        kCol--;
                        iz[kRow][kCol] = 1;
                    }
                    break;
                case 's':
                    if (kRow < a - 1) {
                        kRow++;
                        iz[kRow][kCol] = 1;
                    }
                    break;
                case 'd':
                    if (kCol < a - 1) {
                        kCol++;
                        iz[kRow][kCol] = 1;
                    }
                    break;
                case 'q':
                    printf("Game Over!\n");              
                    return 0;
                case 'r'://bomb relocation function
				     restart(a,bombac ,tablo);
					 break;    
            }
            
		     if (bombac[kRow][kCol]) {
                kalancan--; 
			    printf("You have %d lives left!\n",kalancan);
                
                if (kalancan == 0) {
                    printf("BOOOOOOOMMM!!!!!?\n");
                    return 0;
                }
                kRow = 0;//send character to starting path
                kCol = 0;
            }        
	//Reposition table and character after move		
            for (i = 0; i < a; i++) {
                for (j = 0; j < a; j++) {
					if (i == kRow && j == kCol) // karakter
                        tablo[i][j] = 'K';
                    else if (iz[i][j]) //marking
                        tablo[i][j] = '-';
                    else
                    	tablo[i][j] = 'o';                       
                }
            }          
        }
        return 0;
    }
}
}

