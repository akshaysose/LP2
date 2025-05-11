# Facts about the system (sample data)
water_supply_status = {"Monday": "Off"}
electricity_status = {"Common_Passage": "Off"}
pump_status = {"Underground_Pump": "Faulty"}
water_tank_level = {"Low": True}
generator_status = {"Common_Passage_Lights": "Functional"}
electricity_supply_status = {"Power_Grid": "Off"}

# Function to check water supply issue
def check_water_supply(issue_day):
    if water_supply_status.get(issue_day) == "Off":
        if pump_status["Underground_Pump"] == "Faulty":
            return f"No water on {issue_day}: Pump is faulty."
        elif water_tank_level.get("Low"):
            return f"No water on {issue_day}: Low water levels in the tank."
        else:
            return f"No water on {issue_day}: Unknown reason."
    return "Water supply is functioning."

# Function to check light issue
def check_light_issue():
    if electricity_status["Common_Passage"] == "Off":
        if electricity_supply_status["Power_Grid"] == "Off":
            return "No lights in common passage: Power grid failure."
        elif generator_status["Common_Passage_Lights"] == "Faulty":
            return "No lights in common passage: Generator malfunction."
        else:
            return "No lights in common passage: Unknown reason."
    return "Lights are functioning in common passage."

# Expert System Main Function
def expert_system():
    while True:
        print("\n===== Society Maintenance Expert System =====")
        print("1. Check Water Supply Issue")
        print("2. Check Lights Issue in Common Passage")
        print("3. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            day = input("Enter the day to check water supply issue (e.g., Monday): ")
            print(check_water_supply(day))
        elif choice == '2':
            print(check_light_issue())
        elif choice == '3':
            print("Exiting system...")
            break
        else:
            print("Invalid choice. Please try again.")

# Run the expert system
expert_system()
