# Cards 2 GUI
## The easy way to track your tickets!

<img src="https://github.com/daltonyxdonovan/Cards2/blob/master/cards2_display.png?raw=true" alt="Cards 2 Display" title="Preview of GUI">


## use the issue tracker for bugs, please! (:
# Due to security restrictions in windows 11

in order to use this, it has to remain in the exact folder configuration provided. the
Cards2 executable requires itself to be in the same folder as the assets folder,
and the .tab to be used is required to be in the folder with it. you can remove and replace
the .tab at will. you are more than welcome to make a shortcut to it, but the .tab still has
to be in the Cards2 folder. this is a requirement so it can work on anyone's pc
with little fuss. I personally keep it in a folder on the desktop, because it's the easiest
workaround to the tight restrictions on file access.

## TO USE

go to the releases tab of the github page here, and download the current version. extract
the .zip to your desktop, put your .tab file in the folder.

i'm not personally well-versed in anything maintech or how to get the .tab, all i know is 
that you download a strictly non-filtered .tab file from the maintech website, and you put 
the file in the same location as the executable. right outside the 'assets' folder.

## CONTROLS
<img src="https://github.com/daltonyxdonovan/Cards2/blob/master/cards2_info.png?raw=true" alt="Cards 2 Controls" title="Preview of GUI controls">
the mouse can check off a card to dismiss it

arrow keys can change the background and text color as well!

the escape button exits the program

## NOTES

note: in the spirit of open source, and so there are no thoughts of viruses or anything, i've
left the source code included. feel free to pick apart my spaghetti code

# FAQ
## MISSING REDIST
if you encounter an error along the lines of "missing redistributable MSVC-xxxxxxxx", you are 
missing a redistributable package from the microsoft website. super easy fix. just plug the 
MSVC number in to google and go to the top microsoft website result and install the package.

## BLANK COLORED SCREEN ON START
if you encounter this, that means the files are either not in a place the application is
allowed to touch, or they are in the wrong order. make a folder on your desktop, put the
Cards2.exe and the entire 'assets' folder *inside* that folder. put your .tab *inside*
that folder, run the application. that's all (:
