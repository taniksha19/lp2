query = {
    "greetings" : ["hi", "hello", "hey", "greetings"],
    "complaint" : ["complaint", "problem", "help", "support", "assistance"],
    "farewell": ["bye", "goodbye", "adios"],
    "info": ["know more", "tell me", "what is"]
}

response = {
    "greetings": "Hi there how are you?",
    "complaint": "We will connect you to customer support shortly",
    "farewell": "Hope you like our service, bye!",
    "info": "You can visit you website, golain.io for more info",
    "default": "Sorry, I didn't understand that. Can you rephrase your query?"
}

def bot(inputT):
    inputT = inputT.lower()
    
    for key, vals in query.items():
        for val in vals:
            if val in inputT:
                return response[key]
    return response["default"]

while True:

    inp = input("User: ")
    botR = bot(inp)

    print("Bot: ", botR)

    if "bye" in botR:
        break
