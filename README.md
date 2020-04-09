# VC

A Vacuum Cleaner project using pic.

## Requirments:

* Has 3 speeds.
* 2 switches to increase or decrease the speed.
* A led to indicate that the bag is filled then reduce speed to protect motor.
* A triac need to be fired every 10 ms With a certian angle to get the desired Motor Speed.


## Design:

### Timer:
- For the os used timer0 in pic MC. with prescaler 256 to get INTERUPPT every 10 ms.
- For the firing part, used Timer1 in pic with prescaler 2.
2 to more accurate time, because with prescaler 2 our tick equals 1 Microsecond. and firing happens starting from 275 Microseconds.
- Timer0 Starts Timer1 with the time for firing angle. (Timer1 still not working here)

### Firing:

<br>In firing we have 3 cases, Soft Switching up, Soft switching down and Harmonic reduce.
(Recommended to read     to undersand the firing better.)

Harmonic reduce Output:

![TRIAC OUTPUT](https://drive.google.com/file/d/1UXj-5GuXd0rehH1beHdQ25US4NIyCQrA/view?usp=sharing)
<br />

### LEDD:
<br>Using switch 3 to simulate the bag is filled, if pressed more than 30 seconds:
- DLed is on.
- Speed--

if the speed now is Low and D led is still on we are in NO_MORE case which prevent any increase in speed and switch + won't respond.

<br />
