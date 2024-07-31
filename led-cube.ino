#include <Adafruit_MCP23X08.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MCP23XXX.h>

Adafruit_MCP23X17 mcp;
bool noMCP = false; // Declare the variable "noMCP" and initialize it to false

const int ledPins[] = {A0, A1, A2, A3}; // Array to hold LED pin numbers
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

//  the setup function runs once when you press reset or power the board
void setup()
{
    Serial.begin(9600);

    // initialize digital pin 13 as an output.
    pinMode(13, OUTPUT);
    for (int i = 0; i < numLeds; i++) {
      pinMode(ledPins[i], OUTPUT);
    }


    // uncomment appropriate mcp.begin
    // if (!mcp.begin_I2C())
    // {
    //     Serial.println("Error.");
    //     noMCP = true;
    // }

    // mcp.pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{

    if (!noMCP)
    {
        Serial.println("Hello, world!");

        digitalWrite(13, HIGH); // turn the LED on (HIGH is the voltage level)
        for (int i = 0; i < numLeds; i++) {
          digitalWrite(ledPins[i], HIGH);
          delay(500);
        }

        delay(1000); // wait for a second

        digitalWrite(13, LOW); // turn the LED off by making the voltage LOW

        for (int i = 0; i < numLeds; i++) {
          digitalWrite(ledPins[i], LOW);
          delay(500);
        }

        delay(1000); // wait for a second
    }
    else
    {
        Serial.println("No MCP.");
        delay(1000);
    }
}