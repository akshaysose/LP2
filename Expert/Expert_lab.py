# List of books in the library with attributes
books = [
    {"title": "Data Structures and Algorithms", "author": "Mark Allen Weiss", "genre": "Computer Science", "type": "Theoretical"},
    {"title": "Introduction to Artificial Intelligence", "author": "Wolfgang Ertel", "genre": "Artificial Intelligence", "type": "Theoretical"},
    {"title": "Machine Learning Yearning", "author": "Andrew Ng", "genre": "Machine Learning", "type": "Practical"},
    {"title": "Deep Learning", "author": "Ian Goodfellow", "genre": "Machine Learning", "type": "Theoretical"},
    {"title": "Clean Code", "author": "Robert C. Martin", "genre": "Software Engineering", "type": "Practical"},
    {"title": "Research Methodology", "author": "Ranjit Kumar", "genre": "Research", "type": "Theoretical"},
    {"title": "Python for Data Analysis", "author": "Wes McKinney", "genre": "Data Science", "type": "Practical"},
    {"title": "Operating Systems: Three Easy Pieces", "author": "Remzi H. Arpaci-Dusseau", "genre": "Computer Science", "type": "Theoretical"}
]

def recommend_books():
    print("\n--- Book Recommendation for Project Work ---")
    # Asking user for project details
    project_topic = input("Enter the project topic/area: ")
    preferred_genre = input("Enter your preferred genre (e.g., Machine Learning, Data Science, AI, etc.): ").lower()
    preferred_type = input("Do you prefer 'Theoretical' or 'Practical' books? ").lower()

    # Filter books based on user preferences
    recommended_books = []
    for book in books:
        if (preferred_genre in book["genre"].lower() and preferred_type in book["type"].lower()):
            recommended_books.append(book)

    # Display recommendations
    if recommended_books:
        print("\nRecommended Books for Your Project:")
        for book in recommended_books:
            print(f"\nTitle: {book['title']}\nAuthor: {book['author']}\nGenre: {book['genre']}\nType: {book['type']}")
    else:
        print("Sorry, no books found based on your preferences. Please try a different genre or type.")

def menu():
    while True:
        print("\n===== Expert System: Library Book Recommendation =====")
        print("1. Recommend Books for Project Work")
        print("2. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            recommend_books()
        elif choice == '2':
            print("Exiting system...")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

menu()
