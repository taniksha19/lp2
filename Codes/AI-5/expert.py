# Define the knowledge base
knowledge_base = {
    'fever': {
        'headache': 'Flu',
        'cough': 'Common Cold'
    },
    'cough': {
        'shortness of breath': 'Pneumonia',
        'chest pain': 'Bronchitis'
    },
    'headache': {
        'stiff neck': 'Meningitis',
        'blurred vision': 'Migraine'
    },
    'fatigue': {
        'body aches': 'Influenza',
        'joint pain': 'Arthritis'
    },
    'abdominal pain': {
        'nausea': 'Appendicitis',
        'bloating': 'Irritable Bowel Syndrome'
    },
    # Add more symptoms and associated diseases
}

# Define the inference engine
def diagnose_symptoms(symptoms):
    for symptom, associated_symptoms in knowledge_base.items():
        if symptom in symptoms:
            for associated_symptom, condition in associated_symptoms.items():
                if associated_symptom in symptoms:
                    return condition
    return "Unknown"

# Chatbot loop
print("Chatbot: Hello! I am a medical chatbot. Please describe your symptoms one by one, or enter 'exit' to quit.")

user_symptoms = []
while True:
    symptom = input("You: ").strip().lower()

    if symptom == 'exit':
        print("Chatbot: Goodbye!")
        break

    user_symptoms.append(symptom)

    diagnosis = diagnose_symptoms(user_symptoms)
    print("Chatbot: Based on your symptoms, the possible diagnosis is:", diagnosis)
    print()
