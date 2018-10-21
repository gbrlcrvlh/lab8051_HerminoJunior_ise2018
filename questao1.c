#include <at89x52.h>

#define COIN P3_0
#define K P3_1
#define T P3_2
#define TEA P3_5
#define COFEE P3_6
#define GLASS P3_7

int aux1 = 0, aux2 = 0;

void delay(int n){
	int j;
  int i;
  for(i = 0; i < n; i++){
    for(j = 0; j < 100; j++);
  }
}


void main(){
	
	P3 = 0;	
	
	while(1){
		
		if(COIN == 0){
			aux1 = 1;
		}
		
		if(COIN == 1 && aux1 == 1){
			
			if(K == 0 || T == 0){
				aux2 = 1;
			}
	
			if(K == 1 && aux2 == 1){
				TEA = 1;
				delay(2500);
					if(TEA == 1 && COFEE == 0){
						GLASS = 1;
						delay(2500);
						aux1 = 0;
						P3 = 0;
					}
			}else if(T == 1 && aux2 == 1){
				COFEE = 1;
				delay(2500);
					if(TEA == 0 && COFEE == 1){
						GLASS = 1;
						delay(2500);
						aux1 = 0;
						P3 = 0;
					}
			}
			delay(2000);
			aux2 = 0;
		}
		delay(2000);
	}
}
