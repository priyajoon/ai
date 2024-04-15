import pandas as pd
from sklearn.metrics.pairwise import cosine_similarity
from sklearn.feature_extraction.text import CountVectorizer
with open('dialogs.txt','r') as chats:
    content = chats.readlines()
data = []
for line in content:
    line_data = line.strip().split('    ')
    data.append(line_data)
df = pd.DataFrame(data,columns = ['message','response'])
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(df['message'])
df_vectorized = pd.DataFrame(X.toarray(), columns=vectorizer.get_feature_names_out())
df_final = pd.concat([df, df_vectorized], axis=1)
df_message = df[['response']].copy()
df_vectorized = df_final.drop(columns=['message', 'response'])
while True:
    input_message = input("You: ")

    if input_message.lower() == 'exit':
        print("Bot: Goodbye!")
        break

    input_vector = vectorizer.transform([input_message])

    cosine_similarities = cosine_similarity(input_vector, df_vectorized)

    closest_index = cosine_similarities.argsort()[0][-1]

    response = df['response'][closest_index]

    print("Bot:", response)