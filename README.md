# pulsar-classification
Binary Classification of Cosmic Radio Signals: Pulsar Star Identification via Decision Trees (Edge AI Approach)

![Python](https://img.shields.io/badge/Python-3.8%2B-blue)
![Machine Learning](https://img.shields.io/badge/Machine_Learning-Decision_Trees-orange)
![Domain](https://img.shields.io/badge/Domain-Astrophysics_%26_Edge_AI-black)

![Graphical simulation of the lighthouse effect in pulsar radiation emission](./assets/pulsar.gif)

## 🌌 Overview & Business Value
Modern radio telescopes and deep-space receivers capture terabytes of data per second. The vast majority of these signals consist of cosmic background noise or human-made Radio Frequency Interference (RFI). 

This project aims to develop a lightweight Machine Learning model capable of autonomously distinguishing genuine **Pulsar Stars** from background noise. 
Designed with an **Edge AI** philosophy, this algorithm is specifically engineered to be translated into low-level code (C/C++) and deployed on embedded microcontrollers onboard satellites. By classifying and filtering out noise directly in orbit, we can drastically reduce downlink bandwidth requirements, lowering operational costs and optimizing deep-space communication pipelines.

## 📓 Notebook Structure
The project workflow is documented in a rigorous, step-by-step Jupyter Notebook:

* **Setup and Library Imports**
* **Phase 1: Data Selection**
  * 1.1 Loading the Dataset
  * 1.2 Dataset Overview
  * Phase 1: Summary & Insights
* **Phase 2: Data Preprocessing**
  * 2.1 Missing Values Check
  * 2.2 Duplicate Check and Removal
  * 2.3 Outlier Detection
  * 2.4 Correlation Matrix
  * Phase 2: Summary & Insights
* **Phase 3: Data Transformation**
  * 3.1 Separating Features and Target Variable
  * 3.2 Dataset Split
  * 3.3 Feature Selection
  * 3.4 Discretization (Binning)
  * Phase 3: Summary & Insights
* **Phase 4: Data Mining**
  * 4.1 Classification - Supervised Algorithm (Decision Tree)
  * 4.2 Classification - Supervised Algorithm (Decision Tree) [Simplified View]
  * Phase 4: Summary & Insights
* **Phase 5: Interpretation and Evaluation**
  * 5.1 Model Evaluation
  * 5.2 Confusion Matrix
  * 5.3 Cross Validation
  * Phase 5: Summary & Insights
* **Deployment - Model Exportation & Example of Use**

## 📊 The Dataset & Feature Selection
The model is trained on the **HTRU_2 Dataset** (High Time Resolution Universe Survey). Initially, it contains 17,898 instances of radio signals summarized by 8 continuous statistical features. 

To meet stringent Edge AI memory constraints, **ANOVA** and Correlation analysis were used to reduce the dimensionality. Only the **4 most informative features** were retained for the final firmware:
1. `Mean_Profile`
2. `Kurtosis_Profile`
3. `Skewness_Profile`
4. `STD_Curve`

* **Target Variable:** Strictly mapped to binary integers (`0` = Noise/RFI, `1` = Real Pulsar) to optimize memory allocation and ensure native metric calculation.

## 🎯 Task, Model & Engineering Approach
* **Paradigm:** Supervised Learning
* **Task:** Binary Classification
* **Core Model:** Decision Tree Classifier (Information Theory Approach)

A **Decision Tree** was explicitly chosen over complex black-box algorithms (like Neural Networks or SVMs) for two strict engineering constraints:
1. **Extremely Low Computational Cost:** Perfect for hardware with limited power budgets.
2. **Total Interpretability (White-Box):** The tree's splits, calculated via *Shannon Entropy* and *Information Gain*, allow us to extract explicit physical rules and directly write `IF/ELSE` firmware.

## ⚙️ Methodology & Architecture
The project is structured into a highly optimized pipeline:

1. **Data Discretization (Binning):** Continuous features were converted into discrete ordinal intervals (Low, Medium, High) using a `KBinsDiscretizer`. This simplifies the decision tree boundaries, allowing for flawless hardware translation.
2. **Class Imbalance Strategy:** Real pulsars make up only ~9% of the dataset. Therefore, standard *Accuracy* is considered a mathematically flawed metric. The evaluation heavily prioritizes **Recall** for the Pulsar class to minimize False Negatives (missing a real scientific discovery).
3. **Leakage-Free Validation:** To ensure absolute structural robustness, a 5-Fold Cross-Validation was performed using a Scikit-Learn `Pipeline`. By recalculating discretization thresholds dynamically within each isolated fold, data leakage was completely prevented.
4. **Hardware Deployment:** The final phase seamlessly exports the trained pipeline (`.joblib`) and automatically generates the exact threshold values (*Bin Edges*) required to write the target C/C++ software.

## 🏆 Key Findings
The final benchmark yielded a highly successful result: the single, lightweight Decision Tree achieved a remarkable **Pulsar Recall of ~86%** and an F1-Score of 0.80, successfully matching the sensitivity of a mathematically heavier **Random Forest** algorithm. 

Due to the extreme class imbalance, the single, un-ensembled tree proved to be a highly aggressive and capable classifier for hunting the minority class, proving that "bigger" is not always better in specialized tasks. By isolating the precise physical signature of a pulsar and transforming it into a strict sequence of logic gates, this model effectively balances computational efficiency with maximum scientific discovery potential.