#include <SD.h>

File dataFile;
int led = 13;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
  Serial.print("Iniciando SD card...");
  pinMode(53, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(53, HIGH);
  if (!SD.begin(53)) {
  Serial.println("Fallo comunicacion o no existe SD");
  digitalWrite(led, HIGH);
  return;}
  digitalWrite(led, LOW);
  Serial.println("SD Iniciada.");
  
  dataFile = SD.open("datalog.txt", FILE_WRITE);
  
  /////////
  if (dataFile) {
    Serial.println(" Informacion...");
    dataFile.println("temp...");
    
    Serial.println("");
    dataFile.println("");
    
    Serial.println("Program: humidity");
    dataFile.println("humidity");
    
    Serial.println("");
    dataFile.println("");
    
    Serial.println("<<< Datalogger >>>");
    dataFile.println("<<< Datalogger >>>");
    

    dataFile.close();}
    else {
    Serial.println("error opening test.txt");}
  ////////////
}

void loop(){
  
  String dataString = "";
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ","; }}
      
dataFile = SD.open("datalog.txt", FILE_WRITE);

  if (dataFile) {
    digitalWrite(led, LOW);
    dataFile.println(dataString);
    delay(1000);  
    dataFile.close();
    Serial.println(dataString);
  }  
  else {
    Serial.println("Fallo comunicacion.txt");
    Serial.println("Revise conecxion");
    digitalWrite(led, HIGH);
    delay(1000); } 
}









