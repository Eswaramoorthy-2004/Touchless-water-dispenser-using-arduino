// Include the necessary libraries
#include <NewPing.h>

// Define the pins for the ultrasonic sensor
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200

// Define the pin for the relay
#define RELAY_PIN    10

// Define the threshold distance for triggering the water dispenser
#define TRIGGER_DISTANCE 10 // Adjust this value based on your setup

// Create an instance of the NewPing library
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // Initialize the relay pin as an output
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // Get the distance measured by the ultrasonic sensor
  int distance = sonar.ping_cm();

  // Check if a hand is detected within the trigger distance
  if (distance < TRIGGER_DISTANCE && distance > 0) {
    // Activate the relay to turn on the water dispenser motor
    digitalWrite(RELAY_PIN, LOW);
    delay(1000); // Adjust this delay to control the water flow duration
    digitalWrite(RELAY_PIN, HIGH);
  }
}