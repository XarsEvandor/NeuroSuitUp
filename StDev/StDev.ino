void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

   // Gather sample data

  float sampleSum = 0;
  for(int i = 0; i < SAMPLES; i++) {
    s_val[i] = analogRead(TS);
    sampleSum += s_val[i];
    delay(20); // set this to whatever you want
  }
  float meanSample = sampleSum/float(SAMPLES);

  // HOW TO FIND STANDARD DEVIATION
  // STEP 1, FIND THE MEAN. (We Just did.)

  // STEP 2, sum the squares of the differences from the mean

  float sqDevSum = 0.0;

  for(int i = 0; i < SAMPLES; i++) {
    // pow(x, 2) is x squared.
    sqDevSum += pow((meanSample - float(s_val[i])), 2);
  }

  // STEP 3, FIND THE MEAN OF THAT
  // STEP 4, TAKE THE SQUARE ROOT OF THAT

  float stDev = sqrt(sqDevSum/float(SAMPLES));

  // TADA, STANDARD DEVIATION.
  // this is in units of sensor ticks (0-1023)

}
