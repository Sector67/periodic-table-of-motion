# Periodic Table of Motion

## Overview

A science museum needs interactive exhibits, and this is an exhibit that can easily be extended, is easy to setup and install, is robust and safe and easy to maintain. Exhibits can easily cost tens of thousands of dollars, but this one can grow to any size budget but the top of the line is still under $4k. The idea is a periodic table of motion, where each cell, instead of an element, is a type of mechanical motion. Inside the cell is a description of the motion, a button to activate it, and an actual example of a working machine that uses the principle. Simple machines (lever, pulley, gear, etc.) are at the top of each column, and they increase in complexity. For an example of the variety of types of motions I want to capture and show off, see http://507movements.com. This project is very educational and interactive, and distills the basics of mechanics into individual and easy to understand concepts, building on them to show advanced motion and power transfer in a fun way.

## Structure

A cell is the basic independent unit. It has a title, description, machine class, and example use. It also has a physical manifestation which is described with 3D cad files and a bill of materials and build instructions. It also has code to control the display, written in Arduino for an ATTiny.

The repository has a section for cells, which are all based on the template cell. Each subfolder in the cells subfolder is used for a different cell. The template_cell can be copied and extended.

The underlying electronics and enclosure for a cell is defined in the cell subfolder. These instructions are used to build every cell. The cells folder is how to modify that cell to be unique.

The table is the large structure that contains the cells. This can be modified to suit the installation, but the repository contains a sample wall that is 5 cells tall, 12 wide, and contains all the parts necessary for the power supply as well.

The power supply is an ATX computer supply. Sufficiently large installations should use multiple supplies, possibly one for every 3-4 columns, as a typical behavior might be for kids to push all the buttons at once.

## Current Status

As of 2015/08/17, the template is complete. Electronics are done and verified, example sketches exist for each piece of hardware, the structure for the project is defined and template documents exist to enable individual cells to be created. A sample cell has been created to verify everything.

Still to do is designing each of the individual cells, building and assembling them, and raising the funds to produce more than a few cells. However, the template cell proves that it's all do-able. Designing the individual cells will take the longest; assembling won't be too bad.

## Cost

A rough estimate of the cost of this project is as follows:

Wall mount:
 * Power supplies 5 ATX: $100
 * Wood/Plastic $200
 * Cables $100

Cells x60:
 * Polycarb $5
 * Enclosure materials $10
 * Electronics $10
 * Motors/Servos $15
 * Plastic printed/machined parts $10
 * LED strip $5

So $4-500 for the main part and $55 per cell.
