#include <SparkFun_ADS1015_Arduino_Library.h>
#include <Wire.h>


ADS1015 fingerSensor;
int EMGsig;          
int EMGthreshold = 500; 
int FLEXthreshold = 900; 

void setup() {
  
  Wire.begin();
  Serial.begin(115200);
  
  if (fingerSensor.begin() == false) {
     Serial.println("Device not found. Check Wiring.");
     while (1);
  } 
  
  fingerSensor.setGain(ADS1015_CONFIG_PGA_TWOTHIRDS); // Gain of 2/3 to works well with flex glove board voltage swings (default is gain of 2)
}

void loop() {  
  //FLEX DISPLAY
  uint16_t data;
  for (int finger = 0; finger < 2; finger++) {
    data = fingerSensor.getAnalogData(finger);
    Serial.print("Finger: "); Serial.println(finger); 
    Serial.print("Data: "); Serial.println(data); 
    Serial.println();

    if (data > FLEXthreshold){     
    Serial.println(" FLEX Above "); Serial.println();
  } else{            
    Serial.println(" FLEX Below "); Serial.println();
}
  }
  Serial.println();

  //EMG DISPLAY
  EMGsig = analogRead(A2); // Read the analog values of the rectified+integrated EMG signal (0–1023)
  Serial.print(" EMG: "); Serial.println(EMGsig);
if (EMGsig > EMGthreshold){     // If EMG signal is below the threshold
    Serial.println(" EMG Above "); 
  } else{            // If the EMG signal is above the threshold,
    Serial.println(" EMG Below ");
} 
  Serial.println();
 delay(500); 
}
