#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h> 
 
#define TRIG 22
#define ECHO 21
 
void setup() {
        wiringPiSetup();
        pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);
 
        //TRIG pin must start LOW
        digitalWrite(TRIG, LOW);
        delay(30);
}
 
int getCM() {
        //Send trig pulse
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG, LOW);
 
        //Wait for echo start
        while(digitalRead(ECHO) == LOW);
 
        //Wait for echo end
        long startTime = micros();
        while(digitalRead(ECHO) == HIGH);
        long travelTime = micros() - startTime;
 
        //Get distance in cm
        int distance = travelTime / 58;
 
        return distance;
}
 
int main(void) {
        setup();
	int i=0;
 	for (i=0;i<=20;i++){
        printf("Distance: %dcm\n", getCM());
 	delay(500);
	}	
        return 0;
}
