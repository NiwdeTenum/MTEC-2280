import serial
ser = serial.Serial("/dev/cu.usbserial-A9007KV6",9600)
print(ser.name)
state = 0
while(True):
    if (state == 0):
    	message = input("start to begin")
    if (message == "start"):
        print(message)
        print("The game is about to begin, listen carefully to the notes")
        state = 1
    if (state == 1):
        print("these are sound a, b and c")
        message = "start" + "\n"
        message = message.encode()
        ser.write(message) 
        state = 2
    if (state == 2): 
        command = input("What is the third note?")
    if (command == "a"):  
    	message = "lose" + "\n"
    	message = message.encode()
    	ser.write(message)
    	break
    if (command == "b"):
    	message = "lose" + "\n"
    	message = message.encode()
    	ser.write(message) 
    	break  	
    if (command == "c"):
	    message = "win" + "\n"
	    message = message.encode()
	    ser.write(message)
	    break
ser.close()


#Start game

#if state = 0
#command = input("Type start to begin")
#if command = start
#send command to arduino
#ser.write command

#if state = 1
#print("these are sound A B or C")
#state =2

#if state = 2
#command = input("Choose sound C")
#if command = A
#if command = B
#send lose tone
#if command = C
# send win tone


