## **Cut stress of the jumper machine** 

<details>
  <summary>Cut stress</summary>
  
  In the need to provide a dimensioning of the stepper motors and allow us to justify our experimental choices. We have performed experiments on the forces related to stripping and cutting.
Our customer asks for a cutting angle of 45° to allow a better insertion of the jumpers in the breadboard. Nevertheless, we would like to see how the cutting force evolves as a function of the insertion angle. For this purpose we have realized the following experimental device:

![Experience](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Dessin%20sans%20titre%20(1).jpg)

It allows us to measure with a dynamometer the force in Newton applied to the wire at the moment of cutting. The insertion angle is adjusted by hand with a protractor and the wire is guided in a tube.  For each value of angle, 5 measurements of force are made and averaged.
We obtain the following results:

![Results](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Dessin%20sans%20titre%20(8).jpg)


We observe that the lowest value is 52,2 N corresponding to an angle of 90°, however this goes against the requirements which impose a bizot cut. So the most interesting value is 61 N corresponding to an angle of 50°. This verifies our observations made with the guide system which reduces the 45° angle by about 10°. We still need to discuss with the customer whether the cutting angle can be reduced.
For the stripping, we observed with a dynamometer that 4 cm sheath is stripped with a force of about 1 Newton. However, this depends on whether the sheath has been pre-cut. In case of bad stripping, the stepper motor can pull with the extruder up to 17N, but this is not enough. It is therefore assumed that the sheath will always be cut properly.

 
 </details>
