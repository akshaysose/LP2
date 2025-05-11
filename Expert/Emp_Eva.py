employees = []

def evaluate_employee():
    print("\n--- Add New Employee ---")
    name = input("Enter employee name: ")
    emp_id = input("Enter employee ID: ")
    
    print("Rate the following from 1 to 5:")
    punctuality = int(input("Punctuality: "))
    task_completion = int(input("Task Completion: "))
    teamwork = int(input("Teamwork: "))
    communication = int(input("Communication: "))
    innovation = int(input("Innovation: "))
    leadership = int(input("Leadership: "))

    avg_score = (punctuality + task_completion + teamwork + communication + innovation + leadership) / 6

    if avg_score >= 4.5:
        rating = "Outstanding"
    elif avg_score >= 4.0:
        rating = "Excellent"
    elif avg_score >= 3.0:
        rating = "Good"
    elif avg_score >= 2.0:
        rating = "Needs Improvement"
    else:
        rating = "Poor"

    employee = {
        "Name": name,
        "ID": emp_id,
        "Scores": {
            "Punctuality": punctuality,
            "Task Completion": task_completion,
            "Teamwork": teamwork,
            "Communication": communication,
            "Innovation": innovation,
            "Leadership": leadership
        },
        "Average Score": avg_score,
        "Rating": rating
    }

    employees.append(employee)
    print(f"\nEvaluation Completed for {name}. Rating: {rating}")

def view_all_employees():
    print("\n--- All Employee Evaluations ---")
    for emp in employees:
        print(f"\nName: {emp['Name']}, ID: {emp['ID']}")
        for k, v in emp["Scores"].items():
            print(f"  {k}: {v}")
        print(f"Average Score: {emp['Average Score']}")
        print(f"Rating: {emp['Rating']}")

def search_employee():
    print("\n--- Search Employee ---")
    key = input("Enter employee name or ID: ")
    found = False
    for emp in employees:
        if emp["Name"] == key or emp["ID"] == key:
            found = True
            print(f"\nName: {emp['Name']}, ID: {emp['ID']}")
            for k, v in emp["Scores"].items():
                print(f"  {k}: {v}")
            print(f"Average Score: {emp['Average Score']}")
            print(f"Rating: {emp['Rating']}")
            break
    if not found:
        print("Employee not found.")

def generate_report():
    print("\n--- Final Performance Report ---")
    total_employees = len(employees)
    if total_employees == 0:
        print("No employees evaluated yet.")
        return

    outstanding = sum(1 for e in employees if e["Rating"] == "Outstanding")
    excellent = sum(1 for e in employees if e["Rating"] == "Excellent")
    good = sum(1 for e in employees if e["Rating"] == "Good")
    needs_improvement = sum(1 for e in employees if e["Rating"] == "Needs Improvement")
    poor = sum(1 for e in employees if e["Rating"] == "Poor")

    print(f"Total Employees Evaluated: {total_employees}")
    print(f"Outstanding: {outstanding}")
    print(f"Excellent: {excellent}")
    print(f"Good: {good}")
    print(f"Needs Improvement: {needs_improvement}")
    print(f"Poor: {poor}")

def menu():
    while True:
        print("\n===== Expert System: Employee Performance Evaluation =====")
        print("1. Add Employee Evaluation")
        print("2. View All Evaluations")
        print("3. Search for an Employee")
        print("4. Generate Final Report")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            evaluate_employee()
        elif choice == '2':
            view_all_employees()
        elif choice == '3':
            search_employee()
        elif choice == '4':
            generate_report()
        elif choice == '5':
            print("Exiting system...")
            break
        else:
            print("Invalid choice.")

menu()
