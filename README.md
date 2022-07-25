# ZorkGame
## Author
I'm Pablo Cebollada and this is my Zork version, called ZorkGame, of the original game Zork.
## Commands
Possible directions, you can use the full name or only the first letter:
* north ( n )
* west ( w )
* south ( s )
* east ( e )

Commands, as the directions you can use the full name or only the first letter:
With 1 args:
* ( l ) look -> to look the room
* ( e ) examine -> to examine the room for entities
* ( h ) heal -> to restore your health, you need bandages
* ( i ) inventory -> to see the items of your inventory
* ( q ) quit -> to exit the game
* ( s ) stats -> to see the stats of the hero

With 2 args
* ( l ) look direction -> to look at a direction of the room
* ( m ) move direction -> to move from a room to another (ex.: m n)
* ( e ) examine entity -> to examine a item or a creature of the room or inventory (ex.: e Wizard)
* ( p ) pick item -> to pick an item of a room (ex.: p Sword)
* ( d ) drop item -> to drop an item to a room
* ( eq ) equip item -> to equip an item of the inventory
* ( a ) attack creature -> to attack a creature of a room
* ( t ) talk npc -> to talk with a npc
* ( lt ) loot creature -> to loot a dead creature

With 3 args
* ( c ) combine item1 item2 -> to combine items of the inventory (you only can combine armour or weapon with upgrades)

## Guide
The game consists of 6 rooms in the following disposition (look Map.jpg):

* J - Jail: you can find a Corpse to Loot, you will obtain a bandage
* M - Main Hall: you can find a creature KnightGroup, if you kill and loot them you will obtain a bandage
* G - Garden: you can find a Wizard, if you kill and loot him you will obtain an upgrade to combine with a sword or shield (you cannot upgrade an item that you already equipped)
* A - Armory: you can find a shield and a sword
* T - Throne: you can find a GoldenKnight, you can talk or kill him, if you kill and loot him you will obtain a GoldenKey
* G - GoldenRoom: you can find a GiantGoblin, if you kill and loot him you will obtain a medal (need GoldenKey to access)

To win you need to loot the medal, and for that you need to kill the GiantGoblin inside the GoldenRoom. To access there you will need the GoldenKey kept by the GoldenKnight. The GiantGoblin is pretty strong, so to win him you need to equip an upgraded sword, you will find the Sword at the armory, with the Shield, and you can upgrade it combining it with the Upgrade found in when you loot the wizard. Bandages will also be necessary.