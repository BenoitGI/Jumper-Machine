## **User interface**

Creating a HMI was an important step to ensure the machine is usable. It allows the user to change the parameters of the machine without changing the code. Different menus were set up to change those values: for the number of jumpers to cut, for their length and for the positioning of the blade to strip the wire. Also two more menus were added: one to feed the wire once it’s in the extruder (avoiding a tedious task by hand) and the menu to start the program to make jumpers. A joystick can change menus vertically and change the values of the menus concerned horizontally, once entered with the button of this joystick. To see that information, a simple 16x2 screen was added for the precise information, and three LEDs were added: green when everything is functioning and it’s fine to manipulate the machine, orange when everything is functioning but one or both motors are functioning, and red when wire is missing.

 ### **1. Components**
<details>
  <summary>Descrition of the user interface</summary>
 
 ![Man machine interface](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/MMI%20organization.PNG)
 
 </details>
 
 ### **2. Algorithm and functionning**
<details>
  <summary>Click to see the guideline!</summary>
 
 ![Man machine interface guidelines](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Man-machine%20interface%20guidelines.png)
</details>

<details>
 <summary>How to set the stripping position</summary>
 </br>
 When you enter the “set denude” menu, you will be able to set the blade to the position of stripping, where it is just cutting the sheath.
 
 The first step will be to ensure a small part of the wire is stepping out of the machine (it will be cut of when you run the program, so you don’t need to much wire because it’s waste).
 
 Then once you enter the menu, you can move the cam with the joystick in one way, the way it will cut during the program (you can turn back of course but it will be blocked at its original position to avoid to turn in way to strip and another way to cut during the program). The more you push the joystick on its side, the more the cam turns, to get close faster but position it more precisely. The screen is showing the number of steps the wire moved from the origin.
 
 Once you get the blades closer to the wire, move them until they can’t move anymore unless the cut the core of the wire. If you found the stripping position, you can press the joystick. You will leave the menu; the cam will turn back to its origin and the screen will show the position of stripping (in number of steps).
 
 It’s recommended to run the program with only one jumper at the time of the desired length to check it’s working, and repeat it once or twice. If it’s not working, change the position of stripping (bigger from the previous position if not cutting enough the sheath, smaller than the previous position if cutting too much and biting into the core).
 
 If it’s working well, you can run the program with the desired number of jumpers.

</details>
