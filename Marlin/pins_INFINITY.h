/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Arduino Mega with INFINITY v1.0 pin assignments
 *
 * Applies to the following boards:
 *
 *  INFINITY_EFB (Hotend0, Fan0, Bed) (dual Z-axis driver)
 *  INFINITY_EEEEFB (Hotend0, Hotend1,  Hotend2,  Hotend3, Fan0, Bed) (dual Z-axis driver)
 *  INFINITY_EEEEEB (Hotend0, Hotend1,  Hotend2,  Hotend3, Hotend4, Bed)
 *  INFINITY_SF  (Spindle, Fan. SPINDLE_LASER_PWM_PIN) (dual X-axis driver, dual Y-axis driver, dual Z-axis driver,)
 *
 *  For fastIO.h DIO lib calls look at device specific API: arduino/avr/variants/mega/pins_arduino.h
 */

#if !defined(__AVR_ATmega2560__)
  #error "Oops!  Make sure you have 'Arduino Mega 2560' selected from the 'Tools -> Boards' menu."
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME "INFINITY 1.0"
#endif

#define LARGE_FLASH true



//
// Augmentation for auto-assigning INFINITY plugs
//

#if DISABLED(IS_INFINITY_EFB) && DISABLED(INFINITY_EEEEFB) && DISABLED(IS_INFINITY_EEEEEB) && DISABLED(IS_INFINITY_SF) 
#if ENABLED(SPINDLE_LASER_ENABLE) 
      #define IS_INFINITY_SF
#else
	#if (HOTENDS > 1) && (HOTENDS < 5)
		#define IS_INFINITY_EEEEFB 
	#elif HOTENDS > 4
		#define IS_INFINITY_EEEEEB 
	#else
		#define IS_INFINITY_EFB 
	#endif
#endif
#endif


//
// Servos
//
#define SERVO0_PIN       11
#define SERVO1_PIN          12
#define SERVO2_PIN          9
#define SERVO3_PIN        10

//
// Limit Switches
//
#define X_MIN_PIN           47
#define X_MAX_PIN         52
#define Y_MIN_PIN          40
#define Y_MAX_PIN          42
#define Z_MIN_PIN          36
#define Z_MAX_PIN          38


//
// Safety Switches
//
#ifndef SAFETY_TRIGGERED_PIN
	//Access door open: SW Door n/c (held high, short to GND to trigger)
	#define SAFETY_TRIGGERED_PIN 28
#endif 
#ifndef KILL_PIN
	//ESTOP n/c (held high, short to GND to trigger)
	#define KILL_PIN 27
#endif
#ifndef SUICIDE_PIN
	//ESTOP n/o (held high, short to GND to trigger)
	#define SUICIDE_PIN 26
#endif 


//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  48
#endif

//
// Steppers
//

//bring high to enable output logic (Pull High to enable outputs)
#define STEPPERS_RESET_PIN  46

#define X_STEP_PIN         62 
#define X_DIR_PIN             37
//not conected to logic
#define X_ENABLE_PIN    49
#define X_CS_PIN           49

#define Y_STEP_PIN         63
#define Y_DIR_PIN          39
//not conected to logic 
#define Y_ENABLE_PIN    49  
#define Y_CS_PIN           49

#define Z_STEP_PIN         64
#define Z_DIR_PIN        41
//not conected to logic   
#define Z_ENABLE_PIN      49
#define Z_CS_PIN           49

#if defined(INFINITY_EEEEEB) && !defined(IS_INFINITY_SF) 
	#define E4_STEP_PIN        65
	#define E4_DIR_PIN          43
	//not conected to logic
	#define E4_ENABLE_PIN     49
	#define E4_CS_PIN          49
else
	#define Z_DUAL_STEPPER_DRIVERS
	#define Z2_STEP_PIN         65
	#define Z2_DIR_PIN       43
	//not conected to logic   
	#define Z2_ENABLE_PIN     49  
	#define Z2_CS_PIN           49
#endif

#if defined(IS_INFINITY_SF) 
	#define X_DUAL_STEPPER_DRIVERS
	#define X2_STEP_PIN         69
	#define X2_DIR_PIN       43
	//not conected to logic   
	#define X2_ENABLE_PIN     49  
	#define X2_CS_PIN           49
else
	#define E3_STEP_PIN        69
	#define E3_DIR_PIN     53
	//not conected to logic    
	#define E3_ENABLE_PIN      49
	#define E3_CS_PIN          49
#endif

#if defined(IS_INFINITY_SF) 
	#define Y_DUAL_STEPPER_DRIVERS
	#define Y2_STEP_PIN         68
	#define Y2_DIR_PIN       43
	//not conected to logic   
	#define Y2_ENABLE_PIN     49  
	#define Y2_CS_PIN           49
else
	#define E2_STEP_PIN        68
	#define E2_DIR_PIN        51
	//not conected to logic    
	#define E2_ENABLE_PIN   49
	#define E2_CS_PIN          49
#endif

#define E1_STEP_PIN        67
#define E1_DIR_PIN           50
//not conected to logic   
#define E1_ENABLE_PIN   49
#define E1_CS_PIN          49

#define E0_STEP_PIN        66
#define E0_DIR_PIN          45
//not conected to logic     
#define E0_ENABLE_PIN  49
#define E0_CS_PIN          49



