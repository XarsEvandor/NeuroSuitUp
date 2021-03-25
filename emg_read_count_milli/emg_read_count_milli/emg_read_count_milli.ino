int EMGsig1;           // Store the EMG signal valueservo
int EMGsig2;  
//int threshold = 500;  // Move the servo when EMG signal is above this threshold. Remember it ranges 0–1023.
int sum = 0;
int count = 0;
float threshold;
int max;
int min;
bool calc = false;
void setup() {
 Serial.begin(9600); // Starting the communication with the computer
  
}
void loop() {
    EMGsig1 = analogRead(A2); // Read the analog values of the rectified+integrated EMG signal (0–1023)
    EMGsig2 = analogRead(A0);

    if (count <100)
    {
      Serial.print(millis()); Serial.print(" ");
      Serial.print(EMGsig1);Serial.print(" ");
      Serial.println(EMGsig2);

        if (count == 1)
        {
            max = EMGsig1;
            min = EMGsig1;
        }
        else
        {
            if (EMGsig1 > max)
            {
                max = EMGsig1;
            }
            else if (EMGsig1 < min)
            {
                min = EMGsig1;
            }
            
        }
        
        count++;
    }
    else
    {
        if (!calc)
        {
            threshold = (max - min)/ count;
            calc = true;
        }
        
    Serial.print(millis()); Serial.print(" ");
    Serial.print(EMGsig1); Serial.print(" ");Serial.print(EMGsig2); Serial.print(" ");
        if (EMGsig1 > threshold)
        {
            Serial.println("1");
        }
        else{
            Serial.println("0");
        }
        
    }



//if (EMGsig1 > threshold){     // If EMG signal is below the threshold
//    Serial.print(" Above ");
//  } else{            // If the EMG signal is above the threshold,
//    Serial.print(" Below ");
//}

  // Display the servo and EMG values.
 delay(100); 
}
