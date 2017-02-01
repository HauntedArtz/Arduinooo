#include <EEPROM.h>     // We are going to read and write PICC's UIDs from/to EEPROM
#include <SPI.h>        // RC522 Module uses SPI protocol
#include <MFRC522.h>  // Library for Mifare RC522 Devices

byte masterCard[4];

byte readCard[4];

byte storedCard[4]; 

int DoorOpen(void);

boolean match = false;          // initialize card match to false
boolean programMode = false;  // initialize programming mode to false
boolean replaceMaster = false;

int Status = 1;


    boolean isMaster( byte test[] ) {
  if ( checkTwo( test, masterCard ) )
    return true;
  else
    return false;
}

    
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 


int DoorOpen(){
  Serial.println("-----Example-----");w
  Serial.println(("Checking Motors"));
  Serial.println(("Motor Status ="));
  Serial.println((Status));
  if (Status == 1){
    printf(("Opening Door"));
  } else {
    printf(("Please fix the motor or the door."));
  }
 Serial.println("------Done-------");

}

void setup(){




  Serial.begin(9600);  // Initialize serial communications with PC
  SPI.begin();           // MFRC522 Hardware uses SPI protocol
  mfrc522.PCD_Init();    // Initialize MFRC522 Hardware




}

void loop(){
  if( isMaster(readCard)){
    DoorOpen();

  }




















}
boolean checkTwo ( byte a[], byte b[] ) {
  if ( a[0] != 0 )      // Make sure there is something in the array first
    match = true;       // Assume they match at first
  for ( uint8_t k = 0; k < 4; k++ ) {   // Loop 4 times
    if ( a[k] != b[k] )     // IF a != b then set match = false, one fails, all fail
      match = false;
  }
  if ( match ) {      // Check to see if if match is still true
    return true;      // Return true
  }
  else  {
    return false;       // Return false
  }
}