//
// Bus voltage Sensors  Vadc=(Vcc*(1000/220))/1024
//
#define HOST_5_VOLT_PIN         0   // Analog Input
#define HOST_12_VOLT_PIN       1   // Analog Input

//#ifndef MAIN_VOLTAGE_MEASURE_PIN
// #define MAIN_VOLTAGE_MEASURE_PIN  HOST_12_VOLT_PIN
//#endif


//
// Temperature Sensors
//
#define TEMP_0_PIN         6   // Analog Input
#define TEMP_1_PIN         5   // Analog Input
#define TEMP_2_PIN         4   // Analog Input
#define TEMP_3_PIN         3   // Analog Input
#define TEMP_4_PIN         2   // Analog Input aux
#define TEMP_BED_PIN     7   // Analog Input



//
// Heaters / Fans (all have PWM modes available)
//
#define MOSFET_E0_PIN		7
#define MOSFET_E1_PIN		6
#define MOSFET_E2_PIN		3
#define MOSFET_E3_PIN		2
#define MOSFET_AUX_PIN		5
#define MOSFET_BED_PIN		8


#if ENABLED(IS_INFINITY_EFB)                      // INFINITY_EFB (Hotend0, Fan0, Bed)
  #define HEATER_0_PIN   MOSFET_E0_PIN
  #define FAN_PIN        MOSFET_AUX_PIN 
  #define HEATER_BED_PIN MOSFET_BED_PIN 
  #ifndef EXTRUDERS
	#define EXTRUDERS 1
  #endif
  #ifndef HOTENDS 
	#define HOTENDS 1
  #endif

#elif ENABLED(IS_INFINITY_EEEEEB)                    //  INFINITY_EEEEEB (Hotend0, Hotend1,  Hotend2,  Hotend3, Hotend4, Bed)
  #define HEATER_0_PIN   MOSFET_E0_PIN
  #define HEATER_1_PIN   MOSFET_E1_PIN
  #define HEATER_2_PIN   MOSFET_E2_PIN
  #define HEATER_3_PIN   MOSFET_E3_PIN
  #define HEATER_4_PIN   MOSFET_E4_PIN
  #define HEATER_BED_PIN MOSFET_BED_PIN 
  #ifndef EXTRUDERS
	#define EXTRUDERS 5
  #endif
  #ifndef HOTENDS 
	#define HOTENDS 1
  #endif
  #ifndef MIXING_STEPPERS 
	#define MIXING_EXTRUDER 
	#define MIXING_STEPPERS 5
  #endif
  
#elif ENABLED(IS_INFINITY_EEEEFB)                      // INFINITY_EEEEFB (Hotend0, Hotend1,  Hotend2,  Hotend3, Fan0, Bed)
  #define HEATER_0_PIN   MOSFET_E0_PIN
  #define HEATER_1_PIN   MOSFET_E1_PIN
  #define HEATER_2_PIN   MOSFET_E2_PIN
  #define HEATER_3_PIN   MOSFET_E3_PIN
  #define FAN_PIN        MOSFET_AUX_PIN 
  #define HEATER_BED_PIN MOSFET_BED_PIN
  #ifndef EXTRUDERS
	#define EXTRUDERS 4
  #endif
  #ifndef HOTENDS 
	#define HOTENDS 1
  #endif
  #ifndef MIXING_STEPPERS 
	#define MIXING_EXTRUDER 
	#define MIXING_STEPPERS 4
  #endif
  

#elif ENABLED(IS_INFINITY_SF)                     // INFINITY_SF  (Spindle, Controller High-power Fan)
  #define HEATER_0_PIN   MOSFET_E0_PIN
  #define FAN_PIN        MOSFET_BED_PIN  
  #define SPINDLE_LASER_ENABLE			// enable LASER power (AUX PWM) and Spindle DIR/EN 5v logic
  #define EXTRUDERS 1
  #ifndef HOTENDS 
	#define HOTENDS 1
  #endif

#else                                       // Non-specific 
  #define HEATER_0_PIN   MOSFET_E0_PIN
  #define FAN_PIN        MOSFET_AUX_PIN 
  #define HEATER_BED_PIN MOSFET_BED_PIN
  #ifndef EXTRUDERS
	#define EXTRUDERS 1
  #endif
  #ifndef HOTENDS 
	#define HOTENDS 1
  #endif

#endif


#ifndef FAN_PIN
  #define FAN_PIN 4     // IO default to pwm4 pin
#endif


//
// M3/M4/M5 - Spindle/Laser Control
//
#if ENABLED(SPINDLE_LASER_ENABLE) && !PIN_EXISTS(SPINDLE_LASER_ENABLE) && ENABLED(IS_INFINITY_SF)  
    #define SPINDLE_LASER_ENABLE_PIN  35  // Pin should have a pullup/pulldown!
    #define SPINDLE_LASER_PWM_PIN  MOSFET_AUX_PIN  // MUST BE HARDWARE PWM
    #define SPINDLE_DIR_PIN           34  // Pin should have a pullup/pulldown!
#endif
 
 
 //
 // 5v I2C Bus
 //
#define  I2C_SCL_PIN 21
#define  I2C_SDA_PIN 20
 
 