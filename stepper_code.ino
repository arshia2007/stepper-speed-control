int dir_pin;

void setup() {
  Serial.begin(9600);
  pinMode(dir_pin, OUTPUT);
}

void loop() {
  Serial.println("Enter data: ");

  while (Serial.available() == 0) {
  }

  String input = Serial.readString();
  String speed = input.substring(1);
  int n = speed.toInt();

  if (input[0] == 'w') {
    digitalWrite(dir_pin, HIGH);
    delay(n);
  } else if (input[0] == 's') {
    digitalWrite(dir_pin, LOW);
    delay(n);
  }
}
