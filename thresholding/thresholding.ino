int EMGsig;           // Store the EMG signal valueservo
//int threshold = 500;  // Move the servo when EMG signal is above this threshold. Remember it ranges 0–1023.
int sum = 0;
int count = 0;
float thresholdMin;
float thresholdMax;
int max;
int min;
bool thres = false;
void setup() {
 Serial.begin(9600); // Starting the communication with the computer
  
}
void loop() {
    if (!thres)
    {
        ThresholderMin();
        ThresholderMax();
    }

    else
    {
        EMGsig = analogRead(A2);

        Serial.print(millis()); Serial.print(" ");
        Serial.print(EMGsig); Serial.print(" ");
        if (EMGsig > thresholdMin)
        {
            Serial.print("1   ");
        }
        else{
            Serial.print("0   ");
        }

        if (EMGsig > thresholdMax)
        {
            Serial.println("1");
        }
        else{
            Serial.println("0");
        }
    }
      delay(100);  
    }



//if (EMGsig > threshold){     // If EMG signal is below the threshold
//    Serial.print(" Above ");
//  } else{            // If the EMG signal is above the threshold,
//    Serial.print(" Below ");
//}

int ThresholderMin(){

    min = 1000;
    max = 0;

    Serial.println("Please keep your hand relaxed for 10 seconds");
    delay(3000);
    for (int i = 0; i < 3; i++)
    {
        Serial.print("Starting in: "); Serial.print(3-i); Serial.println("\r");
        delay(1000);
        }

        for (int k = 0; k < 100; k++)
        {
            EMGsig = analogRead(A2);

            Serial.print(millis()); Serial.print(" ");
            Serial.print(EMGsig); Serial.println(" ");

            if (EMGsig > max)
            {
                max = EMGsig;
            }
            else if (EMGsig < min)
            {
                min = EMGsig;
            }
            delay(100);
        }


        thresholdMin = (max + min)/2*1.3;
        Serial.print("Max: "); Serial.println(max);
        Serial.print("Min: "); Serial.println(min);
        Serial.print("Minimum Threshold: "); Serial.println(thresholdMin);

        delay(3000);
        

        thres = true;

        return thresholdMin;
}


int ThresholderMax(){

    min = 1000;
    max = 0;

    Serial.println("Please keep your hand clenched for 10 seconds");
    delay(3000);
    for (int i = 0; i < 3; i++)
    {
        Serial.print("Starting in: "); Serial.print(3-i); Serial.println("\r");
        delay(1000);
        }

        for (int k = 0; k < 100; k++)
        {
            EMGsig = analogRead(A2);

            Serial.print(millis()); Serial.print(" ");
            Serial.print(EMGsig); Serial.println(" ");

            if (EMGsig > max)
            {
                max = EMGsig;
            }
            else if (EMGsig < min)
            {
                min = EMGsig;
            }
            delay(100);
        }


        thresholdMax = (max + min)/2*0.6;
        Serial.print("Max: "); Serial.println(max);
        Serial.print("Min: "); Serial.println(min);
        Serial.print("Maximum Threshold: "); Serial.println(thresholdMax);

        delay(3000);
        

        thres = true;

        return thresholdMax;
}
