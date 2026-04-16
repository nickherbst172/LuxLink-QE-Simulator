/*
 * PROJECT: Quantum Entanglement Logic Simulator
 * HARDWARE: Arduino Uno, 2x LEDs (Pins 2, 3), 2x Resistors
 * LOGIC: Demonstrating non-local correlation from a shared random seed.
 */

// Pin Definitions
const int qubitA = 2; // LED representing Particle A
const int qubitB = 3; // LED representing Particle B
const int triggerPin = 4; // Use a wire to touch Pin 4 to GND to "Measure"

void setup() {
  pinMode(qubitA, OUTPUT);
  pinMode(qubitB, OUTPUT);
  
  // Using Internal Pullup: Measurement happens when Pin 4 hits Ground
  pinMode(triggerPin, INPUT_PULLUP);
  
  // Engineering Trick: Seed randomness using noise from an empty analog pin
  randomSeed(analogRead(A5)); 
  
  Serial.begin(9600);
  Serial.println("--- QUANTUM SYSTEM INITIALIZED ---");
  Serial.println("Status: In Superposition (Flickering)");
  Serial.println("Action: Ground Pin 4 to perform measurement...");
}

void loop() {
  // --- STAGE 1: SUPERPOSITION ---
  // The LEDs flicker independently. They are not yet correlated.
  while(digitalRead(triggerPin) == HIGH) {
    digitalWrite(qubitA, random(0, 2)); 
    digitalWrite(qubitB, random(0, 2));
    delay(30); // Fast flicker to simulate 'uncertainty'
  }

  // --- STAGE 2: THE MEASUREMENT (COLLAPSE) ---
  // The moment the trigger is hit, the universe makes ONE decision
  // for the entire entangled system.
  int collapsedState = random(0, 2); 

  // --- STAGE 3: CORRELATION ---
  // Spooky action: both LEDs snap to the same result instantly.
  digitalWrite(qubitA, collapsedState);
  digitalWrite(qubitB, collapsedState);

  // Output the result to the Serial Monitor
  Serial.print("CRITICAL: Wavefunction Collapsed! Result: |");
  Serial.print(collapsedState);
  Serial.println(">");

  // Hold the measurement for 3 seconds so the human eye can process it
  delay(3000); 

  Serial.println("\nResetting to Superposition...");
}