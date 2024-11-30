#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the WeatherForecast structure
typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;

// Define the Crop structure
typedef struct {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    WeatherForecast *weatherForecast;
} Crop;

// Define the Equipment structure
typedef struct {
    char equipmentType[50];
    char operationalStatus[50];
    float fuelLevel;
    char activitySchedule[100];
} Equipment;

// Define the Sensor structure
typedef struct {
    float soilNutrients;
    float pHLevel;
    float pestActivity;
} Sensor;

// Define the Field structure
typedef struct {
    float gpsCoordinates[2];
    float soilHealthMetrics;
    float moistureLevels;
    Crop *crops;
    int cropCount;
    Equipment *equipment;
    int equipmentCount;
    Sensor *sensors;
    int sensorCount;
} Field;

// Define the RegionalHub structure
typedef struct {
    Field *fields;
    int fieldCount;
    float yieldPrediction;
    float resourceDistribution;
    char emergencyResponsePlan[200];
} RegionalHub;

// Define the CentralAnalyticsServer structure
typedef struct {
    RegionalHub *regionalHubs;
    int regionalHubCount;
} CentralAnalyticsServer;

int main() {
    //creating and initializing structures
    CentralAnalyticsServer server;
    
    server.regionalHubCount = 1; // i have currently set to 1
    server.regionalHubs = (RegionalHub *)malloc(server.regionalHubCount * sizeof(RegionalHub));

    server.regionalHubs[0].fieldCount = 1;
    server.regionalHubs[0].fields = (Field *)malloc(server.regionalHubs[0].fieldCount * sizeof(Field));

    server.regionalHubs[0].fields[0].cropCount = 1;
    server.regionalHubs[0].fields[0].crops = (Crop *)malloc(server.regionalHubs[0].fields[0].cropCount * sizeof(Crop));

    server.regionalHubs[0].fields[0].crops[0].weatherForecast = (WeatherForecast *)malloc(sizeof(WeatherForecast));

    // Initialize values
    server.regionalHubs[0].fields[0].crops[0].weatherForecast->temperature = 25.5;
    server.regionalHubs[0].fields[0].crops[0].weatherForecast->rainfall = 12.3;
    server.regionalHubs[0].fields[0].crops[0].weatherForecast->windSpeed = 5.4;

    // Initialize values for Crop
    strcpy(server.regionalHubs[0].fields[0].crops[0].cropType, "Wheat");
    strcpy(server.regionalHubs[0].fields[0].crops[0].growthStage, "Flowering");
    server.regionalHubs[0].fields[0].crops[0].expectedYield = 1500.0;

    // Initialize values for Equipment
    server.regionalHubs[0].fields[0].equipmentCount = 1;
    server.regionalHubs[0].fields[0].equipment = (Equipment *)malloc(server.regionalHubs[0].fields[0].equipmentCount * sizeof(Equipment));
    strcpy(server.regionalHubs[0].fields[0].equipment[0].equipmentType, "Tractor");
    strcpy(server.regionalHubs[0].fields[0].equipment[0].operationalStatus, "Operational");
    server.regionalHubs[0].fields[0].equipment[0].fuelLevel = 75.5;
    strcpy(server.regionalHubs[0].fields[0].equipment[0].activitySchedule, "Plowing on Monday");

    // Initialize values for Sensor
    server.regionalHubs[0].fields[0].sensorCount = 1;
    server.regionalHubs[0].fields[0].sensors = (Sensor *)malloc(server.regionalHubs[0].fields[0].sensorCount * sizeof(Sensor));
    server.regionalHubs[0].fields[0].sensors[0].soilNutrients = 7.8;
    server.regionalHubs[0].fields[0].sensors[0].pHLevel = 6.5;
    server.regionalHubs[0].fields[0].sensors[0].pestActivity = 2.3;

    // Initialize values for Field
    server.regionalHubs[0].fields[0].gpsCoordinates[0] = 40.7128;
    server.regionalHubs[0].fields[0].gpsCoordinates[1] = -74.0060;
    server.regionalHubs[0].fields[0].soilHealthMetrics = 8.5;
    server.regionalHubs[0].fields[0].moistureLevels = 20.0;

    // Initialize values for RegionalHub
    server.regionalHubs[0].yieldPrediction = 2000.0;
    server.regionalHubs[0].resourceDistribution = 500.0;
    strcpy(server.regionalHubs[0].emergencyResponsePlan, "Evacuate immediately in case of flood");

    // Print values to verify
    printf("Temperature: %.2f\n", server.regionalHubs[0].fields[0].crops[0].weatherForecast->temperature);
    printf("Rainfall: %.2f\n", server.regionalHubs[0].fields[0].crops[0].weatherForecast->rainfall);
    printf("Wind Speed: %.2f\n", server.regionalHubs[0].fields[0].crops[0].weatherForecast->windSpeed);

    printf("Crop Type: %s\n", server.regionalHubs[0].fields[0].crops[0].cropType);
    printf("Growth Stage: %s\n", server.regionalHubs[0].fields[0].crops[0].growthStage);
    printf("Expected Yield: %.2f\n", server.regionalHubs[0].fields[0].crops[0].expectedYield);

    printf("Equipment Type: %s\n", server.regionalHubs[0].fields[0].equipment[0].equipmentType);
    printf("Operational Status: %s\n", server.regionalHubs[0].fields[0].equipment[0].operationalStatus);
    printf("Fuel Level: %.2f\n", server.regionalHubs[0].fields[0].equipment[0].fuelLevel);
    printf("Activity Schedule: %s\n", server.regionalHubs[0].fields[0].equipment[0].activitySchedule);

    printf("Soil Nutrients: %.2f\n", server.regionalHubs[0].fields[0].sensors[0].soilNutrients);
    printf("pH Level: %.2f\n", server.regionalHubs[0].fields[0].sensors[0].pHLevel);
    printf("Pest Activity: %.2f\n", server.regionalHubs[0].fields[0].sensors[0].pestActivity);

    printf("GPS Coordinates: [%.4f, %.4f]\n", server.regionalHubs[0].fields[0].gpsCoordinates[0], server.regionalHubs[0].fields[0].gpsCoordinates[1]);
    printf("Soil Health Metrics: %.2f\n", server.regionalHubs[0].fields[0].soilHealthMetrics);
    printf("Moisture Levels: %.2f\n", server.regionalHubs[0].fields[0].moistureLevels);

    printf("Yield Prediction: %.2f\n", server.regionalHubs[0].yieldPrediction);
    printf("Resource Distribution: %.2f\n", server.regionalHubs[0].resourceDistribution);
    printf("Emergency Response Plan: %s\n", server.regionalHubs[0].emergencyResponsePlan);

    free(server.regionalHubs[0].fields[0].sensors);
    free(server.regionalHubs[0].fields[0].equipment);
    free(server.regionalHubs[0].fields[0].crops[0].weatherForecast);
    free(server.regionalHubs[0].fields[0].crops);
    free(server.regionalHubs[0].fields);
    free(server.regionalHubs);

    return 0;
}