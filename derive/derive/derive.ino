int EMGsig1=0;           // Store the EMG signal valueservo
int EMGsig2=0;           // Store the EMG signal valueservo
int PrevSig1=0;
int twoPrevsig;
int Prevprevsig;
int PrevSig2=0;
float avgsig = 0;
float deriv1 = 0;
float deriv2 = 0;
int threshold = 500;  // Move the servo when EMG signal is above this threshold. Remember it ranges 0–1023.
void setup() {
 Serial.begin(9600); // Starting the communication with the computer
}
void loop() {
EMGsig1 = analogRead(A2); // Read the analog values of the rectified+integrated EMG signal (0–1023)
deriv1 = abs((EMGsig1-avgsig));
avgsig = (PrevSig1+Prevprevsig+twoPrevsig)/3;
 
//if (EMGsig > threshold){     // If EMG signal is below the threshold
//    Serial.print(" Above ");
//  } else{            // If the EMG signal is above the threshold,
//    Serial.print(" Below ");
//}
 //Serial.print(millis()); Serial.print(" ");
 Serial.print(EMGsig1); Serial.print(" ");
 //Serial.print(PrevSig1);Serial.print(" "); 
 Serial.println(deriv1);
 twoPrevsig = Prevprevsig;
 Prevprevsig = PrevSig1;
PrevSig1 = EMGsig1; 
  // Display the servo and EMG values.
 delay(100); 
}
