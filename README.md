<h1 align="center">Embedded Vault</h1>
<p align="center">A small vault programmed in Arduino. Uses a number pad and a locking mechanism to open/close a door.
Uses two instances of the vector data structure in order to keep track of the saved password inputted by the user when locking the door, 
as well as any attempts when trying to unlock the door.</p>

## :wrench: Physical Implementation

&emsp; Pictures of the vault's physical implementation can be seen below. The door uses a servo motor which turns a gear, moving a gear box below it. This gear box serves as a lock, keeping the door from moving after the lock is instantiated. The gearbox rotates on a horizontal axis, which I used a Chicago screw for it to rotate upon. On the front, a keypad for user entry can be seen, as well as an LED that flashes after keypad entries.

## :old_key: Usage

&emsp; The keypad follows an algorithm using two separate vector data structures to keep track of both the stored password and the user's current inputted password attempt. Upon program execution, a password may be stored into the vault by pressing the pound (#) key. After this, the user may enter their desired password (of length 5 or less) into the keypad. Once the password is finished being entered, the pound key may be pressed again to signal password storage termination. This will trigger the servo closing mechanism, locking the vault from being opened.
&emsp; The password may now be entered in the same fashion of storage by pressing the pound key to begin and end password attempts. If a wrong attempt is entered, the LED will flash five times in quick session to signal that the attempt was wrong. If the password entered was correct, the servo will open the lock and the LED will stay flashing until it finishes.

## :building_construction: Assembly Visuals

The front and back of the door may be seen below:

<p align="center">
  <img width="460" height="400" src="https://i.imgur.com/3MapPml.jpg">
</p>

<p align="center">
  <img width="460" height="400" src="https://i.imgur.com/Yh9mOBx.jpg">
</p>

As well as the encasement, which uses a pole to keep the hinge intact:

<p align="center">
  <img width="460" height="400" src="https://i.imgur.com/iRj9F1z.jpg">
</p>

And here's the entire assembly:

<p align="center">
  <img width="460" height="400" src="https://i.imgur.com/dSCXjau.jpg">
</p>
