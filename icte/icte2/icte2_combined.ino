// File name: icte2_combined.ino
// Authors: Aya Burpee, Brandon Tsai
// Date: 7/6/2026
// Description: This file contains code for both Part 1 and Part 2 of ICTE #2.


// Part 1: Blink and LED using delay() ------------------------------------------------
#include "driver/gpio.h"            // For GPIO driver-level macros
#include "soc/io_mux_reg.h"         // For configuring the MUX (multiplexer)
#include "soc/gpio_reg.h"           // For direct GPIO register access
#include "soc/gpio_periph.h"        // For GPIO pin definitions

// --- Constants --- //
#define GPIO_PIN 5    // GPIO pin connected to the LED

void setup() {
  // --- Set the pin function to GPIO using the appropriate macro --- //
  // Use a macro to select the GPIO function for GPIO_PIN
  PIN_FUNC_SELECT(IO_MUX_GPIO5_REG, FUNC_GPIO5_GPIO5);
  

  // --- Enable the GPIO pin as an output --- //
  // Use GPIO_ENABLE_REG and a bitwise OR operation
  *((volatile uint32_t *)GPIO_ENABLE_REG) |= (1 << GPIO_PIN);
}

void loop() {
  // --- Turn the LED ON --- //
  // Write 1 to set, don't need bitwise OR
  *((volatile uint32_t *)GPIO_OUT_W1TS_REG) = (1 << GPIO_PIN); 

  // Wait for 1 second
  delay(1000);

  // --- Turn the LED OFF --- //
  // Write 1 to clear, don't need bitwise AND
  *((volatile uint32_t *)GPIO_OUT_W1TC_REG) = (1 << GPIO_PIN); 

  // Wait again
  delay(1000);
}



// Part 2: Blink an LED using a timer -------------------------------------------------
// #include "driver/gpio.h"
// #include "soc/io_mux_reg.h"
// #include "soc/gpio_reg.h"
// #include "soc/gpio_periph.h"
// #include "soc/timer_group_reg.h"

// // Define GPIO pin number
// #define GPIO_PIN 5

// // Define toggle interval in timer ticks (e.g., 1 second)
// #define LED_TOGGLE_INTERVAL 1000000 // 1 million

// // chooses which timer to use
// #define WHICH_TIMER 0

// // Define TIMER_INCREMENT_MODE and TIMER_ENABLE macros
// #define TIMER_INCREMENT_MODE TIMG_T0_INCREASE
// #define TIMER_ENABLE TIMG_T0_EN

// void setup() {
//   // Set GPIO_PIN function to GPIO using MUX macro
//   PIN_FUNC_SELECT(GPIO_PIN_MUX_REG[GPIO_PIN], PIN_FUNC_GPIO); 

//   // Enable GPIO_PIN as output
//   *((volatile uint32_t *)GPIO_ENABLE_REG) |= (1 << GPIO_PIN);

//   // Configure timer
//   uint32_t timer_config = 0; 

//   // Optionally apply a clock divider
//   timer_config |= (40 << TIMG_T0_DIVIDER_S); // divide 40MHz by 40 to get 1MHz

//   // Set increment mode and enable timer
//   timer_config |= TIMER_INCREMENT_MODE;

//   // added to specify that we're using the 40MHz clock
//   timer_config |= TIMG_T0_USE_XTAL; // without this line, would use APB_CLOCK

//   // enable timer
//   timer_config |= TIMER_ENABLE;

//   // Write config to timer register
//   *((volatile uint32_t *)TIMG_T0CONFIG_REG(WHICH_TIMER)) = timer_config;

//   // Trigger a timer update to load settings
//   *((volatile uint32_t *)TIMG_T0UPDATE_REG(WHICH_TIMER)) = 1;
// }

// void loop() {
//   // Track last toggle time
//   static uint32_t last_toggle_time = 0;

//   // Read current timer value
//   uint32_t current_time = 0;
//   current_time = *((volatile uint32_t *)TIMG_T0LO_REG(WHICH_TIMER));

//   // Check if toggle interval has passed
//   if ((current_time - last_toggle_time) >= LED_TOGGLE_INTERVAL) {
//     // Read current GPIO output state
//     uint32_t gpio_out = 0;
//     gpio_out = *((volatile uint32_t *)GPIO_OUT_REG);

//     // Toggle GPIO_PIN using XOR
//     *((volatile uint32_t *)GPIO_OUT_REG) = gpio_out ^ (1 << GPIO_PIN);

//     // Update last_toggle_time
//     last_toggle_time = current_time;
//   }

//   // Refresh timer counter value
//   *((volatile uint32_t *)TIMG_T0UPDATE_REG(WHICH_TIMER)) = 1;
// }