## Questão 2:

Nessa questão foi feita uma suposição de que a caixa está cheia quando atinge a quantidade de 300 produtos.
Neste sentido, as cada 1 segundo, passam 60 produtos na ESTEIRA_1, logo serão 5 segundos até a caixa está cheia.
Quando a ESTEIRA_1 está em movimento a ESTEIRA_2 está parada. Quando a caixa encher, a ESTEIRA_1 irá parar e a ESTEIRA_2
irá se movimentar por 1 segundos tempo estimado(na suposição) entre as distâncias das caixas. Depois o processo se repete.

```c
#include <at89x52.h>

#define ESTERIRA_1 P2_0
#define ESTERIRA_2 P2_1
#define CAIXA_CHEIA P2_3


int timer = 0;
int qtdProduto = 0;

void atendeTimer() interrupt 1 {
	TR0 = 0;
	TH0 = 0x3C;
	TL0 = 0xAF;
	TR0 = 1;
	
	timer++;
	
	if(qtdProduto < 300){
		qtdProduto+=3;
	}
	
	if(qtdProduto == 300){
		CAIXA_CHEIA = 1;
	}
	
	
	if(timer == 100){
		ESTERIRA_1 = 0;
		ESTERIRA_2 = 1;
	}	
	if(timer == 120 && CAIXA_CHEIA == 1){
		ESTERIRA_1 = 1;
		ESTERIRA_2 = 0;
		CAIXA_CHEIA = 0;
		timer = 0;
		qtdProduto = 0;
	}
}

void main(){
	P2 = 0;
		
	EA = 1;
	ET0 = 1;
	TMOD = 1;
	TR0 = 1;
	
	ESTERIRA_1 = 1;
	ESTERIRA_2 = 0;
	
	while(1){
		
	}
}
```
