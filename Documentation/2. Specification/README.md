# **Specification**

In order to best meet the customer's needs, we felt it was more efficient to ask him directly what he wanted from our machine. To do this, we drew up a first set of specifications and sent them to him. This was followed by several email exchanges and corrections to the specifications. We were also able to prioritize the functions of the machine from the most important to the least important with the customer. We also integrated a method of verification for each function (visual method, on software, by measurement, etc). To date, here are our main objectives.

## **Main objectives of this project**

First of all, the machine must distribute rigid wire. It must therefore be fed with wire, tension the wire and make it circulate in the system. The tensioned wire must not deviate from its initial axis by more than 1 millimeter.

Then, the machine must cut the wire to the right length and in bizot (45 degree angle). The length of wire to be cut ranges from 5.08 to 50.8 mm with a pitch of 2.54 mm with a tolerance of 0.5 mm. Here is the nomenclature of a jumper to make it clearer :

As for the removal of the sleeve, it must be done on the left and right parts of the cut wire on a length of 6.5 mm on each side with a tolerance of 0.5 mm. This step must be done with care in order not to damage the conductors. We have also thought of a sorting system in order to differentiate between the waste of the sleeve and the waste of the conductor wire.

For the bending part of the machine, the edges of the wires must be bent at 90° with a tolerance of 5°, and above all they must not modify the initial geometry of the wire, that is to say that the wire must remain straight.

Then, for the operation of the machine, the customer would like it to be powered by different sources (nomadic mode, 12v DC) and to withstand the temperature conditions of a laboratory. Moreover, the machine must also respect a rate of 1 jumper in 10 seconds. It must be reliable, i.e. it must produce at least 10 jumpers in a row that comply with the specifications mentioned above. But the machine must also be dismountable and mountable with simple tools in one hour maximum.

As far as safety is concerned, the customer would like the machine to stop completely in less than one second with a simple manipulation. Also, if the instructions are not followed, the machine should not start. Moreover, during its operation no moving part of the system should be reachable by the user.

Finally, for the spatial dimensions, the system must not exceed the dimensions L50*W30*H30 cm and must not weigh more than 15 Kg.

 
## **1. State of the art**
<details>
  <summary>Click to see the guideline!</summary>


Since a few decades, human beings have been using wires, especially jumpers, for electronic systems and often need to cut and strip them. That’s why they have created both wire cutter and wire stipper, then he wanted to do both those tasks with only one tool. Today, there are machines which can automatically cut and strip wires. They can either be big industrial machines or homemade ones depending on making rate, quantity, … It’s also possible for some machines to bend wires in order to make jumpers.


Using wire stipper or special blades can be considered as the main way to get stripped wires even though a carbon-dioxide laser is a good solution as well. However, a carbon-dioxide laser is very expensive thus outside the budget. The last solution to strip a wire we thought about consisted in using chemicals to dissolve the wire sleeve but we have quickly forgotten this solution because of its dangerousness.

About bending, there are many existing solutions and not only the basic one by using a plier but also, for example, an interesting and uncommon way with a hot wire. On the Internet, most bending machines work with a spinning part (linked to a stepper) and an offset axis.
			
A wire cutting machine “typically feeds the wire in on a reel, marks the wire using an inkjet or hot stamp printing mechanism, cuts the wire, and then coils the finished product on another reel or stacks it in a guide channel” [2].
A wire cutting/stripping machine usually has a rotating blade that follows the input cable and strips or cuts away the insulation.
However, such tools are expensive, and can’t be afforded by small workshops. For example, the Model WS-212 wire stripping machine by Bluerock Tools costs $ 1,299.00. Moreover the machine weighs 90 kilograms which is not convenient to be carried. The main issue with old wire cutting machines is the fact that they are not accurate or reliable. They tend to waste material which is an important issue when you are doing a project for the school of the environment.

Before the appearance of the first machines for cutting and stripping electrical wires, these tasks had to be done manually. Thanks to the particular shape of its blades, the "classic" cutting pliers can easily cut wires of various diameters.

![Cutting pliers](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Cutting_pliers.jpg)

