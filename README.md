# Attiny85
Accessing Inputs, Outputs, EEPROM
LED Brightness Adjuster
- Tactile switch 1 for increasing LED brightness
- Tactile switch 2 for decreasing LED brightness
- Brighness levels will be having 5 steps
- In case of no changes in tactile switch for 3 Minutes, everything will goes to OFF state
- Returns to actual state in case of changes in tactile switch
- Preserves LED brightness state even when power goes OFF state
- When Power returns, it resumes in previous state with the help of internal EEPROM
