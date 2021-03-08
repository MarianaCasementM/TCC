# -*- coding: utf-8 -*-
"""
Created on Fri Nov 13 14:19:17 2020

@author: Mariana Casement

Some of the code taken from: 
https://www.learnrobotics.org/blog/arduino-data-logger-csv/?utm_source=youtube&utm_medium=description&utm_campaign=arduino_CSV_data_logger
an article written by Liz Miller from Learn Robotics and accessed on
13/11/2020.
    "Excerpts and links may be used, provided that full and clear credit 
    is given to Learn Robotics and www.learnrobotics.org with appropriate 
    and specific direction to the original content."

Program for reading data on an Arduino UNO Serial port and saving it on a
.csv file

"""

import serial
#import sys
import time
import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft, ifft, fftshift, ifftshift

#%%


port = "COM3" #serial port of Arduino: have to check on Ard. console
baud = 115200 #Arduino UNO runs at 9600 baud
#fileName = "amplitude.csv" #name of the CSV file generated
n = 4680 #quantas medidas queremos ler (46080 passos no motor ou 4 voltas 
#no micrômetro) estou escrevendo mais aqui (deveria ser 4608) caso a gente 
#queira desconsiderar alguns dados no inicio ou final da medida. Por 
#exemplo, se houver algum movimento irregular ou contato com o equipamento,
# podemos tirar os primeiros dados.

#serial.Serial(port, baud).close()

ser = serial.Serial(port, baud) #Connection to serial port
#print("Connected to Arduino port:" + arduino_port)

#ser.close()

if not ser.isOpen():
    ser.open()
print('com3 is open', ser.isOpen())

#file = open(fileName, "w") #Create file. If want to append data: "a", if
#want to write a new one "w"
#print("Created file")

#%%

#reads the data (only one line of data)

#getData = str(ser.readline()) #converts what is read in serial to a 
#string, needs for two bits of data
#data = getData[0:][:-2] #if there are two columns (what happening?)

#data = ser.readline() #reads whole line of data at serial

#print(data) #prints at terminal

#add the data to the file
#file = open(fileName, "a") #append the data to the file
#file.write(data + "\\n") #write data with a newline

#file.close()#close out the file

#%%

print_labels = False
l = 0 #how many lines we are reading from serial
a = np.array([])

start = time.time()

while l <= n:
    incoming = ser.readline() #reads data
    #print(incoming)
    data = float(incoming)
    print(data)
    #ser.close()
    #time.sleep(1) #in secs
    #sys.exit()
    if len(incoming) > 0: #if there is data on the line
    
        if print_labels:
            if l == 0:
                print("Printing Column Headers")
            # else:
                # print("Line " + str(line) + ": writing...") #To print line
            
        # getData=str(ser.readline()) #for two pieces of data, reads whole line
        # data=getData[0:][:-2]
    
        a = np.append(a, data)
        
        l += 1

#%%

finish = time.time() - start
print("time:", finish, "s")
np.savetxt('amplitudes4680.txt', a)
print("Data collection complete!")

ser.close()

#%%

plt.plot(a)
plt.xlim(0,1000) #uma parte dos dados p HeNe, p ver oscilações melhor

w = np.absolute(fft(a)) #amplitude
plt.plot(fftshift(w)) #shift to have 0 peak at centre
plt.xlim(2140,2200) #parte bonitinha
plt.ylim(0,250000)


