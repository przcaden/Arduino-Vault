#include <Vector.h>
#include <Keypad.h>
#include <Servo.h>

#define SERVO 10
#define gled A5

// Initialize values for PIN pad recognition
const byte dim = 4; // dimensions of pad
char keys[dim][dim] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Servo servo;
byte rowPins[dim] = {2,3,4,5};
byte colPins[dim] = {6,7,8,9};
Keypad pad = Keypad(makeKeymap(keys), rowPins, colPins, dim, dim);
bool record;
bool vaultIsOpen;
typedef Vector<char> Elements;
Elements pin;
Elements attempt;
const int ELEMENT_COUNT_MAX = 5;

void setup() {
  servo.attach(SERVO);
  servo.write(0);
  // Initialize algorithm values
  pinMode(gled, OUTPUT);
  record = false;
  vaultIsOpen = true;

  // Initialize vector storage
  char storage_array_1[ELEMENT_COUNT_MAX];
  char storage_array_2[ELEMENT_COUNT_MAX];
  pin.setStorage(storage_array_1);
  attempt.setStorage(storage_array_2);
  
  // Set debounce allowance times
  pad.setHoldTime(500);
  pad.setDebounceTime(50);
  Serial.begin(9600);
  while (!Serial) {} // Wait for serial to initialize
}

// Loop to grab key press, pass to algorithm
void loop() {
  char key = pad.getKey();
  inputAlgo(key);
}

// Algorithm for key presses
void inputAlgo(char key) {
  if (key == NO_KEY) return;
  Serial.println(key);
  // Check to begin recording
  if (key == '#') {
    // If PIN or attempt was finished, open/close the vault
    if (record) {
      if (vaultIsOpen) {
        digitalWrite(gled, HIGH);
        closeVault();
        delay(2000);
        digitalWrite(gled, LOW);
      }
      else if (compare(pin, attempt)) {
        digitalWrite(gled, HIGH);
        openVault();
        pin.clear();
        delay(2000);
        digitalWrite(gled, LOW);
      }
      else {
        // Blink the LED five times when you enter the PIN wrong
        for (int i=0; i<5; i++) {
          digitalWrite(gled, HIGH);
          delay(100);
          digitalWrite(gled, LOW);
          delay(100);
        }
      }
      attempt.clear();
    }
    record = !record;
    return;
  }
  
  // Push to PIN/attempt if recording is in progress
  else if (record) {
    digitalWrite(gled, HIGH);
    if (vaultIsOpen)
      pin.push_back(key);
    else
      attempt.push_back(key);
    delay(40);
    digitalWrite(gled, LOW);
  }
}

// Compares two vectors of characters and returns if they are equal or not.
bool compare(Elements v1, Elements v2) {
  // Return false if sizes are different
  if (v1.size() != v2.size()) return false;

  // Return false if vectors contain different characters
  for (int i=0; i<v1.size(); i++) {
    if (v1[i] != v2[i]) return false;
  }
  // If other checks are passed, vectors are equivalent
  return true;
}

// Opens the vault.
void openVault() {
  Serial.println("Opening vault");
  servo.write(-88);
  vaultIsOpen = true;
}

// Closes the vault.
void closeVault() {
  Serial.println("Closing vault");
  servo.write(88);
  vaultIsOpen = false;
}
