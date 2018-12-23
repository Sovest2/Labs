import os
import math

#Функция очистки экрана от мусора
def cls():
    os.system('cls' if os.name=='nt' else 'clear')

#Алфавиты
lang = ["abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ","абвгдеёжзийклмнопрстуфхцчшщъыьэюя","АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"]

#Совершение сдвига
def doShift(char,shift):
    for alphabet in lang:
        oldpos = alphabet.find(char)
        if oldpos != -1:
            newPos = oldpos + shift
            if newPos >= len(alphabet):
                newPos-= len(alphabet) * (math.ceil(newPos/len(alphabet)))
                return alphabet[newPos]
            elif newPos < 0:
                while newPos < 0:
                    newPos= len(alphabet) + newPos
                return alphabet[newPos]
            else:
                return alphabet[newPos]
            break
    else:
        return char

#Ввод сообщения
def doAction(action):

    mod = 1 #Отвечает за метод(шифрование\расшифровка)
    message = input()
    cls()
    if(action):
        print("You have encrypted your message. Results:")
    else:
        print("You have decrypted your message. Results:")
        mod = -1

    for i in range(33): #Отвечает за общее кол-во сдвигов
        newMessage = str()
        for char in message: #Формировнаие нового сообщения
            newMessage+= str(doShift(char,i * mod))
        print("ROT{0}\t{1}".format(str(i),newMessage))

#Тело основной программы
isRunning = True
while isRunning:
    cls()
    motd = "|Hello. This is the cezar encryptor/decryptor based on python!|"
    print("_"*len(motd))
    print(motd)
    print("‾"*len(motd))
    print("What do you want?\ne - to encrypt message\nd - to decrypt your message\nq - to quit\nYour decision:")
    action = input()
    cls()

    #Выбор действия
    if action == 'e':
        print("Enter message to encrypt:")
        doAction(True)
    elif action == 'd':
        print("Enter message to decrypt")
        doAction(False)
    elif action == 'q':
        isRunning = False
        print("Goodbye!")
    else:
        print("You have made a mistake. Try again!")

    print("Press any button to proceed")
    input()
    cls()
