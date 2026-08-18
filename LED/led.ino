int led1 = 2;
int led2 = 3;
int led3 = 4;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  for (int num = 0; num < 8; num++) {

    int b0 = num % 2;       
    int b1 = (num / 2) % 2;  
    int b2 = (num / 4) % 2;  

    digitalWrite(led1, b0);
    digitalWrite(led2, b1);
    digitalWrite(led3, b2);

    delay(1000);
  }
}
