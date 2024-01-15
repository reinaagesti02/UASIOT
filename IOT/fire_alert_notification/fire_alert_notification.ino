#define BLYNK_TEMPLATE_ID "TMPL6t5klKFzI"
#define BLYNK_TEMPLATE_NAME "Fire Alert Notification"
#define BLYNK_AUTH_TOKEN "62XzJwaip3sqcALkvoGJJN62d7WhXAmn"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "ARIF JAYA AC MOBIL";  // type your wifi name
char pass[] = "Felisaja";  // type your wifi password
 

BlynkTimer timer;
int flag=0; 
void sendSensor(){ 
   int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==0 && flag==0) {
    Serial.println("Fire in the House");  
    //Blynk.email("reinaagesti02@gmail.com", "Alert", "Fire Detected!");
    Blynk.logEvent("fire_alert","Fire Detected");
    
    flag=1;
  }
  else if (isButtonPressed==1)
  {
    flag=0;
    
  }


 
}

void setup(){
  pinMode(D1, INPUT);
 
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(5000L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
