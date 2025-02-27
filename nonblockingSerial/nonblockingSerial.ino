#include "comms.h"

const long BAUD = 115200;
const uint8_t OK    = 0;
const uint8_t ERROR = 1;

// Prints a help message to the screen.
//
// Update this function if LINE_TERMINATOR changes.
void printHelp() {
  Serial.println(F("Available commands:"));
  Serial.println(F("  help\\n"));
  Serial.println(F(""));
  Serial.println(F("Note: commands must be terminated with a \\n character."));
}

///////////////////////////////////////////////////////////////////////////////////////
/// Main Program
///////////////////////////////////////////////////////////////////////////////////////
String input;
Message msg;

void setup() {
  Serial.begin(BAUD);
  messageInit(msg);

  Serial.println("Ready to read from the serial port!");
}

void loop() {
    if (readStringUntil(input, LINE_TERMINATOR, CHAR_LIMIT)) {
      parseMessage(input, msg);
      if (msg.isValid) {
        doAction(msg);
        Serial.print(String(OK) + LINE_TERMINATOR);
      } else {
        Serial.println(msg.errorMsg);
        Serial.print(String(ERROR) + LINE_TERMINATOR);
      }

      // Clear the input buffer to prepare for the next command.
      input = "";
    }
}

// Perform the action associated with the message.
void doAction(const Message& msg) {
  switch (msg.cmd) {
    case Command::help:
      printHelp();
      break;
    default:
      break;
  }
}