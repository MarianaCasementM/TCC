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
.txt file
Randomly bilingual coments, mostly in English.

"""

import serial
import time
import numpy as np
from scipy.fft import fft, fftfreq

#%%
#setup

#[POR] SEMPRE LEMBRAR DE VERIFICAR SE A PORTA SERIAL TA FECHADA, 
#SE NÃO, FECHAR COM ser.close()
#[ENG] ALWAYS REMEMBER TO CHECK IF THE SERIAL PORT IS CLOSED, IF
#NOT, CLOSE IT WITH ser.close()

port = "COM3" #serial port of Arduino: have to check name on Ard. console
baud = 115200 #Check what baud rate it´s running at
n = 4680 #[POR] quantas medidas queremos ler #[ENG] how many measurements we want to read

#(46080 passos no motor ou 4 voltas no micrômetro) estou escrevendo mais aqui 
#(deveria ser 4608) caso a gente 
#queira desconsiderar alguns dados no inicio ou final da medida. Por 
#exemplo, se houver algum movimento irregular ou contato com o equipamento,
# podemos tirar os primeiros dados.

ser = serial.Serial(port, baud) #Connection to serial port

if not ser.isOpen():
    ser.open()
print('com3 is open', ser.isOpen())

#%%
#read data and save to an array

l = 0 #how many lines we have read from serial
a = np.array([])

start = time.time()

while l < n:
    incoming = ser.readline() #reads data
    data = float(incoming)
    print(data)
    
    if len(incoming) > 0: #if there is data on the line
        a = np.append(a, data)      
        l += 1

#%%
#save data

finish = time.time() - start
print("time:", finish, "s") #how long it took for us to receive and record all data asked for
np.savetxt('amplitudes4680.txt', a)
print("Data collection complete!")

ser.close()

#%%
#scale data and take fft

b = np.zeros([n,2])
stp_p_dado = 80 #[POR] quantos steps foram andados entre cada medição #[ENG] how many steps motor moved between each acquisition
stp_p_vol_mm = 737280 #[POR] quantos steps devem ser andados para termos uma volta no micrômetro #[ENG] how many steps correspond to a whole turn of the micrometer
anda_feixe_vol_mm = 2e-04 #[POR] quantos metros são "andados" pelo feixe em uma volta do micrômetro #[ENG] how many meters the light "runs" along a turn of the micrometer

#[POR] fatores de escala #[ENG] scale adjustments
no_feixe = (stp_p_dado*anda_feixe_vol_mm)/stp_p_vol_mm #scale of each piece of data
scale_vol = 5./1023. #scale of signal from fotodiode (Arduino converts voltage of 0-5V to 0-1023)

for i in range(n): #save data in the correct dimensions to an array
    b[i,0] = i*no_feixe
    b[i,1] = scale_vol*a[i]
    
c = fftfreq(n,no_feixe) #[POR] eixo x da fft #[ENG] fft x-axis
f = abs(fft(b[:,1])) #fft y-axis
d = np.zeros([n,2])

for i in range(n): #save fft of scaled data to an array
    d[i,0] = c[i]
    d[i,1] = f[i]
    
#%%
#plot data (to check)

plt.plot(b[:,0],b[:,1]) #plot scaled data
#plt.xlim(0,1e-04) #only part of it, for better visualization

plt.plot(c,f) #plot fft of data
#plt.xlim(0,1000) #[POR] uma parte dos dados p HeNe, p ver oscilações melhor #[ENG] same as above

w = np.absolute(fft(a)) #amplitude
plt.plot(fftshift(w)) #shift to have 0 peak at centre
plt.xlim(2140,2200) #main peak
plt.ylim(0,250000)

#real values of HeNe laser
#lambda = 632,8nm
#nu = 4,471 e14 Hz
    
#%%
#save data

np.savetxt('dados_dim_corr.txt',b,delimiter=' ') #file with scaled data
np.savetxt('fft_dados.txt', d, delimiter=' ') #file with fft of scaled data



