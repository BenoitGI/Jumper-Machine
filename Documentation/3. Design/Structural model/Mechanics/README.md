### Technical work and calculations
## **Cut stress**
<details>
  <summary>Calculations</summary>
  
In the need to provide a dimensioning of the stepper motors and allow us to justify our experimental choices. We have performed experiments on the forces related to stripping and cutting.
Our customer asks for a cutting angle of 45° to allow a better insertion of the jumpers in the breadboard. Nevertheless, we would like to see how the cutting force evolves as a function of the insertion angle. For this purpose we have realized the following experimental device:

![Cut_stress_measures](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Stress_cut_calculation.PNG)

It allows us to measure with a dynamometer the force in Newton applied to the wire at the moment of cutting. The insertion angle is adjusted by hand with a protractor and the wire is guided in a tube.  For each value of angle, 5 measurements of force are made and averaged.
We obtain the following results:

![Cut_stress_results](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Stress_cut_results.PNG)

We observe that the lowest value is 52,2 N corresponding to an angle of 90°, however this goes against the requirements which impose a bizot cut. So the most interesting value is 61 N corresponding to an angle of 50°. This verifies our observations made with the guide system which reduces the 45° angle by about 10°. We still need to discuss with the customer whether the cutting angle can be reduced.
For the stripping, we observed with a dynamometer that 4 cm sheath is stripped with a force of about 1 Newton. However, this depends on whether the sheath has been pre-cut. In case of bad stripping, the stepper motor can pull with the extruder up to 17N, but this is not enough. It is therefore assumed that the sheath will always be cut properly.

  
</details>

## **Bending tests**
<details>
  <summary>Calculations</summary>
When testing the first revision of our bending system, we noticed we couldn’t validate requirement 4.1 - Bend the edges at the right angle. In order to compensate for the wire springback we designed a die with an undercut.

Objective of the test: determine which undercut angle is ideal to compensate for springback when bending jumpers.

Process: After having designed and printed a bending die with five different undercut angles, it is necessary to carry out five bending tests to determine the best angle. In order to determine whether the jumper obtained after bending is considered as "good", the same visual validation criteria defined in the requirements will be used. In addition, the jumper must fit correctly and easily into the breadboard.
  
![Bending large wire](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Angle_testing.PNG)
Bending parts for the largest jumper size (25.4)
  
Equipment: 
3D printed die with five different undercut angles
semiflex piece allowing to bend the jumpers’ edges  until the elastic return is compensated
holding plate to prevent the body of the jumpers from rising up during bending
u-shaped piece that rests on the ends of the semiflex piece to bend the jumpers' edges
ocular measuring device called eyes
breadboard


Test 1: we carried out five tests (angles: 8°, 6°, 4°, 2, 0°) and noted the quality of the jumpers according to the visual criterion and good fit in the breadboard. The scoring system is explained below:

“NO”: angle of the jumper’s edges doesn’t look good and the jumper doesn’t fit in the breadboard
“OK-”: angle of the jumper’s edges looks good and the jumper doesn’t fit in the breadboard without a slight adjustment
“OK”: angle of the jumper’s edges looks good and the jumper fits perfectly in the breadboard

The table with the results is attached to the appendix (1st test). We already knew that 0° was not at all the ideal angle, but we wanted to demonstrate that again, and we found that 8° was not suitable either. The 6° angle was visually better but did not fit in the breadboard. Finally, the 4° and 2° angles seemed to be the best angles.

Thanks to this test, it appeared that the ideal angle we are looking for is between 2° and 4°. It is for this reason that we decided to refine the angular range in order to carry out new tests.


Test 2: based on the same process and with a new 3D printed die, we carried out five more tests by refining the angular range (angles: 4°, 3.5°, 3°, 2.5, 2°). Criterions and scoring system remain the same.

The table with the results is bellow. All jumpers looked good and most of them were perfectly fitting into the breadboard. We decided to choose the 2.5° because we got the best jumpers with this angle.

![Jumper length](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Jumper_length.PNG)

Conclusion: The 0° angle is the worst angle because it is not possible to compensate for the elastic return and the angles above 6° should be avoided. Therefore, and thanks to the second test, it is highly recommended to choose an angle in the range 2° and 4° because they all allow you to get the best jumpers. For example, we have chosen a 2.5° angle based on the tests we did.
  
![Results1](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Bending%20tests.PNG)

</details>

## **Distribution of the wire**
<details>
  <summary>Calculations</summary>
 We have conducted tests on jumpers. We launched for each size of pin a dozen jumpers and we observed if the size, the straightness were validated and if the jumper does not present any defects. To make the measurements, we put a white witness on one of the wires with Tip-ex.

There were no problems with the extruder. A wire is made to go back and forth. We mark the thread at the initial position and then we notice the thread at the end of the back and forth. The difference between the 2 marks shows the shift.
On 30 round trips, we have an offset of 0,04mm and on 100 round trips, we have an offset of 0,02mm.

</details>

## **Stripping and cutting tests**
<details>
  <summary>Calculations</summary>
 We tested the flexibility of the inclined plate under cutting and stripping forces. We used a measuring gauge that we placed on the plate while the machine was running. Our measurements proved that the plate moves very little (order of magnitude of a hundredth of a millimeter). We concluded that the variations due to the flexibility of the plate had no impact on the quality of the jumpers.

We performed some tests to ensure the repeatability of the stripping motors. It is critical to verify repeatability because this is the part that needs the most precision.
We changed the program to perform 30 movements from the origin to a set position (in numbers of steps). The goal is to observe a displacement of the motor. For parameters, we had the resolution in numbers of steps per revolution. Also we added an offset to the origin of the stepper position every time it came back (going back to the “origin” + the number of offset steps).
To perform the test, we secured the machine in position, with a mechanical comparator set to measure the displacements along the axis of movement from the blade.

![Stripping testing](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Stripping%20test.PNG)

Stripping repeatability experimental device (1600 steps per revolution and then 3200 steps per revolution)
![Stripping results](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Stripping%20tests%20results.PNG)

  Conclusion: The results clearly show there is a displacement of our motor for each repetition, with a different constant tendency for each offset. 
To solve that issue, we raised the number of steps per revolution from 1600 to 3200 as it cut the errors by a factor of 2. Also, we added a 2 steps offset every time the cam turns back to the origin, as for each resolution this offset results in the least error in time, even though there is still a tendency to drop for this offset. It will be recommended to redo the stripping position every hundredths of jumpers' cut, some longer tests are needed to check more precisely how many we can cut before there is an issue and we stay in the tolerances fixed.

</details>

## **Test on the deformation of the inclined plate**
<details>
  <summary>Calculations</summary>

We tested the flexibility of the inclined plate under cutting and stripping forces. We used a measuring gauge that we placed on the plate while the machine was running. Our measurements proved that the plate moves very little (order of magnitude of a hundredth of a millimeter). We concluded that the variations due to the flexibility of the plate had no impact on the quality of the jumpers.
  
</details>
