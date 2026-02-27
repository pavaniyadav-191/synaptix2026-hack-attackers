# Health Monitoring Program in Python

def predict_risk(hr, spo2):
    if hr > 90 and spo2 < 95:
        return "High"
    elif hr > 80 and spo2 < 97:
        return "Moderate"
    else:
        return "Low"

def main():
    print("=== Health Monitoring Program ===")
    try:
        hr = int(input("Enter your Heart Rate (bpm): "))
        spo2 = int(input("Enter your Oxygen Level (%): "))
    except ValueError:
        print("Invalid input! Please enter numbers only.")
        return

    risk = predict_risk(hr, spo2)
    print(f"\nHeart Rate: {hr} bpm")
    print(f"Oxygen Level: {spo2} %")
    print(f"Risk Prediction: {risk}")

if __name__ == "__main__":
    main()