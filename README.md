# NanoTekSpice
[![GPLv3 licensed](https://img.shields.io/badge/license-GPLv3-blue.svg)](./LICENSE)

![Nano](https://ethan.jp/images/git/nano.jpg)

Second year Epitech project.

The NanoTekSpice is a basic electronic circuit simulator. It loads a circuit from a configuration file and allows you to simulate its operation.

## Requirements

- CMake
- A compiler that supports C++14 or newer

## Compilation and Installation

```bash
cmake .
make
sudo make install # Optional
```

If you chose to not install it, the binary will be located in the `./bin` directory.

## Usage

```bash
./nanotekspice <file_name> [<input=value> ...]
```

Available commands :

* `exit` : closes the program.
* `display` : prints the value of all outputs.
* `input=value` : changes the value of an input. This does not apply to `Clock`, `False` and `True`.
* `simulate` : runs the simulation.
* `loop` : continuously runs the simulation until SIGINT is received.
* `dump` : prints detailed information about the simulation.

## Circuits

### Location

Some configuration files are located in the `./circuits` directory. You can use one of them or create your own.

### Syntax

```
# Declare your components into the 'chipsets' section...
.chipsets:

# <chipset> <name>
# The name is up to you
# Example :
input   i1
output  s1
4081    and

# ...then link them within the 'links' section
.links:

# <chipset_name1>:<pin1> <chipset_name2>:<pin2>
# Example :
i1:1    and:1
s1:1    and:3
```
