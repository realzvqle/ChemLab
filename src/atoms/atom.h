#ifndef ATOM_H_INCLUDED
#define ATOM_H_INCLUDED



#include <stdint.h>
#include <stdbool.h>
#include "../exheaders/raylib.h"

typedef struct _element{
    uint8_t protons;
    char* name;
    Color color;
} Element;

typedef struct _atom{
    Element element;
    uint8_t electrons;
    uint8_t neutrons;
} Atom;

Atom AtInitializeAtom(uint8_t protons, uint8_t neutrons, uint8_t electrons);
uint8_t AtGetValenceElectrons(Atom* atom);
char* AtReturnElementNameFromProtonNumber(int protonnum);
uint8_t AtReturnProtonNumberFromElementName(char* elementname);
Element AtReturnElementFromProtonNumber(int protonnum);
Element AtReturnElementFromElementName(char* elementname);
#endif