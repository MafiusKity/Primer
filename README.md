# Primer
A C++ program to encounter the nth primer number (new version of https://github.com/MafiusKity/cousins)
## Install
To install, clone this repo. or download the files of this repo. in the same directory.

```Bash
#For Linux
git clone https://github.com/MafiusKity/Primer
cd Primer
g++ primer_v1.cpp -o primer
```

## Use
```Bash
#Standard use
./primer nth  #nth>0 and integer
#Flags use:
./primer [[-flag]]
  [[-flags]]:
    -h  #Show help about the program
    -v  #Show version
    -r  #Reset memory.primer. This maybe solve any bug...
    -n nth  #Use memory.primer file to search nth primer number without algorithm
    -t nth  #Perform -n flag and algorithm if necessary
    -l nth  #Display a list of primer numbers in memory.primer until the nth number (nth=0 for display all)
```

## Future features
- Remove error of negatives entrances. I thinking if this revision is really necessary...
- Add -q (quiet) flag for run program without display result. I beliven't that will happen;
- Add windows installation tutorial;
- Remove unnecessary comments in the source code;