For the stripping pliers, there are more or less sophisticated models. A calibrated wire stripper is very interesting for stripping small diameter wires, but its range of action is limited by its size. Indeed, the more it is possible to use it for different wires, the more it will be cumbersome. For this reason, it is sometimes interesting to have a second stripper at one's disposal to strip wires with a larger diameter.

![Pliers](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Pliers.jpg)


Stripping a wire is based on the principle of two blades that partially cut a sleeve that surrounds the electrical wires. Then pull to detach a piece of the sleeve. However, it may be interesting to be inspired by the principle of a foil cutter. That is to say, to have a device equipped with four rotating circular blades that can cut the sleeve around the wires completely.

![Wine foil cutter](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Wine_foil_cutter.jpg)


The use of blades to cut and strip wires is certainly the most common because of its simplicity, its low risk of injury but especially its very low cost compared to other devices. 


It is possible to perform these cutting and stripping tasks automatically with machines made by professionals [3] and usually sold at high prices. However, many individuals wish to have such machines to make their own jumpers. That's why there are DIY machines [4] with tutorials available online so you can make them yourself. All of these machines work in much the same way. The wire first passes through a tensioning system which also allows to straighten it. It’s then pulled by rollers which, according to their direction of rotation, make the wire advance or retreat. Finally, these machines use two V-shaped blades capable of cutting and stripping the wire. The whole thing is often managed by an Arduino type board that controls stepper motors. Finally, the use of such machines allows to cut and strip wires much faster than with pliers. It is especially possible to manufacture some of them for a lower cost.


V-blade technology is not the only technology that can be used for wire stripping. In fact, some individuals have already built their own machines and used a laser to strip the wires.


You might wonder why should a laser be considered for this purpose when the equipment is significantly more expensive than the competing methods?
The answer lies in its easy integration with electromechanical equipment, high controllability, non-contact process and no cutting force on the workpiece. Previous researches have proved that laser means has absolute advantages over traditional ways of mechanical wire stripping. [5]

![Laser stripping](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Laser_cutting.jpg)

Currently, carbon dioxide lasers are used on stripping machines because of their ability to selectively remove only the insulation without damaging the wire.
The absorption coefficient of non-metal material for this kind of laser wavelength is high and the absorption coefficient of metal material for this kind of laser wavelength is low, so the metal layer will not be damaged.
Laser wire stripping has been effectively applied as a production process in the aerospace, medical and data communications fields. There are specific advantages of using a laser over other methods but the emphasis varies from application to application.

Advantages : 
Selectively removes insulation with no conductor damage.
Near perfect process yield.
Lowest rework costs.
Provides excellent wire integrity, significantly increasing product life and reliability.
Can be automated, reducing labor costs.

Lasers have become valuable tools in manufacturing. Laser wire stripping is now performing production requirements very satisfactorily. The companies requiring wire stripping can now use lasers for this purpose and have various processes that cover all insulation materials presently in use.

Drawbacks :
High component costs.
If not fully automated, need for protection for users (closed carter and protective eyewear).
Need for a ventilation system to avoid accumulation of toxic fumes.


In the 2000s, NASA developed a manufacturing standard for wire stripping using chemical agents [6] . This method can only be used for single-conductor wires, but it is effective and allows a clean stripping without sleeve residues. However, the use of such chemical agents remains dangerous even if it seems to be possible to buy professional chemical pots [7] that enable the user to strip wires by using the method with chemical agents.

![Chemical stripping](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Chemical_stripping.jpg)


In order to bend the wires in the least complex way possible, one would simply use pliers to bend the stripped ends into the desired jumper shape. The disadvantage of this method is that it is not very fast, it can be a pain for smaller wires and it does not allow a good regularity of the jumper shape. On the other hand, it is possible to consider 3D printing a bending die allowing to deposit the wires according to the corresponding size, then to press on the edges in order to bend them. This method could also be semi-automated or even totally automated by considering two dies (female and male) that would perform the bending and would overcome some of the shortcomings of the entirely manual method.


The most commonly used solution for bending wires is to use a part controlled by a stepper motor and equipped with an eccentric and extruded cylinder. There are many machines with different designs. Indeed, some are arranged horizontally [8] and others vertically [9] . It does not seem that either of these operating modes offers any particular advantages. The majority of the machines only allow folding. However, there are some machines that are able to perform all three tasks at once [10] .

