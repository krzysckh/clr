# clr

clr shows html colors in a truecolor terminal

# installation

```
git clone https://github.com/krzysckh/clr
cd clr
make
sudo make install
```

# usage

```
CLR(1)				 General Commands Manual			   CLR(1)

NAME
       clr - show html color codes in truecolor terminals

SYNOPSIS
       clr [arguments] #color [#color...]

ARGUMENTS
	    --show <str> / -s <str>  -	  sets a message

	    --bg <#color>	     -	  sets background color

	    -O			     -	  displays message only once

EXAMPLES
	    clr -O --bg "#fff" "#000" -s "test"

		 displays a black word "test" on a white background

	    clr $(cat $HOME/.cache/wal/colors | sed 's/\n/ /')

		 shows current pywal-generated colors

AUTHOR
       krzysckh (github.com/krzysckh)

										   CLR(1)
```
