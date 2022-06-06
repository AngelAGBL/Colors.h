# Colors.h
## This is a lib for C/C++ Language that add colors to the output text in console.

### Functions
- Box1
  > This function creates a box around the text you write in it.
- Box2
  > This is the same of box1 but the box is drawed with two lines
- FG
  > Set a foreground color of 24 bits in the form RGB like #FFFFFF but instead the '#' you should put '0x' like this 0xFFFFFF
- Fg
  > Set a foreground color of 12 bits (0xFFF)
- fG
  > Set a foregroung color of 8 bits, the codes of this functions are different because they are based on the ansi standard
- fg
  > finally this the last function of foregound colors, there are only eight colors, the colors are:
    * 0: BLACK
    * 1: RED
    * 2: YELLOW
    * 3: GREEN
    * 4: CYAN
    * 5: BLUE
    * 6: MAGENTA
    * 7: WHITE
- Funtions BG, Bg, bG and bg
  > This functions have the same functionality that the previous functions, but this functions are for background
