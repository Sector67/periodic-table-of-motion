# Periodic Table of Motion

## Overview

A science museum needs interactive exhibits, and this is an exhibit that can easily be extended, is easy to setup and install, is robust and safe and easy to maintain. The idea is a periodic table of motion, where each cell, instead of an element, is a type of mechanical motion. Inside the cell is a description of the motion, a button to activate it, and an actual example of a working machine that uses the principle. Simple machines (lever, pulley, gear, etc.) are at the top of each column, and they increase in complexity. Cells are individual units that get power (+12V and +5V) via a bus. They are a standard size (9"x9"x3"). They have a standard electronics unit that provides for up to 2 DC motors, 2 Servos, 4 limit switches, and 1 switched output. All cells also have a single capacitive touch button to activate the cell, and a 12V switched output dedicated to an output for an LED strip to light up the activated cell (indicating that it has been activated).

## Structure

A cell is the basic independent unit. It has a title, description, machine class, and example use. It also has a physical manifestation which is described with 3D cad files and a bill of materials and build instructions. It also has code to control the display, written in Arduino for an ATTiny.

The repository has a section for cells, which are all based on the template cell. Each subfolder in the cells subfolder is used for a different cell. The template_cell can be copied and extended.

The underlying electronics and enclosure for a cell is defined in the cell subfolder. These instructions are used to build every cell. The cells folder is how to modify that cell to be unique.

The table is the large structure that contains the cells. This can be modified to suit the installation, but the repository contains a sample wall that is 5 cells tall, 12 wide, and contains all the parts necessary for the power supply as well.
