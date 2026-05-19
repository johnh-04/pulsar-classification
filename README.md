# pulsar-classification
Binary Classification of Cosmic Radio Signals: Pulsar Star Identification via Decision Trees

![Python](https://img.shields.io/badge/Python-3.8%2B-blue)
![Machine Learning](https://img.shields.io/badge/Machine_Learning-Decision_Trees-orange)
![Domain](https://img.shields.io/badge/Domain-Astrophysics_%26_SatCom-black)

## 🌌 Overview
Modern radio telescopes and deep-space receivers capture terabytes of data per second. The vast majority of these signals consist of cosmic background noise or human-made Radio Frequency Interference (RFI). 

This project aims to develop a lightweight Machine Learning model capable of distinguishing genuine **Pulsar** signals from background noise.
In a real-world scenario (such as a New Space Economy startup), this type of algorithm is designed to be deployed on embedded systems (Edge AI) onboard satellites or remote telescopes.
By classifying and filtering signals directly at the edge, we can drastically reduce the required downlink bandwidth and optimize communication pipelines.

## 📊 The Dataset
The **HTRU2 Dataset** (High Time Resolution Universe Survey) was chosen for this project.
The dataset contains instances of radio signals summarized by 8 statistical features extracted from two main observations:
1. **Integrated Pulse Profile:** The shape of the radio pulse.
2. **DM-SNR Curve:** The Dispersion Measure and Signal-to-Noise Ratio curve, showing how the signal dispersed while traveling through space.

For both observations, the extracted features are: *Mean, Standard Deviation, Kurtosis, and Skewness*.
* **Target Variable:** `target_class` (0 = Noise/RFI, 1 = Real Pulsar).

## 🎯 Objective & Task
* **Paradigm:** Supervised Learning
* **Task:** Binary Classification
* **Model:** Decision Tree Classifier

The Decision Tree was specifically chosen for its **interpretability** (White-Box model).
It allows us to extract explicit physical rules (e.g., "If the Kurtosis of the integrated profile is > X, then it is a Pulsar") and understand the physical properties that distinguish these celestial bodies.

## ⚙️ Methodology & Challenges
This project tackles several real-world data science challenges:
1. **Class Imbalance:** Pulsars are extremely rare. The dataset has a roughly 10:1 ratio of negative to positive classes.
2. **Custom Evaluation Metrics:** Because of the class imbalance, standard *Accuracy* is misleading. The model is evaluated using a **Confusion Matrix**, with a strong focus on maximizing **Recall** (minimizing False Negatives, to avoid discarding real scientific discoveries).
3. **Model Optimization:** Application of **Pruning** techniques to control the depth of the Decision Tree, preventing overfitting and keeping the model lightweight for potential embedded deployment.