# Internet-Bandwitch-Module-for-DD-WRT-router
<p align="justify"> Un module Arduino (équipé d'un écran LCD et d'un controlleur Ethernet) qui se connecte à un routeur DD-WRT avec le protocole TELNET. Le module Arduino lit la consommation Internet et l'affiche sur l'écran LCD. </p>
<br />

## Installation
<p align="justify"> Tout dabord, votre routeur principal (celui connecté directement sur le modem de votre ISP) doit être flashé avec le firmware de <a href="http://dd-wrt.com">DD-WRT.com</a>. Ensuite, le calcul du <i>bandwitch</i> et <i>Telnet</i> doivent être activés dans la configuration de votre routeur.</p>
<p align="justify"> Si vous avez tous les prérequis précédent, effectuer tout simplement les raccordements indiqués dans la section <b>Schéma</b> et uploadé le code tel qu'indiqué dans la section <b>Code</b>.</p>
<br />

## Liste des composantes
* Un routeur avec un firmware **DD-WRT**
* **Arduino UNO** ou une variante
* **ENC28J60** ou **EthernetShield**
* **LCD screen** : (compatible avec le driver Hitachi HD44780)
* **pin headers** : pour l'écran LCD et/ou le module ENC
* **220Ω Resistor**
* **Potentiomètre** : résistance maximale 10kΩ
<br />
<br />

## Code
### Script pour votre routeur
<p align="justify"> Vous devez ajouté dans votre routeur ce script de démarrage : <a href="https://github.com/MarcAndreJean/Internet-Bandwitch-Module-for-DD-WRT-router/tree/master/Code/bandswitch.txt">bandwitch.txt</a>. Celui-ci créera un script dans le dossier temporaire du Root à chaque redémarrage. Il aurait été possible de mettre le script dans l'espace de stockage permanent JFFS mais malheuresement cette solution ne marche pas pour tous les routeurs. Et puisque que les fichiers temporaires sont supprimés après chaque démarrage, il s'agit de la seule solution que j'ai trouvé. C'est moche mais ça fonctionne.</p>

### Code pour votre Arduino
<p align="justify"> Le code à uploader dans votre Arduino est celui du fichier <a href="https://github.com/MarcAndreJean/Internet-Bandwitch-Module-for-DD-WRT-router/tree/master/Code/arduinocode.inu">arduinocode.inu</a>
<p align="justify"> Si vous utilisé le module Ethernet ENC28J60, vous devez ajouté la librairie <i>&#60;UIPEthernet.h&#62;</i> disponible <a href="https://github.com/ntruchsess/arduino_uip">ici</a>. Vous devrez downloadé le zip du projet complet avec le button <i>clone or download</i> du Git puis ajouté avec l'IDE d'arduino le fichier zip [ <i>IDE->Croquis->Inclure une bibliothèque->Ajouter bibliothèque ZIP ...</i> ]. Sinon, si vous avez le Shield Ethernet, vous devez utilisé la librairie <i>&#60;Ethernet.h&#62;</i> qui est déjà inclut dans l'IDE d'Arduino. </p>
<br />
<br /> 

## Schéma
### Avec un module Ethernet ENC28J60

#### Connections ENC :
* ENC **SCK** ➜ Arduino pin **13**
* ENC **SO** ➜ Arduino pin **12**
* ENC **SI** ➜ Arduino pin **11**
* ENC **CS** ➜ Arduino pin **10**
* ENC **VCC** ➜ Arduino **3V3** pin
* ENC **GND** ➜ Arduino **GND** pin

#### Connections LCD :
* LCD **RS** ➜ Arduino pin **7**
* LCD **Enable** ➜ Arduino pin **6**
* LCD **D4** ➜ Arduino pin **5**
* LCD **D5** ➜ Arduino pin **4**
* LCD **D6** ➜ Arduino pin **3**
* LCD **D7** ➜ Arduino pin **2**
* LCD **VDD** ➜ Arduino **5V** pin
* LCD **VSS** ➜ Arduino **GND** pin
* LCD **R/W** ➜ Arduino **GND** pin
* Potentiomètre **+** ➜ Arduino **5V** pin
* Potentiomètre **-** ➜ Arduino **GND** pin
* LCD **V0** ➜ Potentiomètre **output**
* LCD **LED+** ➜ 220 ohm resistor ➜ Arduino **5V** pin
* LCD **LED-** ➜ Arduino **GND** pin

> ![Schema avec ENC28J60](https://github.com/MarcAndreJean/Internet-Bandwitch-Module-for-DD-WRT-router/blob/master/Schematic/Schematic_w_ENC28J60.png)


### Avec un Shield Ethernet

#### Connections LCD :
* LCD **RS** ➜ Arduino pin **7**
* LCD **Enable** ➜ Arduino pin **6**
* LCD **D4** ➜ Arduino pin **5**
* LCD **D5** ➜ Arduino pin **4**
* LCD **D6** ➜ Arduino pin **3**
* LCD **D7** ➜ Arduino pin **2**
* LCD **VDD** ➜ Arduino **5V** pin
* LCD **VSS** ➜ Arduino **GND** pin
* LCD **R/W** ➜ Arduino **GND** pin
* Potentiomètre **+** ➜ Arduino **5V** pin
* Potentiomètre **-** ➜ Arduino **GND** pin
* LCD **V0** ➜ Potentiomètre **output**
* LCD **LED+** ➜ 220 ohm resistor ➜ Arduino **5V** pin
* LCD **LED-** ➜ Arduino **GND** pin

> ![Schema avec EthernetShield](https://github.com/MarcAndreJean/Internet-Bandwitch-Module-for-DD-WRT-router/blob/master/Schematic/Schematic_w_EthernetShield.png?raw=true)

### Notices
...
