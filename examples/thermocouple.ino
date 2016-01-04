/**************** MAX31855K_Thermocouple_Digitizer_Example.ino *****************
 *                                                                             *
 * MAX31855K Thermocouple Breakout Example Code                                *
 * bsatrom@gmail.com                                                           *
 * January 3rd 2016                                                            *
 * Based on example code from SparkFun Electronics                             *
 * https://github.com/sparkfun/MAX31855K_Thermocouple_Digitizer                *
 *                                                                             *
 * Use the "serial monitor" window to read a temperature sensor.               *
 *                                                                             *
 * Circuit:                                                                    *
 * MAX31855K breakout attached to the following pins                           *
 *  SS:   pin D3                                                               *
 *  MOSI: pin A5 (NC)                                                          *
 *  MISO: pin A4                                                               *
 *  SCK:  pin A3                                                               *
 *  VCC:  pin D1                                                               *
 *  GND:  pin D2                                                               *
 *                                                                             *
 ******************************************************************************/

#include "SparkFunMAX31855k.h" // Using the max31855k driver

// Define SPI Arduino pin numbers (Arduino Pro Mini)
const uint8_t CHIP_SELECT_PIN = D3; // Using standard CS line (SS)
// SCK & MISO are defined by Arduiino
const uint8_t VCC = D1; // Powering board straight from Arduino Pro Mini
const uint8_t GND = D2;

// Instantiate an instance of the SparkFunMAX31855k class
SparkFunMAX31855k probe(CHIP_SELECT_PIN, VCC, GND);

void setup() {
  Serial.begin(9600);
  Serial.println("\nBeginning...");
  delay(50);  // Let IC stabilize or first readings will be garbage
}

void loop() {
  float temperature = probe.readCJT();
  
  // Read methods return NAN if they don't have a valid value to return.
  // The following conditionals only print the value if it's not NAN.
  if (!isnan(temperature)) {
    Serial.print("CJT is (˚C): ");
    Serial.println(temperature);
  }
  
  // Read the temperature in Celsius
  temperature = probe.readTempC();
  if (!isnan(temperature)) {
    Serial.print("Temp[C]=");
    Serial.print(temperature);
  }

  // Read the temperature in Fahrenheit
  temperature = probe.readTempF();
  if (!isnan(temperature)) {
    Serial.print("\tTemp[F]=");
    Serial.print(temperature);
  }

  // Read the temperature in Kelvin
  temperature = probe.readTempK();
  if (!isnan(temperature)) {
    Serial.print("\tTemp[K]=");
    Serial.print(temperature);
  }

  // Read the temperature in Rankine
  temperature = probe.readTempR();
  if (!isnan(temperature)) {
    Serial.print("\tTemp[R]=");
    Serial.println(temperature);
  }

  delay(750);
}