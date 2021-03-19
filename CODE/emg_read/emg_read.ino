int EMGsig;           // Store the EMG signal valueservo
int threshold = 500;  // Move the servo when EMG signal is above this threshold. Remember it ranges 0–1023.
void setup() {
 Serial.begin(9600); // Starting the communication with the computer
}
void loop() {
EMGsig = analogRead(A2); // Read the analog values of the rectified+integrated EMG signal (0–1023)
//if (EMGsig > threshold){     // If EMG signal is below the threshold
//    Serial.print(" Above ");
//  } else{            // If the EMG signal is above the threshold,
//    Serial.print(" Below ");
//}
 Serial.print(" EMG:"); Serial.println(EMGsig); 
  // Display the servo and EMG values.
 delay(100); 
}
