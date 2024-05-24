# Zork
A reimplementation of the game structure based on the original Zork game (https://de.wikipedia.org/wiki/Zork)

# Link
https://github.com/LukasGanter/Zork

# Licence
MIT licence (https://opensource.org/license/mit)

# Authors
Development: 	Lukas Ganter
Testing: 		Various colleagues and family members

# Implementation
I implemented the software with scalability in mind. Most of the features can easily be extended or new content can quickly be added.
Some features are partially included but not activated in the final release. I also reduced the effort to fill the game with high quality textual content. Some parts are written in a way which shows the functionality, without the focus on being typographically pleasing.

# Special features
As a special feature i implemented a locking and unlocking mechanism for doors and chests. Both options are present in the game on the main player path.
Implemented by storing the key id inside the door / chest classes and comparing it to the ids of available key objects inside the players inventory.

# Problems
The biggest issue i faced was the difference between "normal" c++ and the version the Unreal Engine uses. 
Over the last years i mostly developed code using the Unreal Engine, which uses a lot of other classes and styleguides.
However a lot of the programming concepts are the same, so the switch took some time and then it worked pretty well.

Another issue was the time. I am working fulltime, so finding the time for the project was difficult. 
However with a reduction in the features i was able to finish a working version.

# Skills sheet
I was not able to edit the provided skills sheed. For the pdf version i don´t have the necessary subscriptions
and the word version is corrupted with my version of word (I have attached a screenshot inside the repositories "delivery" folder.)
The skills tables are provided inside the "Skills Test Programming.pdf" file, for the projects i have submitted my portfolio.

# Game instruction
There are five rooms in the game, each one contains a letter. These letters combined give you a passcode which needs to be remembered and is necessary for collecting the medallion (Hint: Code consists of 5 numbers). 
The game finishes once you go back to the old man and talk to him while having the medallion.
As an input syntax, the game currently supports one order followed by a value. Order and value need to be separated by a space, the value is mostly made up of in game item names.
Example: "take sword", "go east", etc.

List of orders:
- LOOK
- TAKE
- LOOT
- DROP
- STORE
- REMEMBER
- MOVE
- TALK
- READ
- INVENTORY
- EQUIP
- UNEQUIP
- LOCK
- UNLOCK
