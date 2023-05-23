import serial.tools.list_ports
import random
import time


ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portsList = []


for onePort in ports:
    portsList.append(str(onePort))
    print(str(onePort))

val = input("Select Port: COM")

for x in range(0,len(portsList)):
    if portsList[x].startswith("COM" + str(val)):
        portVar = "COM" + str(val)
        print(portVar)


serialInst.baudrate = 9600
serialInst.port = portVar
serialInst.open()

level = 1
x = 4
while True:
    my_list = []
    input_list = []
    counter=0
    print('Press RED button to start level ', level)
    
    data = serialInst.readline().decode().rstrip() 
    
    if data == '3':
        print("Level ",level," Started!")
        #serialInst.write(data.encode('utf-8'))

        for i in range(int(x)):
            value = random.randint(3, 7)   # Generate a random number between 8 and 12 (inclusive)
            my_list.append(value)  # Append the value to the list
            #print (value)
            data = str(value)
            serialInst.write(data.encode('utf-8'))
            time.sleep(2.5)
            z=1
        while counter < int(x):
            
            if z==1:
                print('Now Give Your Answer')
                z+=1
                
            data = serialInst.readline().decode().rstrip()
            listdata = int(data)
            input_list.append(listdata)
            counter += 1
        #print('my_list ',my_list)
        #print('input_list ', input_list)

        if my_list == input_list :
            x+=0.5
            level+=1
        else:
            print('Game Over!, You Failed level ',level)
            while True:
                pass

        if level == 21:
            print('GOOD JOB, you completed the game!')
            while True:
                pass
    else:
        continue
