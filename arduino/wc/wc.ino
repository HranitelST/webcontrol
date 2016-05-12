int led1 = 2;
int led2 = 3;
int led3 = 4;
String inString = "";

void setup() {
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	Serial.begin(9600);
	} 
 
void loop() {
	while (Serial.available()) {
		char inChar = Serial.read(); 
		//Serial.write(inChar);        // эхо
		if (inChar!= 13) {
			inString += inChar;          // формируем строку
			}
		if (inChar == 13) {
			command();
			Serial.flush();
			}
		}
	} 


void command() {
	// разбор данных вида H2...H13, L2...L13: H - включен, L - выключен
	if (inString[0] == 'H') {
		switch (inString[1]) {
			case '2': digitalWrite(led1, HIGH); Serial.println ("LED1 ON"); break;
			case '3': digitalWrite(led2, HIGH); Serial.println ("LED2 ON"); break;
			case '4': digitalWrite(led3, HIGH); Serial.println ("LED3 ON"); break;
			}
		}
	if (inString[0] == 'L') {
		switch (inString[1]) {
			case '2': digitalWrite(led1, LOW); Serial.println ("LED1 OFF"); break;
			case '3': digitalWrite(led2, LOW); Serial.println ("LED2 OFF"); break;
			case '4': digitalWrite(led3, LOW); Serial.println ("LED3 OFF"); break;
			}
		}
	inString = "";
}
