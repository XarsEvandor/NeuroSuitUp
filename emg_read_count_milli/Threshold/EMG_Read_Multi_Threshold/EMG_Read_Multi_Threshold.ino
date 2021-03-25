int EMGsig;           // Store the EMG signal valueservo
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

    
    EMGsig = analogRead(A2); // Read the analog values of the rectified+integrated EMG signal (0–1023)

    if (count <100)
    {
      Serial.print(millis()); Serial.print(" ");
      Serial.println(EMGsig);

        if (count == 1)
        {
            max = EMGsig;
            min = EMGsig;
        }
        else
        {
            if (EMGsig > max)
            {
                max = EMGsig;
            }
            else if (EMGsig < min)
            {
                min = EMGsig;
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
    Serial.print(EMGsig); Serial.print(" ");
        if (EMGsig > threshold)
        {
            Serial.println("1");
        }
        else{
            Serial.println("0");
        }
        
    }



//if (EMGsig > threshold){     // If EMG signal is below the threshold
//    Serial.print(" Above ");
//  } else{            // If the EMG signal is above the threshold,
//    Serial.print(" Below ");
//}

  // Display the servo and EMG values.
 delay(100); 
}