![Bending die](https://github.com/BenoitGI/Jumper-Machine-/blob/main/Sources/Images/Bending_die.jpg)

The last possible method is probably one of the least used, but it is quite possible to bend wires using an electrically heated wire [11] . It works in much the same way as the bending die, but the effort required to bend the wire is reduced. The main disadvantage of this technique is obviously the risk of burning.

[2] Wire Cutting Machines Information, para. 1, Globalspec, accessed 06/10/2022, website, https://www.globalspec.com/learnmore/manufacturing_process_equipment/machine_tools/wire_cutting_machi nes 
[3]Eraser’s catalog, p.15-29, accessed 06/11/2022, pdf document, https://www.eraser.com/pdf/Eraser_Catalog.pdf
[4] Wire cutter stripper machine DIY, Ivan Rodyk, accessed 06/11/2022, Youtube video, https://www.youtube.com/watch?v=mNCjpKPapnc&ab_channel=IvanRodyk
[5] Study on the optimal process parameters for stripping the X-ETFE insulation layer of aviation wires by a small semiconductor laser, Sage Journals, accessed 10/10/2022, Research Article, https://doi.org/10.1177/16878132221127592
[6] Wire Preparation Chemical Stripping, Nasa Workmanship Standard, accessed 06/11/2022, Research Article, https://workmanship.nasa.gov/lib/insp/2%20books/links/sections/104%20Chemical%20Stripping.html
[7] Chemical Wire Stripping, Eraser, accessed 06/11/2022, Website, https://www.eraser.com/products/wire-cable-strippers/chemical-wire-stripping/
[8] DIY Wire Bender ets wires all bend into shape, Steven Dufresne, Hackaday, accessed 06/11/2022, Blog, https://hackaday.com/2018/10/14/diy-wire-bender-gets-wires-all-bent-into-shape/
[9] Arduino wire bender probably won’t kill all humans, Kristina Panos, Hackaday, accessed 06/11/2022, Blog, https://hackaday.com/2019/09/28/arduino-wire-bender-probably-wont-kill-all-humans/
[10] Fully Automatic Wire Cutter Stripper Bender Machine YH-680Z, Kunshan Yuanhan Electronic Equipment, accessed 06/11/2022, Youtube video, https://www.youtube.com/watch?v=nUAdrEDehpE&ab_channel=KunshanYuanhanElectronicEquipment
[11] Bending materials with a simple hot wire forming tool, Mike Szczys, Hackaday, accessed 06/11/2022, Blog, https://hackaday.com/2013/02/28/bending-materials-with-a-simple-hot-wire-forming-tool/

 
 </details>
  
- **Definition:** *Stakeholders generally refer to all the actors (human and non-human) who have an interest in a product. Among the stakeholders, there are both internal players, such as users and participants of the project, and external players that are represented by the potential user of products or external entities.*

- **Comments:**

  - *A stakeholder is not necessarily a person (e.g. considering airports as a stakeholder when designing a two-deck aircraft).*
  - *A stakeholder can indirectly affect the product (e.g. considering neighborhood when designing a nuclear power plant).*
  - *A stakeholder can indirectly be affected by the product (e.g. considering the local biodiversity when designing an airport).*
 </details>
 
  <details>
    <summary>Click to see the example!</summary>
  
  ```
  What does contain the minimum documentation of the stakeholders? 
  
  Example of the ADD-ONS project of XYZ cargo
  
  - Specify the name of potential stakeholdrs 
    - Environmental activist
    - Repairmen
    - Food producer
    - Transporter
    - Health care (street medic, ...)
    - Makers
    - Craftmen
    - Other potential user
  ```
#### *Project of the [XYZ Cargo-ADD ONS](https://projects.opennext.eu/@xyz-cargo-add-ons/xyz-cargo-add-ons)*
*The image below shows the stakeholders of  ADD-ONS of XYZ cargo as a graph*

  ![Image of stakeholder of ADD-ONS of XYZ cargo](https://github.com/OPEN-NEXT/WP2.3-Guideline-and-templatefor-documentation-of-OSH-design-reuse/blob/main/Sources/Images/Stakeholders%20of%20XYZ%20cargo%20ADD-ONS.jpg)
  
<a href="https://app.diagrams.net/?libs=general#Hamerezoji1362%2Fdrawio-github%2Fmaster%2FStakeholders.drawio" target="_blank">Edit As New</a> | <a href="https://app.diagrams.net/#Hamerezoji1362%2Fdrawio-github%2Fmaster%2Fstakeholders.png">Edit in diagrams.net</a>
</details>

### Template of stakeholders
  
   * Stakeholder name 1
   * ...

  ![Image of template of stakeholder diagram](https://github.com/OPEN-NEXT/WP2.3-Guideline-and-templatefor-documentation-of-OSH-design-reuse/blob/main/Sources/Images/Stakeholder%20diagram%20for%20template.jpg)
            
  *The link below can be used to define the stakeholders of your project/product.*
  
  <a href="https://app.diagrams.net/?libs=general#Hamerezoji1362%2Fdrawio-github%2Fmaster%2FStakeholder%20diagram%20for%20template.drawio" target="_blank">Edit As New</a> | <a href="https://app.diagrams.net/?libs=general#Hamerezoji1362%2Fdrawio-github%2Fmaster%2FStakeholder%20diagram%20for%20template.png">Edit in diagrams.net</a>
  
## **2. External interfaces**
<details>
  <summary>Click to see the guideline!</summary>
  
- **Definition:**  *External interfaces are interactions between the product and the stakeholders.*

- **Comments:**
  - *An interface is made of a port (in, out, or in-out)*
  - *An interface is made of a flow (matter, energy, or signal)*
</details>
 <details>
  <summary>Click to see the example!</summary>
   
 ```
What does contain the minimum documentation of the external interfaces? 

Example XYZ Cargo ADD-ONS

  - Identify the interactions between food producer and the product including 
    - Specify needs
    - Uses
    
  - Identify the interactions between maker and the product inculding  
    - repair
      - unmount 
    - make
    - reproduce
    - modify
  - ...
  ```

*The image below shows the external interfaces of  ADD-ONS of XYZ cargo as a graph*

![Image of External interfaces of XYZ cargo-ADD ONS](https://github.com/OPEN-NEXT/WP2.3-Guideline-and-templatefor-documentation-of-OSH-design-reuse/blob/main/Sources/Images/External%20interfaces%20of%20XYZ%20Cargo%20ADD-ONS.jpg)

<a href="https://app.diagrams.net/?libs=general#Hamerezoji1362%2Fdrawio-github%2Fmaster%2FExternal%20interfaces.drawio">Edit As New</a> | <a href="https://app.diagrams.net/#Hamerezoji1362%2Fdrawio-github%2Fmaster%2FExternal%20interfaces.png">Edit in diagrams.net</a>
</details>

### Template of external interfaces
   
   * Stakeholder name 1
       * Flow 1
       * ...
 
 ![Image of stakeholder diagram for template](https://github.com/OPEN-NEXT/WP2.3-Guideline-and-templatefor-documentation-of-OSH-design-reuse/blob/main/Sources/Images/External%20interfaces%20for%20template.jpg)
  
   *The link below can be used to define the external interfaces of your project/product.*
  
  <a href="https://app.diagrams.net/#Hamerezoji1362%2Fdrawio-github%2Fmaster%2FExternal%20interfaces%20for%20template.drawio">Edit As New</a> | <a href="https://app.diagrams.net/#Hamerezoji1362%2Fdrawio-github%2Fmaster%2FExternal%20interfaces%20for%20template.drawio">Edit in diagrams.net</a>

## 3. Service *(synonyms: external function, capability)* 
<details>
  <summary>Click to see the guideline!</summary>
  
- **Definition:** *A service is an effect intended by a stakeholder resulting from the interaction of the product with its environment (i.e. what the  product is for).*

- **Comments:**
  - *Services provide users with an exchange value that can be included in an economic system (e.g. airlines buy flight hours).*
  - *Services are intended effects that can be observed from outside the product ("black box" external view), but not from outside an internal component ("white box" internal view).*
  - *Services are defined in a solution neutral-way.*
  - *Services can be stated as follows: The [Product] shall enable [Stakeholder] [Action verb] (e.g. The product shall enable end-user to clean its teeth)*
  - *we often reason in terms of action verbs to communicate expected behaviors, so it would be nice to be able to search designs with action verbs*
</details>

<details>
  <summary>Click to see the example!</summary>
  
 ```
  What does contain the minimum documentation of the service to stakeholders?
  
  Example of services for ADD-ONS of XYZ Cargo
  
    - The ADD-ONS shall enable the food producer to store food
      - 1.1 solid (10 kilos)
      - 1.2 liquid (5 litrs)
    - The ADD-ONS shall enable the food producer to heat food
      -  2.1solid (150 deg Celcius)
      - 2.2 liquid (80 deg Celcius)
    - The ADD-ONS shall enable the food producer to cool down food for 4 hours
      - 3.1 solid (6 deg Celcius)
      - 3.2 liquid (6 deg Celcius)
      
    - ...
  ```
 </details>

### Template of services
  
   * Services to stakeholder 1
       * Service 1.1
       * ...

## 4. Constraint *(Synonyms: non function requirement)*
<details>
  <summary>Click to see the guideline!</summary>
  
- **Definition:**  *A constraint is a choice that makes certain designs "not allowed" or inappropriate for their intended use.*

- **Comments:**

  - *The constraint is a restriction, limit, or regulation imposed on a product.*
  - *There are two kinds of constraints: input constraints and system constraints.* 
    - *Input constraints are imposed as part of the design specifications.*
    - *System constraints are constraints imposed by the system in which the design solution must function.*
 </details> 
 
 <details>
  <summary>Click to see the example!</summary>
  
   ```
  What does contain the minimum documentation of the constraints?
  
  Example XYZ Cargo ADD-ONS, constraints for maker of ADD-ONS
  
   - User should be able to dismantle ADD-ONS with a maximum one wrench and one screwdriver 
   - Users should be able to customize the modules of ADD-ONS to fit their use. 
   - The ADD-ONS should enable the users to do the assembly of components in a short time (10 minutes) and the maker shall select the resistance material for using ADD-ONS in different weather conditions. 
   - ADD-ONS should be dismantled for recycling purposes.
   - ...

  ```
</details>

### Template of constraints
  
   * Constraint 1
   * ...
     
  
## **5. Requirement**

<details>
  <summary>Click to see the guideline!</summary>
  
- **Definition:** *A requirement is a formal statement that specifies when condition C is true, property P of object O is actual and its value shall belong  to domain D.*

- **Comments:**
  -  *The minimum set of independent requirements can completely characterize the needs of the product in the functional domain.*
  -  *Functional requirements describe qualitatively the system functions or tasks to be performed in operation.* 
  -  *Requirement can state as follows: The [stakeholder] need [Property] [object] [Action verb]  at [Condition]* 
 </details>
 
 <details>
  <summary>Click to see the example!</summary>
  
  ```
  Example of the functional requirement that ADD-ONS of XYZ cargo provides for the food producers, as a stakeholder, to preserve the quality of food.
 
  In this example, we assumed a refrigerator on the ADD-ONS could help the food producers to cool down and preserve the temperature of food. 
  
  So, we defined some  functional requirements (FR) based on this assumption that consist:
 
    - FR1: To maintain the quality of food, the food producer needs to main the material at cold temperature (between 3 °C and 10 °C) for short-term preservation (3h) or long-term preservation (24h).
    - FR2: ADD-ONS shall fix the internal ADD-ONS temperature for 7 °C.
    - FR3: To create a cold ambient in the cooling down system, the ADD-ONS shall compress the low temperature and pressured gas to start the cooling cycle.
    - FR4: the cooling down system shall control the pressure of exit hot gas 
    - FR5: the hot and pressured exit gas needs to meet the cooler external ambient temperature to become a liquid.
    - ...
    
  ```
 </details>
 
 ### Template of requirements
    
   * Requirement 1
   * ...
 



