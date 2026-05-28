word=input()
new_word=""
for i in range(len(word)):
    idx=int(input())
    new_word=word[idx]+new_word
print(new_word)
