#include "thingProperties.h"
#include "AtomMotion.h"
#include "Ultrasonic.h"

AtomMotion Atom;
Ultrasonic ultrasonic(22);

xSemaphoreHandle CtlSemaphore;
void TaskMotion(void *pvParameters) {
  unsigned long currentTime = millis();
  long RangeInCentimeters;

  while (1)
  {
    RangeInCentimeters = ultrasonic.MeasureInCentimeters();
    duration = (int)RangeInCentimeters;
    
    if (duration < 3) {
      Atom.SetServoAngle(1, 40);
      currentTime = millis();
      openFlag = true;
      
    }else if(duration >= 3 && millis() - currentTime > 10000){
      Atom.SetServoAngle(1, 90);
      openFlag = false;
      
    }

    vTaskDelay( 1000 / portTICK_RATE_MS );
  }
}

void setup() {
  Atom.Init();
  delay(10);
  Serial.begin(115200);
  pinMode(6, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(7, INPUT);
  delay(1000);

  Atom.SetServoAngle(1, 90);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  // note: Arduino IoT Cloudのネット接続と分けるため、プロセスを別にした。
  xTaskCreatePinnedToCore(
    TaskMotion
    ,  "TaskMotion"
    ,  4096
    ,  NULL
    ,  2
    ,  NULL
    ,  1);


}

void loop() {
  ArduinoCloud.update();
  M5.update();

  delay(100);
}

void onOpenFlagChange()  {
  // note:値が変化したときに実施する処理は無いが、関数が定義されていないとエラーになるため注意

}
