// This #include statement was automatically added by the Particle IDE.
#include <JsonParserGeneratorRK.h>

// This #include statement was automatically added by the Particle IDE.
#include "lib1.h"

int sensor1= A1; // Instead of writing D0 over and over again, we'll write led1
// You'll need to wire an LED to this one to see it blink.


void setup() {


	pinMode(sensor1, INPUT);

}


void loop() {


  int humid =  analogRead(sensor1);
	
  // Trigger the integration
  createEventPayload(humid);
  // Wait 30seconds
  delay(30000);


	// And repeat!
}

void createEventPayload(int humid)
{
    JsonWriterStatic<256> jw;
    {
        JsonWriterAutoObject obj(&jw);
        jw.insertKeyValue("humid",humid);
    }
    Particle.publish("Humid_Vals", jw.getBuffer(), PRIVATE);

}

