int dir_pin;
int step_pin;

void setup() {
  Serial.begin(9600);

  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  digitalWrite(dir_pin, LOW);
}

void loop() {
  Serial.println("Enter data: ");

  if (Serial.available() > 0) {
  
// 10w100 (10 - Revolutions, w-direction, 100 - speed)
  String input = Serial.readString();

  int speed = input.substring(3).toInt();
  char direction = input[2];
  int rev = input.substring(0,2).toInt();

  Serial.println("Speed: ");
  Serial.println(speed);

  Serial.println("No. of revolutions: ");
  Serial.println(rev);

  for (int i = 0; i < 200*rev; i++){
    if (direction == 'w'){
      Serial.println("Direction: Forward");
      digitalWrite(dir_pin, HIGH); //forward dir
      digitalWrite(step_pin, HIGH);
      delay(speed);
      digitalWrite(step_pin, LOW);
      delay(speed);
    } else if (direction == 's'){
      Serial.println("Direction: Backward");
      digitalWrite(dir_pin, LOW); //backward dir
      digitalWrite(step_pin, HIGH);
      delay(speed);
      digitalWrite(step_pin, LOW);
      delay(speed);
    } else{
      Serial.println("Invalid Input");
    }

  }
  }
}
