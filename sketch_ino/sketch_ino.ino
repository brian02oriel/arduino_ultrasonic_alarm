#define trigPin 6
#define echoPin 5
#define buzzer 8

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  long distance = getDistance();
  activateBuzzer(distance);
  delay(200);
}

long getDistance(){
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

void activateBuzzer(long distance){
    float newDelay = (distance * 3) + 30;
    if(distance < 50) {
    tone(buzzer, 2000);
    delay(newDelay);
    noTone(buzzer);
  } else {
    noTone(buzzer);
  }  
}
