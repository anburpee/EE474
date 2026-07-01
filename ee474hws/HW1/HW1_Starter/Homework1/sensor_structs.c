#include <stdio.h>
#include <string.h>
#include "hwlib.h"

// Step 1
// =================> TODO: Define a Sensor struct with int id, char label[10], float reading
struct Sensor {
    int id;
    char label[10];
    float reading;
}

void run_sensor_structs() {
    // Step 1 Continued
    // =================> TODO: Declare a Sensor instance and set its fields
    Sensor sensor0 = (Sensor)malloc(sizeof(Sensor));
    sensor0.id = 123;
    sensor0.label = "label1";
    sensor0.reading = 1.23;

    // =================> TODO: Print its values
    printf("sensor 0 - id=%d, label=%s, reading=%f\n", sensor0.id, sensor0.label, sensor0.reading);


    // Step 2
    // =================> TODO: Declare a Sensor pointer pointing to the struct from Step 1
    Sensor* sensor1 = (Sensor*)malloc(sizeof(Sensor*));
    *sensor1 = sensor0;

    // =================> TODO: Use the pointer to modify reading and print again
    sensor1->reading = 2.34;
    printf("sensor 1 - id=%d, label=%s, reading=%f\n", sensor1->id, sensor1->label, sensor1->reading);

    // Step 3
    // =================> TODO: Allocate memory for 3 Sensor structs
    Sensor* sensorArr = (Sensor*)malloc(3 * sizeof(Sensor));

    // =================> TODO: Fill in ids, labels (T0, T1, T2), and readings
    for (int i = 0; i < 3; i++) {
        snprintf(sensorArr[i].id, sizeof(sensorArr[0].id), "%d", i);
        snprintf(sensorArr[i].label, sizeof(sensorArr[0].label), "T%d", i);
        snprintf(sensorArr[i].reading, sizeof(sensorArr[0].reading), "%f", i + 0.67);
    }

    // =================> TODO: Print all sensor info using pointer
    for (int i = 0; i < 3; i++) {
        printf("sensor %d - id=%d, label=%s, reading=%f\n", i, sensor1->id, sensor1->label, sensor1->reading);
    }
    
    // =================> TODO: Free memory
    free(sensor0);
    free(sensor1);
    for (int i = 0; i < 3; i++) {
        free(sensorArr[i]);
    }
}
