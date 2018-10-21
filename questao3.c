#include <at89x52.h>

#define CAMERA_1 P2_0
#define CAMERA_2 P2_1
#define CAMERA_3 P2_2
#define CAMERA_4 P2_3
#define ALARME P2_7
#define PRESENCA_1 P3_0
#define PRESENCA_2 P3_1
#define PRESENCA_3 P3_2
#define PRESENCA_4 P3_3


int timer = 0;

void atendeTimer() interrupt 1 {
		TR0 = 0;
		TH0 = 0x3C;
		TL0 = 0xAF;
		TR0 = 1;
	
	timer++;
	
	if(timer == 60){
		CAMERA_1 = 1;
		CAMERA_4 = 0;
		if(PRESENCA_1 == 1){
			ALARME = 1;
		}
	}
	
	if(timer == 120){
		CAMERA_2 = 1;
		CAMERA_1 = 0;
		if(PRESENCA_2 == 1){
			ALARME = 1;
		}
	}
	
	if(timer == 180){
		CAMERA_3 = 1;
		CAMERA_2 = 0;
		if(PRESENCA_3 == 1){
			ALARME = 1;
		}
	}
	
	if(timer == 240){
		CAMERA_4 = 1;
		CAMERA_3 = 0;
		if(PRESENCA_4 == 1){
			ALARME = 1;
		}
		timer = 0;
	}

}

void main(){
	P2 = 0;
	P3 = 0;
		
	EA = 1;
	ET0 = 1;
	TMOD = 1;
	TR0 = 1;
	
	CAMERA_1 = 0;
	CAMERA_2 = 0;
	CAMERA_3 = 0;
	CAMERA_4 = 0;
	
	PRESENCA_1 = 0;
	PRESENCA_2 = 0;
	PRESENCA_3 = 0;
	PRESENCA_4 = 0;
	
	ALARME = 0;
	
	while(1){
		
	}
}
