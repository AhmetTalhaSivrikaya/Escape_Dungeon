
	//23110131316-Ahmet Talha Sivrikaya
	//23110131355-Muhammed Mete

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void restart(int a,int bombac[][a],char tablo[][a]){
	int i,j;
	for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            bombac[i][j] = 0;//bombalar?n hepsini kaldýrýr
        }
    }
	int bomba = (a * a) / 20;	
    for (i = 0; i < bomba; i++) {//bombalarý rastgele geri yerleþtirir
        int randomRow, randomCol;
        do {
            randomRow = rand() % a;
            randomCol = rand() % a;
        } while (tablo[randomRow][randomCol] == 'x' || (randomRow == 0 && randomCol == 0) || (randomRow == a - 1 && randomCol == a - 1));

        bombac[randomRow][randomCol] = 1;
        
}			
	printf("Bombalar yeniden yerlestirildi!\n");		
}
int main() {
   	while(1){
   		
    int a;
    printf("Lutfen Tablo Buyuklugunu Giriniz: ");
    scanf("%d", &a);
	
	
		 if (a <= 4) {
        printf("Lutfen Gecerli Aralik Giriniz (min.5x5)");      
    } 	
   
	else {	  
	printf("Iste Oyun Alaniniz\n");
        char tablo[a][a];
        int iz[a][a]; // karakterin arkasida býraktýðý iz 
        int bombac[a][a];
        int i, j;
        int kRow = 0, kCol = 0; // karakterin konumu
		 
		
        srand(time(NULL));
        // oyun alaný
        for (i = 0; i < a; i++) {
            for (j = 0; j < a; j++) {
                tablo[i][j] = 'o';
                iz[i][j] = 0;
                bombac[i][j] = 0;//merkezdeki bomba
                
            }
        }
        // rastgele yer belirleme
        int bomba = (a * a) / 10;
        for (i = 0; i < bomba; i++) {
            int randomRow, randomCol;
            do {
                randomRow = rand() % a;
                randomCol = rand() % a;
            } while (tablo[randomRow][randomCol] == 'x' || (randomRow == 0 && randomCol == 0) || (randomRow == a-1 && randomCol == a-1)); // baþlangýca ve bitiþe bomba koymama kontrolü(doðruluðundan emin deðilim

            bombac[randomRow][randomCol] = 1;
        }
		int kalancan = bomba/2;
		printf("Amaciniz En Alttaki Cikisa Ulasmak\n");
		printf("Tam %d Caniniz Vardir Dikkat Edin!\n",kalancan);
        
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
            // Çýkýþa ulaþma kontrolü
            if (kRow == a - 1 && kCol == a - 1) {
                printf("Tebrikler! Oyun bitti!\n");
                return 0;
            }
           
		    // hareket mekanizmasý
            char hareket;
            printf("WASD tuslariyla hareket edin (cikis icin 'q',bombalari yeniden yerlestirmek icin 'r'): ");
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
                    printf("Oyun bitti!\n");              
                    return 0;
                case 'r'://bombalarý tekrar yerleþtirme fonksiyonu
				     restart(a,bombac ,tablo);
					 break;    
            }
            
		     if (bombac[kRow][kCol]) {
                kalancan--; 
			    printf("%d Caniniz Kaldi!\n",kalancan);
                
                if (kalancan == 0) {
                    printf("BOOOOOOOMMM!!!!!?\n");
                    return 0;
                }
                kRow = 0;//karakteri baþa gönderme
                kCol = 0;
            }
	
            // tabloyu ve karakteri hareketten sonra tekrar yerleþtirme
			
            for (i = 0; i < a; i++) {
                for (j = 0; j < a; j++) {
					if (i == kRow && j == kCol) // karakter
                        tablo[i][j] = 'K';
                    else if (iz[i][j]) // iz
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

