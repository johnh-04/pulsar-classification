#include <stdio.h>

// Mean_Profile Edges
#define MEAN_P_EDGE_1 106.4844f
#define MEAN_P_EDGE_2 123.0312f

// Kurtosis_Profile Edges
#define KURT_P_EDGE_1 0.0932f
#define KURT_P_EDGE_2 0.3729f

// Skewness_Profile Edges
#define SKEW_P_EDGE_1 -0.0689f
#define SKEW_P_EDGE_2 0.5760f

// STD_Curve Edges
#define STD_C_EDGE_1 15.5557f
#define STD_C_EDGE_2 23.3080f

int discretize(float raw_value, float threshold_1, float threshold_2) {
    if (raw_value <= threshold_1) {
        return 0;   // Low (Bin 0)
    } else if (raw_value <= threshold_2) {
        return 1;   // Medium (Bin 1)
    } else {
        return 2;   // High (Bin 2)
    }
}

int classify_pulsar(float raw_mean_profile, float raw_kurt_profile, float raw_skew_profile, float raw_std_curve) {
    
    int mean_bin = discretize(raw_mean_profile, MEAN_P_EDGE_1, MEAN_P_EDGE_2);
    int kurt_bin = discretize(raw_kurt_profile, KURT_P_EDGE_1, KURT_P_EDGE_2);
    int skew_bin = discretize(raw_skew_profile, SKEW_P_EDGE_1, SKEW_P_EDGE_2);
    int stdc_bin = discretize(raw_std_curve, STD_C_EDGE_1, STD_C_EDGE_2);

    if (kurt_bin == 2 && stdc_bin == 2 && skew_bin == 2 && mean_bin == 0) {
        return 1; // It's a pulsar! Send data to Earth for further analysis
    }
    
    return 0; // It's just noise. Discard the data
}

int main() {

    float sensor_mean_profile = 25.5f;
    float sensor_kurtosis_profile = 5.2f;
    float sensor_skewness_profile = 8.1f;
    float sensor_std_curve = 85.5f;
    
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