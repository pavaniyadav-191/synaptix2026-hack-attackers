#include <stdio.h>
#include <unistd.h> // For sleep()

// Function to compute subtle risk score
float compute_risk(int hr, float spo2, float temp) {
    float risk = 0.0;
    risk += (hr - 70) * 0.02;         // small HR deviation
    risk += (97 - spo2) * 0.5;        // small SpO2 drop
    risk += (temp - 36.8) * 0.7;      // temp drift
    return risk;
}

// Function to trigger alert
void trigger_alert(float risk) {
    printf("?? ALERT! Subtle Risk Detected! Risk Level: %.2f\n", risk);
}

int main() {
    float baseline = 0.2;   // Initial baseline risk
    int hr;
    float spo2, temp;
    char choice;

    printf("=== Real-Time Wearable Health Monitoring ===\n");

    do {
        // User inputs for simulated sensor readings
        printf("\nEnter Heart Rate (bpm): ");
        scanf("%d", &hr);

        printf("Enter SpO2 (%): ");
        scanf("%f", &spo2);

        printf("Enter Body Temperature (°C): ");
        scanf("%f", &temp);

        // Compute risk
        float risk = compute_risk(hr, spo2, temp);

        printf("Computed Risk: %.2f", risk);

        // Check if subtle risk exceeds baseline + margin
        if(risk > baseline + 0.15) {
            trigger_alert(risk);
        } else {
            printf(" ? No significant risk detected.\n");
        }

        // Update baseline slowly for adaptive monitoring
        baseline = 0.98 * baseline + 0.02 * risk;

        // Ask if user wants to continue
        printf("\nDo you want to enter next reading? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("\nMonitoring stopped. Stay healthy!\n");
    return 0;
}
