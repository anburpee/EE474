#include <stdio.h>
#include <string.h>
#include "hwlib.h"

// Step 1
// =================> TODO: Define a Sensor struct with int id, char label[10], float reading
typedef struct Sensor {
    int id;
    char label[10];
    float reading;
} Sensor;

void run_sensor_structs() {
    // Step 1 Continued
    // =================> TODO: Declare a Sensor instance and set its fields
    Sensor sensor0;
    sensor0.id = 123;
    strncpy(sensor0.label, "label0", 7); // sensor0.label = "label1"
    sensor0.reading = 1.23;

    // =================> TODO: Print its values
    printf("Sensor 0 - ID: %d, Label: %s, Reading: %f\n", sensor0.id, sensor0.label, sensor0.reading);


    // Step 2
    // =================> TODO: Declare a Sensor pointer pointing to the struct from Step 1
    Sensor* sensor1 = (Sensor*)malloc(sizeof(Sensor));
    *sensor1 = sensor0;

    // =================> TODO: Use the pointer to modify reading and print again
    sensor1->reading = 2.34;
    printf("Updated sensor 0 reading via pointer: %f\n", sensor0.reading);
    printf("Sensor 1 - ID: %d, Label: %s, Reading: %f\n", sensor1->id, sensor1->label, sensor1->reading);

    // Step 3
    // =================> TODO: Allocate memory for 3 Sensor structs
    Sensor* sensorArr = (Sensor*)malloc(3 * sizeof(Sensor));

    // =================> TODO: Fill in ids, labels (T0, T1, T2), and readings
    for (int i = 0; i < 3; i++) {
        sensorArr[i].id = 100 + i;
        snprintf(sensorArr[i].label, sizeof(sensorArr[0].label), "T%d", i);
        sensorArr[i].reading = (float)i + 0.67;
    }

    // =================> TODO: Print all sensor info using pointer
    printf("\nAllocated 3 sensors...\n");
    for (int i = 0; i < 3; i++) {
        printf("Sensor %d - ID: %d, Label: %s, Reading: %f\n", i, sensorArr[i].id, sensorArr[i].label, sensorArr[i].reading);
    }
    
    // =================> TODO: Free memory
    free(sensor1);
    free(sensorArr);
}
