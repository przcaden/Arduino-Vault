# Arduino-Vault
A small vault programmed in Arduino. Uses a number pad and a locking mechanism to open/close a door.
Uses two instances of the vector data structure in order to keep track of the saved password inputted by the user when locking the door, 
as well as any attempts when trying to unlock the door.

## Physical Implementation

Pictures of the vault's physical implementation can be seen below. The door uses a servo motor which turns a gear, moving a gear box below it. This gear box serves
as a lock, keeping the door from moving after the lock is instantiated. The gearbox rotates on an axis, which I used a Chicago screw for.
On the front, a keypad for user entry can be seen, as well as an LED that flashes after keypad entries.

The front and back of the door may be seen below:

![alt text](https://i.imgur.com/3MapPml.jpg)

![alt text](https://i.imgur.com/Yh9mOBx.jpg)

As well as the encasement:

![alt text](https://i.imgur.com/iRj9F1z.jpg)

And here's the entire assembly:

![alt text](https://i.imgur.com/dSCXjau.jpg)
