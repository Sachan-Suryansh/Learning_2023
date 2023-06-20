#include <stdio.h>
#include <string.h>

struct SensorData {
    char sensorID[3];
    float temperature;
    int humidity;
    int lightIntensity;
};

void parseData(const char *data, struct SensorData *sensorData) {
    sscanf(data, "S%2[^-]-T:%f-H:%d-L:%d", sensorData->sensorID, &sensorData->temperature, &sensorData->humidity, &sensorData->lightIntensity);
}

void printSensorData(const struct SensorData *sensorData) {
    printf("Sensor Info:\n");
    printf("---------------------\n");
    printf("Sensor ID: %s\n", sensorData->sensorID);
    printf("Temperature: %.1f C\n", sensorData->temperature);
    printf("Humidity: %d\n", sensorData->humidity);
    printf("Light Intensity: %d%%\n", sensorData->lightIntensity);
    printf("---------------------\n");
}

int main() {
    const char *data = "S1-T:36.5-H:100-L:50";
    struct SensorData sensorData;

    parseData(data, &sensorData);
    printSensorData(&sensorData);

    return 0;
}
