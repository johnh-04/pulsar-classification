#include <stdio.h>

// KBinsDiscretizer-like function to convert raw float values into discrete bins (0, 1, 2)
int discretize(float raw_value, float threshold_1, float threshold_2) {
    
    if (raw_value <= threshold_1) {
        return 0; // Low (Bin 0)
    } else if (raw_value <= threshold_2) {
        return 1; // Medium (Bin 1)
    } else {
        return 2; // High (Bin 2)
    }
    
}

// Returns 0 for RFI (Noise) and 1 for actual Pulsar
int classify_pulsar(float raw_mean_profile, float raw_kurt_profile, float raw_skew_profile, float raw_std_curve) {
    
    int mean_bin = discretize(raw_mean_profile, 106.4844, 123.0312);
    int kurt_bin = discretize(raw_kurt_profile, 0.0932, 0.3729);
    int skew_bin = discretize(raw_skew_profile, -0.0689, 0.5760);
    int stdc_bin = discretize(raw_std_curve, 15.5557, 23.3080);

    if (kurt_bin == 2 && stdc_bin == 2 && skew_bin == 2 && mean_bin == 0) {
        return 1; // It's a pulsar! Send data to Earth for further analysis
    }
    
    return 0; // It's just noise. Discard the data and wait for the next signal

}

int main() {

    // Example of a raw signal
    float sensor_mean_profile = 25.5;
    float sensor_kurtosis_profile = 5.2;
    float sensor_skewness_profile = 8.1;
    float sensor_std_curve = 85.5;
    
    int is_pulsar = classify_pulsar(
        sensor_mean_profile, 
        sensor_kurtosis_profile, 
        sensor_skewness_profile, 
        sensor_std_curve
    );
    
    if (is_pulsar == 1) {
        printf("Pulsar detected! Sending data to Earth for further analysis.\n");
    } else {
        printf("Cosmic background noise or interference. Data discarded.\n");
    }
    
    return 0;

}